#pragma once
#include <memory>

namespace DEV
{
    /// <summary>
    /// �A�v���P�[�V�����̋@�\��񋟂��܂�.
    /// </summary>
    class Application
    {
    public:
        static Application& GetInstance()
        {
            static Application Instance;
            return Instance;
        }

        void Run(const HINSTANCE& Inst);

        void OnRender();

    private:
        class Impl;
        std::unique_ptr<DEV::Application::Impl> PrivateInst;

    private:
        Application();
        ~Application();
    };
};