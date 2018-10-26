#pragma once
#include "Object/Object.h"

namespace DEV
{
    class Component : public Object
    {
    public:
        Component();
        Component(class GameObject* Obj, const TCHAR* Name);
        virtual ~Component();

        class GameObject& GetGameObject();

    private:
        class GameObject* CachedGameObject;
    };
};
