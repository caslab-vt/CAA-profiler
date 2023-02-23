/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgemv.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "xgemv.h"

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                const emxArray_real_T *A
 *                int ia0
 *                int lda
 *                const emxArray_real_T *x
 *                int ix0
 *                double y_data[]
 * Return Type  : void
 */
void b_xgemv(int m, int n, const emxArray_real_T *A, int ia0, int lda, const
             emxArray_real_T *x, int ix0, double y_data[])
{
  int iy;
  int i12;
  int iac;
  int ix;
  double c;
  int i13;
  int ia;
  if (n != 0) {
    if (0 <= n - 1) {
      memset(&y_data[0], 0, (unsigned int)(n * (int)sizeof(double)));
    }

    iy = 0;
    i12 = ia0 + lda * (n - 1);
    for (iac = ia0; lda < 0 ? iac >= i12 : iac <= i12; iac += lda) {
      ix = ix0;
      c = 0.0;
      i13 = (iac + m) - 1;
      for (ia = iac; ia <= i13; ia++) {
        c += A->data[ia - 1] * x->data[ix - 1];
        ix++;
      }

      y_data[iy] += c;
      iy++;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                const emxArray_real_T *A
 *                int ia0
 *                int lda
 *                const emxArray_real_T *x
 *                int ix0
 *                double y_data[]
 * Return Type  : void
 */
void xgemv(int m, int n, const emxArray_real_T *A, int ia0, int lda, const
           emxArray_real_T *x, int ix0, double y_data[])
{
  int ix;
  int i8;
  int iac;
  int iy;
  int i9;
  int ia;
  if (m != 0) {
    if (0 <= m - 1) {
      memset(&y_data[0], 0, (unsigned int)(m * (int)sizeof(double)));
    }

    ix = ix0;
    i8 = ia0 + lda * (n - 1);
    for (iac = ia0; lda < 0 ? iac >= i8 : iac <= i8; iac += lda) {
      iy = 0;
      i9 = (iac + m) - 1;
      for (ia = iac; ia <= i9; ia++) {
        y_data[iy] += A->data[ia - 1] * x->data[ix - 1];
        iy++;
      }

      ix++;
    }
  }
}

/*
 * File trailer for xgemv.c
 *
 * [EOF]
 */
