/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: randomTaskIndConditions.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

#ifndef RANDOMTASKINDCONDITIONS_H
#define RANDOMTASKINDCONDITIONS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "centralizedTaskIndOptimization_types.h"

/* Function Declarations */
extern void randomTaskIndConditions(double N, double numReq, double numFunc,
  double maxFuncPerReq, double *numTasks, emxArray_real_T *taskIdxToFuncReq,
  emxArray_real_T *funcReqToTaskIdx, emxArray_cell_wrap_4 *indConstraints);

void initialize_variable(void);

#endif

/*
 * File trailer for randomTaskIndConditions.h
 *
 * [EOF]
 */
