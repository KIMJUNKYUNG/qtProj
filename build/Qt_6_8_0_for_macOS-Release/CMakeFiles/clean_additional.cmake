# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/qtProj_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/qtProj_autogen.dir/ParseCache.txt"
  "qtProj_autogen"
  )
endif()