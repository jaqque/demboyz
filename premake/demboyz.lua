
solution "demboyz"
    basedir ".."
    location (_ACTION)
    startproject "demboyz"
    configurations { "Debug", "Release" }
    platforms "x32"
    
    project "demboyz"
        kind "ConsoleApp"
        language "C++"
        files
        {
            "../demboyz/*.h",
            "../demboyz/*.cpp",
            "../demboyz/netmessages/*.h",
            "../demboyz/netmessages/*.cpp",
            "../external/sourcesdk/*.h",
            "../external/sourcesdk/*.cpp"
        }
        includedirs
        {
            "../external/sourcesdk"
        }

        configuration "Debug"
            targetdir (_ACTION .. "/build/Debug")
            defines { "DEBUG" }
            flags { "Symbols" }

        configuration "Release"
            targetdir (_ACTION .. "/build/Release")
            defines { "NDEBUG" }
            optimize "Full"
