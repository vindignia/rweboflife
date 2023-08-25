# rweboflife
This is an R package for the analysis of ecological networks developed in collaboration with the [Bascompte group](https://www.bascompte.net/) of the University of Zurich.


# Documentation 

### [Null models](documents/null_models.md)

### [Nestedness](documents/nestedness.md)

### [Network robustness](documents/robustness.md)

# Installation requirements

* **igraph** (C library) see installation instructions on the relative [github](https://github.com/igraph/igraph) page  
* CMake 3.18 or later
* C and C++ compilers: on ubuntu the compilation of `rweboflife` is successful  with gcc-11 and g++-11, but throws an error if igraph is built with previous versions 
* If you fetch igraph RELEASE from github, add the line 
> set_target_properties(igraph PROPERTIES POSITION_INDEPENDENT_CODE ON)   
to the file ./src/CMakeLists.txt then compile igraph with cmake as suggested in the manual
* R (>= 3.1.0), dplyr, permute, fastmatch, igraph (R library) 
