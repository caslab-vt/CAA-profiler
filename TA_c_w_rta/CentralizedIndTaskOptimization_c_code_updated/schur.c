/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: schur.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "schur.h"
#include "triu.h"
#include "centralizedTaskIndOptimization_emxutil.h"
#include "sortLE.h"
#include "xdlanv2.h"
#include "xhseqr.h"
#include "xgehrd.h"
#include "anyNonFinite.h"
#include "test_rtwutil.h"

/* Function Declarations */
static void eml_rsf2csf(const emxArray_real_T *Tr, emxArray_creal_T *T);

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *Tr
 *                emxArray_creal_T *T
 * Return Type  : void
 */
static void eml_rsf2csf(const emxArray_real_T *Tr, emxArray_creal_T *T)
{
  int m;
  int loop_ub;
  int n;
  double r;
  double b;
  double s;
  double t1_re;
  double t1_im;
  double rt1i;
  double rt2r;
  double rt2i;
  double mu1_im;
  double mu1_re;
  m = T->size[0] * T->size[1];
  T->size[0] = Tr->size[0];
  T->size[1] = Tr->size[1];
  emxEnsureCapacity_creal_T(T, m);
  loop_ub = Tr->size[0] * Tr->size[1];
  for (m = 0; m < loop_ub; m++) {
    T->data[m].re = Tr->data[m];
    T->data[m].im = 0.0;
  }

  m = Tr->size[0];
  n = Tr->size[1];
  if (m < n) {
    n = m;
  }

  for (m = n - 1; m + 1 >= 2; m--) {
    if (Tr->data[m + Tr->size[0] * (m - 1)] != 0.0) {
      r = Tr->data[(m + Tr->size[0] * (m - 1)) - 1];
      b = Tr->data[(m + Tr->size[0] * m) - 1];
      s = Tr->data[m + Tr->size[0] * (m - 1)];
      t1_re = Tr->data[m + Tr->size[0] * m];
      xdlanv2(&r, &b, &s, &t1_re, &t1_im, &rt1i, &rt2r, &rt2i, &mu1_im, &mu1_re);
      mu1_re = t1_im - Tr->data[m + Tr->size[0] * m];
      r = rt_hypotd_snf(rt_hypotd_snf(mu1_re, rt1i), Tr->data[m + Tr->size[0] *
                        (m - 1)]);
      if (rt1i == 0.0) {
        mu1_re /= r;
        mu1_im = 0.0;
      } else if (mu1_re == 0.0) {
        mu1_re = 0.0;
        mu1_im = rt1i / r;
      } else {
        mu1_re /= r;
        mu1_im = rt1i / r;
      }

      s = Tr->data[m + Tr->size[0] * (m - 1)] / r;
      for (loop_ub = m; loop_ub <= n; loop_ub++) {
        t1_re = T->data[(m + T->size[0] * (loop_ub - 1)) - 1].re;
        t1_im = T->data[(m + T->size[0] * (loop_ub - 1)) - 1].im;
        rt2r = T->data[(m + T->size[0] * (loop_ub - 1)) - 1].re;
        rt2i = T->data[(m + T->size[0] * (loop_ub - 1)) - 1].im;
        r = T->data[(m + T->size[0] * (loop_ub - 1)) - 1].im;
        b = T->data[(m + T->size[0] * (loop_ub - 1)) - 1].re;
        T->data[(m + T->size[0] * (loop_ub - 1)) - 1].re = (mu1_re * rt2r +
          mu1_im * rt2i) + s * T->data[m + T->size[0] * (loop_ub - 1)].re;
        T->data[(m + T->size[0] * (loop_ub - 1)) - 1].im = (mu1_re * r - mu1_im *
          b) + s * T->data[m + T->size[0] * (loop_ub - 1)].im;
        r = mu1_re * T->data[m + T->size[0] * (loop_ub - 1)].re - mu1_im *
          T->data[m + T->size[0] * (loop_ub - 1)].im;
        b = mu1_re * T->data[m + T->size[0] * (loop_ub - 1)].im + mu1_im *
          T->data[m + T->size[0] * (loop_ub - 1)].re;
        T->data[m + T->size[0] * (loop_ub - 1)].re = r - s * t1_re;
        T->data[m + T->size[0] * (loop_ub - 1)].im = b - s * t1_im;
      }

      for (loop_ub = 0; loop_ub <= m; loop_ub++) {
        t1_re = T->data[loop_ub + T->size[0] * (m - 1)].re;
        t1_im = T->data[loop_ub + T->size[0] * (m - 1)].im;
        r = mu1_re * T->data[loop_ub + T->size[0] * (m - 1)].re - mu1_im *
          T->data[loop_ub + T->size[0] * (m - 1)].im;
        b = mu1_re * T->data[loop_ub + T->size[0] * (m - 1)].im + mu1_im *
          T->data[loop_ub + T->size[0] * (m - 1)].re;
        rt2r = T->data[loop_ub + T->size[0] * m].re;
        rt2i = T->data[loop_ub + T->size[0] * m].im;
        T->data[loop_ub + T->size[0] * (m - 1)].re = r + s * rt2r;
        T->data[loop_ub + T->size[0] * (m - 1)].im = b + s * rt2i;
        rt2r = T->data[loop_ub + T->size[0] * m].re;
        rt2i = T->data[loop_ub + T->size[0] * m].im;
        r = T->data[loop_ub + T->size[0] * m].im;
        b = T->data[loop_ub + T->size[0] * m].re;
        T->data[loop_ub + T->size[0] * m].re = (mu1_re * rt2r + mu1_im * rt2i) -
          s * t1_re;
        T->data[loop_ub + T->size[0] * m].im = (mu1_re * r - mu1_im * b) - s *
          t1_im;
      }

      T->data[m + T->size[0] * (m - 1)].re = 0.0;
      T->data[m + T->size[0] * (m - 1)].im = 0.0;
    }
  }
}

/*
 * Arguments    : emxArray_real_T *A
 *                emxArray_creal_T *V
 * Return Type  : void
 */
void schur(emxArray_real_T *A, emxArray_creal_T *V)
{
  emxArray_real_T *Vr;
  signed char unnamed_idx_0;
  signed char unnamed_idx_1;
  int i2;
  int loop_ub;
  if (anyNonFinite(A)) {
    unnamed_idx_0 = (signed char)A->size[0];
    unnamed_idx_1 = (signed char)A->size[1];
    i2 = V->size[0] * V->size[1];
    V->size[0] = unnamed_idx_0;
    V->size[1] = unnamed_idx_1;
    emxEnsureCapacity_creal_T(V, i2);
    loop_ub = unnamed_idx_0 * unnamed_idx_1;
    for (i2 = 0; i2 < loop_ub; i2++) {
      V->data[i2].re = rtNaN;
      V->data[i2].im = 0.0;
    }

    triu(V);
  } else {
    emxInit_real_T(&Vr, 2);
    xgehrd(A);
    i2 = Vr->size[0] * Vr->size[1];
    Vr->size[0] = A->size[0];
    Vr->size[1] = A->size[1];
    emxEnsureCapacity_real_T(Vr, i2);
    loop_ub = A->size[0] * A->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      Vr->data[i2] = A->data[i2];
    }

    xhseqr(Vr);
    eml_rsf2csf(Vr, V);
    emxFree_real_T(&Vr);
  }
}

/*
 * File trailer for schur.c
 *
 * [EOF]
 */
