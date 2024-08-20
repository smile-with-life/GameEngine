#include "Log.h"

namespace GE
{
std::shared_ptr<quicklog::Logger> Log::s_CoreLogger;
std::shared_ptr<quicklog::Logger> Log::s_ClientLogger;
Log::Log()
{

}

Log::~Log()
{

}

void Log::Init()
{
    s_CoreLogger = quicklog::create<quicklog::stdout_mt>("GE",quicklog::ColorMode::automatic);
    s_CoreLogger->setLevel(quicklog::LogLevel::Trace);
    s_ClientLogger = quicklog::create<quicklog::stdout_mt>("APP", quicklog::ColorMode::automatic);
    s_ClientLogger->setLevel(quicklog::LogLevel::Trace);
}
}//namespace GE