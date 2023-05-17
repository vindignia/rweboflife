#' @export
#' @rawNamespace useDynLib(rweboflife)
invPerc <- function(EL) {
  .Call('_rweboflife_inversePercolationCpp', PACKAGE = 'rweboflife', EL)
}

