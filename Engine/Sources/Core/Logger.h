#pragma once

#include <spdlog/spdlog.h>

#include <memory>
#include <string>
#include <vector>

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Engine
{
	class Logger
	{
	public:
		static void Init();

		static void Set_Engine_LogLevel(int log_level);

		static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
	};

	// Core log macros
#define LOG_TRACE(...)			Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)			Logger::GetEngineLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)			Logger::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)			Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)			Logger::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)		Logger::GetEngineLogger()->critical(__VA_ARGS__) 
}