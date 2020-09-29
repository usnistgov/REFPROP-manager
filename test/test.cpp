
#include "REFPROP-manager/REFPROP-manager.hpp"

int main() {

    char errmsg[255];
    int handle_errcode = 0;
    char* RPPREFIX = std::getenv("RPPREFIX");
    if (RPPREFIX == nullptr) {
        throw std::invalid_argument("RPPREFIX environment variable must be set to root folder of REFPROP");
    }
#if defined(WIN32)
    int handle = construct_handle(RPPREFIX, "REFPRP64.dll", &handle_errcode, errmsg, 255);
#else
    int handle = construct_handle(RPPREFIX, "librefprop.so", &handle_errcode, errmsg, 255);
#endif
    if (handle_errcode != 0) {
        throw InvalidHandle(errmsg, handle_errcode);
    }

    int nc = 1;
    int ierr = 0;
    char herr[255], hfld[] = "WATER.FLD", hhmx[] = "HMX.BNC", href[] = "DEF";
    SETUPdll(handle, &handle_errcode, nc, hfld, hhmx, href, ierr, herr, 10000, 255, 3, 255);

    int kq = 1;
    double z[] = { 1.0 }, x[] = { 1.0 }, y[] = { 1.0 }, T = 300, p = 101.325, d = -1, dl = -1, dv = -1, h = -1, s = -1, u = -1, cp = -1, cv = -1, q = 0, w = -1;
    PQFLSHdll(handle, &handle_errcode, p, q, z, kq, T, d, dl, dv, x, y, u, h, s, cp, cv, w, ierr, herr, 255);

    return EXIT_SUCCESS;
}