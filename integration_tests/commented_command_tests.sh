#!/bin/sh

echo "Beginning single command tests"
echo "Testing commands in order: echo hello world \#, echo hello \# world, echo \# hello world"
../rshell << EOL
echo hello world #
echo hello # world
echo # hello world
exit
EOL 