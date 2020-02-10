#!/bin/sh

echo "Beginning commented command tests"
echo "Testing commands in order: echo hello world \#, echo hello \# world, echo \# hello world"
../VerseShell << EOL
echo hello world #
echo hello # world
echo # hello world   
exit
EOL 
