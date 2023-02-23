/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: anyNonFinite.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "anyNonFinite.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : boolean_T
 */
boolean_T anyNonFinite(const emxArray_real_T *x)
{
  boolean_T p;
  int nx;
  int k;
  double b_x;
  nx = x->size[0] * x->size[1];
  p = true;
  for (k = 0; k < nx; k++) {
    if (p) {
      b_x = x->data[k];
      if ((!rtIsInf(b_x)) && (!rtIsNaN(b_x))) {
        p = true;
      } else {
        p = false;
      }
    } else {
      p = false;
    }
  }

  return !p;
}

/*
 * File trailer for anyNonFinite.c
 *
 * [EOF]
 */
