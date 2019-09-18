cmake_minimum_required(VERSION 3.12)

project(Merge C)

set(CMAKE_C_STANDARD 99)

add_library(LinkedRecords ../src/List.h ../src/LinkedRecords.c ../src/TestDynamicArray.h)

add_library(DynamicArray ../src/List.h ../src/DynamicArray.c ../src/TestDynamicArray.h)

add_library(unity ../src/unity_internals.h ../src/unity.h ../src/unity.c)

add_library(MergeAPI ../src/Merge.h ../src/Merge.c)
#----------------------------------------------------------------------------------

add_executable(Merge ../src/main.c)

target_link_libraries(Merge LinkedRecords MergeAPI)#Change 'LinkedRecords' with 'DynamicArray' if you want use DynamicArrays as list

set_target_properties(Merge PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../bin/Merge")
#-----------------------------------------------------------------------------------

add_executable(TestArray ../src/TestDynamicArray.c)

set_target_properties(TestArray PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../bin/TestArray")

target_link_libraries(TestArray DynamicArray unity)
#-----------------------------------------------------------------------------------

add_executable(TestLinkedRecords ../src/TestLinkedRecords.c)

set_target_properties(TestLinkedRecords PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../bin/TestLinkedRecords")

target_link_libraries(TestLinkedRecords LinkedRecords unity)

#------------------------------------------------------------------------------------
#------------------------------------------------------------------------------------

add_executable(MergeTestDynamicArray ../src/MergeTest.c)

target_link_libraries(MergeTestDynamicArray DynamicArray MergeAPI unity)

set_target_properties(MergeTestDynamicArray PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../bin/MergeTestDynamicArray")
#------
add_executable(MergeTestLinkedRecords ../src/MergeTest.c)

target_link_libraries(MergeTestLinkedRecords LinkedRecords MergeAPI unity)

set_target_properties(MergeTestLinkedRecords PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../bin/MergeTestLinkedRecords")
#------------------------------------------------------------------------------------