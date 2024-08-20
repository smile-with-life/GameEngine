workspace "GameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngine"
	location "GameEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/Quicklog/include"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.22621.0"
		defines
		{
			"GE_PLATFORM_WINDOWS",
			"GE_BUILD_DLL",
		}

		postbuildcommands
		{
			("{MKDIR} %[bin/" .. outputdir .. "/Sandbox]"),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
	    defines "GE_DEBUG"
		symbols "On"

	filter "configurations:Release"
	    defines "GE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
	    defines "GE_DIST"
		optimize "On"

project "Sandbox"
    location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"GameEngine/vendor/Quicklog/include",
		"GameEngine/src"
	}

	links
	{
		"GameEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.22621.0"
		
		defines
		{
			"GE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
	    defines "GE_DEBUG"
		symbols "On"

	filter "configurations:Release"
	    defines "GE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
	    defines "GE_DIST"
		optimize "On"