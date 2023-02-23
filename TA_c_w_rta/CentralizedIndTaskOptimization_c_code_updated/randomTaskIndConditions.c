/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: randomTaskIndConditions.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "rand.h"
#include "centralizedTaskIndOptimization_emxutil.h"
#include "mod.h"

/* Function Definitions */

/*
 * Set functionalities for each requirement
 * Arguments    : double N
 *                double numReq
 *                double numFunc
 *                double maxFuncPerReq
 *                double *numTasks
 *                emxArray_real_T *taskIdxToFuncReq
 *                emxArray_real_T *funcReqToTaskIdx
 *                emxArray_cell_wrap_4 *indConstraints
 * Return Type  : void
 */

emxArray_real_T *func;
emxArray_real_T *hashTbl;
emxArray_real_T *link;
emxArray_real_T *val;
emxArray_real_T *loc;
emxArray_real_T *b_taskIdxToFuncReq;

void randomTaskIndConditions(double N, double numReq, double numFunc, double
  maxFuncPerReq, double *numTasks, emxArray_real_T *taskIdxToFuncReq,
  emxArray_real_T *funcReqToTaskIdx, emxArray_cell_wrap_4 *indConstraints)
{

  int i0;
  int i1;
  int i2;
  int loop_ub;
  int i;
  double selectedLoc;
  double x;
  double t;
  double taskIdxs[2];
  int jlast;
  int m;
  double j;
  double newEntry;
  double nleftm1;
  signed char b_hashTbl[2];
  cell_wrap_3 r0;
  cell_wrap_3 r1;
  cell_wrap_3 r2;
  double b_jlast;
  boolean_T exitg1;
  cell_wrap_3 rv0[3];


  *numTasks = 0.0;
  taskIdxToFuncReq->size[0] = 0;
  taskIdxToFuncReq->size[1] = 0;
  //printf("%d \n",funcReqToTaskIdx->size[0]);

  i0 = funcReqToTaskIdx->size[0] * funcReqToTaskIdx->size[1];
  i1 = (int)numFunc;
  funcReqToTaskIdx->size[0] = i1;
  i2 = (int)numReq;
  funcReqToTaskIdx->size[1] = i2;
  emxEnsureCapacity_real_T(funcReqToTaskIdx, i0);
  loop_ub = i1 * i2;
  for (i0 = 0; i0 < loop_ub; i0++) {
    funcReqToTaskIdx->data[i0] = 0.0;
  }

  for (i = 0; i < i2; i++) {
    selectedLoc = b_rand();
    x = floor(selectedLoc * maxFuncPerReq);
    i0 = func->size[0] * func->size[1];
    func->size[0] = 1;
    loop_ub = (int)(1.0 + x);
    func->size[1] = loop_ub;
    emxEnsureCapacity_real_T(func, i0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      func->data[i0] = 0.0;
    }

    if (!(1.0 + x == 0.0)) {
      if (1.0 + x >= numFunc) {
        func->data[0] = 1.0;
        i0 = (int)(numFunc - 1.0);
        for (jlast = 0; jlast < i0; jlast++) {
          j = b_rand() * ((1.0 + (double)jlast) + 1.0);
          i1 = (int)(floor(j) + 1.0) - 1;
          func->data[1 + jlast] = func->data[i1];
          func->data[i1] = (1.0 + (double)jlast) + 1.0;
        }
      } else if (1.0 + x >= numFunc / 4.0) {
        t = 0.0;
        i0 = (int)(((1.0 + x) - 1.0) + 1.0);
        for (m = 0; m < i0; m++) {
          newEntry = (1.0 + x) - (double)m;
          nleftm1 = numFunc - t;
          selectedLoc = newEntry / nleftm1;
          j = b_rand();
          while (j > selectedLoc) {
            t++;
            nleftm1--;
            selectedLoc += (1.0 - selectedLoc) * (newEntry / nleftm1);
          }

          t++;
          j = b_rand() * ((double)m + 1.0);
          i1 = (int)(floor(j) + 1.0) - 1;
          func->data[m] = func->data[i1];
          func->data[i1] = t;
        }
      } else {
        i0 = hashTbl->size[0];
        hashTbl->size[0] = loop_ub;
        emxEnsureCapacity_real_T(hashTbl, i0);
        for (i0 = 0; i0 < loop_ub; i0++) {
          hashTbl->data[i0] = 0.0;
        }

        i0 = link->size[0];
        link->size[0] = loop_ub;
        emxEnsureCapacity_real_T(link, i0);
        for (i0 = 0; i0 < loop_ub; i0++) {
          link->data[i0] = 0.0;
        }

        i0 = val->size[0];
        val->size[0] = loop_ub;
        emxEnsureCapacity_real_T(val, i0);
        for (i0 = 0; i0 < loop_ub; i0++) {
          val->data[i0] = 0.0;
        }

        i0 = loc->size[0];
        loc->size[0] = loop_ub;
        emxEnsureCapacity_real_T(loc, i0);
        for (i0 = 0; i0 < loop_ub; i0++) {
          loc->data[i0] = 0.0;
        }

        newEntry = 1.0;
        for (m = 0; m < loop_ub; m++) {
          nleftm1 = numFunc - (1.0 + (double)m);
          selectedLoc = b_rand() * (nleftm1 + 1.0);
          selectedLoc = floor(selectedLoc);
          jlast = (int)(1.0 + b_mod(selectedLoc, 1.0 + x)) - 1;
          j = hashTbl->data[jlast];
          exitg1 = false;
          while ((!exitg1) && (j > 0.0)) {
            i0 = (int)j - 1;
            if (loc->data[i0] != selectedLoc) {
              j = link->data[i0];
            } else {
              exitg1 = true;
            }
          }

          if (j > 0.0) {
            func->data[m] = val->data[(int)j - 1] + 1.0;
          } else {
            func->data[m] = selectedLoc + 1.0;
            j = newEntry;
            newEntry++;
            i0 = (int)j - 1;
            loc->data[i0] = selectedLoc;
            link->data[i0] = hashTbl->data[jlast];
            hashTbl->data[jlast] = j;
          }

          if (1.0 + (double)m < 1.0 + x) {
            selectedLoc = hashTbl->data[(int)(1.0 + b_mod(nleftm1, 1.0 + x)) - 1];
            exitg1 = false;
            while ((!exitg1) && (selectedLoc > 0.0)) {
              i0 = (int)selectedLoc - 1;
              if (loc->data[i0] != nleftm1) {
                selectedLoc = link->data[i0];
              } else {
                exitg1 = true;
              }
            }

            if (selectedLoc > 0.0) {
              val->data[(int)j - 1] = val->data[(int)selectedLoc - 1];
            } else {
              val->data[(int)j - 1] = nleftm1;
            }
          }
        }
      }
    }

    i0 = func->size[1];
    if (0 <= i0 - 1) {
      taskIdxs[1] = 1.0 + (double)i;
    }

    for (jlast = 0; jlast < i0; jlast++) {
      (*numTasks)++;
      taskIdxs[0] = func->data[jlast];
      if ((taskIdxToFuncReq->size[0] != 0) && (taskIdxToFuncReq->size[1] != 0))
      {
        loop_ub = taskIdxToFuncReq->size[0];
      } else {
        loop_ub = 0;
      }

      i1 = b_taskIdxToFuncReq->size[0] * b_taskIdxToFuncReq->size[1];
      b_taskIdxToFuncReq->size[0] = loop_ub + 1;
      b_taskIdxToFuncReq->size[1] = 2;
      emxEnsureCapacity_real_T(b_taskIdxToFuncReq, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_taskIdxToFuncReq->data[i1] = taskIdxToFuncReq->data[i1];
      }

      for (i1 = 0; i1 < loop_ub; i1++) {
        b_taskIdxToFuncReq->data[i1 + b_taskIdxToFuncReq->size[0]] =
          taskIdxToFuncReq->data[i1 + taskIdxToFuncReq->size[0]];
      }

      b_taskIdxToFuncReq->data[loop_ub] = taskIdxs[0];
      b_taskIdxToFuncReq->data[loop_ub + b_taskIdxToFuncReq->size[0]] =
        taskIdxs[1];
      i1 = taskIdxToFuncReq->size[0] * taskIdxToFuncReq->size[1];
      taskIdxToFuncReq->size[0] = b_taskIdxToFuncReq->size[0];
      taskIdxToFuncReq->size[1] = b_taskIdxToFuncReq->size[1];
      emxEnsureCapacity_real_T(taskIdxToFuncReq, i1);
      loop_ub = b_taskIdxToFuncReq->size[0] * b_taskIdxToFuncReq->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        taskIdxToFuncReq->data[i1] = b_taskIdxToFuncReq->data[i1];
      }

      funcReqToTaskIdx->data[((int)func->data[jlast] + funcReqToTaskIdx->size[0]* i) - 1] = *numTasks;
    }
  }
  /*  Set independence constraints for each agent */
  i0 = (int)N;
  i1 = indConstraints->size[0] * indConstraints->size[1];
  indConstraints->size[0] = 1;
  indConstraints->size[1] = i0;
  emxEnsureCapacity_cell_wrap_4(indConstraints, i1);
  for (i = 0; i < i0; i++) {
    if (b_rand() > 0.5) {
      selectedLoc = b_rand();
      loop_ub = taskIdxToFuncReq->size[1];
      i1 = (int)(1.0 + floor(selectedLoc * *numTasks));
      r0.f1.size[0] = 1;
      r0.f1.size[1] = loop_ub;
      for (i2 = 0; i2 < loop_ub; i2++) {
        r0.f1.data[r0.f1.size[0] * i2] = taskIdxToFuncReq->data[(i1 +
          taskIdxToFuncReq->size[0] * i2) - 1];
      }

      indConstraints->data[i].f1.size[0] = 1;
      indConstraints->data[i].f1.size[1] = 1;
      indConstraints->data[i].f1.data[0] = r0;
    } else {
      taskIdxs[1] = 0.0;
      if (2.0 >= *numTasks) {
        taskIdxs[0] = 1.0;
        j = b_rand() * 2.0;
        jlast = (int)(floor(j) + 1.0) - 1;
        taskIdxs[1] = taskIdxs[jlast];
        taskIdxs[jlast] = 2.0;
      } else if (2.0 >= *numTasks / 4.0) {
        t = 0.0;
        nleftm1 = *numTasks;
        selectedLoc = 2.0 / *numTasks;
        j = b_rand();
        while (j > selectedLoc) {
          t++;
          nleftm1--;
          selectedLoc += (1.0 - selectedLoc) * (2.0 / nleftm1);
        }

        t++;
        j = b_rand();
        taskIdxs[0] = 0.0;
        taskIdxs[(int)(floor(j) + 1.0) - 1] = t;
        nleftm1 = *numTasks - t;
        selectedLoc = 1.0 / nleftm1;
        j = b_rand();
        while (j > selectedLoc) {
          t++;
          nleftm1--;
          selectedLoc += (1.0 - selectedLoc) * (1.0 / nleftm1);
        }

        t++;
        j = b_rand() * 2.0;
        nleftm1 = floor(j);
        taskIdxs[1] = taskIdxs[(int)(nleftm1 + 1.0) - 1];
        taskIdxs[(int)(nleftm1 + 1.0) - 1] = t;
      } else {
        b_hashTbl[0] = 0;
        b_hashTbl[1] = 0;
        selectedLoc = b_rand() * ((*numTasks - 1.0) + 1.0);
        newEntry = floor(selectedLoc);
        if (rtIsNaN(newEntry)) {
          selectedLoc = rtNaN;
        } else if (newEntry == 0.0) {
          selectedLoc = 0.0;
        } else {
          selectedLoc = fmod(newEntry, 2.0);
          if (selectedLoc == 0.0) {
            selectedLoc = 0.0;
          }
        }

        taskIdxs[0] = newEntry + 1.0;
        b_hashTbl[(int)(1.0 + selectedLoc) - 1] = 1;
        jlast = b_hashTbl[(int)fmod(*numTasks - 1.0, 2.0)];
        while ((jlast > 0) && (newEntry != *numTasks - 1.0)) {
          jlast = 0;
        }

        selectedLoc = b_rand() * ((*numTasks - 2.0) + 1.0);
        nleftm1 = floor(selectedLoc);
        if (rtIsNaN(nleftm1)) {
          selectedLoc = rtNaN;
        } else if (nleftm1 == 0.0) {
          selectedLoc = 0.0;
        } else {
          selectedLoc = fmod(nleftm1, 2.0);
          if (selectedLoc == 0.0) {
            selectedLoc = 0.0;
          }
        }

        j = b_hashTbl[(int)(1.0 + selectedLoc) - 1];
        while ((j > 0.0) && (newEntry != nleftm1)) {
          j = 0.0;
        }

        if (j > 0.0) {
          if (jlast > 0) {
            b_jlast = 0.0;
          } else {
            b_jlast = *numTasks - 1.0;
          }

          taskIdxs[1] = b_jlast + 1.0;
        } else {
          taskIdxs[1] = nleftm1 + 1.0;
        }
      }

      loop_ub = taskIdxToFuncReq->size[1];
      r0.f1.size[0] = 1;
      r0.f1.size[1] = loop_ub;
      for (i1 = 0; i1 < loop_ub; i1++) {
        r0.f1.data[r0.f1.size[0] * i1] = taskIdxToFuncReq->data[((int)taskIdxs[0]
          + taskIdxToFuncReq->size[0] * i1) - 1];
      }

      loop_ub = taskIdxToFuncReq->size[1];
      r1.f1.size[0] = 1;
      r1.f1.size[1] = loop_ub;
      for (i1 = 0; i1 < loop_ub; i1++) {
        r1.f1.data[r1.f1.size[0] * i1] = taskIdxToFuncReq->data[((int)taskIdxs[1]
          + taskIdxToFuncReq->size[0] * i1) - 1];
      }

      loop_ub = taskIdxToFuncReq->size[1];
      jlast = taskIdxToFuncReq->size[1];
      r2.f1.size[0] = 2;
      r2.f1.size[1] = loop_ub;
      for (i1 = 0; i1 < loop_ub; i1++) {
        r2.f1.data[r2.f1.size[0] * i1] = taskIdxToFuncReq->data[((int)taskIdxs[0]
          + taskIdxToFuncReq->size[0] * i1) - 1];
      }

      for (i1 = 0; i1 < jlast; i1++) {
        r2.f1.data[1 + r2.f1.size[0] * i1] = taskIdxToFuncReq->data[((int)
          taskIdxs[1] + taskIdxToFuncReq->size[0] * i1) - 1];
      }

      rv0[0] = r0;
      rv0[1] = r1;
      rv0[2] = r2;
      indConstraints->data[i].f1.size[0] = 1;
      indConstraints->data[i].f1.size[1] = 3;
      indConstraints->data[i].f1.data[0] = rv0[0];
      indConstraints->data[i].f1.data[1] = rv0[1];
      indConstraints->data[i].f1.data[2] = rv0[2];
    }
  }
}


void initialize_variable(void)
{
  emxInit_real_T(&func, 2);
  emxInit_real_T(&hashTbl, 1);
  emxInit_real_T(&link, 1);
  emxInit_real_T(&val, 1);
  emxInit_real_T(&loc, 1);
  emxInit_real_T(&b_taskIdxToFuncReq, 2);
}
/*
 * File trailer for randomTaskIndConditions.c
 *
 * [EOF]
 */
