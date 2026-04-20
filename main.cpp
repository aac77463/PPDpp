#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include "interp1d.h"
#include "sigma_test.h"
#include "make_grid.h"
#include "constants.h"
#include "find_planet.h"
;
int main(){

int nr = 1000;
double xin = 1.0e-1;
double xout = 30.0;
double rpl = 1.0;

std::cout << constants::ms << std::endl;
std::cout << "test main init" << std::endl;
// Calling the make_grid function to make grid in AU
std::vector<double> grid = make_grid(xin, xout, nr);
// Making a vector for our grid in cm
std::vector<double> ra = grid;
// Multiplying each element in our initial grid by AU in [cm]
for (auto& element : ra) {
    element *= constants::au;
}
// Printing out the grid values
for (double val : ra) {
    std::cout << val << " ";
    }
std::cout << std::endl;
//Definining the initial location of planet on grid
int idx_loc = find_planet(nr, rpl, grid);
std::cout << "Planet location in [AU] " << grid[idx_loc] << std::endl;
std::cout << "test main end";
return 0;

}
