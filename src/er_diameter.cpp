#include <Rcpp.h>
#include <iostream>
#include <igraph/igraph.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
double er_diameterCpp(int n, int m) {
  igraph_integer_t num_vertices = n;
  igraph_integer_t num_edges = m;
  igraph_bool_t IGRAPH_UNDIRECTED = true;
  igraph_bool_t IGRAPH_NO_LOOPS = false;
  igraph_t graph;
  igraph_real_t diameter;

printf("\n create ER graph\n\n");
  igraph_rng_seed(igraph_rng_default(), 42);
  igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNM,
                          num_vertices, num_edges,
                          IGRAPH_UNDIRECTED, IGRAPH_NO_LOOPS);

  igraph_diameter(&graph, &diameter, NULL, NULL, NULL, 0, IGRAPH_UNDIRECTED, true);

cout << "\nThe diameter of the ER random graph with average degree " <<
2.0 * igraph_ecount(&graph) / igraph_vcount(&graph) << " is " << diameter << "\n\n";
return diameter;
}
