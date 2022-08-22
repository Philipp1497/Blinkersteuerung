

set defines=-DSPLINT -Dinterrupt=""

splint.exe Main.c %defines% >> log.txt 2>&1
splint.exe Taster.c %defines% >> log.txt 2>&1
splint.exe Timer.c %defines% >> log.txt 2>&1
splint.exe Init.c %defines% >> log.txt 2>&1
exit 0
pause