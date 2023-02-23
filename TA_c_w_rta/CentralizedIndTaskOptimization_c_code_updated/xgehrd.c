/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgehrd.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "xgehrd.h"
#include "xzlarf.h"
#include "xzlarfg.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *a
 * Return Type  : void
 */
void xgehrd(emxArray_real_T *a)
{
  int n;
  signed char a_idx_0;
  double work_data[100];
  int i6;
  int i;
  int im1n;
  int in;
  double alpha1;
  int u0;
  double d0;
  n = a->size[0];
  a_idx_0 = (signed char)a->size[0];
  if (0 <= a_idx_0 - 1) {
    memset(&work_data[0], 0, (unsigned int)(a_idx_0 * (int)sizeof(double)));
  }

  i6 = a->size[0];
  for (i = 0; i <= i6 - 2; i++) {
    im1n = i * n + 2;
    in = (i + 1) * n;
    alpha1 = a->data[(i + a->size[0] * i) + 1];
    u0 = i + 3;
    if (u0 >= n) {
      u0 = n;
    }

    d0 = xzlarfg((n - i) - 1, &alpha1, a, u0 + i * n);
    a->data[(i + a->size[0] * i) + 1] = 1.0;
    xzlarf(n, (n - i) - 1, i + im1n, d0, a, in + 1, n, work_data);
    b_xzlarf((n - i) - 1, (n - i) - 1, i + im1n, d0, a, (i + in) + 2, n,
             work_data);
    a->data[(i + a->size[0] * i) + 1] = alpha1;
  }
}

/*
 * File trailer for xgehrd.c
 *
 * [EOF]
 */
