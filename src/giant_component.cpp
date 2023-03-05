#include <Rcpp.h>
//#include </usr/local/lib/R/site-library/RcppArray/include/RcppArray.h>
#include <iostream>
#include </usr/local/include/igraph/igraph.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
int giant_componentCpp(IntegerVector edges_c_arr, const int len_c_arr) {

  long int helper_vec[len_c_arr];
  igraph_integer_t *ptr;
  igraph_vector_int_t edges_vec;
//
  igraph_t graph;
  igraph_vector_int_t membership;
  igraph_vector_int_t csize;
  int gc = 0;

// Ideally one should put this at work with RcppArray
//helper_vec = Rcpp::as<std::array<int, len_c_arr>>(edges_c_arr);

   for (int i = 0; i <len_c_arr; i++){
     helper_vec[i] = edges_c_arr[i];
   }

  igraph_integer_t len = len_c_arr;
  ptr = helper_vec;
  cout << "\n length in function largest cluster:\n";
  cout << "\n\n" << len  << "\n\n";
  igraph_vector_int_view(&edges_vec, ptr, len);
  igraph_vector_int_print(&edges_vec);

  igraph_create(&graph, &edges_vec, 0, IGRAPH_UNDIRECTED);

  igraph_vector_int_init_int(&csize, 3, 2);
  igraph_vector_int_init_int(&membership, 8, 10);

  igraph_connected_components(&graph, &membership, &csize, 0, IGRAPH_WEAK);
  //  igraph_vector_int_print(&membership);
  igraph_vector_int_print(&csize);

  gc = igraph_vector_int_max(&csize);

  // free memory
  igraph_destroy(&graph);
  igraph_vector_int_destroy(&membership);
  igraph_vector_int_destroy(&csize);

  return gc;
}
