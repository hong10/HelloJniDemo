//
// Created by hong on 2016/7/3.
//

#include <stdio.h>
#include "com_hong_hellojnidemo_TransportData.h"
#include <android/log.h>
#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


JNIEXPORT jint JNICALL Java_com_hong_hellojnidemo_TransportData_add
  (JNIEnv * env, jobject obj, jint x, jint y)
  {
    LOGI("x=%d",x);
    LOGD("y=%d",y);
    int result = x + y;
    LOGD("result=%d",result);
    return result;

  }

