
#include "REFPROP-manager/REFPROP-manager.hpp"
#include <string>
#include <future>

int main() {

    std::vector<std::string> names = {"METHANE","ETHANE","PROPANE","BUTANE","PENTANE","HEXANE","HEPTANE","OCTANE","NONANE","DECANE"};

    // Load 10 instances of REFPROP, and for each one, initialize it in serial(!)
    std::vector<int> handles;
    for (auto i = 0; i < 10; ++i){
        char errmsg[255];
        int handle_errcode = 0;
        char* RPPREFIX = std::getenv("RPPREFIX");
        int handle = construct_handle(RPPREFIX, "librefprop.so", &handle_errcode, errmsg, 255);
        if (handle_errcode != 0){
            std::cout << "Could not load REFPROP from "+std::string(RPPREFIX)+"; fail!\n";
            std::cout << errmsg << std::endl;
            return EXIT_FAILURE;
        }
        int ierr = 0;
        char hfld[10001] = "";
        std::string name = names[i].c_str();
        strcpy(hfld, (name.c_str() + std::string(10001 - name.size(), ' ')).c_str());
        SETFLUIDSdll(handle, &handle_errcode, hfld, ierr, 10000);
        if (ierr != 0){
            std::cout << "Setting fluids failed" << std::endl;
            return EXIT_FAILURE;
        }
        handles.push_back(handle);
    }
    const int repeats = 100;

    // Now we do a serial evaluation, calculation of the NBP temperature for each one
    std::vector<double> serial_outs;
    {
    auto startTime = std::chrono::system_clock::now();
    for (auto handle: handles){
        double Tavg = 0;
        for (auto count = 0; 0 < repeats; ++count){
            int kq = 1;
            int ierr = 0;
            int handle_errcode = 0;
            char herr[255];
            double z[20] = { 1.0 }, x[20] = { 1.0 }, y[20] = { 1.0 }, T = -100, p = 101.325+count*1e-12, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
            PQFLSHdll(handle, &handle_errcode, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);
            Tavg += T;
        }
        serial_outs.push_back(Tavg);
    }
    auto endTime = std::chrono::system_clock::now();
    double elap = std::chrono::duration<double>(endTime - startTime).count();
    std::cout << elap << "s serial\n";
    }

    // Same exercise, with a future...
    std::vector<std::future<double>> futures;
    // Set up the tasks
    for(int i = 0; i < 10; ++i) {
        auto f = [](int handle){
            double Tavg = 0;
            for (auto count = 0; count < repeats; ++count){
                int kq = 1;
                int ierr = 0;
                int handle_errcode = 0;
                char herr[255];
                double z[20] = { 1.0 }, x[20] = { 1.0 }, y[20] = { 1.0 }, T = -100, p = 101.325+count*1e-12, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
                PQFLSHdll(handle, &handle_errcode, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);
                Tavg += T;
            }
            return Tavg;
        };
        futures.push_back(std::async(f, handles[i]));
    }
    auto startTime = std::chrono::system_clock::now();
    std::vector<double> parallel_outs;
    // Retrive and print the value stored in the future
    for(auto &e : futures) {
        parallel_outs.push_back(e.get());
    }
    auto endTime = std::chrono::system_clock::now();
    double elap = std::chrono::duration<double>(endTime - startTime).count();
    std::cout << elap << "s parallel\n";
    for (auto i = 0; i < serial_outs.size(); ++i){
        std::cout << names[i] << ": " << serial_outs[i] << "; " << parallel_outs[i] << std::endl;
    }
    return EXIT_SUCCESS;
}