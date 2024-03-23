// Properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define ENGINE_PLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define ENGINE_PLATFORM_LINUX 1
#if defined(__ANDROID__)
#define ENGINE_PLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Catch anything not caught by the above.
#define ENGINE_PLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
// Posix
#define ENGINE_PLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
#define ENGINE_PLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define ENGINE_PLATFORM_IOS 1
#define ENGINE_PLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define ENGINE_PLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform!"
#endif

//Renderer selection
#define PLATFORM_OPENGL 1

//Input Handling
#define PLATFORM_GLFW 1

#if PLATFORM_OPENGL
#define GL_VERSION_MAJOR 4
#define GL_VERSION_MINOR 5
#endif

#ifdef ENGINE_EXPORT
// Exports
#ifdef _MSC_VER
#define EAPI __declspec(dllexport)
#else
#define EAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define EAPI __declspec(dllimport)
#else
#define EAPI
#endif
#endif