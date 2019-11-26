#!/bin/sh

echo "Beginning single command tests"
echo "Testing commands in order: echo "Hello World!", ls -f"
../rshell << EOL
echo "Hello World!"
ls -f
exit
EOL 
