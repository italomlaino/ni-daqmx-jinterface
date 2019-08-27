@ECHO OFF

:: Variables
SET "CLASS_NAME=com.NIDAQmxJWrapper"
SET "PROJECT_FOLDER=C:\Users\Adm\VirtualBox Shared Folder\NIDAQmxJInterface\NIDAQmxJWrapper-Java\build\classes"
SET "OUTPUT_DIR=C:\Users\Adm\VirtualBox Shared Folder\NIDAQmxJInterface\NIDAQmxJWrapper\NIDAQmxJWrapper\NIDAQmxJWrapper.h"

:: Generate JNI header
javah -classpath "%PROJECT_FOLDER%" -o "%OUTPUT_DIR%" -force "%CLASS_NAME%"