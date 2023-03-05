#include <Rcpp.h>
#include </usr/local/lib/R/site-library/RcppArray/include/RcppArray.h>
#include <iostream>
#include </usr/local/include/igraph/igraph.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
int giant_componentCpp(IntegerVector edges_c_arr,   int len_c_arr) {

//  // Erdos Renyi graph
//  igraph_integer_t num_vertices = n;
//  igraph_integer_t num_edges = m;
//  igraph_bool_t IGRAPH_UNDIRECTED = true;
//  igraph_bool_t IGRAPH_NO_LOOPS = false;

  int helper_vec[100];
  igraph_integer_t *ptr;
  igraph_vector_int_t edges_vec;
//
  igraph_t graph;
  igraph_vector_int_t membership;
  igraph_vector_int_t csize;
  int gc = 0;

//  helper_vec = edges_c_arr;

// TODO put it at work with len_c_arr
  helper_vec = Rcpp::as<std::array<int, 100>>(edges_c_arr);

  igraph_integer_t len = len_c_arr;

  ptr = helper_vec;

  cout << "\n\n Test giant component \n";

//  igraph_rng_seed(igraph_rng_default(), 42);
//  igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNM,
//                          num_vertices, num_edges,
//                          IGRAPH_UNDIRECTED, IGRAPH_NO_LOOPS);
//
//  cout << "\n ER graph with " << num_vertices << " nodes and " << num_edges << " links: p =" <<
//    double(num_vertices)/num_edges << "\n\n";

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
