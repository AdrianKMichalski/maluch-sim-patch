set GCC_32_BIT_PATH=C:\dev\mingw32\bin\gcc
set DEPENDENCIES=entry.c plugin.c patches.c memutils.c
%GCC_32_BIT_PATH% -m32 -Wall -g -shared -o ms1.asi %DEPENDENCIES%

set MS1_PATH="C:\games\Maluch sim"
copy /Y ms1.asi %MS1_PATH%\ms1.asi