
#include "REFPROP-manager/REFPROP-manager.hpp"
#include <string>

int main() {

    std::vector<std::string> names = {"METHANE","ETHANE","PROPANE","BUTANE","PENTANE","HEXANE","HEPTANE","OCTANE","NONANE","DECANE"};

    // Load 10 instances of REFPROP, and for each one, initialize it in serial(!)
    std::vector<int> handles;
    for (auto i = 0; i < 10; ++i){
        char errmsg[255];
        int handle_errcode = 0;
        int handle = construct_handle("D:/Program Files (x86)/REFPROP/", "REFPRP64.dll", &handle_errcode, errmsg, 255);
        int ierr = 0;
        char hfld[255] = std::string(255, " ").c_str();
        strcpy(hfld, names[1].c_str());
        SETFLUIDSdll(handle, &handle_errcode, hfld, ierr);
        handles.push_back(handle);
    }

    // Now we do a serial evaluation, calculation of the NBP temperature for each one
    //int kq = 1;
    //double z[] = { 1.0 }, x[] = { 1.0 }, y[] = { 1.0 }, T = 300, p = 101.325, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
    //PQFLSHdll(handle, &handle_errcode, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);

    return EXIT_SUCCESS;
}