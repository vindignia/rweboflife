#include <Rcpp.h>
#include <iostream>
#include </usr/local/include/igraph/igraph.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
int giant_componentCpp(int n, int m) {

  // Erdos Renyi graph
  igraph_integer_t num_vertices = n;
  igraph_integer_t num_edges = m;
  igraph_bool_t IGRAPH_UNDIRECTED = true;
  igraph_bool_t IGRAPH_NO_LOOPS = false;
  igraph_t graph;
  igraph_vector_int_t membership;
  igraph_vector_int_t csize;
  int gc = 0;

  cout << "\n\n Test giant component \n";

  igraph_rng_seed(igraph_rng_default(), 42);
  igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNM,
                          num_vertices, num_edges,
                          IGRAPH_UNDIRECTED, IGRAPH_NO_LOOPS);

  cout << "\n ER graph with " << num_vertices << " nodes and " << num_edges << " links: p =" <<
    double(num_vertices)/num_edges << "\n\n";

  igraph_vector_int_init_int(&csize, 3, 2, 1, 1, 1);
  igraph_vector_int_init_int(&membership, 8, 10, 10, 1, 1);

  igraph_connected_components(&graph, &membership, &csize, 0, IGRAPH_WEAK);
  //  igraph_vector_int_print(&membership);
  igraph_vector_int_print(&csize);

  // free memory
  igraph_destroy(&graph);
  igraph_vector_int_destroy(&membership);
  igraph_vector_int_destroy(&csize);

  // gc = igraph_vector_int_get(&csize, 0);
  return gc;
}
