/*
  Test vectorization for simple arithemetic statements.
*/
#include "rose_simd.h" 

int main()
{
  int i_nom_1_strip_10;
  int i_nom_1;
  float a[16];
  __SIMD *a_SIMD = (__SIMD *)a;
  float b[16];
  __SIMD *b_SIMD = (__SIMD *)b;
  float c[16];
  __SIMD *c_SIMD = (__SIMD *)c;
  int n = 16;
  __SIMDi n_SIMD;
  
#pragma SIMD
  n_SIMD = _SIMD_splats_epi32(n);
  for (i_nom_1 = 0, i_nom_1_strip_10 = i_nom_1; i_nom_1 <= n - 1; (i_nom_1 += 4 , i_nom_1_strip_10 += 1)) {
    c_SIMD[i_nom_1_strip_10] = _SIMD_add_ps(a_SIMD[i_nom_1_strip_10],b_SIMD[i_nom_1_strip_10]);
  }
  n = _SIMD_extract_epi32(n_SIMD,3);
  for (int i = 0; i < n; i++) {
    c[i] = a[i] + b[i];
  }
}
