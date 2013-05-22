REM build the main firmware
REM ---------------------------------------------------------------

SET projfile=%CD%\"Sonar Launchpad".rprj

CALL ..\substitute.bat PROJECT_PATH "%projfile%" build.js>intbuild.js
CALL ..\substitute.bat \ "\\" intbuild.js>dobuild.js

SET scriptfile=%CD%\dobuild.js

"C:\Program Files\Raisonance\Ride\bin\Ride7.exe" -p %scriptfile%

.\cortex-apps\versionate main/obj/main.hex 08003130 -version 999 -quiet
REM .\cortex-apps\concat bootloader/obj/bootloader.hex main/obj/main.hex main.hex
COPY main/obj/main.hex main.hex
.\cortex-apps\hextosyx main.hex 8003000 -id0033 -n32
