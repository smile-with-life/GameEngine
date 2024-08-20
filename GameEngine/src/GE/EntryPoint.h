#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GE::Application* GE::CreateApplication();

int main(int argc,char** argv)
{
    GE::Log::Init();
    GE_CORE_WARNING("Initialized Log!");
    GE_LOG_INFO("hello");
    auto app = GE::CreateApplication();
    app->run();
    delete app;
    return 0;
}
#endif // GE_PLATFORM_WINDOWS
