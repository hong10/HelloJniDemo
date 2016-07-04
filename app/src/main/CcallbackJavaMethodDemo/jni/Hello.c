#include <stdio.h>
#include <jni.h>
#include <android/log.h>
#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


/**
 * env JNIEnv* java�����������ָ��.
 *
 *jobject obj ,�ĸ�������õ����native�ķ��� , obj�ʹ�������ĸ�����
 */
JNIEXPORT void JNICALL Java_cn_itcast_ndk4_DataProvider_callmethod1
  (JNIEnv * env, jobject obj){
	//˼�� java�еķ���
	//1.�ҵ�ĳһ������ֽ���
	//   jclass      (*FindClass)(JNIEnv*, const char*);
	jclass jclazz = (*env)->FindClass(env,"cn/itcast/ndk4/DataProvider");
	if(jclazz==0){
		LOGI("LOAD CLAZZ ERROR");
	}else{
		LOGI("LOAD CLAZZ success");
	}
	//2.�ҵ�����ֽ�������ķ���.
	// jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);

	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"helloFromJava","()V");
	if(methodid==0){
		LOGI("LOAD methodid ERROR");
	}else{
		LOGI("LOAD methodid success");
	}

	//3.���÷���
	//void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env,obj,methodid);


}

/**
 * ����java���� ��������int�ķ���
 */
JNIEXPORT void JNICALL Java_cn_itcast_ndk4_DataProvider_callmethod2
  (JNIEnv * env , jobject obj){
	jclass jclazz = (*env)->FindClass(env,"cn/itcast/ndk4/DataProvider");
	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"Add","(II)I");
	//    jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
	int result = (*env)->CallIntMethod(env,obj,methodid,3,5);
	LOGI("result=%d",result);
}


JNIEXPORT void JNICALL Java_cn_itcast_ndk4_DataProvider_callmethod3
  (JNIEnv * env, jobject obj){
	jclass jclazz = (*env)->FindClass(env,"cn/itcast/ndk4/DataProvider");
	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"printString","(Ljava/lang/String;)V");
	(*env)->CallVoidMethod(env,obj,methodid,(*env)->NewStringUTF(env,"haha from c "));

}

// ����nativite�ķ��� ����dp���涨��� obj ����ľ���dp�������
JNIEXPORT void JNICALL Java_cn_itcast_ndk4_DataProvider_callmethod4
  (JNIEnv * env, jobject obj){
	jclass jclazz = (*env)->FindClass(env,"cn/itcast/ndk4/DemoActivity");
	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"methodInDemoActivity","()V");
	 //jobject     (*AllocObject)(JNIEnv*, jclass);
	jobject demoobj = (*env)->AllocObject(env,jclazz);
	(*env)->CallVoidMethod(env,demoobj,methodid);

}
JNIEXPORT void JNICALL Java_cn_itcast_ndk4_DemoActivity_callDemoActivitMethod
  (JNIEnv * env, jobject obj){
	jclass jclazz = (*env)->FindClass(env,"cn/itcast/ndk4/DemoActivity");
	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"methodInDemoActivity","()V");
	 //jobject     (*AllocObject)(JNIEnv*, jclass);
	//jobject demoobj = (*env)->AllocObject(env,jclazz);
	(*env)->CallVoidMethod(env,obj,methodid);

}
/**
 * ��̬������Ѱ��
 */
JNIEXPORT void JNICALL Java_cn_itcast_ndk4_DemoActivity_callDemoActivitMethod2
  (JNIEnv * env, jobject obj){
	jclass jclazz = (*env)->FindClass(env,"cn/itcast/ndk4/DemoActivity");
	//jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"methodInDemoActivity","()V");

	//jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
	jmethodID  methodid =  (*env)->GetStaticMethodID(env,jclazz,"showToast","(Landroid/content/Context;Ljava/lang/String;)V");
//   void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
	(*env)->CallStaticVoidMethod(env,jclazz,methodid,obj,(*env)->NewStringUTF(env,"haha from static method"));


}
