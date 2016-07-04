   LOCAL_PATH := $(call my-dir)
   include $(CLEAR_VARS)

   LOCAL_MODULE    := Hello
   LOCAL_SRC_FILES := Hello.c
   LOCAL_LDLIBS += -llog 
   #把c语言调用的log函数对应的函数库加入到编译的运行时里面
   #liblog.so 
   include $(BUILD_SHARED_LIBRARY)