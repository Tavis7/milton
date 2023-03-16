#!/bin/bash

# This script passes its arguments to cmake directly. The following may be
# particularly useful:
#
# `-DCMAKE_BUILD_TYPE=Debug`
# `-DCMAKE_BUILD_TYPE=Release`
# `-DCMAKE_CXX_FLAGS="-Wno-deprecated-declarations"`

MYDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $MYDIR

# Build and install the cmake static library and headers into a subdirectory
# Specifically: third_party/SDL2-2.0.3/build/linux64/{lib,include}
#
# This really should become an ExternalProject_Add inside the CMakelists.txt
# and windows, linux, and osx should all use the same approach for building cmake.
pushd third_party/SDL2-2.0.8
    CMAKE_CMD='cmake
    -D ARTS:BOOL=OFF
    -D ALSA:BOOL=OFF
    -D PULSEAUDIO:BOOL=OFF
    -D OSS:BOOL=OFF
    -D ESD:BOOL=OFF
    -D SDL_SHARED:BOOL=OFF
    -D VIDEO_WAYLAND:BOOL=OFF
    -D CMAKE_INSTALL_PREFIX="../linux64"
    -G "Unix Makefiles"
    -D CMAKE_DEBUG_POSTFIX="_debug"
    -D SDL_STATIC_PIC:BOOL=ON
    '

    mkdir -p build/linrelease
    pushd build/linrelease
        eval $CMAKE_CMD "$@" ../.. || exit 1
        make -j install || exit 1
    popd
popd

mkdir -p build
cd build

cmake "$@" .. || exit 1
make -j || exit 1
