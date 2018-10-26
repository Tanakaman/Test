#pragma once
#include <memory>

namespace DEV
{
    /// <summary>
    /// �E�B���h�E�̐�����񋟂��܂�.
    /// </summary>
    class WindowCreator
    {
    public:
        WindowCreator();
        virtual ~WindowCreator();

        void Create(const HINSTANCE& hInst);
        const HWND& GetHandle() const;

        void ChangeWindowText(const TCHAR* Text);
        void SetWindowMode(bool bWindow);

    private:
        class Impl;
        std::unique_ptr<Impl> PrivateInst;
    };
};