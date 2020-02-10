#!/bin/sh

echo "Beginning test input redirection tests"

../VerseShell << EOL
cat < ../names.txt
exit
EOL

../VerseShell << EOL
cat < ../names.txt || cat < ../README.md
exit
EOL

../VerseShell << EOL
cat < ../names.txt && cat < ../names.txt
exit
EOL
