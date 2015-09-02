PROJECT (t3DataStructures)
cmake_minimum_required(VERSION 2.6)

#head file path
INCLUDE_DIRECTORIES(
	./t3DataStructures
)

#AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#set envirronment variable
#SET(t3DS ${t3DS_SRCS})

#add file to ide
#main
FILE(GLOB MAIN "./t3DataStructures/*.cpp") 
SOURCE_GROUP("main" FILES ${MAIN})

#Common
FILE(GLOB Common_H "./t3DataStructures/Common/*.h") 
SOURCE_GROUP("Common" FILES ${Common_H})

FILE(GLOB Common_CPP "./t3DataStructures/Common/*.cpp") 
SOURCE_GROUP("Common" FILES ${Common_CPP})

#LinearList
FILE(GLOB LinearList_H "./t3DataStructures/LinearList/*.h") 
SOURCE_GROUP("LinearList" FILES ${LinearList_H})

FILE(GLOB LinearList_CPP "./t3DataStructures/LinearList/*.cpp") 
SOURCE_GROUP("LinearList" FILES ${LinearList_CPP})

#LinkList
FILE(GLOB LinkList_H "./t3DataStructures/LinkList/*.h") 
SOURCE_GROUP("LinkList" FILES ${LinkList_H})

FILE(GLOB LinkList_CPP "./t3DataStructures/LinkList/*.cpp") 
SOURCE_GROUP("LinkList" FILES ${LinkList_CPP})

#SparseMatrix
FILE(GLOB SparseMatrix_H "./t3DataStructures/SparseMatrix/*.h") 
SOURCE_GROUP("SparseMatrix" FILES ${SparseMatrix_H})

FILE(GLOB SparseMatrix_CPP "./t3DataStructures/SparseMatrix/*.cpp") 
SOURCE_GROUP("SparseMatrix" FILES ${SparseMatrix_CPP})

#String
FILE(GLOB String_H "./t3DataStructures/String/*.h") 
SOURCE_GROUP("String" FILES ${String_H})

FILE(GLOB String_CPP "./t3DataStructures/String/*.cpp") 
SOURCE_GROUP("String" FILES ${String_CPP})

#Test
FILE(GLOB Test_H "./t3DataStructures/Test/*.h") 
SOURCE_GROUP("Test" FILES ${Test_H})

#FILE(GLOB Test_CPP "./t3DataStructures/Test/*.cpp") 
#SOURCE_GROUP("Test" FILES ${Test_CPP})

#Tree
FILE(GLOB Tree_H "./t3DataStructures/Tree/*.h") 
SOURCE_GROUP("Tree" FILES ${Tree_H})

FILE(GLOB Tree_CPP "./t3DataStructures/Tree/*.cpp") 
SOURCE_GROUP("Tree" FILES ${Tree_CPP})

#add executable file
ADD_EXECUTABLE(t3DataStructures ${MAIN} 
	${Common_H} ${Common_CPP} 
	${LinearList_H} ${LinearList_CPP}
	${LinkList_H} ${LinkList_CPP}
	${SparseMatrix_H} ${SparseMatrix_CPP}
	${String_H} ${String_CPP}
	${Test_H}
	${Tree_H} ${Tree_CPP})