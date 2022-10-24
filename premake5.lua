include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "TerrariumGame"
	architecture "x86_64"
	startproject "TerrariumGame"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Terrarium/vendor/GLFW"
	include "Terrarium/vendor/Glad"
	include "Terrarium/vendor/imgui"
group ""

group "Core"
	include "Terrarium"
group ""

include "TerrariumGame"
