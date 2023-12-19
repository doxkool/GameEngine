workspace "GameEngine"
   architecture "x64"
   configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

-- Include directories relative to root folder.
IncludeDir = {}


project "Engine"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir ("bin/" .. outputdir)
   objdir ("bin-int/" .. outputdir)

   files 
   {
    "%{prj.name}/src/**"
   }

   includedirs
   {
      "Engine/src",

   }

   libdirs
   {

   }

   links
   {

   }

   filter "system.windows"
      systemversion "latest"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "on"