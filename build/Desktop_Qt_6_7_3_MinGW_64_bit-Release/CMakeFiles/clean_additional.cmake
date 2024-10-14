# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\imageRotationApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\imageRotationApp_autogen.dir\\ParseCache.txt"
  "imageRotationApp_autogen"
  )
endif()
