cmake_minimum_required(VERSION 3.16)
project(821data_structures)

set(CMAKE_CXX_STANDARD 20)

add_executable(821data_structures main.cpp LinearList.cpp LinearList.h Vector.h Vector.cpp Sort.h CMyString.h CMyString.cpp Stack.h Stack.cpp WDString.h WDString.cpp LinkList/node.h LinkList/node.cpp LinkList/linkedlist.h LinkList/linkedlist.cpp LinkList/linkedstack.cpp LinkList/linkedstack.h LinkList/linkedqueque.h LinkList/linkedqueue.cpp)
add_executable(algorithm1 Algorithm/1.1.cpp)
add_executable(algorithm6.1 Algorithm/6.1.cpp)
add_executable(KMP Test/KMP_Next.cpp)
add_executable(TianQin TianQin/main.cpp TianQin/example2.3.cpp TianQin/TianQin.h TianQin/LinearList.cpp TianQin/practise3.7.cpp TianQin/practise3.6.cpp TianQin/Sort.cpp)