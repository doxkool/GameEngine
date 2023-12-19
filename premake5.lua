workspace "GameEngine"
   architecture "x64"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder.
IncludeDir = {}
IncludeDir["spdlog"] = "Engine/vendors/spdlog"
IncludeDir["GLFW"] = "Engine/vendors/GLFW/include"
IncludeDir["GLEW"] = "Engine/vendors/GLEW/include"

project "Engine"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir ("bin/" .. outputdir)
   objdir ("bin-int/" .. outputdir)

   files 
   {
    "%{prj.name}/src/**",
    "spdlog/**.h"
   }

   includedirs
   {
      "Engine/src",
      "%{IncludeDir.spdlog}",
      "%{IncludeDir.GLFW}",
      "%{IncludeDir.GLEW}"
   }

   libdirs
   {
        "Engine/vendors/GLFW/lib",
        "Engine/vendors/GLEW/lib"
   }

   links
   {
      "GLFW3.lib",
      "glew32s.lib"
   }

   filter "system.windows"
      systemversion "latest"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "on"