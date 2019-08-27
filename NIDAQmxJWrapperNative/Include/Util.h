#include <jni.h>

#ifndef UTIL_H_
#define UTIL_H_

const char *getStringUTFChars(JNIEnv *env, jstring jstr, jboolean *isCopy);

void throwNIDAQmxJWrapperException(JNIEnv *env, int32 code);

#endif
