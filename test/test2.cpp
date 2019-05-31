
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

    // Now we do a serial evaluation, calculation of the NBP temperature for each one
    std::vector<double> serial_outs;
    for (auto handle: handles){
        int kq = 1;
        int ierr = 0;
        int handle_errcode = 0;
        char herr[255];
        double z[20] = { 1.0 }, x[20] = { 1.0 }, y[20] = { 1.0 }, T = -100, p = 101.325, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
        PQFLSHdll(handle, &handle_errcode, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);
        serial_outs.push_back(T);
    }
    for (auto i = 0; i < serial_outs.size(); ++i){
        std::cout << names[i] << ": " << serial_outs[i];
    }

    // Same exercise, with a future
    std::vector<std::future<double>> futures;
    for(int i = 0; i < 10; ++i) {
        auto f = [](int handle){
            int kq = 1;
            int ierr = 0;
            int handle_errcode = 0;
            char herr[255];
            double z[20] = { 1.0 }, x[20] = { 1.0 }, y[20] = { 1.0 }, T = -100, p = 101.325, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
            PQFLSHdll(handle, &handle_errcode, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);
            return T;
        };
        futures.push_back(std::async(f, handles[i]));
    }
    // Retrive and print the value stored in the future
    for(auto &e : futures) {
        std::cout << e.get() << std::endl;
    }
    return EXIT_SUCCESS;
}