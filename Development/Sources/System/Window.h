#pragma once
#include <memory>

namespace DEV
{
    /// <summary>
    /// ウィンドウの生成を提供します.
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