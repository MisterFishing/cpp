发布源文件：
MyClass.cpp
MyStruct.cpp

使用源文件：
g++ test.cpp MyClass.cpp MyStruct.cpp -o test1.exe

发布目标文件：
g++ -c MyClass.cpp -o MyClass.o
g++ -c MyStruct.cpp -o MyStruct.o

使用目标文件：
g++ test.cpp MyClass.o MyStruct.o -o test2.exe

发布库文件：
ar -crv MyLib.a MyClass.o MyStruct.o
ar -t MyLib.a

使用库文件：
g++ test.cpp MyLib.a -o test3.exe
改名：libMy.a
g++ test.cpp -L. -lMy -o test4.exe
移动到库目录：mingw\lib
g++ test.cpp -lMy -o test5.exe



