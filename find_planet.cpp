#include <iostream>
#include <vector>
#include "constants.h"
#include "find_planet.h"
;
int find_planet(int nr, double rpl, std::vector<double> x){
    // Making a vector to hold the diff between x[i] and rpl
    std::vector<double> diff;
    diff.resize(nr);

    //Calculating the closest point between the planet location
    //and the nearest disk grid point
    for (int i = 0; i < nr; i++) {
        diff[i] = std::abs(x[i] - rpl);
  }

  // This find the smallest element from diff
  auto intmd = std::min_element(diff.begin(), diff.end());

  //This should find the index location of the smallest element
  int idx_loc = std::distance(diff.begin(), intmd);

  return idx_loc;
}
