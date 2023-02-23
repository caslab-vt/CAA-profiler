/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: centralizedTaskIndOptimization_emxAPI.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

#ifndef CENTRALIZEDTASKINDOPTIMIZATION_EMXAPI_H
#define CENTRALIZEDTASKINDOPTIMIZATION_EMXAPI_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "centralizedTaskIndOptimization_types.h"

/* Function Declarations */
extern emxArray_cell_wrap_4 *emxCreateND_cell_wrap_4(int numDimensions, int
  *size);
extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_cell_wrap_4 *emxCreateWrapperND_cell_wrap_4(cell_wrap_4 *data,
  int numDimensions, int *size);
extern emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
  int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_cell_wrap_4 *emxCreateWrapper_cell_wrap_4(cell_wrap_4 *data, int
  rows, int cols);
extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_cell_wrap_4 *emxCreate_cell_wrap_4(int rows, int cols);
extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_cell_wrap_4(emxArray_cell_wrap_4 *emxArray);
extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroy_coder_internal_sparse_1(coder_internal_sparse_1 emxArray);
extern void emxInitArray_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray, int
  numDimensions);
void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_coder_internal_sparse_1(coder_internal_sparse_1 *pStruct);

#endif

/*
 * File trailer for centralizedTaskIndOptimization_emxAPI.h
 *
 * [EOF]
 */
