cmake_minimum_required(VERSION 2.6)

PROJECT(fftw)

SET(FFTW_VERSION 3.3.5)

set(src_dirs
    ${CMAKE_SOURCE_DIR}/api
    ${CMAKE_SOURCE_DIR}/kernel
    ${CMAKE_SOURCE_DIR}/dft
    ${CMAKE_SOURCE_DIR}/dft/scalar
    ${CMAKE_SOURCE_DIR}/dft/scalar/codelets
    ${CMAKE_SOURCE_DIR}/rdft
    ${CMAKE_SOURCE_DIR}/rdft/scalar
    ${CMAKE_SOURCE_DIR}/rdft/scalar/r2cf
    ${CMAKE_SOURCE_DIR}/rdft/scalar/r2cb
    ${CMAKE_SOURCE_DIR}/rdft/scalar/r2r
    ${CMAKE_SOURCE_DIR}/reodft
    ${CMAKE_SOURCE_DIR}/simd-support
    ${CMAKE_SOURCE_DIR}/dft/simd
    ${CMAKE_SOURCE_DIR}/rdft/simd
    ${CMAKE_SOURCE_DIR}/dft/simd
    ${CMAKE_SOURCE_DIR}/rdft/simd
    ${CMAKE_SOURCE_DIR}/threads
)

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}
    ${src_dirs}
)

foreach(dir ${src_dirs})
    file(GLOB_RECURSE srcs ${dir} "*.c")
endforeach()

INCLUDE (CheckTypeSize)
CHECK_TYPE_SIZE("double"             SIZEOF_DOUBLE)
CHECK_TYPE_SIZE("float"              SIZEOF_FLOAT)
CHECK_TYPE_SIZE("int"                SIZEOF_INT)
CHECK_TYPE_SIZE("long"               SIZEOF_LONG)
CHECK_TYPE_SIZE("long long"          SIZEOF_LONG_LONG)
CHECK_TYPE_SIZE("ptrdiff_t"          SIZEOF_PTRDIFF_T)
CHECK_TYPE_SIZE("size_t"             SIZEOF_SIZE_T)
CHECK_TYPE_SIZE("unsigned int"       SIZEOF_UNSIGNED_INT)
CHECK_TYPE_SIZE("unsigned long"      SIZEOF_UNSIGNED_LONG)
CHECK_TYPE_SIZE("unsigned long long" SIZEOF_UNSIGNED_LONG_LONG)

#set(srcs ${CMAKE_SOURCE_DIR}/api/configure.c)
configure_file(${CMAKE_SOURCE_DIR}/config.h.in
        ${CMAKE_SOURCE_DIR}/config.h
)

set(LIBFFTW_NAME "${LIBFFTW_NAME}-${FFTW_VERSION}")
ADD_LIBRARY(${LIBFFTW_NAME} SHARED ${srcs})

#set_target_properties(libfftwf-${FFTW_VERSION} PROPERTIES
#                      COMPILE_DEFINITIONS "BENCHFFT_SINGLE=1;FFTW_SINGLE=1")

INSTALL(FILES ${PROJECT_SOURCE_DIR}/api/fftw3.h
        DESTINATION $ENV{LIBRARY_INC}/include)

INSTALL(TARGETS ${LIBFFTW_NAME}
        RUNTIME DESTINATION $ENV{LIBRARY_BIN}
        LIBRARY DESTINATION $ENV{LIBRARY_LIB}
        ARCHIVE DESTINATION $ENV{LIBRARY_LIB}
)
