# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\visual_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\visual_autogen.dir\\ParseCache.txt"
  "visual_autogen"
  )
endif()
