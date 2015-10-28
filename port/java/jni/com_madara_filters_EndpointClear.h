/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "madara/MADARA_export.h"
/* Header for class com_madara_filters_EndpointClear */

#ifndef _Included_com_madara_filters_EndpointClear
#define _Included_com_madara_filters_EndpointClear
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_madara_filters_EndpointClear
 * Method:    jni_EndpointClear
 * Signature: ()J
 */
MADARA_Export jlong JNICALL Java_com_madara_filters_EndpointClear_jni_1EndpointClear
  (JNIEnv *, jobject);

/*
 * Class:     com_madara_filters_EndpointClear
 * Method:    jni_addReceiveFilterTo
 * Signature: (JJ)V
 */
MADARA_Export void JNICALL Java_com_madara_filters_EndpointClear_jni_1addReceiveFilterTo
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_madara_filters_EndpointClear
 * Method:    jni_addSendFilterTo
 * Signature: (JJ)V
 */
MADARA_Export void JNICALL Java_com_madara_filters_EndpointClear_jni_1addSendFilterTo
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_madara_filters_EndpointClear
 * Method:    jni_addRebroadcastFilterTo
 * Signature: (JJ)V
 */
MADARA_Export void JNICALL Java_com_madara_filters_EndpointClear_jni_1addRebroadcastFilterTo
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_madara_filters_EndpointClear
 * Method:    jni_setPrefix
 * Signature: (JLjava/lang/String;)V
 */
MADARA_Export void JNICALL Java_com_madara_filters_EndpointClear_jni_1setPrefix
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     com_madara_filters_EndpointClear
 * Method:    jni_freeEndpointClear
 * Signature: (J)V
 */
MADARA_Export void JNICALL Java_com_madara_filters_EndpointClear_jni_1freeEndpointClear
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
