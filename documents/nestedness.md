# Nestedness 


An adjaceincy/incidence matrix representing a network is said to be nested when the non-zero elements in a given row are a subset of the non-zero elements in another row. An example of a perfectly netsed matrix is a square matrix in which the upper triangle consists of non-zero elements (say 1s) and the lower triangle consists of zeros. Several possible way of measuring the nestedness of a network can be found in the literature. In this repository we adopt the definiton given in the manuscript Fortuna, M.A., et al.: Coevolutionary dynamics shape the structure of bacteria‐phage infection networks [Evolution 1001-1011 (2019)](https://doi.org/10.1111/evo.13731).

Other algorithms to assess nestedness are implemented, e.g., in the [bipartite](https://cran.r-project.org/web/packages/bipartite/index.html) package.  
