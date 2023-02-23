/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ishermitian.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "ishermitian.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 * Return Type  : boolean_T
 */
boolean_T ishermitian(const emxArray_real_T *A)
{
  boolean_T p;
  int j;
  boolean_T exitg2;
  int i;
  int exitg1;
  p = (A->size[0] == A->size[1]);
  if (p) {
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j <= A->size[1] - 1)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= j) {
          if (!(A->data[i + A->size[0] * j] == A->data[j + A->size[0] * i])) {
            p = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  }

  return p;
}

/*
 * File trailer for ishermitian.c
 *
 * [EOF]
 */
