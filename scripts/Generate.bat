@ECHO OFF

:: Variables
SET "DEMO_PATH=C:\Users\Adm\Files\Projetos\NIDAQmxJInterface\Demo\bin"
SET "INTERFACE_PATH=C:\Users\Adm\Files\Projetos\NIDAQmxJInterface\NIDAQmxJInterface\bin"
SET "WRAPPER_PATH=C:\Users\Adm\Files\Projetos\NIDAQmxJInterface\NIDAQmxJWrapper\bin"
SET "WRAPPER_NATIVE_PATH=C:\Users\Adm\Files\Projetos\NIDAQmxJInterface\NIDAQmxJWrapperNative\Release\NIDAQmxJWrapperNative.dll"

SET "SCRIPT_PATH=C:\Users\Adm\Files\Projetos\NIDAQmxJInterface\Scripts\Execute.bat"

SET "OUTPUT_PATH=C:\Users\Adm\VirtualBox Shared Folder\NIDAQmxJInterface\Output"

:: Create output folder
xcopy /Y /I /E "%DEMO_PATH%" "%OUTPUT_PATH%"
xcopy /Y /I /E "%INTERFACE_PATH%" "%OUTPUT_PATH%"
xcopy /Y /I /E "%WRAPPER_PATH%" "%OUTPUT_PATH%"
xcopy /Y /I /E "%WRAPPER_NATIVE_PATH%" "%OUTPUT_PATH%"
xcopy /Y /I /E "%SCRIPT_PATH%" "%OUTPUT_PATH%"