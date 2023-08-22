#include <RcppArmadillo.h>
#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Rcpp;
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

//OLD
// bool all_equal(IntegerMatrix A, IntegerMatrix B) {
//   int nrow = A.nrow();
//   int ncol = A.ncol();
//
//   for (int i = 0; i < nrow; i++) {
//     for (int j = 0; j < ncol; j++) {
//       if (A(i, j) != B(i, j)) {
//         return false;
//       }
//     }
//   }
//   return true;
// }

bool all_equal(IntegerMatrix A, IntegerMatrix B) {
  // Check if all elements are equal using vectorized operation => no improvement
  return is_true(all(A == B));
}

IntegerMatrix extract_subset(IntegerMatrix A, int i_a, int i_b, int j_a, int j_b) {
  IntegerMatrix set_out(2,2);

  set_out(0,0) = A(i_a,j_a);
  set_out(1,0) = A(i_b,j_a);
  set_out(0,1) = A(i_a,j_b);
  set_out(1,1) = A(i_b,j_b);
  return set_out;
}

IntegerMatrix assign_subset(IntegerMatrix A, int i_a, int i_b, int j_a, int j_b, IntegerMatrix set_in) {
  IntegerMatrix B(A.nrow(), A.ncol());

  A(i_a,j_a) = set_in(0,0);
  A(i_b,j_a) = set_in(1,0);
  A(i_a,j_b) = set_in(0,1);
  A(i_b,j_b) = set_in (1,1);
  return A;
}

arma::ivec rnd_indices(const int N) {
  arma_rng::set_seed_random(); // TODO set iseed
  ivec result(2);

  // Generate two distinct random integers lying in the interval (0,N)
  do {
    result = randi(2,distr_param(0,N-1));
  } while (result[1] == result[0]);  // Ensure distinctness

  return result;
}


// [[Rcpp::export]]
IntegerMatrix null_swapCpp(const NumericMatrix & M, int iter_max) {

  IntegerMatrix shuffled_mat(M.nrow(), M.ncol()), subset(2,2);
  // IntegerVector row_indices(2), col_indices(2);

  ivec row_indices(2), col_indices(2);

  IntegerVector v_id = {1,0,0,1};
  v_id.attr("dim") = Dimension(2, 2);
  IntegerMatrix ID = as<IntegerMatrix>(v_id);

  IntegerVector v_sx = {0,1,1,0};
  v_sx.attr("dim") = Dimension(2, 2);
  IntegerMatrix SX = as<IntegerMatrix>(v_sx);

  int i, nr, nc, i0, i1, j0, j1;
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


  for (int iter = 0;  iter < iter_max; iter++) {

    // attempt to swap as many 2x2 subsets as the matrix elements

    for(i = 0; i < nc*nr; i++) {

      row_indices = rnd_indices(nr);
      col_indices = rnd_indices(nc);

      //  Rcout << row_indices[0] << " , " << row_indices[1] << endl;

      i0 = row_indices[0];
      i1 = row_indices[1];
      j0 = col_indices[0];
      j1 = col_indices[1];

      subset = extract_subset(shuffled_mat, i0, i1, j0, j1);
      if(all_equal(subset, ID)){
        // then swap
        assign_subset(shuffled_mat, i0, i1, j0, j1, SX);
      } else if (all_equal(subset, SX)){
        // then swap
        assign_subset(shuffled_mat, i0, i1, j0, j1, ID);
      }
    }
  }
  return shuffled_mat;
}
