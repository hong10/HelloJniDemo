//
// Created by hong on 2016/7/3.
//

#include <stdio.h>
#include "com_hong_hellojnidemo_TransportData.h"
#include <android/log.h>

#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


/**
 * Jstring2CStr 把java中的string 转化成 c中的char数组
 * jstring   jstr要被转化的java string
 * char*  代表的是字符串数组名称（字符串数组的首地址）
 *
 */
char *Jstring2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");//寻找java里面String.class
    jstring strencode = (*env)->NewStringUTF(env, "utf-8");//创建java字符串 "utf-8"
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",
                                        "(Ljava/lang/String;)[B");//寻找到java String getbytes();
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid,
                                                           strencode); // String .getByte("utf-8");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte *ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);         //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);  //
    return rtn;
}


JNIEXPORT jint JNICALL Java_com_hong_hellojnidemo_TransportData_add
        (JNIEnv *env, jobject obj, jint x, jint y) {
    LOGI("x=%d", x);
    LOGD("y=%d", y);
    int result = x + y;
    LOGD("result=%d", result);
    return result;

}

JNIEXPORT jstring JNICALL Java_com_hong_hellojnidemo_TransportData_sayHelloInC
        (JNIEnv *env, jobject obj, jstring jstr) {
    //把java中的string转化成c中的char*
    char *cstr = Jstring2CStr(env, jstr);
    LOGI("cstr=%s", cstr);

    char *chello = " ni hao ！";
    strcat(cstr, chello);
    LOGI("cstr=%s", cstr);

    return (*env)->NewStringUTF(env, cstr);

}


JNIEXPORT jintArray JNICALL Java_com_hong_hellojnidemo_TransportData_inMethod
        (JNIEnv * env, jobject obj, jintArray jintarr)
{
    // jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
    //获取一个int类型数组 第一个元素的首地址
    //jsize       (*GetArrayLength)(JNIEnv*, jarray);
    //获取一个数组的长度 返回值 是int类型

    int len = (*env)->GetArrayLength(env, jintarr);
    LOGI("len=%d",len);
    jint * intarr = (*env)->GetIntArrayElements(env, jintarr, 0);
    int i;
    for (i = 0; i < len; i++) {
        LOGI("intarr[%d]=%d", i, intarr[i]);//int 数组原来每一个元素的初始值
        *(intarr+i) += 10;
    }

    return jintarr;


}
