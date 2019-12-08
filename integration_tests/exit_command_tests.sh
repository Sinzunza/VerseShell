#!/bin/sh

echo "Beginning exit command tests"
echo "Testing command: echo hello || exit; echo world && exit; echo you should not be able to see this"
../rshell << EOL
echo hello || exit; echo world && exit; echo you should not be able to see this
EOL 
