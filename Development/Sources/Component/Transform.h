#pragma once
#include "Collection/List/List.hpp"
#include "Component.h"

namespace DEV
{
    class Transform : public Component
    {
    public:
        Transform();
        Transform(class GameObject* Obj, const TCHAR* Name);
        virtual ~Transform();

        void AddChild(Transform* InChild);

        void SetParent(Transform* InParent);

        Transform* GetParent();

        void GetChildren(List<Transform*>& Children);

    private:
        List<UINT> Children;

        UINT Parent;
    };
};
