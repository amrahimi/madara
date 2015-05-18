/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "madara/MADARA_export.h"
/* Header for class com_madara_containers_NativeDoubleVector */

#ifndef _Included_com_madara_containers_NativeDoubleVector
#define _Included_com_madara_containers_NativeDoubleVector
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_NativeDoubleVector
 * Signature: ()J
 */
MADARA_Export jlong JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1NativeDoubleVector__
  (JNIEnv *, jobject);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_NativeDoubleVector
 * Signature: (J)J
 */
MADARA_Export jlong JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1NativeDoubleVector__J
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_freeNativeDoubleVector
 * Signature: (J)V
 */
MADARA_Export void JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1freeNativeDoubleVector
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_set
 * Signature: (JID)V
 */
MADARA_Export void JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1set
  (JNIEnv *, jobject, jlong, jint, jdouble);

/*
* Class:     com_madara_containers_NativeDoubleVector
* Method:    jni_pushback
* Signature: (JD)V
*/
MADARA_Export void JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1pushback
(JNIEnv *, jobject, jlong, jdouble);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_getName
 * Signature: (J)Ljava/lang/String;
 */
MADARA_Export jstring JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1getName
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_setName
 * Signature: (JJJLjava/lang/String;)V
 */
MADARA_Export void JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1setName
  (JNIEnv *, jobject, jlong, jlong, jlong, jstring);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_get
 * Signature: (JI)D
 */
MADARA_Export jdouble JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1get
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_toRecord
 * Signature: (JI)J
 */
MADARA_Export jlong JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1toRecord__JI
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_toRecord
 * Signature: (J)J
 */
MADARA_Export jlong JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1toRecord__J
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_toArray
 * Signature: (J)[Ljava/lang/Object;
 */
MADARA_Export jobjectArray JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1toArray
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_size
 * Signature: (J)J
 */
MADARA_Export jlong JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1size
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    jni_resize
 * Signature: (JJ)V
 */
MADARA_Export void JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1resize
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_madara_containers_NativeDoubleVector
 * Method:    modify
 * Signature: (J)V
 */
MADARA_Export void JNICALL Java_com_madara_containers_NativeDoubleVector_jni_1modify
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
