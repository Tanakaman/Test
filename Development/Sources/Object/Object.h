#pragma once

namespace DEV
{
    class Object
    {
    public:
        Object();
        Object(const TCHAR* InName);

        virtual ~Object();

        void Destory();

        virtual void Update(){}

        const UINT& GetInstanceId() const { return InstanceId; }

        const TCHAR* GetName() const { return Name; }

    private:
        UINT InstanceId;

        const TCHAR* Name;
    };
};