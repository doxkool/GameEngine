#pragma once

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