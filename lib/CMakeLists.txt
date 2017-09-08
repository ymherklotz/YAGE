# ----------------------------------------------------------------------------
# CMakeLists.txt
#
# Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
# See file LICENSE for more details
# ----------------------------------------------------------------------------

# Initializing google test
# prevents overriding the parent project's compiler/linter settings on windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest")

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# include headers for rapidjson, no need to build it
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/rapidjson/include")
