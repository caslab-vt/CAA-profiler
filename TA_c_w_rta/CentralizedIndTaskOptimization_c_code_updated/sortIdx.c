/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 30-Apr-2020 22:49:10
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "sortIdx.h"

/* Function Declarations */
static void merge(int idx_data[], double x_data[], int offset, int np, int nq,
                  int iwork_data[], double xwork_data[]);

/* Function Definitions */

/*
 * Arguments    : int idx_data[]
 *                double x_data[]
 *                int offset
 *                int np
 *                int nq
 *                int iwork_data[]
 *                double xwork_data[]
 * Return Type  : void
 */
static void merge(int idx_data[], double x_data[], int offset, int np, int nq,
                  int iwork_data[], double xwork_data[])
{
  int n_tmp;
  int iout;
  int p;
  int i6;
  int q;
  int exitg1;
  int exitg2;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i6 = offset + iout;
      iwork_data[iout] = idx_data[i6];
      xwork_data[iout] = x_data[i6];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      do {
        exitg2 = 0;
        iout++;
        if (xwork_data[p] <= xwork_data[q]) {
          idx_data[iout] = iwork_data[p];
          x_data[iout] = xwork_data[p];
          p++;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      idx_data[iout] = iwork_data[q];
      x_data[iout] = xwork_data[q];
      if (q + 1 < n_tmp) {
        q++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    q = iout - p;
    for (iout = p + 1; iout <= np; iout++) {
      i6 = q + iout;
      idx_data[i6] = iwork_data[iout - 1];
      x_data[i6] = xwork_data[iout - 1];
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
void sortIdx(double x_data[], int x_size[1], int idx_data[], int idx_size[1])
{
  signed char x_idx_0;
  int n;
  double x4[4];
  signed char idx4[4];
  int iwork_data[2];
  int ib;
  double xwork_data[2];
  int nNaNs;
  int k;
  int i3;
  signed char perm[4];
  int quartetOffset;
  int nPairs;
  int i1;
  int i4;
  double d2;
  double d3;
  x_idx_0 = (signed char)x_size[0];
  idx_size[0] = x_idx_0;
  if (0 <= x_idx_0 - 1) {
    memset(&idx_data[0], 0, (unsigned int)(x_idx_0 * (int)sizeof(int)));
  }

  if (x_size[0] != 0) {
    n = x_size[0];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    if (0 <= x_idx_0 - 1) {
      memset(&iwork_data[0], 0, (unsigned int)(x_idx_0 * (int)sizeof(int)));
    }

    ib = (signed char)x_size[0];
    if (0 <= ib - 1) {
      memset(&xwork_data[0], 0, (unsigned int)(ib * (int)sizeof(double)));
    }

    nNaNs = 0;
    ib = -1;
    for (k = 0; k < n; k++) {
      if (rtIsNaN(x_data[k])) {
        idx_data[(n - nNaNs) - 1] = k + 1;
        xwork_data[(n - nNaNs) - 1] = x_data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = (signed char)(k + 1);
        x4[ib] = x_data[k];
        if (ib + 1 == 4) {
          quartetOffset = k - nNaNs;
          if (x4[0] <= x4[1]) {
            i1 = 1;
            ib = 2;
          } else {
            i1 = 2;
            ib = 1;
          }

          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }

          d2 = x4[i1 - 1];
          d3 = x4[i3 - 1];
          if (d2 <= d3) {
            d2 = x4[ib - 1];
            if (d2 <= d3) {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i3;
              perm[3] = (signed char)i4;
            } else if (d2 <= x4[i4 - 1]) {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)ib;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)ib;
            }
          } else {
            d3 = x4[i4 - 1];
            if (d2 <= d3) {
              if (x4[ib - 1] <= d3) {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)i1;
                perm[2] = (signed char)ib;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)i1;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)ib;
              }
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)i4;
              perm[2] = (signed char)i1;
              perm[3] = (signed char)ib;
            }
          }

          i4 = perm[0] - 1;
          idx_data[quartetOffset - 3] = idx4[i4];
          ib = perm[1] - 1;
          idx_data[quartetOffset - 2] = idx4[ib];
          nPairs = perm[2] - 1;
          idx_data[quartetOffset - 1] = idx4[nPairs];
          i1 = perm[3] - 1;
          idx_data[quartetOffset] = idx4[i1];
          x_data[quartetOffset - 3] = x4[i4];
          x_data[quartetOffset - 2] = x4[ib];
          x_data[quartetOffset - 1] = x4[nPairs];
          x_data[quartetOffset] = x4[i1];
          ib = -1;
        }
      }
    }

    i3 = (n - nNaNs) - 1;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }

      for (k = 0; k <= ib; k++) {
        i4 = (i3 - ib) + k;
        idx_data[i4] = idx4[perm[k] - 1];
        x_data[i4] = x4[perm[k] - 1];
      }
    }

    ib = (nNaNs >> 1) + 1;
    for (k = 0; k <= ib - 2; k++) {
      nPairs = (i3 + k) + 1;
      i1 = idx_data[nPairs];
      i4 = (n - k) - 1;
      idx_data[nPairs] = idx_data[i4];
      idx_data[i4] = i1;
      x_data[nPairs] = xwork_data[i4];
      x_data[i4] = xwork_data[nPairs];
    }

    if ((nNaNs & 1) != 0) {
      ib += i3;
      x_data[ib] = xwork_data[ib];
    }

    i3 = x_size[0] - nNaNs;
    if (i3 > 1) {
      nPairs = i3 >> 2;
      i4 = 4;
      while (nPairs > 1) {
        if ((nPairs & 1) != 0) {
          nPairs--;
          ib = i4 * nPairs;
          i1 = i3 - ib;
          if (i1 > i4) {
            merge(idx_data, x_data, ib, i4, i1 - i4, iwork_data, xwork_data);
          }
        }

        ib = i4 << 1;
        nPairs >>= 1;
        for (k = 0; k < nPairs; k++) {
          merge(idx_data, x_data, k * ib, i4, i4, iwork_data, xwork_data);
        }

        i4 = ib;
      }

      if (i3 > i4) {
        merge(idx_data, x_data, 0, i4, i3 - i4, iwork_data, xwork_data);
      }
    }
  }
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
