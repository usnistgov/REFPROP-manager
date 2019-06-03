
#include "REFPROP-manager/REFPROP-manager.hpp"
#include <string>
#include <future>
#include "ThreadPool.h"

int main() {

    std::vector<std::string> names = {"METHANE","ETHANE","PROPANE","BUTANE","PENTANE","HEXANE","HEPTANE","OCTANE"};//,"NONANE","DECANE"};
    std::vector<REFPROPInstance> instances;

    // Load instances of REFPROP, and for each one, initialize it in serial(!)
    for (auto i = 0; i < names.size(); ++i){
        char errmsg[255];
        int handle_errcode = 0;
        char* RPPREFIX = std::getenv("RPPREFIX");
        try{
            REFPROPInstance inn(RPPREFIX, "librefprop.so");
            instances.push_back(std::move(inn));
        }
        catch(...){
            std::cout << "Could not load REFPROP from "+std::string(RPPREFIX)+"; fail!\n";
            std::cout << errmsg << std::endl;
            return EXIT_FAILURE;
        }
        auto &handle = instances.back();
        int ierr = 0;
        char hfld[10001] = "";
        std::string name = names[i].c_str();
        strcpy(hfld, (name.c_str() + std::string(10000 - name.size(), ' ')).c_str());
        handle.SETFLUIDSdll(hfld, ierr, 10000);
        if (ierr != 0){
            std::cout << "Setting fluids failed" << std::endl;
            return EXIT_FAILURE;
        }
    }
    const int repeats = 1000000;

    // Calculation of the NBP temperature for each one
    auto f = [](REFPROPInstance &RP, double &elap){
        auto startTime = std::chrono::system_clock::now();
        double Tavg = 0;
        int kq = 1;
        int ierr = 0;
        char herr[255];
        double z[20] = { 1.0 }, x[20] = { 1.0 }, y[20] = { 1.0 }, T = -100, p = 101.325, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
        for (auto count = 0; count < repeats; ++count){
            p = 101.325+100*count/repeats;
            RP.PQFLSHdll(p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);
            Tavg += T;
        }
        auto endTime = std::chrono::system_clock::now();
        elap = std::chrono::duration<double>(endTime - startTime).count();
        return Tavg;
    };

    // Now we do a serial evaluation, 
    std::vector<double> serial_outs;
    {
        auto startTime = std::chrono::system_clock::now();
        for (auto &handle: instances){
            double elap;
            serial_outs.push_back(f(handle, elap));
            std::cout << elap << std::endl;
        }
        auto endTime = std::chrono::system_clock::now();
        double elap = std::chrono::duration<double>(endTime - startTime).count();
        std::cout << elap << "s serial\n";
    }

    // Same exercise, with a future...
    std::vector<double> parallel_outs, parallel_times(names.size());
    {
        std::vector<std::future<double> > futures;
        // Set up the tasks
        for(int i = 0; i < names.size(); ++i) {
            double &elap = parallel_times[i];
            REFPROPInstance &inst = instances[i];
            futures.push_back(
                std::async([f, &elap, &inst](){auto o = f(inst, elap); std::cout << elap << std::endl; return o;})
            );
        }
        // Run and time...
        auto startTime = std::chrono::system_clock::now();
        for(auto &e : futures) {
            parallel_outs.push_back(e.get());
        }
        auto endTime = std::chrono::system_clock::now();
        double elap = std::chrono::duration<double>(endTime - startTime).count();
        std::cout << elap << "s parallel w/ futures\n";
    }

    // And this time with a ThreadPool
    std::vector<double> pool_outs(names.size()), pool_times(names.size());
    {
        // Create the thread(s).
        ThreadPool pool(8); 

        // Set up the tasks
        for(int i = 0; i < names.size(); ++i) {
            auto &handle = instances[i];
            double &o = pool_outs[i], &elap = pool_times[i];
            auto f_wrap = [&o, f, &handle, &elap](){
                o = f(handle, elap);
            };
            pool.AddJob(f_wrap);
        }
        // Run and time...
        auto startTime = std::chrono::system_clock::now();
            pool.WaitAll();
        auto endTime = std::chrono::system_clock::now();
        auto elap = std::chrono::duration<double>(endTime - startTime).count();
        for (auto i = 0; i < pool_times.size(); ++i){
            std::cout << pool_times[i] << std::endl;
        }
        std::cout << elap << "s pool\n";
    }
    
    // // Print the values; serial followed by parallel, followed by pool, should be the same
    // for (auto i = 0; i < serial_outs.size(); ++i){
    //     std::cout << names[i] << ": " << serial_outs[i] << "; " << parallel_outs[i]  << "; " << pool_outs[i] << std::endl;
    // }
    return EXIT_SUCCESS;
}