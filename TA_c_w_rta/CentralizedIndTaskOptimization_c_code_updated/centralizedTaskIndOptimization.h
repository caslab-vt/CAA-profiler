/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: centralizedTaskIndOptimization.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

#ifndef CENTRALIZEDTASKINDOPTIMIZATION_H
#define CENTRALIZEDTASKINDOPTIMIZATION_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "centralizedTaskIndOptimization_types.h"

/* Function Declarations */
extern void centralizedTaskIndOptimization(double numReq, double numTasks, emxArray_real_T *taskIdxToFuncReq,
                                    emxArray_real_T *utility,emxArray_cell_wrap_4 *indConstraints,
                                    emxArray_real_T *pos,emxArray_real_T *commRadii, boolean_T CONSTRAIN_TOPOLOGY,
                                    struct0_T *indset,emxArray_real_T *G,emxArray_real_T *Gprev,unsigned int *task_index);


extern void initialize_variable_centralized_task(void);
#endif

/*
 * File trailer for centralizedTaskIndOptimization.h
 *
 * [EOF]
 */
