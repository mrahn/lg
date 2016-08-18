# mirko.rahn@web.de

cmake_minimum_required (VERSION "2.8.4" FATAL_ERROR)

set (HTMLCXX_PREFIX "" CACHE PATH "Path to a htmlcxx installation")

find_path (HTMLCXX_INCLUDE_DIR htmlcxx/html/ParserDom.h
  PATHS ${HTMLCXX_PREFIX}/include
)
find_library (HTMLCXX_LIBRARY NAMES htmlcxx
  PATHS ${HTMLCXX_PREFIX}/lib
)

if (HTMLCXX_INCLUDE_DIR AND HTMLCXX_LIBRARY)
  get_filename_component (HTMLCXX_LIBRARY_DIR ${HTMLCXX_LIBRARY} PATH)
else()
  message (FATAL_ERROR "Could not find HTMLCXX")
endif()

include_directories (SYSTEM "${HTMLCXX_INCLUDE_DIR}")

add_definitions ("--std=c++11")
add_definitions ("-Wall")
add_definitions ("-Wextra")
add_definitions ("-Werror")
add_definitions ("-O3")

add_executable (tournament tournament.cpp)
target_link_libraries (tournament
  "${HTMLCXX_LIBRARY}"
)
