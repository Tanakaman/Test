#include "Project.h"
#include "System/Application.h"
#include "Scene/BattleScene.h"

using namespace DEV;

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, int)
{
#if _DEBUG
    // メモリリークの検出を行います.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // コンソール画面を出力します.
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);
#endif

    // アプリケーションの起動を行います.
    Application::GetInstance().Run(hInst);

    Scene* Battle = NEW BattleScene();

    do 
    {
        Battle->Update();

        ScreenFlip();
    }
    while (ProcessMessage() != -1);

    delete Battle;

    // Application にうつす.
    DxLib_End();

#if _DEBUG	
    FreeConsole();
#endif
    return 0;
}