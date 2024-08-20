#pragma once
#include "Core.h"
#include "quicklog/quicklog.h"
namespace GE
{
class GE_API Log
{
public:
    Log();
    ~Log();

    static void Init();

    inline static std::shared_ptr<quicklog::Logger> GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<quicklog::Logger> GetClientLogger() { return s_ClientLogger; }
private:
    static std::shared_ptr<quicklog::Logger> s_CoreLogger;
    static std::shared_ptr<quicklog::Logger> s_ClientLogger;
};
}//namespace GE

#define GE_CORE_TRACE(...) ::GE::Log::GetCoreLogger()->Trace(__VA_ARGS__)
#define GE_CORE_DEBUG(...) ::GE::Log::GetCoreLogger()->Debug(__VA_ARGS__)
#define GE_CORE_INFO(...) ::GE::Log::GetCoreLogger()->Info(__VA_ARGS__)
#define GE_CORE_WARNING(...) ::GE::Log::GetCoreLogger()->Warning(__VA_ARGS__)
#define GE_CORE_ERROR(...) ::GE::Log::GetCoreLogger()->Error(__VA_ARGS__)
#define GE_CORE_FATAL(...) ::GE::Log::GetCoreLogger()->Fatal(__VA_ARGS__)

#define GE_LOG_TRACE(...) ::GE::Log::GetClientLogger()->Trace(__VA_ARGS__)
#define GE_LOG_DEBUG(...) ::GE::Log::GetClientLogger()->Debug(__VA_ARGS__)
#define GE_LOG_INFO(...) ::GE::Log::GetClientLogger()->Info(__VA_ARGS__)
#define GE_LOG_WARNING(...) ::GE::Log::GetClientLogger()->Warning(__VA_ARGS__)
#define GE_LOG_ERROR(...) ::GE::Log::GetClientLogger()->Error(__VA_ARGS__)
#define GE_LOG_FATAL(...) ::GE::Log::GetClientLogger()->Fatal(__VA_ARGS__)
