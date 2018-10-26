#include "Project.h"
#include "Component.h"
#include "Object/GameObject.h"

using namespace DEV;

Component::Component()
    : Object()
{
}

Component::Component(GameObject* Obj, const TCHAR* Name)
    : Object(Name)
{
    CachedGameObject = Obj;
}

Component::~Component()
{
}

GameObject& Component::GetGameObject()
{
    return *this->CachedGameObject;
}