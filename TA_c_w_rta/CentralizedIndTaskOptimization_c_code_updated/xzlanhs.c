/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlanhs.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "xzlanhs.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_creal_T *A
 *                int ilo
 *                int ihi
 * Return Type  : double
 */
double xzlanhs(const emxArray_creal_T *A, int ilo, int ihi)
{
  double f;
  double scale;
  double sumsq;
  boolean_T firstNonZero;
  int j;
  int i4;
  int i;
  double reAij;
  double imAij;
  double temp1;
  f = 0.0;
  if (ilo <= ihi) {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    for (j = ilo; j <= ihi; j++) {
      i4 = j + 1;
      if (ihi < j + 1) {
        i4 = ihi;
      }

      for (i = ilo; i <= i4; i++) {
        reAij = A->data[(i + A->size[0] * (j - 1)) - 1].re;
        imAij = A->data[(i + A->size[0] * (j - 1)) - 1].im;
        if (reAij != 0.0) {
          temp1 = fabs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = temp1;
            firstNonZero = false;
          } else if (scale < temp1) {
            reAij = scale / temp1;
            sumsq = 1.0 + sumsq * reAij * reAij;
            scale = temp1;
          } else {
            reAij = temp1 / scale;
            sumsq += reAij * reAij;
          }
        }

        if (imAij != 0.0) {
          temp1 = fabs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = temp1;
            firstNonZero = false;
          } else if (scale < temp1) {
            reAij = scale / temp1;
            sumsq = 1.0 + sumsq * reAij * reAij;
            scale = temp1;
          } else {
            reAij = temp1 / scale;
            sumsq += reAij * reAij;
          }
        }
      }
    }

    f = scale * sqrt(sumsq);
  }

  return f;
}

/*
 * File trailer for xzlanhs.c
 *
 * [EOF]
 */
