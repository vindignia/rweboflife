#include <Rcpp.h>
#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Rcpp;

// [[Rcpp::export]]
IntegerMatrix null_swapCpp(const NumericMatrix & M, int iter_max) {

  IntegerMatrix B(M.nrow(), M.ncol());


  IntegerVector v_id = {1,0,1,0};
  v_id.attr("dim") = Dimension(2, 2);
  IntegerMatrix ID = as<IntegerMatrix>(v_id);

  IntegerVector v_sx = {0,1,0,1};
  v_sx.attr("dim") = Dimension(2, 2);
  IntegerMatrix SX = as<IntegerMatrix>(v_sx);

  int i, j, nr, nc;
  nr = M.nrow();
  nc = M.ncol();

  //binarize the matrix
  for(i = 0; i < nc*nr; i++) {
    if(M[i]>0){
      B[i]=1;
    } else {
      B[i]=0;
    }
  }

  // nestedness of rows
  double nestedness_rows = 0;
  for(i = 0; i < (nr-1); i++) {
    j = i + 1;
    while (j < nr) {
      IntegerVector v_i = B( i , _ );
      IntegerVector v_j = B( j , _ );

      int k_i = accumulate(v_i.begin(), v_i.end(), 0);
      int k_j = accumulate(v_j.begin(), v_j.end(), 0);

      int shared = inner_product(v_i.begin(), v_i.end(), v_j.begin(), 0);

      // handle disconnected nodes
      if (!((k_i == 0) || (k_j==0))){
        int min_shared = min(k_i, k_j); // min of the degrees
        nestedness_rows = nestedness_rows + (1.0*shared/min_shared);
      }
      j++;
    } // end while iterator
  } //   end for loop


  // nestedness of columns
  double nestedness_cols = 0;
  for(i = 0; i < (nc-1); i++) {
    j = i + 1;
    while (j < nc) {

      IntegerVector v_i = B( _ , i );
      IntegerVector v_j = B( _ , j );

      int k_i = accumulate(v_i.begin(), v_i.end(), 0);
      int k_j = accumulate(v_j.begin(), v_j.end(), 0);

      int shared = inner_product(v_i.begin(), v_i.end(), v_j.begin(), 0);

      // handle disconnected nodes
      if (!((k_i == 0) || (k_j==0))){
        int min_shared = min(k_i, k_j); // min of the degrees
        nestedness_cols = nestedness_cols + (1.0*shared/min_shared);
      }
      j++;
    } // end while iterator
  } //   end for loop

  //  Compute nestedness of the network
  double nestedness_val = (nestedness_rows + nestedness_cols) / ((nr * (nr - 1) / 2) + (nc * (nc - 1) / 2));

 return SX;
//  return nestedness_val;
}
