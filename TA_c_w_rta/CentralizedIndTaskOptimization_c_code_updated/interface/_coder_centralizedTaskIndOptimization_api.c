/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_centralizedTaskIndOptimization_api.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/* Include Files */
#include <string.h>
#include "tmwtypes.h"
#include "_coder_centralizedTaskIndOptimization_api.h"
#include "_coder_centralizedTaskIndOptimization_mex.h"

/* Type Definitions */
#ifndef typedef_emxArray_cell_wrap_1_1x8
#define typedef_emxArray_cell_wrap_1_1x8

typedef struct {
  cell_wrap_1 data[8];
  int32_T size[2];
} emxArray_cell_wrap_1_1x8;

#endif                                 /*typedef_emxArray_cell_wrap_1_1x8*/

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "centralizedTaskIndOptimization",    /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_emlrt_marshallOut(void);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *taskIdxToFuncReq, const char_T *identifier, real_T **y_data, int32_T y_size[2]);
static const mxArray *c_emlrt_marshallOut(const real_T u);
static void c_emxFreeStruct_coder_internal_(coder_internal_sparse_1 *pStruct);
static void c_emxInitStruct_coder_internal_(const emlrtStack *sp,
  coder_internal_sparse_1 *pStruct, boolean_T doPush);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u);
static boolean_T db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *utility,
  const char_T *identifier, real_T **y_data, int32_T y_size[2]);
static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_4 *u);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *numReq,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(void);
static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *indConstraints, const char_T *identifier, cell_wrap_1 y_data[], int32_T
  y_size[2]);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_1 y_data[], int32_T y_size[2]);
static int32_T hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_0 y_data[], int32_T y_size[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pos, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static boolean_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *CONSTRAIN_TOPOLOGY, const char_T *identifier);
static boolean_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *partialSolution, const char_T *identifier);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Gprev, const
  char_T *identifier);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *G, const
  char_T *identifier, coder_internal_sparse_1 *y);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder_internal_sparse_1 *y);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static int32_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 8, 20 };

  const boolean_T bv4[2] = { true, true };

  int32_T iv13[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv4[0],
    iv13);
  ret_size[0] = iv13[0];
  ret_size[1] = iv13[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(void)
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv7[2] = { 0, 0 };

  static const int32_T iv8[2] = { 0, 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv7, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, NULL);
  emlrtSetDimensions((mxArray *)m1, iv8, 2);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret_data[]
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 2, 2 };

  const boolean_T bv5[2] = { true, false };

  int32_T iv14[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv5[0],
    iv14);
  ret_size[0] = iv14[0];
  ret_size[1] = iv14[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *taskIdxToFuncReq
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *taskIdxToFuncReq, const char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(taskIdxToFuncReq), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&taskIdxToFuncReq);
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : coder_internal_sparse_1 *pStruct
 * Return Type  : void
 */
static void c_emxFreeStruct_coder_internal_(coder_internal_sparse_1 *pStruct)
{
  emxFree_real_T(&pStruct->d);
  emxFree_int32_T(&pStruct->colidx);
  emxFree_int32_T(&pStruct->rowidx);
}

/*
 * Arguments    : const emlrtStack *sp
 *                coder_internal_sparse_1 *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void c_emxInitStruct_coder_internal_(const emlrtStack *sp,
  coder_internal_sparse_1 *pStruct, boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->d, 1, doPush);
  emxInit_int32_T(sp, &pStruct->colidx, 1, doPush);
  emxInit_int32_T(sp, &pStruct->rowidx, 1, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 5, 2 };

  const boolean_T bv6[2] = { true, false };

  int32_T iv15[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv6[0],
    iv15);
  ret_size[0] = iv15[0];
  ret_size[1] = iv15[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r1;
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv10[2] = { 0, 0 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv10, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, &u->data[0]);
  emlrtSetDimensions((mxArray *)m3, u->size, 2);
  emlrtAssign(&y, m3);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : boolean_T
 */
static boolean_T db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *utility
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *utility,
  const char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r2;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(utility), &thisId, &r2, y_size);
  *y_data = r2;
  emlrtDestroyArray(&utility);
}

