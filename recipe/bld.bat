copy %RECIPE_DIR%\\cmake\\CMakeLists.txt .

%PYTHON% %RECIPE_DIR%\\replace.py config.h.in

if errorlevel 1 exit 1

mkdir build && cd build

set "cmake_config_options=-DHAVE_THREADS=1 -DDISABLE_FORTRAN=1"

:: single
set "cmake_config_options_single=-DFFTW_SINGLE=1 -DHAVE_SSE2=1 -DHAVE_AVX=1"

:: double
set "cmake_config_options_double=-DHAVE_SSE2=1 -DHAVE_AVX=1"

:: long double
set "cmake_config_options_long_double=-DFFTW_LDOUBLE=1"

:: foreach lib in libfftw, libfftwf, libfftwl
set libs="libfftw libfftwf libfftwl"

:: set cmake_gen="NMake Makefiles"
set cmake_gen="Visual Studio 9 2008 Win64"

set lib=libfftw
echo %lib%
cmake .. -G %cmake_gen% ^
        -DLIBFFTW_NAME=%lib% ^
        %cmake_config_options% ^
        %cmake_config_options_single%
cmake --build . --config Release --target install

:: set lib=libfftwf
:: echo %lib
:: cmake .. -DLIBFFTW_NAME=%lib --config Release "%cmake_config_options%" "%cmake_config_options_double%"
:: cmake --build . --config Release --target install
:: 
:: set lib=libfftwl
:: echo %lib
:: cmake .. -DLIBFFTW_NAME=%lib --config Release "%cmake_config_options%" "%cmake_config_options_long_double%"
:: cmake --build . --config Release --target install

:: copy DLLs to LIBRARY_BIN
::copy libfftw3*-3.dll "%LIBRARY_BIN%\"

:: copy .lib "import libraries" to LIBRARY_LIB
::copy libfftw3*-3.lib "%LIBRARY_LIB%\"

:: copy headers to LIBRARY_INC
::copy *.h "%LIBRARY_INC%\"

if errorlevel 1 exit 1
