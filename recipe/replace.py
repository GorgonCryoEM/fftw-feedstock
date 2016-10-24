import fileinput
import re

for line in fileinput.input(inplace=1, backup='.bak'):
    if line.rstrip() == '#undef inline':
        print(line.rstrip())
    elif line.rstrip()=='#undef SIZEOF_VOID_P':
        print("#define SIZEOF_VOID_P @CMAKE_SIZEOF_VOID_P@")
    elif line.rstrip()=='#undef SIZEOF_DOUBLE':
        print("#define SIZEOF_DOUBLE @SIZEOF_DOUBLE@")
    elif line.rstrip()=='#undef SIZEOF_FLOAT':
        print("#define SIZEOF_FLOAT @SIZEOF_FLOAT@")
    elif line.rstrip()=='#undef SIZEOF_INT':
        print("#define SIZEOF_INT @SIZEOF_INT@")
    elif line.rstrip()=='#undef SIZEOF_LONG':
        print("#define SIZEOF_LONG @SIZEOF_LONG@")
    elif line.rstrip()=='#undef SIZEOF_LONG_LONG':
        print("#define SIZEOF_LONG_LONG @SIZEOF_LONG_LONG@")
    elif line.rstrip()=='#undef SIZEOF_PTRDIFF_T':
        print("#define SIZEOF_PTRDIFF_T @SIZEOF_PTRDIFF_T@")
    elif line.rstrip()=='#undef SIZEOF_SIZE_T':
        print("#define SIZEOF_SIZE_T @SIZEOF_SIZE_T@")
    elif line.rstrip()=='#undef SIZEOF_UNSIGNED_INT':
        print("#define SIZEOF_UNSIGNED_INT @SIZEOF_UNSIGNED_INT@")
    elif line.rstrip()=='#undef SIZEOF_UNSIGNED_LONG':
        print("#define SIZEOF_UNSIGNED_LONG @SIZEOF_UNSIGNED_LONG@")
    elif line.rstrip()=='#undef SIZEOF_UNSIGNED_LONG_LONG':
        print("#define SIZEOF_UNSIGNED_LONG_LONG @SIZEOF_UNSIGNED_LONG_LONG@")

    else:
        line = re.sub('#undef','#cmakedefine', line.rstrip())
        print(line)
