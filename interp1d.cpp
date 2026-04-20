#include <iostream>
#include <vector>
#include "interp1d.h"

void interp1d(int nr,
std::vector<double>& x1, std::vector<double>& y1,
std::vector<double>& x2, std::vector<double>& y2) {
  for (int i = 0; i < nr; ++i) {
    // An intermediate step for     the fraction
    double frac = (y1[i + 1] - y1[i]) / (x1[i +1] - x1[i]);
    y2[i] = y1[i] + (x2[i] - x1[i]) * frac;
    }
}

