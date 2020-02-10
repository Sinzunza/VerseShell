#!/bin/sh

echo "Beginning test symbolic tests"
echo "Testing commands in order: [ ../names.txt ],[ -e ../src/ ] , [ -f ../CMakeLists.txt ] , [ -d ../names.txt ], [ -d ../images/ ], echo hello && [ -e ../src/ ] || [ ../fail.txt ], [ ../names.txt ] && [ ..fail.txt ] || [ -d ../images/ ], ls || [ -f ../images/ ] && echo hello && [ -e ../names.txt ] " 
../VerseShell << EOL
[ ../names.txt ] 
[ -e ../src/ ]
[ -f ../CMakeLists.txt ]
[ -d ../names.txt ]
[ -d ../images/ ]
echo hello && [ -e ../src/ ] || [ ../fail.txt ]
[ ../names.txt ] && [ ../fail.txt ] || [ -d ../images/ ]
ls || [ -f ../images/ ] && echo hello && [ -e ../names.txt ]
exit
EOL 
