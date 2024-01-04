workspace "Poutine Engine"
   architecture "x64"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder.
IncludeDir = {}
IncludeDir["spdlog"] = "Engine/vendors/spdlog"
IncludeDir["GLFW"] = "Engine/vendors/GLFW/include"
IncludeDir["GLEW"] = "Engine/vendors/GLEW/include"
IncludeDir["GLM"] = "Engine/vendors/glm"
IncludeDir["IMGUI"] = "Engine/vendors/imgui"

project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
	files 
	{
	 "%{prj.name}/src/**",
	 "spdlog/**.h"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
	   "Engine/src",
	   "%{IncludeDir.spdlog}",
	   "%{IncludeDir.GLFW}",
	   "%{IncludeDir.GLEW}",
	   "%{IncludeDir.GLM}",
	   "%{IncludeDir.IMGUI}"
	}
	
	libdirs
	{
	     "Engine/vendors/GLFW/lib",
	     "Engine/vendors/GLEW/lib"
	}
	
	links
	{
	   "glfw3.lib",
	   "glew32s.lib",
	   "opengl32.lib"
	}
	
	filter "system.windows"
	   systemversion "latest"
	
	filter "configurations:Debug"
	   defines { "ENGINE_DEBUG" }
	   symbols "On"
	
	filter "configurations:Release"
	   defines { "N_ENGINE_DEBUG" }
	   optimize "on"

project "Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	
	targetdir ("bin/" .. outputdir)
	objdir ("bin-int/" .. outputdir)
	
	
	files 
	{
	   "%{prj.name}/src/**"
	}
	
	includedirs
	{
	   "Engine/src",
	   "%{IncludeDir.spdlog}",
	   "%{IncludeDir.GLFW}",
	   "%{IncludeDir.GLEW}",
	   "%{IncludeDir.GLM}"
	}
	
	libdirs
	{
	   "bin/Debug_windows_x86_64"
	}
	
	links
	{
	   "Engine.lib"
	}
	
	filter "system.windows"
	   systemversion "latest"
	
	filter "configurations:Debug"
	   defines { "GAME_DEBUG" }
	   symbols "On"
	
	filter "configurations:Release"
	   defines { "N_GAME_DEBUG" }
	   optimize "on"