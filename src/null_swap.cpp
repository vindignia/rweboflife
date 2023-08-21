#include <Rcpp.h>
#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Rcpp;

bool all_equal(IntegerMatrix A, IntegerMatrix B) {
  int nrow = A.nrow();
  int ncol = A.ncol();

  for (int i = 0; i < nrow; i++) {
    for (int j = 0; j < ncol; j++) {
      if (A(i, j) != B(i, j)) {
        return false;
      }
    }
  }
  return true;
}

IntegerMatrix extract_subset(IntegerMatrix A, int i, int j) {
  IntegerMatrix set_out(2,2);

  set_out(0,0) = A(i,j);
  set_out(1,0) = A(i+1,j);
  set_out(0,1) = A(i,j+1);
  set_out(1,1) = A(i+1,j+1);
  return set_out;
}


IntegerMatrix assign_subset(IntegerMatrix A, int i, int j, IntegerMatrix set_in) {
  IntegerMatrix B(A.nrow(), A.ncol());

  A(i,j) = set_in(0,0);
  A(i+1,j) = set_in(1,0);
  A(i,j+1) = set_in(0,1);
  A(i+1,j+1) = set_in (1,1);
  return A;
}


// [[Rcpp::export]]
IntegerMatrix null_swapCpp(const NumericMatrix & M, int iter_max) {

  IntegerMatrix shuffled_mat(M.nrow(), M.ncol()), subset(2,2);

  IntegerVector v_id = {1,0,0,1};
  v_id.attr("dim") = Dimension(2, 2);
  IntegerMatrix ID = as<IntegerMatrix>(v_id);

  IntegerVector v_sx = {0,1,1,0};
  v_sx.attr("dim") = Dimension(2, 2);
  IntegerMatrix SX = as<IntegerMatrix>(v_sx);

  int i, j, nr, nc;
  nr = M.nrow();
  nc = M.ncol();

  //initialize a binarized shuffled matrix
  for(i = 0; i < nc*nr; i++) {
    if(M[i]>0){
      shuffled_mat[i]=1;
    } else {
      shuffled_mat[i]=0;
    }
  }

  // TODO implement the loop
  //i = 2, j =0;
  i = 1, j =0;

  subset = extract_subset(shuffled_mat, i, j);
  if(all_equal(subset, ID)){
    // then swap
    assign_subset(shuffled_mat, i,j, SX);
  } else if (all_equal(subset, SX)){
    // then swap
    assign_subset(shuffled_mat, i,j, ID);
  }


 return shuffled_mat;
}
