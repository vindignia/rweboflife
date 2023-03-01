#include <Rcpp.h>
#include <iostream>
#include "er_giant_componentC.c"
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
int giant_componentCpp(int n, int m) {
  int d;

cout << "\n\n Test \n\n";

d = er_giant_component(n, m);
return d;
}