/*
 * Arguments    : const emxArray_cell_wrap_4 *u
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const emxArray_cell_wrap_4 *u)
{
  const mxArray *y;
  int32_T i2;
  int32_T n;
  emxArray_cell_wrap_3_1x3 b_u;
  int32_T loop_ub;
  int32_T i3;
  const mxArray *b_y;
  int32_T u_size[2];
  int32_T i4;
  const mxArray *c_y;
  real_T u_data[4];
  const mxArray *m5;
  real_T *pData;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i2 = 0;
  n = u->size[1];
  while (i2 < n) {
    b_u.size[0] = 1;
    b_u.size[1] = u->data[i2].f1.size[1];
    loop_ub = u->data[i2].f1.size[0] * u->data[i2].f1.size[1];
    for (i3 = 0; i3 < loop_ub; i3++) {
      b_u.data[i3] = u->data[i2].f1.data[i3];
    }

    b_y = NULL;
    emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, b_u.size));
    for (i3 = 0; i3 < b_u.size[1]; i3++) {
      u_size[0] = b_u.data[i3].f1.size[0];
      u_size[1] = b_u.data[i3].f1.size[1];
      loop_ub = b_u.data[i3].f1.size[0] * b_u.data[i3].f1.size[1];
      for (i4 = 0; i4 < loop_ub; i4++) {
        u_data[i4] = b_u.data[i3].f1.data[i4];
      }

      c_y = NULL;
      m5 = emlrtCreateNumericArray(2, u_size, mxDOUBLE_CLASS, mxREAL);
      pData = emlrtMxGetPr(m5);
      i4 = 0;
      for (loop_ub = 0; loop_ub < u_size[1]; loop_ub++) {
        for (i = 0; i < u_size[0]; i++) {
          pData[i4] = u_data[i + u_size[0] * loop_ub];
          i4++;
        }
      }

      emlrtAssign(&c_y, m5);
      emlrtSetCell(b_y, i3, c_y);
    }

    emlrtSetCell(y, i2, b_y);
    i2++;
  }

  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *numReq
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *numReq,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(numReq), &thisId);
  emlrtDestroyArray(&numReq);
  return y;
}

/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(void)
{
  const mxArray *y;
  static const char * sv0[5] = { "taskIdxs", "functionalities", "requirements",
    "utility", "agentID" };

  const mxArray *b_y;
  const mxArray *m0;
  static const int32_T iv2[2] = { 0, 0 };

  static const int32_T iv3[2] = { 0, 0 };

  static const int32_T iv4[2] = { 0, 0 };

  static const int32_T iv5[2] = { 0, 0 };

  static const int32_T iv6[2] = { 0, 0 };

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 5, sv0));
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "taskIdxs", b_y, 0);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv3, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "functionalities", b_y, 1);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv4, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "requirements", b_y, 2);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "utility", b_y, 3);
  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "agentID", b_y, 4);
  return y;
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_4 **pEmxArray
 * Return Type  : void
 */
static void emxFree_cell_wrap_4(emxArray_cell_wrap_4 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_4 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_4 *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_4 *)NULL;
  }
}

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_cell_wrap_4 **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_cell_wrap_4(const emlrtStack *sp, emxArray_cell_wrap_4
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_4 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_4 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_4));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_4);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_4 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_int32_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)emlrtMallocMex(sizeof(emxArray_int32_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_int32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r3;
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r3, y_size);
  *y_data = r3;
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv7[1] = { true };

  int32_T iv16[1];
  int32_T i5;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv7[0],
    iv16);
  i5 = ret->size[0];
  ret->size[0] = iv16[0];
  emxEnsureCapacity_real_T(ret, i5);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *indConstraints
 *                const char_T *identifier
 *                cell_wrap_1 y_data[]
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *indConstraints, const char_T *identifier, cell_wrap_1 y_data[], int32_T
  y_size[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(indConstraints), &thisId, y_data, y_size);
  emlrtDestroyArray(&indConstraints);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_int32_T *ret
 * Return Type  : void
 */
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv8[1] = { true };

  int32_T iv17[1];
  int32_T i6;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 1U, dims, &bv8[0],
    iv17);
  i6 = ret->size[0];
  ret->size[0] = iv17[0];
  emxEnsureCapacity_int32_T(ret, i6);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_wrap_1 y_data[]
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_1 y_data[], int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  int32_T iv0[2];
  static const boolean_T bv0[2] = { false, true };

  int32_T sizes[2];
  int32_T i0;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv0[0] = 1;
  iv0[1] = 8;
  emlrtCheckVsCell(sp, parentId, u, 2U, iv0, bv0, sizes);
  y_size[0] = sizes[0];
  y_size[1] = sizes[1];
  for (i0 = 0; i0 < sizes[1]; i0++) {
    sprintf(&str[0], "%d", i0 + 1);
    thisId.fIdentifier = &str[0];
    i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i0)),
                       &thisId, y_data[i0].f1.data, y_data[i0].f1.size);
  }

  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : int32_T
 */
