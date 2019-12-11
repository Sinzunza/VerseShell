#!/bin/sh

echo "Beginning test pipe operator tests"

echo "Testing cat < ../names.txt | tr a-z A-Z"
../rshell << EOL
cat < ../names.txt | tr a-z A-Z
exit
EOL 

echo "Testing cat < ls | tr a-z A-Z"
../rshell << EOL
cat < ls | tr a-z A-Z
exit
EOL

echo "Testing cat < ls | tr a-z A-Z > r.out"
../rshell << EOL
cat < ls | tr a-z A-Z > r.out
./r.out
rm r.out
exit
EOL

echo "Performing compatability tests"
../rshell << EOL
cat < ../names.txt | tr a-z A-Z && cat < ../names.txt | tr A-Z a-z
exit
EOL

../rshell << EOL
cat < ../names.txt | tr a-z A-Z || cat < ../names.txt | tr A-Z a-z
exit
EOL
