#include "Project.h"
#include "Object.h"
#include "ObjectContainer.h"

using namespace DEV;

Object::Object()
    : Object(TEXT(""))
{
    
}

Object::Object(const TCHAR* InName)
{
    this->Name = InName;

    InstanceId = ObjectContainer::GetInstance().AddObject(this);
}

Object::~Object()
{
    
}

void Object::Destory()
{
    if (this->InstanceId == 0) return;

    ObjectContainer::GetInstance().DestroyObject(this->InstanceId);

    this->InstanceId = 0;
}