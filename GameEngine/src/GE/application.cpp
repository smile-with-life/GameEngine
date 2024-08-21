#include "Application.h"

#include "GE/Events/ApplicationEvent.h"
#include "GE/Log.h"

namespace GE 
{
Application::Application()
{

}

Application::~Application()
{

}

void Application::run()
{
    WindowResizeEvent event(1280, 720);
    GE_LOG_TRACE(event.ToString());
    while (true);
}
}//namespace GE
