#pragma once
#include"Core.h"
namespace GE
{
class GE_API Application
{
public:
    Application();

    virtual ~Application();

    void run();
};
Application* CreateApplication();
}//namespace GE
