set -e

REM cmake -G "NMake Makefiles" -D CMAKE_INSTALL_PREFIX=%LIBRARY_PREFIX% -D CMAKE_BUILD_TYPE=Release .

export LDFLAGS="-L${PREFIX}/lib"
export CFLAGS="${CFLAGS} -I${PREFIX}/include"

CONFIGURE="./configure --prefix=$PREFIX --with-pic --enable-shared --enable-threads --disable-fortran"

# (Note exported LDFLAGS and CFLAGS vars provided above.)
BUILD_CMD="make -j${CPU_COUNT}"
INSTALL_CMD="make install"

# Test suite
# tests are performed during building as they are not available in the
# installed package.
# Additional tests can be run with "make smallcheck" and "make bigcheck"
TEST_CMD="eval cd tests && ${LIBRARY_SEARCH_VAR}=\"$PREFIX/lib\" make check-local && cd -"

#
# We build 3 different versions of fftw:
#
build_cases=(
    # single
    "$CONFIGURE --enable-float --enable-sse --enable-sse2 --enable-avx"
    # double
    "$CONFIGURE --enable-sse2 --enable-avx"
    # long double (SSE2 and AVX not supported)
    "$CONFIGURE --enable-long-double"
)

for config in "${build_cases[@]}"
do
    :
    $config
    ${BUILD_CMD}
    ${INSTALL_CMD}
    ${TEST_CMD}
done

unset LIBRARY_SEARCH_VAR
unset DYLIB_EXT
unset CC
unset CXX
unset CXXFLAGS
unset CXX_LDFLAGS
unset LDFLAGS
unset CFLAGS
