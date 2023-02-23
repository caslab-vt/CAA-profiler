/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xhseqr.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "xhseqr.h"
#include "xdhseqr.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *h
 * Return Type  : int
 */
int xhseqr(emxArray_real_T *h)
{
  int info;
  int m;
  int istart;
  int jend;
  int j;
  int i;
  info = eml_dlahqr(h);
  m = h->size[0];
  if (3 < h->size[0]) {
    istart = 4;
    if (h->size[0] - 4 < h->size[1] - 1) {
      jend = h->size[0] - 3;
    } else {
      jend = h->size[1];
    }

    for (j = 0; j < jend; j++) {
      for (i = istart; i <= m; i++) {
        h->data[(i + h->size[0] * j) - 1] = 0.0;
      }

      istart++;
    }
  }

  return info;
}

/*
 * File trailer for xhseqr.c
 *
 * [EOF]
 */
