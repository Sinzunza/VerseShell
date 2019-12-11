#!/bin/sh

echo "Beginning test input redirection tests"

../rshell << EOL
cat < ../names.txt
exit
EOL

../rshell << EOL
cat < ../names.txt || cat < ../README.md
exit
EOL

../rshell << EOL
cat < ../names.txt && cat < ..names.txt
exit
EOL
