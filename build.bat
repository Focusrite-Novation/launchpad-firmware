REM build the main firmware
REM ---------------------------------------------------------------
ECHO OFF

SET RIDE_EXE="C:\Program Files\Raisonance\Ride\bin\Ride7.exe"
SET projfile=%CD%\Sonar Launchpad.rprj
SET scriptfile=%CD%\dobuild.js

CALL substitute.bat PROJECT_PATH "%projfile%" build.js>intbuild.js
CALL substitute.bat \ "\\" intbuild.js>dobuild.js

ECHO RIDE path set to %RIDE_EXE%

%RIDE_EXE% -p %scriptfile%
IF NOT %ERRORLEVEL%==0 GOTO BuiLD_ERROR

.\cortex-apps\versionate "main/obj/Sonar Launchpad.hex" 08003130 -version 999 -quiet
REM .\cortex-apps\concat bootloader/obj/bootloader.hex main/obj/Sonar Launchpad.hex Sonar Launchpad.hex
COPY ".\main\obj\Sonar Launchpad.hex" ".\" /Y
.\cortex-apps\hextosyx "Sonar Launchpad.hex" 8003000 -id0020 -n32

ECHO Build succeeded!
PAUSE

exit

:BUILD_ERROR
ECHO Build failed!
PAUSE
