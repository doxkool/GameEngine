#pragma once

#include "Core/Base.h"

#include <spdlog/spdlog.h>

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
		static void Set_Game_LogLevel(int log_level);

		static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		static std::shared_ptr<spdlog::logger>& GetGameLogger() { return s_GameLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_GameLogger;
	};
}

// Core log macros
#define LOG_E_TRACE(...)			Engine::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_E_DEBUG(...)			Engine::Logger::GetEngineLogger()->debug(__VA_ARGS__)
#define LOG_E_INFO(...)				Engine::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_E_WARN(...)				Engine::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_E_ERROR(...)			Engine::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_E_CRITICAL(...)			Engine::Logger::GetEngineLogger()->critical(__VA_ARGS__)

// Client log macros
#define LOG_G_TRACE(...)			Engine::Logger::GetGameLogger()->trace(__VA_ARGS__)
#define LOG_G_DEBUG(...)			Engine::Logger::GetGameLogger()->debug(__VA_ARGS__)
#define LOG_G_INFO(...)				Engine::Logger::GetGameLogger()->info(__VA_ARGS__)
#define LOG_G_WARN(...)				Engine::Logger::GetGameLogger()->warn(__VA_ARGS__)
#define LOG_G_ERROR(...)			Engine::Logger::GetGameLogger()->error(__VA_ARGS__)
#define LOG_G_CRITICAL(...)			Engine::Logger::GetGameLogger()->critical(__VA_ARGS__)