#ifndef JVM_H
#define JVM_H

#include <jni.h>


namespace jvm {
    void load();

    inline JavaVM *vm = nullptr;
    inline JNIEnv *env = nullptr;
}


#endif //JVM_H
