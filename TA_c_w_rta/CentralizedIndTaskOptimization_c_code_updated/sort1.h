/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort1.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 29-Apr-2020 19:47:55
 */

#ifndef SORT1_H
#define SORT1_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "centralizedTaskIndOptimization_types.h"

/* Function Declarations */
extern void sort(creal_T x_data[], int x_size[2]);
extern void b_sort(double x_data[], int x_size[2], int idx_data[], int idx_size
                   [2]);
extern void c_sort(double x_data[], int x_size[1], int idx_data[], int idx_size
                   [1]);
#endif

/*
 * File trailer for sort1.h
 *
 * [EOF]
 */
