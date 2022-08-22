

set defines=-DSPLINT -Dinterrupt=""

splint.exe C:\Blinkersteuerung\Source\src\Main.c %defines% >> log.txt 2>&1
splint.exe C:\Blinkersteuerung\Source\src\Taster.c %defines% >> log.txt 2>&1
splint.exe C:\Blinkersteuerung\Source\src\Timer.c %defines% >> log.txt 2>&1
splint.exe C:\Blinkersteuerung\Source\src\Init.c %defines% >> log.txt 2>&1
exit 0
pause