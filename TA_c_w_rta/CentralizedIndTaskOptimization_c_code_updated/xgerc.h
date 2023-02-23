/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgerc.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

#ifndef XGERC_H
#define XGERC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
//#include "test_types.h"
#include "centralizedTaskIndOptimization.h"

/* Function Declarations */
extern void b_xgerc(int m, int n, double alpha1, int ix0, const double y_data[],
                    emxArray_real_T *A, int ia0, int lda);
extern void xgerc(int m, int n, double alpha1, const double x_data[], int iy0,
                  emxArray_real_T *A, int ia0, int lda);

#endif

/*
 * File trailer for xgerc.h
 *
 * [EOF]
 */
