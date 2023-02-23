/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlangeM.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "xzlangeM.h"
#include "sortLE.h"
#include "test_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_creal_T *x
 * Return Type  : double
 */
double xzlangeM(const emxArray_creal_T *x)
{
  double y;
  int i3;
  int k;
  double absxk;
  y = 0.0;
  i3 = x->size[0] * x->size[1];
  for (k = 0; k < i3; k++) {
    absxk = rt_hypotd_snf(x->data[k].re, x->data[k].im);
    if (absxk > y) {
      y = absxk;
    }
  }

  return y;
}

/*
 * File trailer for xzlangeM.c
 *
 * [EOF]
 */
