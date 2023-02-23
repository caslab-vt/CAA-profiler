/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort1.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 29-Apr-2020 19:47:55
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "sort1.h"
#include "sortLE.h"
#include "sortIdx.h"

/* Function Definitions */

/*
 * Arguments    : creal_T x_data[]
 *                int x_size[2]
 * Return Type  : void
 */
void sort(creal_T x_data[], int x_size[2])
{
  int n;
  int i;
  int idx_data[5];
  int k;
  int i2;
  creal_T xwork_data[5];
  int j;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  int iwork_data[5];
  n = x_size[1] + 1;
  i = x_size[1];
  if (0 <= i - 1) {
    memset(&idx_data[0], 0, (unsigned int)(i * (int)sizeof(int)));
  }

  i = x_size[1] - 1;
  for (k = 1; k <= i; k += 2) {
    if (sortLE(x_data, k, k + 1)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }

  if ((x_size[1] & 1) != 0) {
    idx_data[x_size[1] - 1] = x_size[1];
  }

  i = 2;
  while (i < n - 1) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n) {
        qEnd = n;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if (sortLE(x_data, idx_data[p - 1], idx_data[q - 1])) {
          iwork_data[k] = idx_data[p - 1];
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = idx_data[q - 1];
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }

      j = qEnd;
    }

    i = i2;
  }

  if (0 <= n - 2) {
    memcpy(&xwork_data[0], &x_data[0], (unsigned int)((n + -1) * (int)sizeof
            (creal_T)));
  }

  for (k = 0; k <= n - 2; k++) {
    x_data[k] = xwork_data[idx_data[k] - 1];
  }
}



void b_sort(double x_data[], int x_size[2], int idx_data[], int idx_size[2])
{
  int vlen;
  int vwork_size[1];
  int j;
  int k;
  double vwork_data[2];
  int iidx_data[2];
  int iidx_size[1];
  vlen = x_size[1] - 1;
  vwork_size[0] = (signed char)x_size[1];
  idx_size[0] = 1;
  idx_size[1] = (signed char)x_size[1];
  for (j = 0; j < 1; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[k];
    }

    sortIdx(vwork_data, vwork_size, iidx_data, iidx_size);
    for (k = 0; k <= vlen; k++) {
      x_data[k] = vwork_data[k];
      idx_data[k] = iidx_data[k];
    }
  }
}

/*
 * Arguments    : double x_data[]
 *                int x_size[1]
 *                int idx_data[]
 *                int idx_size[1]
 * Return Type  : void
 */
void c_sort(double x_data[], int x_size[1], int idx_data[], int idx_size[1])
{
  int dim;
  int i7;
  int vlen;
  int vwork_size[1];
  int vstride;
  int k;
  double vwork_data[2];
  int iidx_data[2];
  int iidx_size[1];
  dim = 0;
  if (x_size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i7 = x_size[0];
  } else {
    i7 = 1;
  }

  vlen = i7 - 1;
  vwork_size[0] = (signed char)i7;
  idx_size[0] = (signed char)x_size[0];
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x_size[0];
  }

  for (dim = 0; dim < vstride; dim++) {
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[dim + k * vstride];
    }

    sortIdx(vwork_data, vwork_size, iidx_data, iidx_size);
    for (k = 0; k <= vlen; k++) {
      i7 = dim + k * vstride;
      x_data[i7] = vwork_data[k];
      idx_data[i7] = iidx_data[k];
    }
  }
}
/*
 * File trailer for sort1.c
 *
 * [EOF]
 */
