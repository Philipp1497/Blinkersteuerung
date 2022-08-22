pushd %CD%
echo %CD%
ceedling gcov:all utils:gcov > Tools\\ReqCoverage\\log.txt
popd
rem pause