#ifndef CLASSES_H
#define CLASSES_H

#include "jni.h"

namespace classes {
    void load();

    inline jclass minecraft_class = nullptr;
    inline jclass entity_player_sp_class = nullptr;
}

#endif //CLASSES_H
