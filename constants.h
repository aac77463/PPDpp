#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED
#include <numbers>
;
// Defining astronomical constans and others needed for calculations
namespace constants {
    inline constexpr double pi = std::numbers::pi;
    inline constexpr double au = 1.4959787069100e13; //AU [cm]
    inline constexpr double me = 5.9723657e27; //Earth mass [g]
    inline constexpr double ms = 1.98847554e33; //Solar mass [g]
    inline constexpr double mu = 2.43; //mean molecular weight
    inline constexpr double mp = 1.6726231e-24; //proton mass [g]
    inline constexpr double kb = 1.380649; //Boltzmann [g cm^2 s^-2]
    inline constexpr double sb = 55.67037e-5; //Ste-Boltz [g s^-3 K^-4]
    inline constexpr double kappa = 508; // grain opacity
    inline constexpr double lsol = 3.828e33; //Solar luminosity [g cm^2 s^-3]
    inline constexpr double g = 6.6743e-8; //Gravitational [cm^3 g^-1 s^-2]
    inline constexpr double epsi = 1.e-2; //Dust to gas ratio
    inline constexpr double a0 = 1.0e-4; //Initial ISM grain size [cm]
    inline constexpr double yts = 3.1557600e7; //Year [s]
}
#endif // CONSTANTS_H_INCLUDED
