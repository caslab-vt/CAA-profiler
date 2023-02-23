/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlarfg.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "xzlarfg.h"
#include "sortLE.h"
#include "xnrm2.h"
#include "test_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                double *alpha1
 *                double x[3]
 * Return Type  : double
 */
double b_xzlarfg(int n, double *alpha1, double x[3])
{
  double tau;
  double xnorm;
  double beta1;
  int knt;
  int k;
  tau = 0.0;
  if (n > 0) {
    xnorm = b_xnrm2(n - 1, x);
    if (xnorm != 0.0) {
      beta1 = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = -1;
        do {
          knt++;
          for (k = 2; k <= n; k++) {
            x[k - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(beta1) >= 1.0020841800044864E-292));

        beta1 = rt_hypotd_snf(*alpha1, b_xnrm2(n - 1, x));
        if (*alpha1 >= 0.0) {
          beta1 = -beta1;
        }

        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        for (k = 2; k <= n; k++) {
          x[k - 1] *= xnorm;
        }

        for (k = 0; k <= knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }

        *alpha1 = beta1;
      } else {
        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        for (k = 2; k <= n; k++) {
          x[k - 1] *= xnorm;
        }

        *alpha1 = beta1;
      }
    }
  }

  return tau;
}

/*
 * Arguments    : int n
 *                double *alpha1
 *                emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
double xzlarfg(int n, double *alpha1, emxArray_real_T *x, int ix0)
{
  double tau;
  double xnorm;
  double beta1;
  int knt;
  int i7;
  int k;
  tau = 0.0;
  if (n > 0) {
    xnorm = xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      beta1 = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        beta1 = -beta1;
      }

      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = -1;
        i7 = (ix0 + n) - 2;
        do {
          knt++;
          for (k = ix0; k <= i7; k++) {
            x->data[k - 1] *= 9.9792015476736E+291;
          }

          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(beta1) >= 1.0020841800044864E-292));

        beta1 = rt_hypotd_snf(*alpha1, xnrm2(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          beta1 = -beta1;
        }

        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        for (k = ix0; k <= i7; k++) {
          x->data[k - 1] *= xnorm;
        }

        for (k = 0; k <= knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }

        *alpha1 = beta1;
      } else {
        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        i7 = (ix0 + n) - 2;
        for (k = ix0; k <= i7; k++) {
          x->data[k - 1] *= xnorm;
        }

        *alpha1 = beta1;
      }
    }
  }

  return tau;
}

/*
 * File trailer for xzlarfg.c
 *
 * [EOF]
 */