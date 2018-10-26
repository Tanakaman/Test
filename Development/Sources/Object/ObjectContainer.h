#pragma once
#include <unordered_map>
#include "Object.h"

namespace DEV
{
    class ObjectContainer
    {
    public:
        ObjectContainer();
        virtual ~ObjectContainer();

        static ObjectContainer& GetInstance()
        {
            static ObjectContainer Instance;
            return Instance;
        }

        UINT AddObject(Object* Target);
        void DestroyObject(UINT InstanceId);
        Object* GetObjectInstance(UINT InstanceId);

    private:

        std::unordered_map<UINT, Object*> CollectionMap;
    };
};
