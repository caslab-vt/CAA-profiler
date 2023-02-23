/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mod.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "mod.h"

/* Function Definitions */

/*
 * Arguments    : double x
 *                double y
 * Return Type  : double
 */
double b_mod(double x, double y)
{
  double r;
  if (rtIsNaN(x) || rtIsNaN(y)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, y);
    if (r == 0.0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += y;
      }
    }
  }

  return r;
}

int c_mod(int x)
{
  return x - x / 10 * 10;
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
