

/*
 * -- SuperLU routine (version 2.0) --
 * Univ. of California Berkeley, Xerox Palo Alto Research Center,
 * and Lawrence Berkeley National Lab.
 * November 15, 1997
 *
 */
#include "csp_defs.h"
#include "util.h"

int sp_cget02(char *trans, int m, int n, int nrhs, SuperMatrix *A,
	      complex *x, int ldx, complex *b, int ldb, float *resid)
{
/*  
    Purpose   
    =======   

    SP_CGET02 computes the residual for a solution of a system of linear   
    equations  A*x = b  or  A'*x = b:   
       RESID = norm(B - A*X) / ( norm(A) * norm(X) * EPS ),   
    where EPS is the machine epsilon.   

    Arguments   
    =========   

    TRANS   (input) CHARACTER*1   
            Specifies the form of the system of equations:   
            = 'N':  A *x = b   
            = 'T':  A'*x = b, where A' is the transpose of A   
            = 'C':  A'*x = b, where A' is the transpose of A   

    M       (input) INTEGER   
            The number of rows of the matrix A.  M >= 0.   

    N       (input) INTEGER   
            The number of columns of the matrix A.  N >= 0.   

    NRHS    (input) INTEGER   
            The number of columns of B, the matrix of right hand sides.   
            NRHS >= 0.
	    
    A       (input) SuperMatrix*, dimension (LDA,N)   
            The original M x N sparse matrix A.   

    X       (input) COMPLEX PRECISION array, dimension (LDX,NRHS)   
            The computed solution vectors for the system of linear   
            equations.   

    LDX     (input) INTEGER   
            The leading dimension of the array X.  If TRANS = 'N',   
            LDX >= max(1,N); if TRANS = 'T' or 'C', LDX >= max(1,M).   

    B       (input/output) COMPLEX PRECISION array, dimension (LDB,NRHS)   
            On entry, the right hand side vectors for the system of   
            linear equations.   
            On exit, B is overwritten with the difference B - A*X.   

    LDB     (input) INTEGER   
            The leading dimension of the array B.  IF TRANS = 'N',   
            LDB >= max(1,M); if TRANS = 'T' or 'C', LDB >= max(1,N).
	    
    RESID   (output) FLOAT PRECISION   
            The maximum over the number of right hand sides of   
            norm(B - A*X) / ( norm(A) * norm(X) * EPS ).   

    =====================================================================
*/

    /* Table of constant values */
    complex alpha = {-1., 0.0};
    complex beta  = {1., 0.0};
    int    c__1  = 1;
    
    /* System generated locals */
    float d__1, d__2;

    /* Local variables */
    int j;
    int n1, n2;
    float anorm, bnorm;
    float xnorm;
    float eps;

    /* Function prototypes */
    extern int lsame_(char *, char *);
    extern float clangs(char *, SuperMatrix *);
    extern float scasum_(int *, complex *, int *);
    extern double slamch_(char *);
    
    /* Function Body */
    if ( m <= 0 || n <= 0 || nrhs == 0) {
	*resid = 0.;
	return 0;
    }

    if (lsame_(trans, "T") || lsame_(trans, "C")) {
	n1 = n;
	n2 = m;
    } else {
	n1 = m;
	n2 = n;
    }

    /* Exit with RESID = 1/EPS if ANORM = 0. */

    eps = slamch_("Epsilon");
    anorm = clangs("1", A);
    if (anorm <= 0.) {
	*resid = 1. / eps;
	return 0;
    }

    /* Compute  B - A*X  (or  B - A'*X ) and store in B. */

    sp_cgemm(trans, "N", n1, nrhs, n2, alpha, A, x, ldx, beta, b, ldb);

    /* Compute the maximum over the number of right hand sides of   
       norm(B - A*X) / ( norm(A) * norm(X) * EPS ) . */

    *resid = 0.;
    for (j = 0; j < nrhs; ++j) {
	bnorm = scasum_(&n1, &b[j*ldb], &c__1);
	xnorm = scasum_(&n2, &x[j*ldx], &c__1);
	if (xnorm <= 0.) {
	    *resid = 1. / eps;
	} else {
	    /* Computing MAX */
	    d__1 = *resid, d__2 = bnorm / anorm / xnorm / eps;
	    *resid = SUPERLU_MAX(d__1, d__2);
	}
    }

    return 0;

} /* sp_cget02 */

