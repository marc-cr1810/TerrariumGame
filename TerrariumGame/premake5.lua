project "TerrariumGame"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Terrarium/vendor/spdlog/include",
		"%{wks.location}/Terrarium/src",
		"%{wks.location}/Terrarium/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Terrarium"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "TE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TE_DIST"
		runtime "Release"
		optimize "on"
