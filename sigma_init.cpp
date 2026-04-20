#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include "interp1d.h"


void sigma_init(double md, double ga, double rc, double mplinit,
		  double xin, double xout, double m_star,
		  double& m_pl, double& ts, double& rpl,
		  //Creating standard vectors with double precision for our main quantities
		  std::vector<double>& du, std::vector<double>& duc,
		  std::vector<double>& pebs, std::vector<double>& pebsc,
		  std::vector<double>& x, std::vector<double>& acrit,
		  std::vector<double>& ra, std::vector<double>& rac,
		  std::vector<double>& diff, std::vector<double>& x2,
		  std::vector<double>& sigg, std::vector<double>& sigc,
		  int nr = 1000) {
  //Resizing all the vectors to initial nr size
  std::cout << 2;
  std::cout << "test";
  int size = nr;
  x.resize(size);
  acrit.resize(size);
  ra.resize(size);
  sigg.resize(size);
  sigc.resize(size-1);
  du.resize(size);
  duc.resize(size-1);
  pebs.resize(size);
  pebsc.resize(size-1);
  diff.resize(size);

  //Changing the planet from Earth masses to [g]
  m_pl = m_earth * mplinit;
  std::cout << m_pl;

  //Making an equidistant logarithmic grid in [AU]
  for (int i = 0; i < nr; ++i) {
    x[i] = std::log(xin) + i * ((std::log(xout) - std::log(xin)) / (nr -1));
  }

  //Converting x from log to linear scale
  for (int i = 0; i < nr; ++i) {
    x[i] = std::exp(x[i]);
  }

  //Calculate the cell centers
  //for (int i = 0; i < nr - 1; ++i) {
  //  x2[i] = std::sqrt(x[i+1]*x[i]);
  //}

  //Calculating the closest point between the planet location
  //and the nearest disk grid point
  for (int i = 0; i < nr; i++) {
    diff[i] = std::abs(x[i] - rpl);
  }

  // This find the smallest element from diff
  auto intmd = std::min_element(diff.begin(), diff.end());

  //This should find the index location of the smallest element
  int idx_loc = std::distance(diff.begin(), intmd);

  std::cout << "smallest element is at index" << idx_loc;

  //Converting grids to cm
  //for(int i = 0; i < nr; i++){
  //  ra[i] = x[i] * au;
  //}

  //for(int i = 0; i < nr; i++) {
  //  rac[i] = x2[i] * au;
  //}

  //Converting critical radius to [cm]
  //We first need to define the variable as a double since
  //we are multiplying an integer by a double precision value
  //double rcau = rc * au;

  //Initializing the initial gas surface density
  //for (int i = 0; i < nr; i++) {
  //  double ratio = ra[i] / rcau;
  //  sigg[i] = (2.0 - ga) * (md / (2.0 * pi * rcau * rcau)) * std::pow(ratio, -ga) *
  //    	      std::exp(std::pow(-ratio, 2.0 - ga));
  //}
}





