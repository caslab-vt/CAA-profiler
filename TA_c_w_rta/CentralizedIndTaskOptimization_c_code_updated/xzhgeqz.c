/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzhgeqz.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "xzhgeqz.h"
#include "centralizedTaskIndOptimization_emxutil.h"
#include "xzlartg.h"
#include "sqrt.h"
#include "mod.h"
#include "xzlanhs.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_creal_T *A
 *                int ilo
 *                int ihi
 *                int *info
 *                creal_T alpha1_data[]
 *                int alpha1_size[1]
 *                creal_T beta1_data[]
 *                int beta1_size[1]
 * Return Type  : void
 */
void xzhgeqz(const emxArray_creal_T *A, int ilo, int ihi, int *info, creal_T
             alpha1_data[], int alpha1_size[1], creal_T beta1_data[], int
             beta1_size[1])
{
  emxArray_creal_T *b_A;
  int jm1;
  int jp1;
  int n;
  double eshift_re;
  double eshift_im;
  creal_T ctemp;
  double anorm;
  double temp;
  double b_atol;
  double ascale;
  double bscale;
  boolean_T failed;
  int j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int ifirst;
  int istart;
  int ilast;
  int ilastm1;
  int ifrstm;
  int ilastm;
  int iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int jiter;
  int exitg1;
  boolean_T b_guard1 = false;
  boolean_T guard3 = false;
  boolean_T exitg2;
  creal_T b_ascale;
  double c;
  creal_T shift;
  double ascale_im;
  creal_T c_A;
  double ad22_re;
  double ad22_im;
  double shift_im;
  double t1_re;
  double t1_im;
  double t1_im_tmp;
  double tempr;
  emxInit_creal_T(&b_A, 2);
  jm1 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_creal_T(b_A, jm1);
  jp1 = A->size[0] * A->size[1];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    b_A->data[jm1] = A->data[jm1];
  }

  *info = 0;
  if ((A->size[0] == 1) && (A->size[1] == 1)) {
    ihi = 1;
  }

  n = A->size[0];
  alpha1_size[0] = A->size[0];
  jp1 = A->size[0];
  if (0 <= jp1 - 1) {
    memset(&alpha1_data[0], 0, (unsigned int)(jp1 * (int)sizeof(creal_T)));
  }

  beta1_size[0] = A->size[0];
  jp1 = A->size[0];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    beta1_data[jm1].re = 1.0;
    beta1_data[jm1].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = xzlanhs(A, ilo, ihi);
  temp = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (temp > 2.2250738585072014E-308) {
    b_atol = temp;
  }

  temp = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    temp = anorm;
  }

  ascale = 1.0 / temp;
  temp = A->size[0];
  c_sqrt(&temp);
  bscale = 1.0 / temp;
  failed = true;
  jm1 = ihi + 1;
  for (j = jm1; j <= n; j++) {
    alpha1_data[j - 1] = A->data[(j + A->size[0] * (j - 1)) - 1];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    ifrstm = ilo;
    ilastm = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
        b_guard1 = false;
        if (ilast + 1 == ilo) {
          goto60 = true;
          b_guard1 = true;
        } else if (fabs(b_A->data[ilast + b_A->size[0] * ilastm1].re) + fabs
                   (b_A->data[ilast + b_A->size[0] * ilastm1].im) <= b_atol) {
          b_A->data[ilast + b_A->size[0] * ilastm1].re = 0.0;
          b_A->data[ilast + b_A->size[0] * ilastm1].im = 0.0;
          goto60 = true;
          b_guard1 = true;
        } else {
          j = ilastm1;
          guard3 = false;
          exitg2 = false;
          while ((!exitg2) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              guard3 = true;
              exitg2 = true;
            } else if (fabs(b_A->data[j + b_A->size[0] * (j - 1)].re) + fabs
                       (b_A->data[j + b_A->size[0] * (j - 1)].im) <= b_atol) {
              b_A->data[j + b_A->size[0] * (j - 1)].re = 0.0;
              b_A->data[j + b_A->size[0] * (j - 1)].im = 0.0;
              guard3 = true;
              exitg2 = true;
            } else {
              j--;
              guard3 = false;
            }
          }

          if (guard3) {
            ifirst = j + 1;
            goto70 = true;
          }

          if (goto70) {
            b_guard1 = true;
          } else {
            jp1 = alpha1_size[0];
            for (jm1 = 0; jm1 < jp1; jm1++) {
              alpha1_data[jm1].re = rtNaN;
              alpha1_data[jm1].im = 0.0;
            }

            jp1 = beta1_size[0];
            for (jm1 = 0; jm1 < jp1; jm1++) {
              beta1_data[jm1].re = rtNaN;
              beta1_data[jm1].im = 0.0;
            }

            *info = 1;
            exitg1 = 1;
          }
        }

        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1_data[ilast] = b_A->data[ilast + b_A->size[0] * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              ilastm = ilast + 1;
              if (ifrstm > ilast + 1) {
                ifrstm = ilo;
              }

              jiter++;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              ifrstm = ifirst;
              if (c_mod(iiter) != 0) {
                anorm = ascale * b_A->data[ilastm1 + b_A->size[0] * ilastm1].re;
                temp = ascale * b_A->data[ilastm1 + b_A->size[0] * ilastm1].im;
                if (temp == 0.0) {
                  shift.re = anorm / bscale;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = temp / bscale;
                } else {
                  shift.re = anorm / bscale;
                  shift.im = temp / bscale;
                }

                anorm = ascale * b_A->data[ilast + b_A->size[0] * ilast].re;
                temp = ascale * b_A->data[ilast + b_A->size[0] * ilast].im;
                if (temp == 0.0) {
                  ad22_re = anorm / bscale;
                  ad22_im = 0.0;
                } else if (anorm == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = temp / bscale;
                } else {
                  ad22_re = anorm / bscale;
                  ad22_im = temp / bscale;
                }

                t1_re = 0.5 * (shift.re + ad22_re);
                t1_im = 0.5 * (shift.im + ad22_im);
                t1_im_tmp = t1_re * t1_im;
                anorm = ascale * b_A->data[ilastm1 + b_A->size[0] * ilast].re;
                temp = ascale * b_A->data[ilastm1 + b_A->size[0] * ilast].im;
                if (temp == 0.0) {
                  c = anorm / bscale;
                  ascale_im = 0.0;
                } else if (anorm == 0.0) {
                  c = 0.0;
                  ascale_im = temp / bscale;
                } else {
                  c = anorm / bscale;
                  ascale_im = temp / bscale;
                }

                anorm = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].re;
                temp = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].im;
                if (temp == 0.0) {
                  tempr = anorm / bscale;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  tempr = 0.0;
                  anorm = temp / bscale;
                } else {
                  tempr = anorm / bscale;
                  anorm = temp / bscale;
                }

                temp = shift.re * ad22_re - shift.im * ad22_im;
                shift_im = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) + (c * tempr -
                  ascale_im * anorm)) - temp;
                shift.im = ((t1_im_tmp + t1_im_tmp) + (c * anorm + ascale_im *
                  tempr)) - shift_im;
                b_sqrt(&shift);
                if ((t1_re - ad22_re) * shift.re + (t1_im - ad22_im) * shift.im <=
                    0.0) {
                  shift.re += t1_re;
                  shift.im += t1_im;
                } else {
                  shift.re = t1_re - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                anorm = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].re;
                temp = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].im;
                if (temp == 0.0) {
                  c = anorm / bscale;
                  ascale_im = 0.0;
                } else if (anorm == 0.0) {
                  c = 0.0;
                  ascale_im = temp / bscale;
                } else {
                  c = anorm / bscale;
                  ascale_im = temp / bscale;
                }

                eshift_re += c;
                eshift_im += ascale_im;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp.re = ascale * b_A->data[j + b_A->size[0] * j].re -
                  shift.re * bscale;
                ctemp.im = ascale * b_A->data[j + b_A->size[0] * j].im -
                  shift.im * bscale;
                temp = fabs(ctemp.re) + fabs(ctemp.im);
                anorm = ascale * (fabs(b_A->data[jp1 + b_A->size[0] * j].re) +
                                  fabs(b_A->data[jp1 + b_A->size[0] * j].im));
                tempr = temp;
                if (anorm > temp) {
                  tempr = anorm;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  temp /= tempr;
                  anorm /= tempr;
                }

                if ((fabs(b_A->data[j + b_A->size[0] * (j - 1)].re) + fabs
                     (b_A->data[j + b_A->size[0] * (j - 1)].im)) * anorm <= temp
                    * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                ctemp.re = ascale * b_A->data[(ifirst + b_A->size[0] * (ifirst -
                  1)) - 1].re - shift.re * bscale;
                ctemp.im = ascale * b_A->data[(ifirst + b_A->size[0] * (ifirst -
                  1)) - 1].im - shift.im * bscale;
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              b_ascale.re = ascale * b_A->data[istart + b_A->size[0] * (istart -
                1)].re;
              b_ascale.im = ascale * b_A->data[istart + b_A->size[0] * (istart -
                1)].im;
              b_xzlartg(ctemp, b_ascale, &c, &shift);
              j = istart;
              jm1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  b_ascale = b_A->data[(j + b_A->size[0] * jm1) - 1];
                  c_A = b_A->data[j + b_A->size[0] * jm1];
                  xzlartg(b_ascale, c_A, &c, &shift, &b_A->data[(j + b_A->size[0]
                           * jm1) - 1]);
                  b_A->data[j + b_A->size[0] * jm1].re = 0.0;
                  b_A->data[j + b_A->size[0] * jm1].im = 0.0;
                }

                for (n = j; n <= ilastm; n++) {
                  temp = shift.re * b_A->data[j + b_A->size[0] * (n - 1)].re -
                    shift.im * b_A->data[j + b_A->size[0] * (n - 1)].im;
                  shift_im = shift.re * b_A->data[j + b_A->size[0] * (n - 1)].im
                    + shift.im * b_A->data[j + b_A->size[0] * (n - 1)].re;
                  ad22_re = c * b_A->data[(j + b_A->size[0] * (n - 1)) - 1].re +
                    temp;
                  ad22_im = c * b_A->data[(j + b_A->size[0] * (n - 1)) - 1].im +
                    shift_im;
                  anorm = b_A->data[(j + b_A->size[0] * (n - 1)) - 1].re;
                  temp = b_A->data[(j + b_A->size[0] * (n - 1)) - 1].im;
                  tempr = b_A->data[(j + b_A->size[0] * (n - 1)) - 1].im;
                  shift_im = b_A->data[(j + b_A->size[0] * (n - 1)) - 1].re;
                  b_A->data[j + b_A->size[0] * (n - 1)].re = c * b_A->data[j +
                    b_A->size[0] * (n - 1)].re - (shift.re * anorm + shift.im *
                    temp);
                  b_A->data[j + b_A->size[0] * (n - 1)].im = c * b_A->data[j +
                    b_A->size[0] * (n - 1)].im - (shift.re * tempr - shift.im *
                    shift_im);
                  b_A->data[(j + b_A->size[0] * (n - 1)) - 1].re = ad22_re;
                  b_A->data[(j + b_A->size[0] * (n - 1)) - 1].im = ad22_im;
                }

                shift.re = -shift.re;
                shift.im = -shift.im;
                n = j;
                if (ilast + 1 < j + 2) {
                  n = ilast - 1;
                }

                for (jp1 = ifrstm; jp1 <= n + 2; jp1++) {
                  temp = shift.re * b_A->data[(jp1 + b_A->size[0] * (j - 1)) - 1]
                    .re - shift.im * b_A->data[(jp1 + b_A->size[0] * (j - 1)) -
                    1].im;
                  shift_im = shift.re * b_A->data[(jp1 + b_A->size[0] * (j - 1))
                    - 1].im + shift.im * b_A->data[(jp1 + b_A->size[0] * (j - 1))
                    - 1].re;
                  ad22_re = c * b_A->data[(jp1 + b_A->size[0] * j) - 1].re +
                    temp;
                  ad22_im = c * b_A->data[(jp1 + b_A->size[0] * j) - 1].im +
                    shift_im;
                  anorm = b_A->data[(jp1 + b_A->size[0] * j) - 1].re;
                  temp = b_A->data[(jp1 + b_A->size[0] * j) - 1].im;
                  tempr = b_A->data[(jp1 + b_A->size[0] * j) - 1].im;
                  shift_im = b_A->data[(jp1 + b_A->size[0] * j) - 1].re;
                  b_A->data[(jp1 + b_A->size[0] * (j - 1)) - 1].re = c *
                    b_A->data[(jp1 + b_A->size[0] * (j - 1)) - 1].re - (shift.re
                    * anorm + shift.im * temp);
                  b_A->data[(jp1 + b_A->size[0] * (j - 1)) - 1].im = c *
                    b_A->data[(jp1 + b_A->size[0] * (j - 1)) - 1].im - (shift.re
                    * tempr - shift.im * shift_im);
                  b_A->data[(jp1 + b_A->size[0] * j) - 1].re = ad22_re;
                  b_A->data[(jp1 + b_A->size[0] * j) - 1].im = ad22_im;
                }

                jm1 = j - 1;
                j++;
              }
            }

            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 <= ilast; jp1++) {
        alpha1_data[jp1].re = rtNaN;
        alpha1_data[jp1].im = 0.0;
        beta1_data[jp1].re = rtNaN;
        beta1_data[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (j = 0; j <= ilo - 2; j++) {
      alpha1_data[j] = b_A->data[j + b_A->size[0] * j];
    }
  }

  emxFree_creal_T(&b_A);
}

/*
 * File trailer for xzhgeqz.c
 *
 * [EOF]
 */
