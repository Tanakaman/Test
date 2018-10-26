#include "Project.h"
#include "BattleScene.h"
#include "Object/GameObject.h"
#include "Component/Transform.h"

using namespace DEV;

class BattleScene::Impl
{
public:

    Impl()
    {
    }

    GameObject* Player;
    GameObject* Enemy;
};

BattleScene::BattleScene()
    : PrivateInstance( NEW Impl() )
{
    // プレイヤー.
    PrivateInstance->Player = AddGameObject(TEXT("Player"));
    PrivateInstance->Player->AddComponent<Component>(TEXT("Component_1"));
    PrivateInstance->Player->AddComponent<Component>(TEXT("Component_2"));
    PrivateInstance->Player->AddComponent<Component>(TEXT("Component_3"));
    PrivateInstance->Player->AddComponent<Component>(TEXT("RenderComponent"));
    PrivateInstance->Player->AddComponent<Component>(TEXT("CollisionComponent"));
    PrivateInstance->Player->AddComponent<Component>(TEXT("InputComponent"));

    // プレイヤーの子.
    {
        GameObject* Child = AddGameObject(TEXT("ChildObj"));
        PrivateInstance->Player->GetTransform().AddChild(&Child->GetTransform());
        GameObject* Child2 = AddGameObject(TEXT("ChildObj2"));
        PrivateInstance->Player->GetTransform().AddChild(&Child2->GetTransform());
        GameObject* Child3 = AddGameObject(TEXT("ChildObj3"));
        PrivateInstance->Player->GetTransform().AddChild(&Child3->GetTransform());
    }

    // エネミー.
    PrivateInstance->Enemy = AddGameObject(TEXT("Enemy"));
    PrivateInstance->Enemy->AddComponent<Component>(TEXT("Component_1"));
    PrivateInstance->Enemy->AddComponent<Component>(TEXT("Component_2"));
    PrivateInstance->Enemy->AddComponent<Component>(TEXT("Component_3"));
}

BattleScene::~BattleScene()
{
    
}
