#!/bin/sh

echo "Beginning test literal tests"
echo "Testing commands in order: test ../names.txt, test -e ../src/, test -f ../CMakeLists.txt, test -d ../names.txt, test -d ../images/, echo hello && test -e ../src/ || test ../fail.txt, test ../names.txt && test ..fail.txt || test -d ../images/, ls || test -f ../images/ && echo hello && test -e ../names.txt " 
../VerseShell << EOL
test ../names.txt
test -e ../src/
test -f ../CMakeLists.txt
test -d ../names.txt
test -d ../images/
echo hello && test -e ../src/ || test ../fail.txt
test ../names.txt && test ../fail.txt || test -d ../images/
ls || test -f ../images/ && echo hello && test -e ../names.txt
exit
EOL 
