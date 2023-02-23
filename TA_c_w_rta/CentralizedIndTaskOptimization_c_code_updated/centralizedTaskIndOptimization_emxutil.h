/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: centralizedTaskIndOptimization_emxutil.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

#ifndef CENTRALIZEDTASKINDOPTIMIZATION_EMXUTIL_H
#define CENTRALIZEDTASKINDOPTIMIZATION_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "centralizedTaskIndOptimization_types.h"
#include "test_types.h"

/* Function Declarations */
extern void c_emxFreeStruct_coder_internal_(coder_internal_sparse_1 *pStruct);
extern void c_emxInitStruct_coder_internal_(coder_internal_sparse_1 *pStruct);
extern void emxEnsureCapacity_cell_wrap_4(emxArray_cell_wrap_4 *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray, int
  numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);


extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);
extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);


#endif

/*
 * File trailer for centralizedTaskIndOptimization_emxutil.h
 *
 * [EOF]
 */
