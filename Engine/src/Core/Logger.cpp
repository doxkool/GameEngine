#include "Core/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Engine
{
	std::shared_ptr<spdlog::logger>  Log::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::s_GameLogger;

	void Log::Init() {

		std::vector<spdlog::sink_ptr> Sinks;
		Sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		Sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Engine.log", true));

		Sinks[0]->set_pattern("[%T] [%^%l%$]	[%n]   	%v");
		Sinks[1]->set_pattern("[%T] [%l]	[%n]   	%v");

		

		s_EngineLogger = std::make_shared<spdlog::logger>("Engine", begin(Sinks), end(Sinks));
		spdlog::register_logger(s_EngineLogger);
		s_EngineLogger->set_level(spdlog::level::trace);
		s_EngineLogger->flush_on(spdlog::level::trace);

		s_GameLogger = std::make_shared<spdlog::logger>("Game", begin(Sinks), end(Sinks));
		spdlog::register_logger(s_GameLogger);
		s_GameLogger->set_level(spdlog::level::trace);
		s_GameLogger->flush_on(spdlog::level::trace);
		
		LOG_E_INFO("====== New logging session ======");

		if (GetEngineLogger)
		{
			LOG_E_DEBUG("Log initialization completed.");
		}
		if (GetGameLogger)
		{
			LOG_G_DEBUG("Log initialization completed.");
		}
		
	}
}