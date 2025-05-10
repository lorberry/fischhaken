#ifndef MINECRAFT_H
#define MINECRAFT_H

#include "../jvm.h"


class c_minecraft : public c_jobject {
public:
    explicit c_minecraft(jobject object_in);

    static c_minecraft get_minecraft();
};


#endif //MINECRAFT_H
