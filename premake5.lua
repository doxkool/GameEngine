workspace "GameEngine"
   architecture "x64"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder.
IncludeDir = {}
IncludeDir["GLFW"] = "Vendors/GLFW/include"
IncludeDir["GLEW"] = "Vendors/GLEW/include"
IncludeDir["glm"] = "Vendors/glm"
IncludeDir["spdlog"] = "Vendors/spdlog"
IncludeDir["stb_image"] = "Vendors/stb_image"
IncludeDir["imgui"] = "Vendors/imgui"
IncludeDir["Entt"] = "Vendors/Entt"

project "Engine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "off"

   targetdir ("bin/" .. outputdir)
   objdir ("bin-int/" .. outputdir)

   files 
   {
		"Engine/Sources/**",
		"Vendors/imgui/*"
   }

   defines
	{
		"ENGINE_EXPORT",	
		"GLFW_INCLUDE_NONE",
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"
	}

   includedirs
   {
		"Engine/Sources",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLEW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.Entt}"
   }

   libdirs
   {
		"Vendors/GLFW/lib",
		"Vendors/GLEW/lib"
   }

   links
   {
		"glfw3_mt.lib",
		"glew32.lib",
		"opengl32.lib"
   }

   filter "system.windows"
      systemversion "latest"

   filter "configurations:Debug"
      defines { "ENGINE_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "ENGINE_NDEBUG" }
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
		"Game/Sources/**"
   }

   defines
	{
		--"_CRT_SECURE_NO_WARNINGS",
		--"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"
	}

   includedirs
   {
		"Engine/Sources",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLEW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.Entt}"
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
      defines { "GAME_NDEBUG" }
      optimize "on"