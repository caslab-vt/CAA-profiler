/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eig.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "eig.h"
#include "centralizedTaskIndOptimization_emxutil.h"
#include "schur.h"
#include "xzgeev.h"
#include "ishermitian.h"
#include "anyNonFinite.h"

/* Function Declarations */
static void mainDiagZeroImag(const emxArray_creal_T *D, creal_T d_data[], int
  d_size[1]);
static void makeD(const creal_T alpha1_data[], const int alpha1_size[1], const
                  creal_T beta1_data[], creal_T D_data[], int D_size[1]);

/* Function Definitions */

/*
 * Arguments    : const emxArray_creal_T *D
 *                creal_T d_data[]
 *                int d_size[1]
 * Return Type  : void
 */
static void mainDiagZeroImag(const emxArray_creal_T *D, creal_T d_data[], int
  d_size[1])
{
  int n;
  int k;
  n = D->size[0];
  d_size[0] = D->size[0];
  for (k = 0; k < n; k++) {
    d_data[k] = D->data[k + D->size[0] * k];
  }
}

/*
 * Arguments    : const creal_T alpha1_data[]
 *                const int alpha1_size[1]
 *                const creal_T beta1_data[]
 *                creal_T D_data[]
 *                int D_size[1]
 * Return Type  : void
 */
static void makeD(const creal_T alpha1_data[], const int alpha1_size[1], const
                  creal_T beta1_data[], creal_T D_data[], int D_size[1])
{
  int loop_ub;
  int i5;
  double brm;
  double bim;
  double d;
  D_size[0] = alpha1_size[0];
  loop_ub = alpha1_size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    if (beta1_data[i5].im == 0.0) {
      if (alpha1_data[i5].im == 0.0) {
        D_data[i5].re = alpha1_data[i5].re / beta1_data[i5].re;
        D_data[i5].im = 0.0;
      } else if (alpha1_data[i5].re == 0.0) {
        D_data[i5].re = 0.0;
        D_data[i5].im = alpha1_data[i5].im / beta1_data[i5].re;
      } else {
        D_data[i5].re = alpha1_data[i5].re / beta1_data[i5].re;
        D_data[i5].im = alpha1_data[i5].im / beta1_data[i5].re;
      }
    } else if (beta1_data[i5].re == 0.0) {
      if (alpha1_data[i5].re == 0.0) {
        D_data[i5].re = alpha1_data[i5].im / beta1_data[i5].im;
        D_data[i5].im = 0.0;
      } else if (alpha1_data[i5].im == 0.0) {
        D_data[i5].re = 0.0;
        D_data[i5].im = -(alpha1_data[i5].re / beta1_data[i5].im);
      } else {
        D_data[i5].re = alpha1_data[i5].im / beta1_data[i5].im;
        D_data[i5].im = -(alpha1_data[i5].re / beta1_data[i5].im);
      }
    } else {
      brm = fabs(beta1_data[i5].re);
      bim = fabs(beta1_data[i5].im);
      if (brm > bim) {
        bim = beta1_data[i5].im / beta1_data[i5].re;
        d = beta1_data[i5].re + bim * beta1_data[i5].im;
        D_data[i5].re = (alpha1_data[i5].re + bim * alpha1_data[i5].im) / d;
        D_data[i5].im = (alpha1_data[i5].im - bim * alpha1_data[i5].re) / d;
      } else if (bim == brm) {
        if (beta1_data[i5].re > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (beta1_data[i5].im > 0.0) {
          d = 0.5;
        } else {
          d = -0.5;
        }

        D_data[i5].re = (alpha1_data[i5].re * bim + alpha1_data[i5].im * d) /
          brm;
        D_data[i5].im = (alpha1_data[i5].im * bim - alpha1_data[i5].re * d) /
          brm;
      } else {
        bim = beta1_data[i5].re / beta1_data[i5].im;
        d = beta1_data[i5].im + bim * beta1_data[i5].re;
        D_data[i5].re = (bim * alpha1_data[i5].re + alpha1_data[i5].im) / d;
        D_data[i5].im = (bim * alpha1_data[i5].im - alpha1_data[i5].re) / d;
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                creal_T V_data[]
 *                int V_size[1]
 * Return Type  : void
 */
void eig(const emxArray_real_T *A, creal_T V_data[], int V_size[1])
{
  int info;
  creal_T alpha1_data[100];
  int alpha1_size[1];
  creal_T beta1_data[100];
  int beta1_size[1];
  emxArray_real_T *b_A;
  int loop_ub;
  emxArray_creal_T *r2;
  if (anyNonFinite(A)) {
    if ((A->size[0] == 1) && (A->size[1] == 1)) {
      V_data[0].re = A->data[0];
      V_data[0].im = 0.0;
      V_size[0] = 1;
      for (info = 0; info < 1; info++) {
        V_data[0].re = rtNaN;
        V_data[0].im = 0.0;
      }
    } else {
      V_size[0] = A->size[0];
      loop_ub = A->size[0];
      for (info = 0; info < loop_ub; info++) {
        V_data[info].re = rtNaN;
        V_data[info].im = 0.0;
      }
    }
  } else if ((A->size[0] == 1) && (A->size[1] == 1)) {
    V_size[0] = 1;
    V_data[0].re = A->data[0];
    V_data[0].im = 0.0;
  } else if (ishermitian(A)) {
    emxInit_real_T(&b_A, 2);
    info = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(b_A, info);
    loop_ub = A->size[0] * A->size[1];
    for (info = 0; info < loop_ub; info++) {
      b_A->data[info] = A->data[info];
    }

    emxInit_creal_T(&r2, 2);
    schur(b_A, r2);
    mainDiagZeroImag(r2, V_data, V_size);
    emxFree_real_T(&b_A);
    emxFree_creal_T(&r2);
  } else {
    xzgeev(A, &info, alpha1_data, alpha1_size, beta1_data, beta1_size);
    makeD(alpha1_data, alpha1_size, beta1_data, V_data, V_size);
  }
}

/*
 * File trailer for eig.c
 *
 * [EOF]
 */
