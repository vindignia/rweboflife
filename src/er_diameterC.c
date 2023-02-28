#include <igraph/igraph.h>  //to compile it as a function, without cmake
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double er_diameter(int n, int m) {

// Erdos Renyi graph
  igraph_integer_t num_vertices = n;
  igraph_integer_t num_edges = m;
  igraph_bool_t IGRAPH_UNDIRECTED = true;
  igraph_bool_t IGRAPH_NO_LOOPS = false;
  igraph_t graph;
  igraph_real_t diameter;

  igraph_rng_seed(igraph_rng_default(), 42);
  igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNM,
                          num_vertices, num_edges,
                          IGRAPH_UNDIRECTED, IGRAPH_NO_LOOPS);

//  printf("IGRAPH_UNDIRECTED: %d\n",IGRAPH_UNDIRECTED);
//  printf("IGRAPH_NO_LOOPS: %d\n",IGRAPH_NO_LOOPS);

printf("\nNodes in ER graph %d\n",num_vertices);

  igraph_diameter(&graph, &diameter, NULL, NULL, NULL, 0, IGRAPH_UNDIRECTED);
  printf("Diameter of the ER random graph with average degree %g: %g\n",
          2.0 * igraph_ecount(&graph) / igraph_vcount(&graph),
          (double) diameter);

return diameter;
}
