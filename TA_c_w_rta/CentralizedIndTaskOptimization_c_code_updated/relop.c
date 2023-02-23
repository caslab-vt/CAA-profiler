/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: relop.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 29-Apr-2020 19:47:55
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "relop.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double y
 * Return Type  : boolean_T
 */
boolean_T iseq(double x, double y)
{
  boolean_T p;
  double absxk;
  int exponent;
  absxk = fabs(y / 2.0);
  if ((!rtIsInf(absxk)) && (!rtIsNaN(absxk))) {
    if (absxk <= 2.2250738585072014E-308) {
      absxk = 4.94065645841247E-324;
    } else {
      frexp(absxk, &exponent);
      absxk = ldexp(1.0, exponent - 53);
    }
  } else {
    absxk = rtNaN;
  }

  if ((fabs(y - x) < absxk) || (rtIsInf(x) && rtIsInf(y) && ((x > 0.0) == (y >
         0.0)))) {
    p = true;
  } else {
    p = false;
  }

  return p;
}

/*
 * File trailer for relop.c
 *
 * [EOF]
 */
