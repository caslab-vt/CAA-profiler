/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xdhseqr.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "xdhseqr.h"
#include "xrot.h"
#include "xdlanv2.h"
#include "xzlarfg.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *h
 * Return Type  : int
 */
int eml_dlahqr(emxArray_real_T *h)
{
  int info;
  int n;
  int ldh;
  double v[3];
  int nr;
  int j;
  int itmax;
  double SMLNUM;
  int i;
  boolean_T exitg1;
  int L;
  boolean_T goto150;
  int its;
  boolean_T exitg2;
  int k;
  boolean_T exitg3;
  double d1;
  double d2;
  double tst;
  double htmp1;
  double aa;
  double ab;
  double ba;
  double h22;
  double s;
  int m;
  double b_SMLNUM;
  int b_k;
  int hoffset;
  n = h->size[0];
  ldh = h->size[0];
  info = 0;
  if (1 != h->size[0]) {
    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 0.0;
    nr = h->size[0];
    for (j = 0; j <= nr - 4; j++) {
      h->data[(j + h->size[0] * j) + 2] = 0.0;
      h->data[(j + h->size[0] * j) + 3] = 0.0;
    }

    if (1 <= n - 2) {
      h->data[(n + h->size[0] * (n - 3)) - 1] = 0.0;
    }

    if (10 > n) {
      nr = 10;
    } else {
      nr = n;
    }

    itmax = 30 * nr;
    SMLNUM = 2.2250738585072014E-308 * ((double)n / 2.2204460492503131E-16);
    i = n - 1;
    exitg1 = false;
    while ((!exitg1) && (i + 1 >= 1)) {
      L = 1;
      goto150 = false;
      its = 0;
      exitg2 = false;
      while ((!exitg2) && (its <= itmax)) {
        k = i;
        exitg3 = false;
        while ((!exitg3) && ((k + 1 > L) && (!(fabs(h->data[k + h->size[0] * (k
                    - 1)]) <= SMLNUM)))) {
          tst = fabs(h->data[(k + h->size[0] * (k - 1)) - 1]) + fabs(h->data[k +
            h->size[0] * k]);
          if (tst == 0.0) {
            if (k - 1 >= 1) {
              tst = fabs(h->data[(k + h->size[0] * (k - 2)) - 1]);
            }

            if (k + 2 <= n) {
              tst += fabs(h->data[(k + h->size[0] * k) + 1]);
            }
          }

          if (fabs(h->data[k + h->size[0] * (k - 1)]) <= 2.2204460492503131E-16 *
              tst) {
            htmp1 = fabs(h->data[k + h->size[0] * (k - 1)]);
            tst = fabs(h->data[(k + h->size[0] * k) - 1]);
            if (htmp1 > tst) {
              ab = htmp1;
              ba = tst;
            } else {
              ab = tst;
              ba = htmp1;
            }

            htmp1 = fabs(h->data[k + h->size[0] * k]);
            tst = fabs(h->data[(k + h->size[0] * (k - 1)) - 1] - h->data[k +
                       h->size[0] * k]);
            if (htmp1 > tst) {
              aa = htmp1;
              htmp1 = tst;
            } else {
              aa = tst;
            }

            s = aa + ab;
            tst = 2.2204460492503131E-16 * (htmp1 * (aa / s));
            if ((SMLNUM > tst) || rtIsNaN(tst)) {
              b_SMLNUM = SMLNUM;
            } else {
              b_SMLNUM = tst;
            }

            if (ba * (ab / s) <= b_SMLNUM) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }

        L = k + 1;
        if (k + 1 > 1) {
          h->data[k + h->size[0] * (k - 1)] = 0.0;
        }

        if (k + 1 >= i) {
          goto150 = true;
          exitg2 = true;
        } else {
          if (its == 10) {
            s = fabs(h->data[(k + h->size[0] * k) + 1]) + fabs(h->data[(k +
              h->size[0] * (k + 1)) + 2]);
            tst = 0.75 * s + h->data[k + h->size[0] * k];
            aa = -0.4375 * s;
            htmp1 = s;
            h22 = tst;
          } else if (its == 20) {
            s = fabs(h->data[i + h->size[0] * (i - 1)]) + fabs(h->data[(i +
              h->size[0] * (i - 2)) - 1]);
            tst = 0.75 * s + h->data[i + h->size[0] * i];
            aa = -0.4375 * s;
            htmp1 = s;
            h22 = tst;
          } else {
            tst = h->data[(i + h->size[0] * (i - 1)) - 1];
            htmp1 = h->data[i + h->size[0] * (i - 1)];
            aa = h->data[(i + h->size[0] * i) - 1];
            h22 = h->data[i + h->size[0] * i];
          }

          s = ((fabs(tst) + fabs(aa)) + fabs(htmp1)) + fabs(h22);
          if (s == 0.0) {
            ba = 0.0;
            tst = 0.0;
            ab = 0.0;
            htmp1 = 0.0;
          } else {
            tst /= s;
            htmp1 /= s;
            aa /= s;
            h22 /= s;
            ab = (tst + h22) / 2.0;
            tst = (tst - ab) * (h22 - ab) - aa * htmp1;
            htmp1 = sqrt(fabs(tst));
            if (tst >= 0.0) {
              ba = ab * s;
              ab = ba;
              tst = htmp1 * s;
              htmp1 = -tst;
            } else {
              ba = ab + htmp1;
              ab -= htmp1;
              if (fabs(ba - h22) <= fabs(ab - h22)) {
                ba *= s;
                ab = ba;
              } else {
                ab *= s;
                ba = ab;
              }

              tst = 0.0;
              htmp1 = 0.0;
            }
          }

          m = i - 1;
          exitg3 = false;
          while ((!exitg3) && (m >= k + 1)) {
            s = (fabs(h->data[(m + h->size[0] * (m - 1)) - 1] - ab) + fabs(htmp1))
              + fabs(h->data[m + h->size[0] * (m - 1)]);
            aa = h->data[m + h->size[0] * (m - 1)] / s;
            v[0] = (aa * h->data[(m + h->size[0] * m) - 1] + (h->data[(m +
                      h->size[0] * (m - 1)) - 1] - ba) * ((h->data[(m + h->size
                       [0] * (m - 1)) - 1] - ab) / s)) - tst * (htmp1 / s);
            v[1] = aa * (((h->data[(m + h->size[0] * (m - 1)) - 1] + h->data[m +
                           h->size[0] * m]) - ba) - ab);
            v[2] = aa * h->data[(m + h->size[0] * m) + 1];
            s = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
            v[0] /= s;
            v[1] /= s;
            v[2] /= s;
            if ((m == k + 1) || (fabs(h->data[(m + h->size[0] * (m - 2)) - 1]) *
                                 (fabs(v[1]) + fabs(v[2])) <=
                                 2.2204460492503131E-16 * fabs(v[0]) * ((fabs
                   (h->data[(m + h->size[0] * (m - 2)) - 2]) + fabs(h->data[(m +
                     h->size[0] * (m - 1)) - 1])) + fabs(h->data[m + h->size[0] *
                   m])))) {
              exitg3 = true;
            } else {
              m--;
            }
          }

          for (b_k = m; b_k <= i; b_k++) {
            nr = (i - b_k) + 2;
            if (3 < nr) {
              nr = 3;
            }

            if (b_k > m) {
              hoffset = (b_k + ldh * (b_k - 2)) - 1;
              for (j = 0; j < nr; j++) {
                v[j] = h->data[j + hoffset];
              }
            }

            tst = v[0];
            ab = b_xzlarfg(nr, &tst, v);
            v[0] = tst;
            if (b_k > m) {
              h->data[(b_k + h->size[0] * (b_k - 2)) - 1] = tst;
              h->data[b_k + h->size[0] * (b_k - 2)] = 0.0;
              if (b_k < i) {
                h->data[(b_k + h->size[0] * (b_k - 2)) + 1] = 0.0;
              }
            } else {
              if (m > k + 1) {
                h->data[(b_k + h->size[0] * (b_k - 2)) - 1] *= 1.0 - ab;
              }
            }

            d1 = v[1];
            tst = ab * v[1];
            if (nr == 3) {
              d2 = v[2];
              aa = ab * v[2];
              for (j = b_k; j <= n; j++) {
                htmp1 = (h->data[(b_k + h->size[0] * (j - 1)) - 1] + d1 *
                         h->data[b_k + h->size[0] * (j - 1)]) + d2 * h->data
                  [(b_k + h->size[0] * (j - 1)) + 1];
                h->data[(b_k + h->size[0] * (j - 1)) - 1] -= htmp1 * ab;
                h->data[b_k + h->size[0] * (j - 1)] -= htmp1 * tst;
                h->data[(b_k + h->size[0] * (j - 1)) + 1] -= htmp1 * aa;
              }

              if (b_k + 3 < i + 1) {
                nr = b_k + 2;
              } else {
                nr = i;
              }

              for (j = 0; j <= nr; j++) {
                htmp1 = (h->data[j + h->size[0] * (b_k - 1)] + d1 * h->data[j +
                         h->size[0] * b_k]) + d2 * h->data[j + h->size[0] * (b_k
                  + 1)];
                h->data[j + h->size[0] * (b_k - 1)] -= htmp1 * ab;
                h->data[j + h->size[0] * b_k] -= htmp1 * tst;
                h->data[j + h->size[0] * (b_k + 1)] -= htmp1 * aa;
              }
            } else {
              if (nr == 2) {
                for (j = b_k; j <= n; j++) {
                  htmp1 = h->data[(b_k + h->size[0] * (j - 1)) - 1] + d1 *
                    h->data[b_k + h->size[0] * (j - 1)];
                  h->data[(b_k + h->size[0] * (j - 1)) - 1] -= htmp1 * ab;
                  h->data[b_k + h->size[0] * (j - 1)] -= htmp1 * tst;
                }

                for (j = 0; j <= i; j++) {
                  htmp1 = h->data[j + h->size[0] * (b_k - 1)] + d1 * h->data[j +
                    h->size[0] * b_k];
                  h->data[j + h->size[0] * (b_k - 1)] -= htmp1 * ab;
                  h->data[j + h->size[0] * b_k] -= htmp1 * tst;
                }
              }
            }
          }

          its++;
        }
      }

      if (!goto150) {
        info = i + 1;
        exitg1 = true;
      } else {
        if ((L != i + 1) && (L == i)) {
          d1 = h->data[(i + h->size[0] * i) - 1];
          d2 = h->data[i + h->size[0] * (i - 1)];
          tst = h->data[i + h->size[0] * i];
          xdlanv2(&h->data[(i + h->size[0] * (i - 1)) - 1], &d1, &d2, &tst,
                  &htmp1, &aa, &ab, &ba, &h22, &s);
          h->data[(i + h->size[0] * i) - 1] = d1;
          h->data[i + h->size[0] * (i - 1)] = d2;
          h->data[i + h->size[0] * i] = tst;
          if (n > i + 1) {
            xrot((n - i) - 1, h, i + (i + 1) * ldh, ldh, (i + (i + 1) * ldh) + 1,
                 ldh, h22, s);
          }

          b_xrot(i - 1, h, 1 + (i - 1) * ldh, 1 + i * ldh, h22, s);
        }

        i = L - 2;
      }
    }
  }

  return info;
}

/*
 * File trailer for xdhseqr.c
 *
 * [EOF]
 */
