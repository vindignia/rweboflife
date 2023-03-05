#' @export
#' @rawNamespace useDynLib(rweboflife)
giant_component <- function(flat_edgelist, length_edgelist) {
  .Call('_rweboflife_giant_componentCpp', PACKAGE = 'rweboflife', flat_edgelist, length_edgelist)
}

