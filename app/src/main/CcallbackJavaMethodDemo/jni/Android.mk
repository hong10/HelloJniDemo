   LOCAL_PATH := $(call my-dir)
   include $(CLEAR_VARS)

   LOCAL_MODULE    := Hello
   LOCAL_SRC_FILES := Hello.c
   LOCAL_LDLIBS += -llog 
   #��c���Ե��õ�log������Ӧ�ĺ�������뵽���������ʱ����
   #liblog.so 
   include $(BUILD_SHARED_LIBRARY)