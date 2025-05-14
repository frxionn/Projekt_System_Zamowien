# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Projekt_System_Zamowien_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Projekt_System_Zamowien_autogen.dir\\ParseCache.txt"
  "Projekt_System_Zamowien_autogen"
  )
endif()
