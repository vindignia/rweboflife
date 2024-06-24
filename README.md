# rweboflife
This is an R package for the analysis of ecological networks developed in collaboration with the [Bascompte group](https://www.bascompte.net/) of the University of Zurich.


# Documentation 

### [Null models](documents/null_models.md)

### [Nestedness](documents/nestedness.md)

### [Network robustness](documents/robustness.md)

# Installation requirements

To ensure the package works correctly, we recommend using a recent R installation (>= 4.1.0). Additionally, you need to verify the installation paths for **Rcpp** and **RcppArmadillo** on your local machine. Once you have these paths, update the `./src/Makevars` file accordingly. You can refer to the command lines used in the `.github/workflows` directory for guidance on how to find these paths.

### From R script 

if (!requireNamespace("devtools", quietly = TRUE)) {
  install.packages("devtools")
}
devtools::install_github("vindignia/rweboflife")
