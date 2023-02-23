/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgerc.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "xgerc.h"

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                double alpha1
 *                int ix0
 *                const double y_data[]
 *                emxArray_real_T *A
 *                int ia0
 *                int lda
 * Return Type  : void
 */
void b_xgerc(int m, int n, double alpha1, int ix0, const double y_data[],
             emxArray_real_T *A, int ia0, int lda)
{
  int jA;
  int jy;
  int j;
  double temp;
  int ix;
  int i14;
  int i15;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y_data[jy] != 0.0) {
        temp = y_data[jy] * alpha1;
        ix = ix0;
        i14 = jA + 1;
        i15 = m + jA;
        for (ijA = i14; ijA <= i15; ijA++) {
          A->data[ijA - 1] += A->data[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += lda;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                double alpha1
 *                const double x_data[]
 *                int iy0
 *                emxArray_real_T *A
 *                int ia0
 *                int lda
 * Return Type  : void
 */
void xgerc(int m, int n, double alpha1, const double x_data[], int iy0,
           emxArray_real_T *A, int ia0, int lda)
{
  int jA;
  int jy;
  int j;
  double temp;
  int ix;
  int i10;
  int i11;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = iy0 - 1;
    for (j = 0; j < n; j++) {
      if (A->data[jy] != 0.0) {
        temp = A->data[jy] * alpha1;
        ix = 0;
        i10 = jA + 1;
        i11 = m + jA;
        for (ijA = i10; ijA <= i11; ijA++) {
          A->data[ijA - 1] += x_data[ix] * temp;
          ix++;
        }
      }

      jy++;
      jA += lda;
    }
  }
}

/*
 * File trailer for xgerc.c
 *
 * [EOF]
 */
