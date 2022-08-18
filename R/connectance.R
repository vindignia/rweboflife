connectance <- function(nw) {
  library(dplyr)
  links <- nw %>% nrow()
  plants <- distinct(nw, species2) %>%  nrow()
  animals <- distinct(nw, species1) %>% nrow()
  size <- plants*animals
  conn <- links/size
  return(conn)
}
