cmake_minimum_required(VERSION 3.13)
project(DataStructureCpp)

set(CMAKE_CXX_STANDARD 11)


add_executable(Union Union/status.h Union/SequenceList.h Union/SequenceListBasicOperations.cpp Union/Union.h Union/Unino_main.cpp)

add_executable(MergeList Union/status.h Union/SequenceList.h Union/SequenceListBasicOperations.cpp MergeList/MergeList.h MergeList/MergeList.cpp MergeList/MergeList_main.cpp)
