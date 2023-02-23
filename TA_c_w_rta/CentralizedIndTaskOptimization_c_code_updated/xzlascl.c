/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlascl.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "xzlascl.h"
#include "centralizedTaskIndOptimization_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : double cfrom
 *                double cto
 *                creal_T A_data[]
 *                int A_size[1]
 * Return Type  : void
 */
void b_xzlascl(double cfrom, double cto, creal_T A_data[], int A_size[1])
{
  double cfromc;
  double ctoc;
  boolean_T notdone;
  double cfrom1;
  double cto1;
  double a;
  int loop_ub;
  int i18;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      a = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      a = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      a = ctoc / cfromc;
      notdone = false;
    }

    loop_ub = A_size[0];
    for (i18 = 0; i18 < loop_ub; i18++) {
      A_data[i18].re *= a;
      A_data[i18].im *= a;
    }
  }
}

/*
 * Arguments    : double cfrom
 *                double cto
 *                emxArray_creal_T *A
 * Return Type  : void
 */
void xzlascl(double cfrom, double cto, emxArray_creal_T *A)
{
  double cfromc;
  double ctoc;
  boolean_T notdone;
  double cfrom1;
  double cto1;
  double a;
  int i16;
  int loop_ub;
  int b_loop_ub;
  int i17;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      a = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      a = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      a = ctoc / cfromc;
      notdone = false;
    }

    i16 = A->size[0] * A->size[1];
    emxEnsureCapacity_creal_T(A, i16);
    loop_ub = A->size[1];
    for (i16 = 0; i16 < loop_ub; i16++) {
      b_loop_ub = A->size[0];
      for (i17 = 0; i17 < b_loop_ub; i17++) {
        A->data[i17 + A->size[0] * i16].re *= a;
        A->data[i17 + A->size[0] * i16].im *= a;
      }
    }
  }
}

/*
 * File trailer for xzlascl.c
 *
 * [EOF]
 */
