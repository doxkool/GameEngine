#pragma once

#include <memory>

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
#define LOG_E_TRACE(...)			Engine::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_E_DEBUG(...)			Engine::Log::GetEngineLogger()->debug(__VA_ARGS__)
#define LOG_E_INFO(...)				Engine::Log::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_E_WARN(...)				Engine::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_E_ERROR(...)			Engine::Log::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_E_CRITICAL(...)			Engine::Log::GetEngineLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_A_TRACE(...)			Engine::Log::GetAppLogger()->trace(__VA_ARGS__)
#define LOG_A_DEBUG(...)			Engine::Log::GetAppLogger()->debug(__VA_ARGS__)
#define LOG_A_INFO(...)				Engine::Log::GetAppLogger()->info(__VA_ARGS__)
#define LOG_A_WARN(...)				Engine::Log::GetAppLogger()->warn(__VA_ARGS__)
#define LOG_A_ERROR(...)			Engine::Log::GetAppLogger()->error(__VA_ARGS__)
#define LOG_A_CRITICAL(...)			Engine::Log::GetAppLogger()->critical(__VA_ARGS__)