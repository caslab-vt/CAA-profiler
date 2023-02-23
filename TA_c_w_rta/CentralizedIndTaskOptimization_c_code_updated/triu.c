/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: triu.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "triu.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_creal_T *x
 * Return Type  : void
 */
void triu(emxArray_creal_T *x)
{
  int m;
  int istart;
  int jend;
  int j;
  int i;
  m = x->size[0];
  if (2 < x->size[0]) {
    istart = 3;
    if (x->size[0] - 3 < x->size[1] - 1) {
      jend = x->size[0] - 2;
    } else {
      jend = x->size[1];
    }

    for (j = 0; j < jend; j++) {
      for (i = istart; i <= m; i++) {
        x->data[(i + x->size[0] * j) - 1].re = 0.0;
        x->data[(i + x->size[0] * j) - 1].im = 0.0;
      }

      istart++;
    }
  }
}

/*
 * File trailer for triu.c
 *
 * [EOF]
 */
