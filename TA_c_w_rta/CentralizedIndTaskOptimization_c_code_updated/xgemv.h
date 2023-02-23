/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgemv.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

#ifndef XGEMV_H
#define XGEMV_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
//#include "test_types.h"
#include "centralizedTaskIndOptimization.h"

/* Function Declarations */
extern void b_xgemv(int m, int n, const emxArray_real_T *A, int ia0, int lda,
                    const emxArray_real_T *x, int ix0, double y_data[]);
extern void xgemv(int m, int n, const emxArray_real_T *A, int ia0, int lda,
                  const emxArray_real_T *x, int ix0, double y_data[]);

#endif

/*
 * File trailer for xgemv.h
 *
 * [EOF]
 */
