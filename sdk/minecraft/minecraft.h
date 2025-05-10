#ifndef MINECRAFT_H
#define MINECRAFT_H

#include "entity.h"
#include "../jvm.h"


class minecraft : public c_jobject {
public:
    explicit minecraft(jobject object_in);

    static minecraft get_minecraft();

    [[nodiscard]] entity get_local_player() const;
};


#endif //MINECRAFT_H
