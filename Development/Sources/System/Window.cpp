#include "Project.h"
#include "Window.h"

using namespace DEV;

// ウィンドウプロシージャを提供します.
static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, UINT wParam, LONG lParam)
{
    HRESULT hr = S_OK;

    switch (msg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);// ウィンドウを閉じます.
            return 0;
        }

        case WM_ACTIVATEAPP:
        {
            break;
        }
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

class WindowCreator::Impl
{
public:
    Impl(){}
    ~Impl(){}

    HWND Handle;
};

WindowCreator::WindowCreator()
    : PrivateInst(NEW Impl())
{

}

WindowCreator::~WindowCreator()
{

}

void WindowCreator::Create(const HINSTANCE& hInst)
{
    // ウィンドウクラスの登録を行います.
    WNDCLASSEX WCEX;
    memset(&WCEX, 0, sizeof(WCEX));
    WCEX.cbSize = sizeof(WNDCLASSEX);
    WCEX.lpfnWndProc = (WNDPROC)WndProc;
    WCEX.hInstance = hInst;
    WCEX.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    WCEX.lpszClassName = TEXT("TEST");

    if (!RegisterClassEx(&WCEX))
    {
        MessageBox(NULL, TEXT("CreateWindow Failed."), TEXT("Window"), MB_OK);
        return ;
    }

    // TODO.
    RECT Rect;
    Rect.top = 0;
    Rect.left = 0;
    Rect.right = 800;
    Rect.bottom = 450;
    AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW, FALSE);

    HWND HWND = CreateWindow(
        WCEX.lpszClassName,
        WCEX.lpszClassName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        Rect.right - Rect.left,
        Rect.bottom - Rect.top,
        NULL,
        NULL,
        hInst,
        NULL);

    if (HWND == NULL)
    {
        MessageBox(NULL, TEXT("CreateWindow Failed."), TEXT("Window"), MB_OK);
        return;
    }

    // ウィンドウを表示します.
    ShowWindow(HWND, SW_SHOW);
    UpdateWindow(HWND);

    this->PrivateInst->Handle = HWND;

    DEBUG_LOG("Created window.");
}

const HWND& WindowCreator::GetHandle() const
{
    return PrivateInst->Handle;
}

void WindowCreator::ChangeWindowText(const TCHAR* Text)
{
    SetMainWindowText(Text);
}

void WindowCreator::SetWindowMode(bool bWindow)
{
    ChangeWindowMode(true);
}