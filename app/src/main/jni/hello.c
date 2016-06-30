//
// Created by hong on 6/30/16.
//
#include <stdio.h>
#include "com_hong_hellojnidemo_MainActivity.h"

jstring JNICALL Java_com_hong_hellojnidemo_MainActivity_helloJni
  (JNIEnv * env, jobject obj){

  return (*env)->NewStringUTF(env,"hello jni hahaha! ");

  }
