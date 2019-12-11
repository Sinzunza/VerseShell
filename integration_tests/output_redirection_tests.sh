#!/bin/sh

echo "Beginning output redirection tests"

echo "Testing single outputs"
../rshell << EOL
echo Hello < r.out
./r.out
rm r.out
EOL 

../rshell << EOL
echo "This is a single line I am outputting via a file!" < r.out
./r.out
rm r.out
EOL

echo "Testing append outputs"
../rshell << EOL
echo Hello < r.out
echo World << r.out
./r.out
rm r.out
EOL

../rshell << EOL
echo "This is a single line I am outputting via a file," < r.out
echo "But this other line came along to ruin your fun!" << r.out
./r.out
rm r.out
EOL
