#' @export
#' @rawNamespace useDynLib(rweboflife)
nestedness <- function(M) {
  .Call('_rweboflife_inversePercolationCpp', PACKAGE = 'rweboflife', M)
}

