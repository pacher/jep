/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4 c-style: "K&R" -*- */
/* 
   jep - Java Embedded Python

   Copyright (c) JEP AUTHORS.

   This file is licenced under the the zlib/libpng License.

   This software is provided 'as-is', without any express or implied
   warranty. In no event will the authors be held liable for any
   damages arising from the use of this software.
   
   Permission is granted to anyone to use this software for any
   purpose, including commercial applications, and to alter it and
   redistribute it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you
   must not claim that you wrote the original software. If you use
   this software in a product, an acknowledgment in the product
   documentation would be appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and
   must not be misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.   
*/

#include "jport.h"

#ifndef _Included_numpyembed
#define _Included_numpyembed


#ifndef USE_NUMPY
 #define USE_NUMPY 1
#endif

/* this whole file is a no-op if numpy support is disabled */
#if USE_NUMPY

/* jclasses cached for faster performance */
extern jclass JBOOLEAN_ARRAY_TYPE;
extern jclass JBYTE_ARRAY_TYPE;
extern jclass JSHORT_ARRAY_TYPE;
extern jclass JINT_ARRAY_TYPE;
extern jclass JLONG_ARRAY_TYPE;
extern jclass JFLOAT_ARRAY_TYPE;
extern jclass JDOUBLE_ARRAY_TYPE;
extern jclass JEP_NDARRAY_TYPE;


/* methods to support numpy <-> java conversion */
int npy_array_check(PyObject*);
int jndarray_check(JNIEnv*, jobject);
jobject convert_pyndarray_jndarray(JNIEnv*, PyObject*);
PyObject* convert_jndarray_pyndarray(JNIEnv*, jobject);
jarray convert_pyndarray_jprimitivearray(JNIEnv*, PyObject*, jclass);

#endif // if numpy is enabled


#endif // ifndef _Included_numpyembed