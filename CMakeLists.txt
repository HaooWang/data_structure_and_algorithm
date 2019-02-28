cmake_minimum_required(VERSION 3.13)
project(DataStructureCpp)

set(CMAKE_CXX_STANDARD 11)


add_executable(Union 01SqList/Union/status.h 01SqList/Union/SequenceList.h 01SqList/Union/SequenceListBasicOperations.cpp 01SqList/Union/Union.h 01SqList/Union/Unino_main.cpp)

add_executable(MergeList 01SqList/Union/status.h 01SqList/Union/SequenceList.h 01SqList/Union/SequenceListBasicOperations.cpp 01SqList/MergeList/MergeList.h 01SqList/MergeList/MergeList.cpp 01SqList/MergeList/MergeList_main.cpp)

add_executable(LinkedList 02LinkedList/SourceFile/main.cpp)