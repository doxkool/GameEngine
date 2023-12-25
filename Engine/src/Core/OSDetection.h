#ifdef _WIN32
	#ifdef _WIN64
		#define ENGINE_PLATFORM_WINDOWS
	#else
		#error "Only Windows x64 Builds are supported!"
	#endif
#endif