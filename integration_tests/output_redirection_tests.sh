#!/bin/sh

echo "Beginning output redirection tests"

echo "Testing single output"
../rshell << EOL
touch  aFile.txt
echo "Hello World" > aFile.txt
cat aFile.txt
exit
EOL

echo "Testing single output override"
../rshell << EOL 
echo "This input should be the first one in the file " > aFile.txt
cat aFile.txt
exit
EOL

echo "Testing single output append"
../rshell << EOL
echo "This input should be appended to existing input " >> aFile.txt
cat aFile.txt
rm aFile.txt
exit
EOL
