#pragma once
#include "Scene.h"
#include <memory>
#include "Object/Object.h"

namespace DEV
{
    class BattleScene : public Scene
    {
    public:
        BattleScene();
        virtual ~BattleScene();

    private:
        class Impl;
        std::unique_ptr<Impl> PrivateInstance;
    };
};
