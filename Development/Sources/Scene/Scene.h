#pragma once
#include <memory>
#include "Object/GameObject.h"
#include "Collection/List/List.hpp"

namespace DEV
{
    class Scene
    {
    public:
        Scene();
        virtual ~Scene();

        GameObject* AddGameObject(const TCHAR* Name);

        void Update();

    private:
        List<UINT> ObjectsHandle;
    };
};
