#pragma once

#include <spdlog/spdlog.h>

namespace Engine
{
	class Log
	{
		public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		static std::shared_ptr<spdlog::logger>& GetAppLogger() { return s_AppLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_AppLogger;
	};
}

// Core log macros
#define LOG_E_TRACE(...)    Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_E_DEBUG(...)    Log::GetEngineLogger()->debug(__VA_ARGS__)
#define LOG_E_INFO(...)     Log::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_E_WARN(...)     Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_E_ERROR(...)    Log::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_E_CRITICAL(...) Log::GetEngineLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_A_TRACE(...)         Log::GetAppLogger()->trace(__VA_ARGS__)
#define LOG_A_DEBUG(...)         Log::GetAppLogger()->debug(__VA_ARGS__)
#define LOG_A_INFO(...)          Log::GetAppLogger()->info(__VA_ARGS__)
#define LOG_A_WARN(...)          Log::GetAppLogger()->warn(__VA_ARGS__)
#define LOG_A_ERROR(...)         Log::GetAppLogger()->error(__VA_ARGS__)
#define LOG_A_CRITICAL(...)      Log::GetAppLogger()->critical(__VA_ARGS__)

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

typedef enum loglevel {
	LOG_LEVEL_FATAL = 0,
	LOG_LEVEL_ERROR = 1,
	LOG_LEVEL_WARN = 2,
	LOG_LEVEL_INFO = 3,
	LOG_LEVEL_DEBUG = 4,
	LOG_LEVEL_TRACE = 5,
} log_level;

extern void log_output(loglevel level, const char* message, ...);

// Logs a fatal level message.
#define log_fatal(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

//#ifdef log_error
// Logs a error level message.
#define log_error(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
//#endif

#if LOG_WARN_ENABLED == 1
// Logs a warning level message.
#define log_warn(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define log_warn(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// Logs a info level message.
#define log_info(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define log_info(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs a debug level message.
#define log_debug(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define log_debug(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs a trace level message.
#define log_trace(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define log_trace(message, ...)
#endif