/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: centralizedTaskIndOptimization_types.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

#ifndef CENTRALIZEDTASKINDOPTIMIZATION_TYPES_H
#define CENTRALIZEDTASKINDOPTIMIZATION_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_2x2
#define struct_emxArray_real_T_2x2

struct emxArray_real_T_2x2
{
  double data[4];
  int size[2];
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
  int size[2];
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
  int size[2];
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
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  int m;
  int n;
  int maxnz;
} coder_internal_sparse_1;

#endif                                 /*typedef_coder_internal_sparse_1*/

#ifndef struct_c_emxArray_sJvpvgIi1UZ1cyLs6cJd
#define struct_c_emxArray_sJvpvgIi1UZ1cyLs6cJd

struct c_emxArray_sJvpvgIi1UZ1cyLs6cJd
{
  cell_wrap_4 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_c_emxArray_sJvpvgIi1UZ1cyLs6cJd*/

#ifndef typedef_emxArray_cell_wrap_4
#define typedef_emxArray_cell_wrap_4

typedef struct c_emxArray_sJvpvgIi1UZ1cyLs6cJd emxArray_cell_wrap_4;

typedef struct {
  emxArray_real_T *tasks;
  emxArray_real_T *functionalities;
  emxArray_real_T *requirements;
  emxArray_real_T *utility;
  emxArray_real_T *agentID;
  unsigned int data_counter;
} struct0_T;

#endif                                 /*typedef_emxArray_cell_wrap_4*/
#endif

/*
 * File trailer for centralizedTaskIndOptimization_types.h
 *
 * [EOF]
 */
