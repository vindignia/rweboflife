#include <igraph/igraph.h>  //to compile it as a function, without cmake
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int er_giant_component(int n, int m) {

// Erdos Renyi graph
  igraph_integer_t num_vertices = n;
  igraph_integer_t num_edges = m;
  igraph_bool_t IGRAPH_UNDIRECTED = true;
  igraph_bool_t IGRAPH_NO_LOOPS = false;
  igraph_t graph;
  igraph_vector_int_t membership;
  igraph_vector_int_t csize;

  igraph_rng_seed(igraph_rng_default(), 42);
  igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNM,
                          num_vertices, num_edges,
                          IGRAPH_UNDIRECTED, IGRAPH_NO_LOOPS);

printf("\nNodes in ER graph %ld Links %ld\n",num_vertices, num_edges);

igraph_vector_int_init(&membership, 8);
igraph_vector_int_init(&csize, 3);

printf("csize ER \n");

igraph_clusters(&graph, &membership, &csize, NULL, IGRAPH_WEAK);
//igraph_connected_components(&graph, &membership, &csize, NULL, IGRAPH_WEAK);
//  printf("membership ER\n");
//  igraph_vector_print(&membership);
igraph_vector_int_print(&csize);

return 0;
}
