g++ 1014_mk.cpp -g -o  mk -Wall -std=c++11
g++ 1014.cpp -g -o A -Wall -std=c++11
g++ 1014_std.cpp -g -o A_ -Wall -std=c++11
:loop
mk
A
A_
fc 1014.out 1014_std.out
if errorlevel==1 pause
goto loop
