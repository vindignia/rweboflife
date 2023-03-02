#' @export
#' @rawNamespace useDynLib(rweboflife)
giant_component <- function(num_nodes, num_links) {
  .Call('_rweboflife_giant_componentCpp', PACKAGE = 'rweboflife', num_nodes, num_links)
}

