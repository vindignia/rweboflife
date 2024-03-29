\name{null_model}
\alias{null_model}

\title{
Matrix randomizer. \cr
}
%~
\description{
Binarizes the input matrix and returns a matrix of the same size and with the same number of non-zero elements (except for the "cell" model),
randmized according to the chosen null-model algorithm.
}
%~
\usage{
null_model(my_matrix, iter_max = 200, model = "swap")
null_model(my_matrix, iter_max = 200, model = "curveball")
null_model(my_matrix, model = "equifrequent")
null_model(my_matrix, model = "cell")
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{my_matrix}{matrix, the input matrix. If not yet binarized, it will be converted into a binary matrix}
  \item{iter_max}{integer, maximum number of iterations (swap model only)}
  \item{model}{string, select the null model; possible values: \cr "swap", "equifrequent", "cell", "curveball"}
}
%~
\details{
Required packages: permute
}
\value{
matrix, randomized binary matrix
%%
}
\references{
%% ~put references to the literature/web site here ~
}
\author{
Alessandro Vindigni, Fernando Pedraza
}
\note{
%%  ~~further notes~~
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{

  n <- 37 # number of rows
  m <- 32 # number of columns
  M <- matrix(0,n,m)

  for(i in 1:n){
    for (j in 1:m){
      M[i,j] <- floor(runif(1, min = 0, max = 1.18)) # binary sparse matrix
    }
  }

  ones_fraction <- sum(M)/(nrow(M)*ncol(M))
  min_overlap <- 1-2*ones_fraction
  max_overlap <- 1-ones_fraction

  # usage
  M_swap <- null_model(M, iter_max = 1200, model = "swap")

  # test the degree of randomization
  overlap_mat <- (M_swap == M)
  class(overlap_mat) <- "numeric"
  overlap <- sum(overlap_mat)/(nrow(M)*ncol(M))

  # it should be (overlap < max_overlap) && (overlap > min_overlap)

}

% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~null models}% use one of  RShowDoc("KEYWORDS")
\keyword{ ~complex networks}% __ONLY ONE__ keyword per line

