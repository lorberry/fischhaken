#ifndef JVM_H
#define JVM_H

#include <jni.h>


namespace jvm {
    void load();

    inline JavaVM *vm = nullptr;
    inline JNIEnv *env = nullptr;
}

class c_jobject {
public:
    explicit c_jobject(jobject object_in);

    ~c_jobject();

    jobject cached_object = nullptr;
};


#endif //JVM_H
