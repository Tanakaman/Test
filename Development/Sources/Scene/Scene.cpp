#include "Project.h"
#include "Scene.h"
#include "Component\Transform.h"

using namespace DEV;

Scene::Scene()
{
}

Scene::~Scene()
{
    // AddObject されたオブジェクトをすべて削除します.
    for (auto Handle : this->ObjectsHandle.Get())
    {
        auto Obj = ObjectContainer::GetInstance().GetObjectInstance(Handle);
        if (Obj == nullptr) continue;
        Obj->Destory();
    }
}

void Scene::Update()
{
    // AddObject されたオブジェクトの更新処理を呼びます.
    for (auto Handle : this->ObjectsHandle.Get())
    {
        auto Obj = ObjectContainer::GetInstance().GetObjectInstance(Handle);
        if (Obj == nullptr) continue;

        Obj->Update();
    }

#if _DEBUG

    // レベル上のオブジェクト、コンポーネントの情報を表示します.
    int Count = 0;

    auto Func = [&](int Count, int OffsX, int OffsY, GameObject& Obj)
    {
        DrawString(OffsX * 2, OffsY * Count, Obj.GetName(), GetColor(255, 255, 255));

        List<Component*> Components;
        Obj.GetComponents(Components);
        for (auto Comp : Components.Get())
        {
            ++Count;
            DrawString(OffsX * 3, OffsY * Count, Comp->GetName(), GetColor(255, 255, 255));
        }
        return Count;
    };

    int OffsY = 16;
    int OffsX = 8;

    DrawString(OffsX, OffsY * ++Count, TEXT("- Hierarchy -"), GetColor(255, 255, 255));

    for (auto Handle : this->ObjectsHandle.Get())
    {
        auto Obj = dynamic_cast<GameObject*>(ObjectContainer::GetInstance().GetObjectInstance(Handle));
        if (Obj == nullptr) continue;

        // 親があるならスルーします.
        if ( Obj->GetTransform().GetParent() != nullptr) continue;

        Count = Func(++Count, OffsX, OffsY, *Obj);

        // TODO : 子の子からが表示できません.
        List<Transform*> Children;
        Obj->GetTransform().GetChildren(Children);
        for (auto Child : Children.Get())
        {
            Count = Func(++Count, OffsX + OffsX, OffsY, Child->GetGameObject());
        }
    }
#endif
}

GameObject* Scene::AddGameObject(const TCHAR* Name)
{
    // GameObjectを追加します.
    GameObject* Obj = NEW GameObject(Name);
    {
        this->ObjectsHandle.Add(Obj->GetInstanceId());
    }
    return Obj;
}