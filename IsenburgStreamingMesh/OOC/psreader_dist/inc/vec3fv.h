/*
===============================================================================

  FILE:  vec3fv.h
  
  CONTENTS:
  
    inlined functions for common vec3fv operations
  
  PROGRAMMERS:
  
    martin isenburg@cs.unc.edu  (with ideas stolen from Kenny Hoff)
  
  COPYRIGHT:
  
    copyright (C) 2000  martin isenburg@cs.unc.edu
    
    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
    12 August 2004 -- added copy with endian swap
    28 June 2000 -- created for GI 2000 submission
  
===============================================================================
*/
#ifndef VEC3FV_H
#define VEC3FV_H

#include <math.h>

inline void VecZero3fv(float v[3]);

inline void VecSet3fv(float v[3], float x, float y, float z);
inline void VecSet3fv_swap_endian(float v[3], float x, float y, float z);

inline void VecCopy3fv(float v[3], const float a[3]);
inline void VecCopy3fv_swap_endian(float v[3], const float a[3]);

inline float VecMin3fv(const float v[3]);
inline float VecMax3fv(const float v[3]);

inline void VecSelfScalarMult3fv(float v[3], float s);
inline void VecSelfScalarDiv3fv(float v[3], float s);
inline void VecSelfNegate3fv(float v[3]);

inline void VecSelfAdd3fv(float v[3], const float a[3]);
inline void VecSelfSubtract3fv(float v[3], const float a[3]);

inline void VecAdd3fv(float v[3], const float a[3], const float b[3]);
inline void VecSubtract3fv(float v[3], const float a[3], const float b[3]);
inline void VecAbsDiff3fv(float v[3], const float a[3], const float b[3]);
inline void VecScalarDiv3fv(float v[3], const float a[3], float s);

inline void VecParallelogram3fv(float v[3], const float a[3], const float b[3], const float c[3]);

inline void VecAddScalarMult3fv(float v[3], const float a[3], const float b[3], float s);
inline void VecSelfAddScalarMult3fv(float v[3], float a[3], float s);

inline int VecEqual3fv(const float a[3], const float b[3]);

inline void VecSelfNormalize3fv(float v[3]);
inline void VecNormalize3fv(float v[3], const float a[3]);

inline float VecLength3fv(const float v[3]);
inline float VecDistance3fv(const float a[3], const float b[3]);
inline float VecSquaredLength3fv(const float v[3]);
inline float VecDotProd3fv(const float a[3], const float b[3]);

inline void VecCrossProd3fv(float v[3], const float a[3], const float b[3]);

inline void VecUpdateMinMax3fv(float min[3], float max[3], const float v[3]);
inline void VecUpdateMin3fv(float min[3], const float v[3]);
inline void VecUpdateMax3fv(float max[3], const float v[3]);

inline void VecCcwNormal3fv(float n[3], const float a[3], const float b[3], const float c[3]);
inline void VecCwNormal3fv(float n[3], const float a[3], const float b[3], const float c[3]);

inline void VecCcwNormNormal3fv(float n[3], const float a[3], const float b[3], const float c[3]);
inline void VecCwNormNormal3fv(float n[3], const float a[3], const float b[3], const float c[3]);

inline void VecCarthesianToSpherical3fv(float v[3], const float a[3]);
inline void VecSphericalToCarthesian3fv(float v[3], const float a[3]);

inline void VecZero3fv(float v[3])
{
  v[0] = 0.0f;
  v[1] = 0.0f;
  v[2] = 0.0f;
}

inline void VecSet3fv(float v[3], float x, float y, float z)
{
  v[0] = x;
  v[1] = y;
  v[2] = z;
}

inline void VecSet3fv_swap_endian(float v[3], float x, float y, float z)
{
  ((char*)v)[0] = ((const char*)&x)[3];
  ((char*)v)[1] = ((const char*)&x)[2];
  ((char*)v)[2] = ((const char*)&x)[1];
  ((char*)v)[3] = ((const char*)&x)[0];
  ((char*)v)[4] = ((const char*)&y)[3];
  ((char*)v)[5] = ((const char*)&y)[2];
  ((char*)v)[6] = ((const char*)&y)[1];
  ((char*)v)[7] = ((const char*)&y)[0];
  ((char*)v)[8] = ((const char*)&z)[3];
  ((char*)v)[9] = ((const char*)&z)[2];
  ((char*)v)[10] = ((const char*)&z)[1];
  ((char*)v)[11] = ((const char*)&z)[0];
}

