#include "Project.h"
#include "Transform.h"
#include "Object/ObjectContainer.h"

using namespace DEV;

Transform::Transform()
    : Component()
    , Parent(0)
{
}

Transform::Transform(class GameObject* Obj, const TCHAR* Name)
    : Component(Obj, Name)
    , Parent(0)
{
}

Transform::~Transform()
{
}

void Transform::AddChild(Transform* InChild)
{
    if ( InChild->GetParent() == this ) return;

    this->Children.Add(InChild->GetInstanceId());
    InChild->SetParent(this);
}

void Transform::SetParent(Transform* InParent)
{
    if ( this->Parent == InParent->GetInstanceId() ) return;

    this->Parent = InParent->GetInstanceId();
    InParent->AddChild(this);
}

Transform* Transform::GetParent()
{
    return (Transform*)ObjectContainer::GetInstance().GetObjectInstance(this->Parent);
}

void Transform::GetChildren(List<Transform*>& OutChildren)
{
    for ( auto Id : this->Children.Get() )
    {
        Transform* Child = dynamic_cast<Transform*>( ObjectContainer::GetInstance().GetObjectInstance(Id) );
        OutChildren.Add(Child);
    }
}