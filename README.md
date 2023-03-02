# rweboflife
This is an R package for the analysis of ecological networks developed in collaboration with the [Bascompte group](https://www.bascompte.net/) of the University of Zurich.

# Installation requirements

* **igraph** (C library) see installation instructions on the relative [github](https://github.com/igraph/igraph) page  
* CMake 3.18 or later
* C and C++ compilers: on ubuntu the compilation of `rweboflife` is successful  with gcc-11 and g++-11, but throws an error if igraph is built with previous versions 
* R (>= 3.1.0), dplyr, permute, fastmatch, JuliaCall, igraph (R library) 
