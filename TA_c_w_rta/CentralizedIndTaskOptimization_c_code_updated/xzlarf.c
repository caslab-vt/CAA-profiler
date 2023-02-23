/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlarf.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "xzlarf.h"
#include "xgerc.h"
#include "xgemv.h"

/* Function Declarations */
static int ilazlc(int m, int n, const emxArray_real_T *A, int ia0, int lda);
static int ilazlr(int m, int n, const emxArray_real_T *A, int ia0, int lda);

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                const emxArray_real_T *A
 *                int ia0
 *                int lda
 * Return Type  : int
 */
static int ilazlc(int m, int n, const emxArray_real_T *A, int ia0, int lda)
{
  int j;
  boolean_T exitg2;
  int coltop;
  int ia;
  int exitg1;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    coltop = ia0 + (j - 1) * lda;
    ia = coltop;
    do {
      exitg1 = 0;
      if (ia <= (coltop + m) - 1) {
        if (A->data[ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          ia++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return j;
}

/*
 * Arguments    : int m
 *                int n
 *                const emxArray_real_T *A
 *                int ia0
 *                int lda
 * Return Type  : int
 */
static int ilazlr(int m, int n, const emxArray_real_T *A, int ia0, int lda)
{
  int i;
  boolean_T exitg2;
  int rowleft;
  int rowright;
  int exitg1;
  i = m;
  exitg2 = false;
  while ((!exitg2) && (i > 0)) {
    rowleft = (ia0 + i) - 1;
    rowright = rowleft + (n - 1) * lda;
    do {
      exitg1 = 0;
      if (((lda > 0) && (rowleft <= rowright)) || ((lda < 0) && (rowleft >=
            rowright))) {
        if (A->data[rowleft - 1] != 0.0) {
          exitg1 = 1;
        } else {
          rowleft += lda;
        }
      } else {
        i--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return i;
}

/*
 * Arguments    : int m
 *                int n
 *                int iv0
 *                double tau
 *                emxArray_real_T *C
 *                int ic0
 *                int ldc
 *                double work_data[]
 * Return Type  : void
 */
void b_xzlarf(int m, int n, int iv0, double tau, emxArray_real_T *C, int ic0,
              int ldc, double work_data[])
{
  int lastv;
  int lastc;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C->data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = ilazlc(lastv, n, C, ic0, ldc);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    b_xgemv(lastv, lastc, C, ic0, ldc, C, iv0, work_data);
    b_xgerc(lastv, lastc, -tau, iv0, work_data, C, ic0, ldc);
  }
}

/*
 * Arguments    : int m
 *                int n
 *                int iv0
 *                double tau
 *                emxArray_real_T *C
 *                int ic0
 *                int ldc
 *                double work_data[]
 * Return Type  : void
 */
void xzlarf(int m, int n, int iv0, double tau, emxArray_real_T *C, int ic0, int
            ldc, double work_data[])
{
  int lastv;
  int lastc;
  if (tau != 0.0) {
    lastv = n;
    lastc = iv0 + n;
    while ((lastv > 0) && (C->data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = ilazlr(m, lastv, C, ic0, ldc);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    xgemv(lastc, lastv, C, ic0, ldc, C, iv0, work_data);
    xgerc(lastc, lastv, -tau, work_data, iv0, C, ic0, ldc);
  }
}

/*
 * File trailer for xzlarf.c
 *
 * [EOF]
 */
