#include "jvm.h"

void jvm::load() {
    JNI_GetCreatedJavaVMs(&vm, 1l, nullptr);

    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_8) == JNI_EDETACHED) {
        vm->AttachCurrentThreadAsDaemon(reinterpret_cast<void **>(&env), nullptr);
    }
}
