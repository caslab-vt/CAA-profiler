/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xrot.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

#ifndef XROT_H
#define XROT_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
//#include "test_types.h"
#include "centralizedTaskIndOptimization.h"

/* Function Declarations */
extern void b_xrot(int n, emxArray_real_T *x, int ix0, int iy0, double c, double
                   s);
extern void xrot(int n, emxArray_real_T *x, int ix0, int incx, int iy0, int incy,
                 double c, double s);

#endif

/*
 * File trailer for xrot.h
 *
 * [EOF]
 */