static int32_T hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 0U, &dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                cell_wrap_0 y_data[]
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, cell_wrap_0 y_data[], int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  int32_T iv1[2];
  static const boolean_T bv1[2] = { false, true };

  int32_T sizes[2];
  int32_T i1;
  char_T str[11];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  iv1[0] = 1;
  iv1[1] = 3;
  emlrtCheckVsCell(sp, parentId, u, 2U, iv1, bv1, sizes);
  y_size[0] = sizes[0];
  y_size[1] = sizes[1];
  for (i1 = 0; i1 < sizes[1]; i1++) {
    sprintf(&str[0], "%d", i1 + 1);
    thisId.fIdentifier = &str[0];
    j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell(sp, parentId, u, i1)),
                       &thisId, y_data[i1].f1.data, y_data[i1].f1.size);
  }

  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y_data[]
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *pos
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pos, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r4;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(pos), &thisId, &r4, y_size);
  *y_data = r4;
  emlrtDestroyArray(&pos);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r5;
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r5, y_size);
  *y_data = r5;
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *CONSTRAIN_TOPOLOGY
 *                const char_T *identifier
 * Return Type  : boolean_T
 */
static boolean_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *CONSTRAIN_TOPOLOGY, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(CONSTRAIN_TOPOLOGY), &thisId);
  emlrtDestroyArray(&CONSTRAIN_TOPOLOGY);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : boolean_T
 */
static boolean_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = db_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *partialSolution
 *                const char_T *identifier
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *partialSolution, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  p_emlrt_marshallIn(sp, emlrtAlias(partialSolution), &thisId);
  emlrtDestroyArray(&partialSolution);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[5] = { "taskIdxs", "functionalities",
    "requirements", "utility", "agentID" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "taskIdxs";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "taskIdxs")),
                     &thisId);
  thisId.fIdentifier = "functionalities";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "functionalities")), &thisId);
  thisId.fIdentifier = "requirements";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "requirements")), &thisId);
  thisId.fIdentifier = "utility";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "utility")),
                     &thisId);
  thisId.fIdentifier = "agentID";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "agentID")),
                     &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Gprev
 *                const char_T *identifier
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Gprev, const
  char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  q_emlrt_marshallIn(sp, emlrtAlias(Gprev), &thisId);
  emlrtDestroyArray(&Gprev);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *G
 *                const char_T *identifier
 *                coder_internal_sparse_1 *y
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *G, const
  char_T *identifier, coder_internal_sparse_1 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  t_emlrt_marshallIn(sp, emlrtAlias(G), &thisId, y);
  emlrtDestroyArray(&G);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                coder_internal_sparse_1 *y
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder_internal_sparse_1 *y)
{
  int32_T i;
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[6];
  int32_T iv9[2];
  boolean_T bv2[2];
  const char * propNames[6] = { "d", "colidx", "rowidx", "m", "n", "maxnz" };

  const char * propClasses[6] = { "coder.internal.sparse",
    "coder.internal.sparse", "coder.internal.sparse", "coder.internal.sparse",
    "coder.internal.sparse", "coder.internal.sparse" };

  for (i = 0; i < 6; i++) {
    propValues[i] = NULL;
  }

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  iv9[0] = -1;
  bv2[0] = true;
  iv9[1] = -1;
  bv2[1] = true;
  emlrtCheckSparse(sp, parentId, u, iv9, bv2, mxDOUBLE_CLASS, mxREAL);
  emlrtCheckMcosClass2017a(sp, parentId, u, "_primitive_sparse");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(sp, u, 0,
    "coder.internal.sparse"));
  emlrtCheckMcosClass2017a(sp, parentId, u, "coder.internal.sparse");
  emlrtGetAllProperties(sp, u, 0, 6, propNames, propClasses, propValues);
  thisId.fIdentifier = "d";
  u_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y->d);
  thisId.fIdentifier = "colidx";
  v_emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId, y->colidx);
  thisId.fIdentifier = "rowidx";
  v_emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId, y->rowidx);
  thisId.fIdentifier = "m";
  y->m = w_emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId);
  thisId.fIdentifier = "n";
  y->n = w_emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId);
  thisId.fIdentifier = "maxnz";
  y->maxnz = w_emlrt_marshallIn(sp, emlrtAlias(propValues[5]), &thisId);
  emlrtDestroyArrays(6, (const mxArray **)&propValues);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int32_T
 */