inline void VecCopy3fv(float v[3], const float a[3])
{
  v[0] = a[0];
  v[1] = a[1];
  v[2] = a[2];
}

inline void VecCopy3fv_swap_endian(float v[3], const float a[3])
{
  ((char*)v)[0] = ((const char*)a)[3];
  ((char*)v)[1] = ((const char*)a)[2];
  ((char*)v)[2] = ((const char*)a)[1];
  ((char*)v)[3] = ((const char*)a)[0];
  ((char*)v)[4] = ((const char*)a)[7];
  ((char*)v)[5] = ((const char*)a)[6];
  ((char*)v)[6] = ((const char*)a)[5];
  ((char*)v)[7] = ((const char*)a)[4];
  ((char*)v)[8] = ((const char*)a)[11];
  ((char*)v)[9] = ((const char*)a)[10];
  ((char*)v)[10] = ((const char*)a)[9];
  ((char*)v)[11] = ((const char*)a)[8];
}

inline float VecMin3fv(const float v[3])
{
  if (v[0] < v[1]) return ((v[0] < v[2]) ? v[0] : v[2]);
  else return ((v[1] < v[2]) ? v[1] : v[2]);
}

inline float VecMax3fv(const float v[3])
{
  if (v[0] > v[1]) return ((v[0] > v[2]) ? v[0] : v[2]);
  else return ((v[1] > v[2]) ? v[1] : v[2]);
}

inline void VecSelfScalarMult3fv(float v[3], float s)
{
  v[0] *= s;
  v[1] *= s;
  v[2] *= s;
}

inline void VecSelfScalarDiv3fv(float v[3], float s)
{
  v[0] /= s;
  v[1] /= s;
  v[2] /= s;
}

inline void VecSelfNegate3fv(float v[3])
{
  v[0] = -v[0];
  v[1] = -v[1];
  v[2] = -v[2];
}

inline void VecSelfAdd3fv(float v[3], const float a[3])
{
  v[0] += a[0];
  v[1] += a[1];
  v[2] += a[2];
}

inline void VecSelfSubtract3fv(float v[3], const float a[3])
{
  v[0] -= a[0];
  v[1] -= a[1];
  v[2] -= a[2];
}

inline void VecAdd3fv(float v[3], const float a[3], const float b[3])
{
  v[0] = a[0] + b[0];
  v[1] = a[1] + b[1];
  v[2] = a[2] + b[2];
}

inline void VecSubtract3fv(float v[3], const float a[3], const float b[3])
{
  v[0] = a[0] - b[0];
  v[1] = a[1] - b[1];
  v[2] = a[2] - b[2];
}

inline void VecAbsDiff3fv(float v[3], const float a[3], const float b[3])
{
  v[0] = a[0] - b[0];
  v[1] = a[1] - b[1];
  v[2] = a[2] - b[2];
  if (v[0] < 0.0f) v[0] = -v[0];
  if (v[1] < 0.0f) v[1] = -v[1];
  if (v[2] < 0.0f) v[2] = -v[2];
}

inline void VecScalarDiv3fv(float v[3], const float a[3], float s)
{
  v[0] = a[0]/s;
  v[1] = a[1]/s;
  v[2] = a[2]/s;
}

inline void VecParallelogram3fv(float v[3], const float a[3], const float b[3], const float c[3])
{
  v[0] = a[0] - b[0] + c[0];
  v[1] = a[1] - b[1] + c[1];
  v[2] = a[2] - b[2] + c[2];
}

inline void VecAddScalarMult3fv(float v[3], const float a[3], const float b[3], float s)
{
  v[0] = a[0] + (s * b[0]);
  v[1] = a[1] + (s * b[1]);
  v[2] = a[2] + (s * b[2]);
}

inline void VecSelfAddScalarMult3fv(float v[3], const float a[3], float s)
{
  v[0] += (s * a[0]);
  v[1] += (s * a[1]);
  v[2] += (s * a[2]);
}

