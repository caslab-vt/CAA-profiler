/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "main.h"
#include "centralizedTaskIndOptimization_terminate.h"
#include "centralizedTaskIndOptimization_emxAPI.h"
#include "centralizedTaskIndOptimization_initialize.h"

/* Type Definitions */
#ifndef typedef_emxArray_cell_wrap_1_1x8
#define typedef_emxArray_cell_wrap_1_1x8

typedef struct {
  cell_wrap_1 data[8];
  int size[2];
} emxArray_cell_wrap_1_1x8;

#endif                                 /*typedef_emxArray_cell_wrap_1_1x8*/

/* Function Declarations */
static void argInit_1xd3_cell_wrap_0(cell_wrap_0 result_data[], int result_size
  [2]);
static void argInit_1xd8_cell_wrap_1(cell_wrap_1 result_data[], int result_size
  [2]);
static emxArray_int32_T *argInit_Unboundedx1_int32_T(void);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static boolean_T argInit_boolean_T(void);
static cell_wrap_0 argInit_cell_wrap_0(void);
static void argInit_cell_wrap_1(cell_wrap_1 *result);
static coder_internal_sparse_1 argInit_coder_internal_sparse_1(void);
static void argInit_d20x2_real_T(double result_data[], int result_size[2]);
static void argInit_d8xd20_real_T(double result_data[], int result_size[2]);
static int argInit_int32_T(void);
static double argInit_real_T(void);
static void main_centralizedTaskIndOptimization(void);
static void main_conncomp1(void);
static void main_randomTaskIndConditions(void);

/* Function Definitions */

/*
 * Arguments    : cell_wrap_0 result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_1xd3_cell_wrap_0(cell_wrap_0 result_data[], int result_size
  [2])
{
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 1;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result_size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[idx1] = argInit_cell_wrap_0();
  }
}

/*
 * Arguments    : cell_wrap_1 result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_1xd8_cell_wrap_1(cell_wrap_1 result_data[], int result_size
  [2])
{
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 1;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result_size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    argInit_cell_wrap_1(&result_data[idx1]);
  }
}

/*
 * Arguments    : void
 * Return Type  : emxArray_int32_T *
 */
static emxArray_int32_T *argInit_Unboundedx1_int32_T(void)
{
  emxArray_int32_T *result;
  static int iv1[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_int32_T(1, iv1);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_int32_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static int iv0[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv0);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : boolean_T
 */
static boolean_T argInit_boolean_T(void)
{
  return false;
}

/*
 * Arguments    : void
 * Return Type  : cell_wrap_0
 */
static cell_wrap_0 argInit_cell_wrap_0(void)
{
  cell_wrap_0 result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_d20x2_real_T(result.f1.data, result.f1.size);
  return result;
}

/*
 * Arguments    : cell_wrap_1 *result
 * Return Type  : void
 */
static void argInit_cell_wrap_1(cell_wrap_1 *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  argInit_1xd3_cell_wrap_0(result->f1.data, result->f1.size);
}

/*
 * Arguments    : void
 * Return Type  : coder_internal_sparse_1
 */
static coder_internal_sparse_1 argInit_coder_internal_sparse_1(void)
{
  coder_internal_sparse_1 result;
  int result_tmp;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.d = argInit_Unboundedx1_real_T();
  result.colidx = argInit_Unboundedx1_int32_T();
  result.rowidx = argInit_Unboundedx1_int32_T();
  result_tmp = argInit_int32_T();
  result.m = result_tmp;
  result.n = result_tmp;
  result.maxnz = argInit_int32_T();
  return result;
}

/*
 * Arguments    : double result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_d20x2_real_T(double result_data[], int result_size[2])
{
  int idx0;
  double result_data_tmp;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 2;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data_tmp = argInit_real_T();
    result_data[idx0] = result_data_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_data[idx0 + 2] = result_data_tmp;
  }
}

/*
 * Arguments    : double result_data[]
 *                int result_size[2]
 * Return Type  : void
 */
static void argInit_d8xd20_real_T(double result_data[], int result_size[2])
{
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result_size[0] = 2;
  result_size[1] = 2;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result_data[idx0 + 2 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : int
 */
static int argInit_int32_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_centralizedTaskIndOptimization(void)
{
  double numReq_tmp;
  double taskIdxToFuncReq_data[40];
  int taskIdxToFuncReq_size[2];
  double utility_data[160];
  int utility_size[2];
  emxArray_cell_wrap_1_1x8 indConstraints;
  double pos_data[10];
  int pos_size[2];
  double commRadii_data[160];
  int commRadii_size[2];

  /* Initialize function 'centralizedTaskIndOptimization' input arguments. */
  numReq_tmp = argInit_real_T();

  /* Initialize function input argument 'taskIdxToFuncReq'. */
  argInit_d20x2_real_T(taskIdxToFuncReq_data, taskIdxToFuncReq_size);

  /* Initialize function input argument 'utility'. */
  argInit_d8xd20_real_T(utility_data, utility_size);

  /* Initialize function input argument 'indConstraints'. */
  argInit_1xd8_cell_wrap_1(indConstraints.data, indConstraints.size);

  /* Initialize function input argument 'pos'. */
  argInit_d20x2_real_T(pos_data, pos_size);

  /* Initialize function input argument 'commRadii'. */
  argInit_d8xd20_real_T(commRadii_data, commRadii_size);

  /* Initialize function input argument 'partialSolution'. */
  /* Initialize function input argument 'Gprev'. */
  /* Call the entry-point 'centralizedTaskIndOptimization'. */
  centralizedTaskIndOptimization(numReq_tmp, numReq_tmp, taskIdxToFuncReq_data,
    taskIdxToFuncReq_size, utility_data, utility_size, indConstraints.data,
    indConstraints.size, pos_data, pos_size, commRadii_data, commRadii_size,
    argInit_boolean_T());
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_conncomp1(void)
{
  coder_internal_sparse_1 G;
  double S;

  /* Initialize function 'conncomp1' input arguments. */
  /* Initialize function input argument 'G'. */
  G = argInit_coder_internal_sparse_1();

  /* Call the entry-point 'conncomp1'. */
  S = conncomp1(G);
  emxDestroy_coder_internal_sparse_1(G);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_randomTaskIndConditions(void)
{
  emxArray_real_T *taskIdxToFuncReq;
  emxArray_real_T *funcReqToTaskIdx;
  emxArray_cell_wrap_4 *indConstraints;
  double numTasks;
  emxInitArray_real_T(&taskIdxToFuncReq, 2);
  emxInitArray_real_T(&funcReqToTaskIdx, 2);
  emxInitArray_cell_wrap_4(&indConstraints, 2);

  /* Initialize function 'randomTaskIndConditions' input arguments. */
  /* Call the entry-point 'randomTaskIndConditions'. */
  randomTaskIndConditions(argInit_real_T(), argInit_real_T(), argInit_real_T(),
    argInit_real_T(), &numTasks, taskIdxToFuncReq, funcReqToTaskIdx,
    indConstraints);
  emxDestroyArray_cell_wrap_4(indConstraints);
  emxDestroyArray_real_T(funcReqToTaskIdx);
  emxDestroyArray_real_T(taskIdxToFuncReq);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  centralizedTaskIndOptimization_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_centralizedTaskIndOptimization();
  main_conncomp1();
  main_randomTaskIndConditions();

  /* Terminate the application.
     You do not need to do this more than one time. */
  centralizedTaskIndOptimization_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
