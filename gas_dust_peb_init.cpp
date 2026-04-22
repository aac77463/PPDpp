#include <vector>
#include <tuple>
#include <iostream>
#include <cmath>
#include "constants.h"
;
std::tuple<std::vector<double>, std::vector<double>, std::vector<double>>
gas_dust_peb_init(int nr, double ga, double mstar, double rc, std::vector<double> grid) {
    std::vector<double> gas;
    std::vector<double> dust;
    std::vector<double> peb;

    gas.resize(nr);
    dust.resize(nr);
    peb.resize(nr);

    // Finding out the disk mass
    double md = 0.1 * mstar;

    // Converting critical radius to AU
    double rccm = rc * constants::au;
    // Initializing the gas surface density
    for (int i = 0; i < nr; ++i){
        double ration = grid[i] / rccm;
         // You cannot say that -ration is the same at -1 * ration, compared to f90
        // pow function only takes in negative bases for int powers
        // Take negative value outside pow function into exp function
        gas[i] = (2.0 - ga) * (md / (2.0 * constants::pi * rccm * rccm)) *
        std::pow(ration, -ga) * std::exp(-std::pow(ration, 2.0 - ga));
    }

    // Initializing the dust surface density
    for (int i = 0; i < nr; ++i){
        dust[i] = gas[i] * 1.e-2;
    }

    // Initializing the pebble surface density
    for (int i = 0; i < nr; ++i){
        peb[i] = 1.e-30;
    }

    // Making a tuple to return our three vectors
    return std::make_tuple(gas, dust, peb);
}
