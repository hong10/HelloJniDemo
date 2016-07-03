LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= hello
LOCAL_SRC_FILES:= hello.c
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_EXPORT_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_STATIC_LIBRARY)


#---------------------

include $(CLEAR_VARS)

LOCAL_MODULE:= transport
LOCAL_SRC_FILES:= transport.c
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_LDLIBS += -llog
#把c语言调用的log函数对应的函数库加入到编译的运行时里面
#liblog.so

include $(BUILD_SHARED_LIBRARY)
