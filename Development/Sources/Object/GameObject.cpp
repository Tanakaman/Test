#include "Project.h"
#include "Component/Transform.h"
#include "GameObject.h"

using namespace DEV;

GameObject::GameObject()
    : GameObject(TEXT(""))
{
    
}

GameObject::GameObject(const TCHAR* InName)
    : Object(InName)
{
    // 必ずTransformを付与します.
    this->CachedTrans = this->AddComponent<Transform>(TEXT("Transform"));
}

GameObject::~GameObject()
{
    // コンポーネントの削除を行います.
    for (auto Handle : this->Components.Get())
    {
        auto Obj = ObjectContainer::GetInstance().GetObjectInstance(Handle);
        if (Obj == nullptr) continue;
        Obj->Destory();
    }
}

Transform& GameObject::GetTransform()
{
    return *CachedTrans; 
}