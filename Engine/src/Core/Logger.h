#pragma once

#include "Core/Base.h"

#include <spdlog/spdlog.h>

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Engine
{
	class Log
	{
		public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		static std::shared_ptr<spdlog::logger>& GetGameLogger() { return s_GameLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_GameLogger;
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
#define LOG_G_TRACE(...)			Engine::Log::GetGameLogger()->trace(__VA_ARGS__)
#define LOG_G_DEBUG(...)			Engine::Log::GetGameLogger()->debug(__VA_ARGS__)
#define LOG_G_INFO(...)				Engine::Log::GetGameLogger()->info(__VA_ARGS__)
#define LOG_G_WARN(...)				Engine::Log::GetGameLogger()->warn(__VA_ARGS__)
#define LOG_G_ERROR(...)			Engine::Log::GetGameLogger()->error(__VA_ARGS__)
#define LOG_G_CRITICAL(...)			Engine::Log::GetGameLogger()->critical(__VA_ARGS__)