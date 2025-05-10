#include "minecraft.h"
#include "../classes/classes.h"

minecraft::minecraft(jobject object_in) : c_jobject(object_in) {
}

minecraft minecraft::get_minecraft() {
    static jmethodID get_minecraft_method = jvm::env->GetStaticMethodID(classes::minecraft_class, "A", "()Lave;");

    return minecraft(jvm::env->CallStaticObjectMethod(classes::minecraft_class, get_minecraft_method));
}

entity minecraft::get_local_player() const {
    static jfieldID the_player_field = jvm::env->GetFieldID(classes::entity_class, "h", "Lbew;");

    return entity(jvm::env->GetObjectField(this->cached_object, the_player_field));
}
