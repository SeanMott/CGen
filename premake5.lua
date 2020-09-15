--CGen, a library for generating and compiling C code.
project "CGen"
    kind "StaticLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")
    
    files 
    {
        "src/**.h",
        "src/**.c",
        "src/**.cpp",
        "src/**.hpp"
    }

    includedirs
    {
        "src",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
    filter "configurations:Debug"
        defines "CG_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "CG_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "CG_DIST"
        optimize "On"