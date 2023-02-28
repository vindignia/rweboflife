#include <Rcpp.h>
#include <iostream>
#include "er_diameterC.c"
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
double er_diameterCpp(int n, int m) {
  double d;

cout << "\n\n The result is\n\n";

d = er_diameter(n, m);
return d;
}
