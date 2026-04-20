#include <vector>
#include <cmath>
#include <iostream>
#include "make_grid.h"

// Returning a vector for our logarithmic grid
// Takes in arguments for the beginning and end of the grid,
// along with the number of grid points
;
std::vector<double> make_grid(double rin, double rout, int nr) {
    // Making the initial grids
    std::vector<double> grid;
    std::vector<double> x;
    // Resizing the grid to our initial nr size
    grid.resize(nr);
    x.resize(nr);

    // Converting our initial and final points into log10
    double login = std::log10(rin);
    double logout = std::log10(rout);

    // Iterating through the loop to assign the logarithmic values
    for (int i = 0; i < nr; ++i) {
        grid[i] = login + (i -1) * ( (logout - login)/(nr - 1));
    }
    // Returning the grid in AU
    for (int i = 0; i < nr; ++i) {
       x[i] = std::pow(10, grid[i]);
    }
    return x;
}
