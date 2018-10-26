#include "Project.h"
#include "ObjectContainer.h"
#include <utility>

using namespace DEV;

ObjectContainer::ObjectContainer()
{
}

ObjectContainer::~ObjectContainer()
{
}

UINT ObjectContainer::AddObject(Object* Target)
{
    UINT Size = CollectionMap.size() + 1;

    this->CollectionMap.insert(std::pair<UINT, Object*>(Size, Target));

    return Size;
}

void ObjectContainer::DestroyObject(UINT InstanceId)
{
    delete this->CollectionMap[InstanceId];

    this->CollectionMap[InstanceId] = nullptr;
}

Object* ObjectContainer::GetObjectInstance(UINT InstanceId)
{
    return this->CollectionMap[InstanceId];
}