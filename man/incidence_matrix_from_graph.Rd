\name{incidence_matrix_from_graph}
\alias{incidence_matrix_from_graph}

\title{
Convert a bipartite graph into an incidence matrix. \cr
}
%~
\description{
Conveert an igraph object into an incidence matrix suitable to be the first argument of the function remove_rows().
}
%~
\usage{
nw_inc_mat <- incidence_matrix_from_graph(nw_graph)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{nw_graph}{igraph object}
}
%~
\details{
Required packages: igraph
}
\value{
incidence matrix
%%
}
\references{
%% ~put references to the literature/web site here ~
}
\author{
Alessandro Vindigni
}
\note{
%%  ~~further notes~~
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{
nw_inc_mat <- incidence_matrix_from_graph(nw_graph)
}

% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~incidence matrix}% use one of  RShowDoc("KEYWORDS")
\keyword{ ~bipartite networks}% __ONLY ONE__ keyword per line

