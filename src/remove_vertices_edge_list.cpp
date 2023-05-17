#include <Rcpp.h>
#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Rcpp;

// [[Rcpp::export]]
int inversePercolationCpp(const NumericMatrix & EL) {
  IntegerMatrix Row(2, 2);

      IntegerVector v_1 = EL( 1 , _ );
      IntegerVector v_2 = EL( 2 , _ );

      int prod = inner_product(v_1.begin(), v_1.end(), v_2.begin(), 0);

  return prod;
}
