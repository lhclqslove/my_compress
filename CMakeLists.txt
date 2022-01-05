cmake_minimum_required(VERSION 3.12)
project(my_compress)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_compress src/main.cpp include/compress.h)
#boost
set( Boost_NO_SYSTEM_PATHS ON ) # do not use system boost
add_subdirectory(boost-cmake)

#xxhash
find_package(xxHash 0.7 CONFIG REQUIRED)
target_link_libraries(my_compress PRIVATE xxHash::xxhash)
# libbsc
add_library(my_compresslib
        STATIC
            src/dnaToBits.cpp
            src/ReadData.cpp
            include/dnaToBits.h
            include/ReadData.h
            include/Types.h
            include/Compressor.h
            src/Compressor.cpp
            include/ReadFilter.h

        )
target_include_directories(my_compresslib
        PUBLIC include src
        )
target_link_libraries(my_compress PUBLIC my_compresslib)
if(OpenMP_CXX_FOUND)
    target_link_libraries(my_compress PUBLIC OpenMP::OpenMP_CXX -DLIBBSC_OPENMP_SUPPORT)
endif()
