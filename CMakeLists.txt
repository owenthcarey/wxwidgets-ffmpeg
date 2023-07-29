cmake_minimum_required(VERSION 3.26)

# The path to vcpkg.cmake file provided by `vcpkg integrate install`
set(CMAKE_TOOLCHAIN_FILE /Users/owenthcarey/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project(wxwidgets_ffmpeg)

set(CMAKE_CXX_STANDARD 23)

# Find the wxWidgets library
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Find the FFmpeg libraries
find_package(FFmpeg COMPONENTS AVCODEC AVFORMAT AVUTIL SWSCALE)

# Add your executable
add_executable(wxwidgets_ffmpeg src/main.cpp src/ffmpegapp.cpp include/ffmpegapp.h src/ffmpegframe.cpp include/ffmpegframe.h)

# Link wxWidgets and FFmpeg to your target
target_link_libraries(wxwidgets_ffmpeg ${wxWidgets_LIBRARIES} ${FFmpeg_LIBRARIES})
