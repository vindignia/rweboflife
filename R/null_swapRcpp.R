#' @export
#' @rawNamespace useDynLib(rweboflife)
swap_modelCpp <- function(M, iter_max) {
  .Call('_rweboflife_null_swapCpp', PACKAGE = 'rweboflife', M, iter_max)
}
