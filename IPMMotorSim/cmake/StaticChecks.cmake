

# Use clang-tidy tool
option(ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)

if(ENABLE_CLANG_TIDY)
  message(STATUS "Looking for clang-tidy")
  find_program(CLANG_TIDY
               NAMES clang-tidy
               DOC "Path to the clang-tidy tool")
  if(CLANG_TIDY)
    message(STATUS "Looking for clang-tidy - found (${CLANG_TIDY})")
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY}  -header-filter=.)
  else()
    message(STATUS "Looking for clang-tidy - not found")
  endif()
endif()

# Use cppcheck tool
option(ENABLE_CPPCHECK "Enable cppcheck" OFF)

if(ENABLE_CPPCHECK)
  message(STATUS "Looking for cppcheck")
  find_program(CPPCHECK
              NAMES cppcheck
              DOC "Path to the cppcheck tool")
  if(CPPCHECK)
    message(STATUS "Looking for cppcheck - found (${CPPCHECK})")
    set(CMAKE_CXX_CPPCHECK
      "${CPPCHECK}"
      "--enable=style,performance,warning,portability"
      "--library=qt")

  else()
    message(STATUS "Looking for cppcheck - not found")
  endif()
endif()