static int32_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 20, 2 };

  const boolean_T bv3[2] = { true, false };

  int32_T iv12[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv3[0],
    iv12);
  ret_size[0] = iv12[0];
  ret_size[1] = iv12[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray *prhs[10]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void centralizedTaskIndOptimization_api(const mxArray *prhs[10], int32_T nlhs,
  const mxArray *plhs[2])
{
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  const mxArray *prhs_copy_idx_6;
  const mxArray *prhs_copy_idx_7;
  const mxArray *prhs_copy_idx_8;
  const mxArray *prhs_copy_idx_9;
  real_T numReq;
  real_T numTasks;
  real_T (*taskIdxToFuncReq_data)[40];
  int32_T taskIdxToFuncReq_size[2];
  real_T (*utility_data)[160];
  int32_T utility_size[2];
  emxArray_cell_wrap_1_1x8 indConstraints;
  real_T (*pos_data)[10];
  int32_T pos_size[2];
  real_T (*commRadii_data)[160];
  int32_T commRadii_size[2];
  boolean_T CONSTRAIN_TOPOLOGY;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  mxMalloc(0U);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = emlrtProtectR2012b(prhs[3], 3, false, 160);
  prhs_copy_idx_4 = prhs[4];
  prhs_copy_idx_5 = prhs[5];
  prhs_copy_idx_6 = prhs[6];
  prhs_copy_idx_7 = prhs[7];
  prhs_copy_idx_8 = prhs[8];
  prhs_copy_idx_9 = emlrtProtectR2012b(prhs[9], 9, false, -1);

  /* Marshall function inputs */
  numReq = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_0), "numReq");
  numTasks = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_1), "numTasks");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "taskIdxToFuncReq",
                     (real_T **)&taskIdxToFuncReq_data, taskIdxToFuncReq_size);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "utility", (real_T **)
                     &utility_data, utility_size);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_4), "indConstraints",
                     indConstraints.data, indConstraints.size);
  k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_5), "pos", (real_T **)
                     &pos_data, pos_size);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_6), "commRadii", (real_T **)
                     &commRadii_data, commRadii_size);
  CONSTRAIN_TOPOLOGY = m_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_7),
    "CONSTRAIN_TOPOLOGY");
  o_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_8), "partialSolution");
  r_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_9), "Gprev");

  /* Invoke the target function */
  centralizedTaskIndOptimization(numReq, numTasks, *taskIdxToFuncReq_data,
    taskIdxToFuncReq_size, *utility_data, utility_size, indConstraints.data,
    indConstraints.size, *pos_data, pos_size, *commRadii_data, commRadii_size,
    CONSTRAIN_TOPOLOGY);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut();
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut();
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void centralizedTaskIndOptimization_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  centralizedTaskIndOptimization_xil_terminate();
  centralizedTaskIndOptimization_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void centralizedTaskIndOptimization_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void centralizedTaskIndOptimization_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void conncomp1_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                   *plhs[2])
{
  coder_internal_sparse_1 G;
  real_T S;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  mxMalloc(0U);
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInitStruct_coder_internal_(&st, &G, true);

  /* Marshall function inputs */
  s_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "G", &G);

  /* Invoke the target function */
  S = conncomp1(G);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(S);
  c_emxFreeStruct_coder_internal_(&G);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut();
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void randomTaskIndConditions_api(const mxArray * const prhs[4], int32_T nlhs,
  const mxArray *plhs[4])
{
  emxArray_real_T *taskIdxToFuncReq;
  emxArray_real_T *funcReqToTaskIdx;
  emxArray_cell_wrap_4 *indConstraints;
  real_T N;
  real_T numReq;
  real_T numFunc;
  real_T maxFuncPerReq;
  real_T numTasks;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &taskIdxToFuncReq, 2, true);
  emxInit_real_T(&st, &funcReqToTaskIdx, 2, true);
  emxInit_cell_wrap_4(&st, &indConstraints, 2, true);

  /* Marshall function inputs */
  N = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "N");
  numReq = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "numReq");
  numFunc = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "numFunc");
  maxFuncPerReq = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "maxFuncPerReq");

  /* Invoke the target function */
  randomTaskIndConditions(N, numReq, numFunc, maxFuncPerReq, &numTasks,
    taskIdxToFuncReq, funcReqToTaskIdx, indConstraints);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(numTasks);
  if (nlhs > 1) {
    taskIdxToFuncReq->canFreeData = false;
    plhs[1] = d_emlrt_marshallOut(taskIdxToFuncReq);
  }

  emxFree_real_T(&taskIdxToFuncReq);
  if (nlhs > 2) {
    funcReqToTaskIdx->canFreeData = false;
    plhs[2] = d_emlrt_marshallOut(funcReqToTaskIdx);
  }

  emxFree_real_T(&funcReqToTaskIdx);
  if (nlhs > 3) {
    plhs[3] = e_emlrt_marshallOut(indConstraints);
  }

  emxFree_cell_wrap_4(&indConstraints);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * File trailer for _coder_centralizedTaskIndOptimization_api.c
 *
 * [EOF]
 */
