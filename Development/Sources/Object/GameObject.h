#pragma once
#include "Object.h"
#include "Collection/List/List.hpp"
#include "Component/Component.h"
#include "ObjectContainer.h"

namespace DEV
{
    class GameObject : public Object
    {
    public:
        GameObject();
        GameObject(const TCHAR* InName);

        virtual ~GameObject();

        template<class T>
        T* AddComponent(const TCHAR* Name = nullptr)
        {
            auto Target = NEW T(this, Name ? Name : TEXT(""));
            this->Components.Add(Target->GetInstanceId());
            return Target;
        }

        template<class T>
        T* GetComponent()
        {
            for ( auto Id : this->Components.Get() )
            {
                auto Target = ObjectContainer::GetInstance().GetObjectInstance(Id);
                auto _ = dynamic_cast<T*>(Target);
                if (_ != nullptr)
                {
                    return _;
                }
            }
            return nullptr;
        }

        void GetComponents(List<Component*>& List)
        {
            for (auto Id : this->Components.Get())
            {
                auto Target = ObjectContainer::GetInstance().GetObjectInstance(Id);
                auto _ = dynamic_cast<Component*>(Target);
                if (_ == nullptr) continue;
                 
                List.Add(_);
            }
        }

        template<class T>
        T* RequireComponent()
        {
            if (T* Comp = GetComponent<T>() )
            {
                return Comp;
            }
            return AddComponent<T>();
        }

        class Transform& GetTransform();

    private:
        List<UINT> Components;

        class Transform* CachedTrans;
    };

};
