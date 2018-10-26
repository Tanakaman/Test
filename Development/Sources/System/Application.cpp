#include "Project.h"
#include "Window.h"
#include "Application.h"

using namespace DEV;

class Application::Impl
{
public:
    Impl()
    {
    }

    ~Impl(){}

    WindowCreator Window;
};

/// <summary>
/// アプリケーションの起動を行います.
/// </summary>
/// <param name="Inst"></param>
void Application::Run(const HINSTANCE& Inst)
{
    DEBUG_LOG("Startup application.");

    //PrivateInst->Window.Create(Inst);

    PrivateInst->Window.ChangeWindowText(TEXT("Yamada game"));
    PrivateInst->Window.SetWindowMode(true);

    if ( DxLib_Init() == -1 )
    {
        DEBUG_LOG_ERROR("DxLib init failed.");
    }
}

void Application::OnRender()
{

}

Application::Application()
    : PrivateInst(NEW Application::Impl())
{

}

Application::~Application()
{
    
}