inline float VecLength3fv(const float v[3])
{
  return( (float)sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]) );
}

inline float VecDistance3fv(const float a[3], const float b[3])
{
  return( (float)sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]) + (a[2]-b[2])*(a[2]-b[2])) );
}

inline float VecSquaredLength3fv(const float v[3])
{
  return( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
}

inline void VecNormalize3fv(float v[3], const float a[3])
{
  float l = VecLength3fv(a);
  v[0] = a[0]/l;
  v[1] = a[1]/l;
  v[2] = a[2]/l;
}

inline void VecSelfNormalize3fv(float v[3])
{
  float l = VecLength3fv(v);
  v[0] /= l;
  v[1] /= l;
  v[2] /= l;
}

inline float VecDotProd3fv(const float a[3], const float b[3])
{
  return( a[0]*b[0] + a[1]*b[1] + a[2]*b[2] );
}

inline void VecCrossProd3fv(float v[3], const float a[3], const float b[3]) // c = a X b
{ 
  VecSet3fv(v, a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]);
}

inline void VecUpdateMinMax3fv(float min[3], float max[3], const float v[3])
{
  if (v[0]<min[0]) min[0]=v[0]; else if (v[0]>max[0]) max[0]=v[0];
  if (v[1]<min[1]) min[1]=v[1]; else if (v[1]>max[1]) max[1]=v[1];
  if (v[2]<min[2]) min[2]=v[2]; else if (v[2]>max[2]) max[2]=v[2];
}

inline void VecUpdateMin3fv(float min[3], const float v[3])
{
  if (v[0]<min[0]) min[0]=v[0];
  if (v[1]<min[1]) min[1]=v[1];
  if (v[2]<min[2]) min[2]=v[2];
}

inline void VecUpdateMax3fv(float max[3], const float v[3])
{
  if (v[0]>max[0]) max[0]=v[0];
  if (v[1]>max[1]) max[1]=v[1];
  if (v[2]>max[2]) max[2]=v[2];
}

inline int VecEqual3fv(const float a[3], const float b[3])
{
  return( a[0]==b[0] && a[1]==b[1] && a[2]==b[2] );
}

inline void VecCcwNormal3fv(float n[3], const float a[3], const float b[3], const float c[3])
{
  float ab[3], ac[3];
  VecSubtract3fv(ab,b,a);
  VecSubtract3fv(ac,c,a);
  VecCrossProd3fv(n,ab,ac);
}

inline void VecCwNormal3fv(float n[3], const float a[3], const float b[3], const float c[3])
{
  float ab[3], ac[3];
  VecSubtract3fv(ab,b,a);
  VecSubtract3fv(ac,c,a);
  VecCrossProd3fv(n,ac,ab);
}

inline void VecCcwNormNormal3fv(float n[3], const float a[3], const float b[3], const float c[3])
{
  float ab[3], ac[3];
  VecSubtract3fv(ab,b,a);
  VecSubtract3fv(ac,c,a);
  VecCrossProd3fv(n,ab,ac);
  VecSelfNormalize3fv(n);
}

inline void VecCwNormNormal3fv(float n[3], const float a[3], const float b[3], const float c[3])
{
  float ab[3], ac[3];
  VecSubtract3fv(ab,b,a);
  VecSubtract3fv(ac,c,a);
  VecCrossProd3fv(n,ac,ab);
  VecSelfNormalize3fv(n);
}

inline void VecCarthesianToSpherical3fv(float v[3], const float a[3])
{
  float r2 = a[0]*a[0]+a[1]*a[1];
  v[1] = (float)atan2(a[0], a[1]);
  v[2] = (float)atan2(sqrt(r2), a[2]);
  v[0] = (float)sqrt(r2+a[2]*a[2]);
}

inline void VecSphericalToCarthesian3fv(float v[3], const float a[3])
{
  v[0] = (float)a[0]*(float)sin(a[2])*(float)sin(a[1]);
  v[1] = (float)a[0]*(float)sin(a[2])*(float)cos(a[1]);
  v[2] = (float)a[0]*(float)cos(a[2]);
}

#endif