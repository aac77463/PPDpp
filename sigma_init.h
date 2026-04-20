#ifndef SIGMA_INIT_H_INCLUDED
#define SIGMA_INIT_H_INCLUDED
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include "interp1d.h"

(double md, double ga, double rc, double mplinit,
		  double xin, double xout, double m_star,
		  double& m_pl, double& ts, double& rpl,
		  //Creating standard vectors with double precision for our main quantities
		  std::vector<double>& du, std::vector<double>& duc,
		  std::vector<double>& pebs, std::vector<double>& pebsc,
		  std::vector<double>& x, std::vector<double>& acrit,
		  std::vector<double>& ra, std::vector<double>& rac,
		  std::vector<double>& diff, std::vector<double>& x2,
		  std::vector<double>& sigg, std::vector<double>& sigc,
		  int nr = 1000);

#endif // SIGMA_INIT_H_INCLUDED
