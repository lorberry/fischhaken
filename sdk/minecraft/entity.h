#ifndef ENTITY_H
#define ENTITY_H
#include "../../jvm.h"


class entity : public c_jobject {
public:
    explicit entity(jobject object_in);
};


#endif //ENTITY_H
