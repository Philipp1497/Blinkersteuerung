pushd %CD%
echo %CD%
ceedling gcov:all utils:gcov -I%CD% > Tools\\ReqCoverage\\log.txt
popd
rem pause