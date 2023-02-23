/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_centralizedTaskIndOptimization_api.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

#ifndef _CODER_CENTRALIZEDTASKINDOPTIMIZATION_API_H
#define _CODER_CENTRALIZEDTASKINDOPTIMIZATION_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_centralizedTaskIndOptimization_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_2x2
#define struct_emxArray_real_T_2x2

struct emxArray_real_T_2x2
{
  real_T data[4];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_2x2*/

#ifndef typedef_emxArray_real_T_2x2
#define typedef_emxArray_real_T_2x2

typedef struct emxArray_real_T_2x2 emxArray_real_T_2x2;

#endif                                 /*typedef_emxArray_real_T_2x2*/

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0

typedef struct {
  emxArray_real_T_2x2 f1;
} cell_wrap_0;

#endif                                 /*typedef_cell_wrap_0*/

#ifndef typedef_emxArray_cell_wrap_0_1x3
#define typedef_emxArray_cell_wrap_0_1x3

typedef struct {
  cell_wrap_0 data[3];
  int32_T size[2];
} emxArray_cell_wrap_0_1x3;

#endif                                 /*typedef_emxArray_cell_wrap_0_1x3*/

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1

typedef struct {
  emxArray_cell_wrap_0_1x3 f1;
} cell_wrap_1;

#endif                                 /*typedef_cell_wrap_1*/

#ifndef struct_scFNy68armYpSMF2B9nOvZH_tag
#define struct_scFNy68armYpSMF2B9nOvZH_tag

struct scFNy68armYpSMF2B9nOvZH_tag
{
  emxArray_real_T_2x2 f1;
};

#endif                                 /*struct_scFNy68armYpSMF2B9nOvZH_tag*/

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3

typedef struct scFNy68armYpSMF2B9nOvZH_tag cell_wrap_3;

#endif                                 /*typedef_cell_wrap_3*/

#ifndef struct_c_emxArray_scFNy68armYpSMF2B9nO
#define struct_c_emxArray_scFNy68armYpSMF2B9nO

struct c_emxArray_scFNy68armYpSMF2B9nO
{
  cell_wrap_3 data[3];
  int32_T size[2];
};

#endif                                 /*struct_c_emxArray_scFNy68armYpSMF2B9nO*/

#ifndef typedef_emxArray_cell_wrap_3_1x3
#define typedef_emxArray_cell_wrap_3_1x3

typedef struct c_emxArray_scFNy68armYpSMF2B9nO emxArray_cell_wrap_3_1x3;

#endif                                 /*typedef_emxArray_cell_wrap_3_1x3*/

#ifndef struct_sJvpvgIi1UZ1cyLs6cJdvh_tag
#define struct_sJvpvgIi1UZ1cyLs6cJdvh_tag

struct sJvpvgIi1UZ1cyLs6cJdvh_tag
{
  emxArray_cell_wrap_3_1x3 f1;
};

#endif                                 /*struct_sJvpvgIi1UZ1cyLs6cJdvh_tag*/

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4

typedef struct sJvpvgIi1UZ1cyLs6cJdvh_tag cell_wrap_4;

#endif                                 /*typedef_cell_wrap_4*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_coder_internal_sparse_1
#define typedef_coder_internal_sparse_1

typedef struct {
  emxArray_real_T *d;
  emxArray_int32_T *colidx;
  emxArray_int32_T *rowidx;
  int32_T m;
  int32_T n;
  int32_T maxnz;
} coder_internal_sparse_1;

#endif                                 /*typedef_coder_internal_sparse_1*/

#ifndef struct_c_emxArray_sJvpvgIi1UZ1cyLs6cJd
#define struct_c_emxArray_sJvpvgIi1UZ1cyLs6cJd

struct c_emxArray_sJvpvgIi1UZ1cyLs6cJd
{
  cell_wrap_4 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_c_emxArray_sJvpvgIi1UZ1cyLs6cJd*/

#ifndef typedef_emxArray_cell_wrap_4
#define typedef_emxArray_cell_wrap_4

typedef struct c_emxArray_sJvpvgIi1UZ1cyLs6cJd emxArray_cell_wrap_4;

#endif                                 /*typedef_emxArray_cell_wrap_4*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void centralizedTaskIndOptimization(real_T numReq, real_T numTasks,
  real_T taskIdxToFuncReq_data[], int32_T taskIdxToFuncReq_size[2], real_T
  utility_data[], int32_T utility_size[2], cell_wrap_1 indConstraints_data[],
  int32_T indConstraints_size[2], real_T pos_data[], int32_T pos_size[2], real_T
  commRadii_data[], int32_T commRadii_size[2], boolean_T CONSTRAIN_TOPOLOGY);
extern void centralizedTaskIndOptimization_api(const mxArray *prhs[10], int32_T
  nlhs, const mxArray *plhs[2]);
extern void centralizedTaskIndOptimization_atexit(void);
extern void centralizedTaskIndOptimization_initialize(void);
extern void centralizedTaskIndOptimization_terminate(void);
extern void centralizedTaskIndOptimization_xil_shutdown(void);
extern void centralizedTaskIndOptimization_xil_terminate(void);
extern real_T conncomp1(coder_internal_sparse_1 G);
extern void conncomp1_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[2]);
extern void randomTaskIndConditions(real_T N, real_T numReq, real_T numFunc,
  real_T maxFuncPerReq, real_T *numTasks, emxArray_real_T *taskIdxToFuncReq,
  emxArray_real_T *funcReqToTaskIdx, emxArray_cell_wrap_4 *indConstraints);
extern void randomTaskIndConditions_api(const mxArray * const prhs[4], int32_T
  nlhs, const mxArray *plhs[4]);

#endif

/*
 * File trailer for _coder_centralizedTaskIndOptimization_api.h
 *
 * [EOF]
 */
