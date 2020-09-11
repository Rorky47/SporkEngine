workspace "Spork"
    architecture "X86"

    configurations
    {
        "Debug",
        "Release",
        "Dist"

    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SporkEngine"
    location "Spork"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .."/%{prj.name}")

    pchheader "sppch.h"
    pchsource "Spork/src/sppch.h"

    files
    {

        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.location}/src",
        "%{prj.location}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SP_PLATFORM_WINDOWS",
            "SP_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/TestBox")
        }

    filter "configurations:Debug"
        defines "SP_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SP_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SP_DIST"
        optimize "On"

project "TestBox"
    location "TestBox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/".. outputdir .."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Spork/vendor/spdlog/include",
        "Spork/src"
    }
    
    links
    {
        "SporkEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
        "SP_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SP_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "SP_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SP_DIST"
        optimize "On"