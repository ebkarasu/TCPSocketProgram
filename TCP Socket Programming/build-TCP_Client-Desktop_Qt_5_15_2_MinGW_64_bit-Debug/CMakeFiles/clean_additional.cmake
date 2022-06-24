# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TCP_Client_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TCP_Client_autogen.dir\\ParseCache.txt"
  "TCP_Client_autogen"
  )
endif()
