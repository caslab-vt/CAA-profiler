/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortLE.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 29-Apr-2020 19:47:55
 */

/* Include Files */
#include <math.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "sortLE.h"
#include "relop.h"
#include "test_rtwutil.h"

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * Arguments    : const creal_T v_data[]
 *                int idx1
 *                int idx2
 * Return Type  : boolean_T
 */
boolean_T sortLE(const creal_T v_data[], int idx1, int idx2)
{
  boolean_T p;
  double ma;
  boolean_T SCALEA;
  double mb;
  boolean_T SCALEB;
  double x;
  double br;
  double Mb;
  double ai;
  double Ma;
  if (rtIsNaN(v_data[idx2 - 1].re) || rtIsNaN(v_data[idx2 - 1].im)) {
    p = true;
  } else if (rtIsNaN(v_data[idx1 - 1].re) || rtIsNaN(v_data[idx1 - 1].im)) {
    p = false;
  } else {
    ma = fabs(v_data[idx1 - 1].re);
    if ((ma > 8.9884656743115785E+307) || (fabs(v_data[idx1 - 1].im) >
         8.9884656743115785E+307)) {
      SCALEA = true;
    } else {
      SCALEA = false;
    }

    mb = fabs(v_data[idx2 - 1].re);
    if ((mb > 8.9884656743115785E+307) || (fabs(v_data[idx2 - 1].im) >
         8.9884656743115785E+307)) {
      SCALEB = true;
    } else {
      SCALEB = false;
    }

    if (SCALEA || SCALEB) {
      x = rt_hypotd_snf(v_data[idx1 - 1].re / 2.0, v_data[idx1 - 1].im / 2.0);
      br = rt_hypotd_snf(v_data[idx2 - 1].re / 2.0, v_data[idx2 - 1].im / 2.0);
    } else {
      x = rt_hypotd_snf(v_data[idx1 - 1].re, v_data[idx1 - 1].im);
      br = rt_hypotd_snf(v_data[idx2 - 1].re, v_data[idx2 - 1].im);
    }

    if (iseq(x, br)) {
      Mb = fabs(v_data[idx1 - 1].im);
      ai = fabs(v_data[idx2 - 1].im);
      if (ma > Mb) {
        Ma = ma;
        ma = Mb;
      } else {
        Ma = Mb;
      }

      if (mb > ai) {
        Mb = mb;
        mb = ai;
      } else {
        Mb = ai;
      }

      if (Ma > Mb) {
        if (ma < mb) {
          x = Ma - Mb;
          br = (ma / 2.0 + mb / 2.0) / (Ma / 2.0 + Mb / 2.0) * (mb - ma);
        } else {
          x = Ma;
          br = Mb;
        }
      } else if (Ma < Mb) {
        if (ma > mb) {
          br = Mb - Ma;
          x = (ma / 2.0 + mb / 2.0) / (Ma / 2.0 + Mb / 2.0) * (ma - mb);
        } else {
          x = Ma;
          br = Mb;
        }
      } else {
        x = ma;
        br = mb;
      }

      if (iseq(x, br)) {
        x = rt_atan2d_snf(v_data[idx1 - 1].im, v_data[idx1 - 1].re);
        br = rt_atan2d_snf(v_data[idx2 - 1].im, v_data[idx2 - 1].re);
        if (iseq(x, br)) {
          Mb = v_data[idx1 - 1].re;
          ai = v_data[idx1 - 1].im;
          br = v_data[idx2 - 1].re;
          Ma = v_data[idx2 - 1].im;
          if (x > 0.78539816339744828) {
            if (x > 2.3561944901923448) {
              Mb = -ai;
              br = -Ma;
            } else {
              Mb = -Mb;
              br = -br;
            }
          } else if (x > -0.78539816339744828) {
            Mb = ai;
            br = Ma;
          } else {
            if (!(x > -2.3561944901923448)) {
              Mb = -ai;
              br = -Ma;
            }
          }

          x = Mb;
          if (iseq(Mb, br)) {
            x = 0.0;
            br = 0.0;
          }
        }
      }
    }

    p = (x <= br);
  }

  return p;
}

/*
 * File trailer for sortLE.c
 *
 * [EOF]
 */
