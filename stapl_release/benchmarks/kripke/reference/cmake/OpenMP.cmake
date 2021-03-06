#
# OpenMP
# 
option(ENABLE_OPENMP "Turn on compiler support for OpenMP" ON)
message(STATUS "OpenMP Support is ${ENABLE_OPENMP}")

if(${ENABLE_OPENMP})
  find_package(OpenMP)
  if (OPENMP_FOUND)
      set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
      set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
      add_definitions (-DKRIPKE_USE_OPENMP)
  endif()
endif()

