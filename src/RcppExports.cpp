// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// er_diameterCpp
double er_diameterCpp(int n, int m);
RcppExport SEXP _rweboflife_er_diameterCpp(SEXP nSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(er_diameterCpp(n, m));
    return rcpp_result_gen;
END_RCPP
}
// giant_componentCpp
int giant_componentCpp(IntegerVector edges_c_arr, const int len_c_arr);
RcppExport SEXP _rweboflife_giant_componentCpp(SEXP edges_c_arrSEXP, SEXP len_c_arrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type edges_c_arr(edges_c_arrSEXP);
    Rcpp::traits::input_parameter< const int >::type len_c_arr(len_c_arrSEXP);
    rcpp_result_gen = Rcpp::wrap(giant_componentCpp(edges_c_arr, len_c_arr));
    return rcpp_result_gen;
END_RCPP
}
// nestednessCpp
double nestednessCpp(const NumericMatrix& M);
RcppExport SEXP _rweboflife_nestednessCpp(SEXP MSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericMatrix& >::type M(MSEXP);
    rcpp_result_gen = Rcpp::wrap(nestednessCpp(M));
    return rcpp_result_gen;
END_RCPP
}
// inversePercolationCpp
int inversePercolationCpp(const IntegerMatrix& EL);
RcppExport SEXP _rweboflife_inversePercolationCpp(SEXP ELSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type EL(ELSEXP);
    rcpp_result_gen = Rcpp::wrap(inversePercolationCpp(EL));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_rweboflife_er_diameterCpp", (DL_FUNC) &_rweboflife_er_diameterCpp, 2},
    {"_rweboflife_giant_componentCpp", (DL_FUNC) &_rweboflife_giant_componentCpp, 2},
    {"_rweboflife_nestednessCpp", (DL_FUNC) &_rweboflife_nestednessCpp, 1},
    {"_rweboflife_inversePercolationCpp", (DL_FUNC) &_rweboflife_inversePercolationCpp, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_rweboflife(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
