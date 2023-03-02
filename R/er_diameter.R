#' @export
#' @rawNamespace useDynLib(rweboflife)
er_diameter <- function(num_nodes, num_links) {
  .Call('_rweboflife_er_diameterCpp', PACKAGE = 'rweboflife', num_nodes, num_links)
}

