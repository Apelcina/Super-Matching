workspace "Super-Matching"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release"
    }

outputdir= "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Super-Matching"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

    filter "configurations:Debug"
        defines "DEBUG"
        optimize "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"