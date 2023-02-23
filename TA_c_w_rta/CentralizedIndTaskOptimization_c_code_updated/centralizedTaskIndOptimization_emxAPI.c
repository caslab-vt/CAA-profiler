/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: centralizedTaskIndOptimization_emxAPI.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/* Include Files */
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "centralizedTaskIndOptimization_emxAPI.h"
#include "centralizedTaskIndOptimization_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : int numDimensions
 *                int *size
 * Return Type  : emxArray_cell_wrap_4 *
 */
emxArray_cell_wrap_4 *emxCreateND_cell_wrap_4(int numDimensions, int *size)
{
  emxArray_cell_wrap_4 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_4(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (cell_wrap_4 *)calloc((unsigned int)numEl, sizeof(cell_wrap_4));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : int numDimensions
 *                int *size
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size)
{
  emxArray_int32_T *emx;
  int numEl;
  int i;
  emxInit_int32_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (int *)calloc((unsigned int)numEl, sizeof(int));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : int numDimensions
 *                int *size
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size)
{
  emxArray_real_T *emx;
  int numEl;
  int i;
  emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : cell_wrap_4 *data
 *                int numDimensions
 *                int *size
 * Return Type  : emxArray_cell_wrap_4 *
 */
emxArray_cell_wrap_4 *emxCreateWrapperND_cell_wrap_4(cell_wrap_4 *data, int
  numDimensions, int *size)
{
  emxArray_cell_wrap_4 *emx;
  int numEl;
  int i;
  emxInit_cell_wrap_4(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int *data
 *                int numDimensions
 *                int *size
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions, int
  *size)
{
  emxArray_int32_T *emx;
  int numEl;
  int i;
  emxInit_int32_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : double *data
 *                int numDimensions
 *                int *size
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreateWrapperND_real_T(double *data, int numDimensions, int *
  size)
{
  emxArray_real_T *emx;
  int numEl;
  int i;
  emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : cell_wrap_4 *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_cell_wrap_4 *
 */
emxArray_cell_wrap_4 *emxCreateWrapper_cell_wrap_4(cell_wrap_4 *data, int rows,
  int cols)
{
  emxArray_cell_wrap_4 *emx;
  emxInit_cell_wrap_4(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols)
{
  emxArray_int32_T *emx;
  emxInit_int32_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : double *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols)
{
  emxArray_real_T *emx;
  emxInit_real_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_cell_wrap_4 *
 */
emxArray_cell_wrap_4 *emxCreate_cell_wrap_4(int rows, int cols)
{
  emxArray_cell_wrap_4 *emx;
  int numEl;
  emxInit_cell_wrap_4(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (cell_wrap_4 *)calloc((unsigned int)numEl, sizeof(cell_wrap_4));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_int32_T *
 */
emxArray_int32_T *emxCreate_int32_T(int rows, int cols)
{
  emxArray_int32_T *emx;
  int numEl;
  emxInit_int32_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (int *)calloc((unsigned int)numEl, sizeof(int));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_real_T *
 */
emxArray_real_T *emxCreate_real_T(int rows, int cols)
{
  emxArray_real_T *emx;
  int numEl;
  emxInit_real_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : emxArray_cell_wrap_4 *emxArray
 * Return Type  : void
 */
void emxDestroyArray_cell_wrap_4(emxArray_cell_wrap_4 *emxArray)
{
  emxFree_cell_wrap_4(&emxArray);
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_int32_T(emxArray_int32_T *emxArray)
{
  emxFree_int32_T(&emxArray);
}

/*
 * Arguments    : emxArray_real_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
  emxFree_real_T(&emxArray);
}

/*
 * Arguments    : coder_internal_sparse_1 emxArray
 * Return Type  : void
 */
void emxDestroy_coder_internal_sparse_1(coder_internal_sparse_1 emxArray)
{
  c_emxFreeStruct_coder_internal_(&emxArray);
}

/*
 * Arguments    : emxArray_cell_wrap_4 **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray, int
  numDimensions)
{
  emxInit_cell_wrap_4(pEmxArray, numDimensions);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

/*
 * Arguments    : coder_internal_sparse_1 *pStruct
 * Return Type  : void
 */
void emxInit_coder_internal_sparse_1(coder_internal_sparse_1 *pStruct)
{
  c_emxInitStruct_coder_internal_(pStruct);
}

/*
 * File trailer for centralizedTaskIndOptimization_emxAPI.c
 *
 * [EOF]
 */
