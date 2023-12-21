#include "Core/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Engine
{
	std::shared_ptr<spdlog::logger>  Log::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::s_AppLogger;

	void Log::Init() {

		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Engine.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		s_EngineLogger = std::make_shared<spdlog::logger>("Engine", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_EngineLogger);
		s_EngineLogger->set_level(spdlog::level::trace);
		s_EngineLogger->flush_on(spdlog::level::trace);

		s_AppLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_AppLogger);
		s_AppLogger->set_level(spdlog::level::trace);
		s_AppLogger->flush_on(spdlog::level::trace);
	}
}

void initialize_logging() {

	init_logFile();

}

void log_output(loglevel level, const char* message, ...) {

	if (level == 0) {
		spdlog::critical(message);
	}
	if (level == 1) {
		spdlog::error(message);
	}
	if (level == 2) {
		spdlog::warn(message);
	}
	if (level == 3) {
		spdlog::info(message, 3);
	}
	if (level == 4) {
		spdlog::debug(message);
	}
	if (level == 5) {
		spdlog::trace(message);
	}
}

void report_assertion_failure(const char* expression, const char* message, const char* file, INT32 line) {
	log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}

bool init_logFile() {
	try
	{
		auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		spdlog::error("Log init failed! {}", ex.what());
		return false;
	}

#if defined(DEBUG)
	spdlog::set_level(spdlog::level::debug); // Set global log level to debug
#endif

	log_debug("Log file created.");

	return true;
}