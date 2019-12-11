#!/bin/sh

echo "Beginning test input redirection tests"

../rshell << EOL
cat < ../names.txt
exit
EOL
