#!/bin/sh

echo "Beginning multiple commands tests"
echo "Testing commands in order: echo \"Hello World!\" && ls -f, echo \"Hello World!\" || ls -f, badcommand && echo \"Good command!\", badcommand || echo \"Good command!\", echo \"hel\"; echo \"lo world\""
../rshell << EOL
echo "Hello World!" && ls -f
echo "Hello World!" || ls -f
badcommand && echo "Good command!"
badcommand || echo "Good command!"
echo "hel"; echo "lo world"
exit
EOL 
