@ECHO OFF

:: Variables
SET "MAIN_CLASS=com.cli.Main"

SET "OUTPUT_PATH=E:\NIDAQmxJInterface\Output"
SET "OUTPUT_FILE_PATH=%OUTPUT_PATH%\Output.txt"

:: Execute JAR and set output to OUTPUT file
java -Djava.library.path="%OUTPUT_PATH%" "%MAIN_CLASS%">"%OUTPUT_FILE_PATH%"

:: Show output
:: notepad "%OUTPUT_FILE_PATH%"

