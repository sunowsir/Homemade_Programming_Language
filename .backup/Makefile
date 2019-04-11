CC=g++
CFLAGS=-g -Wall 

NOW_DIR=$(shell pwd)
Build_DIR=${NOW_DIR}/1.CC_Build
Src_DIR=${NOW_DIR}/2.CC_src
Include_DIR=${NOW_DIR}/4.CC_include
Program_DIR=${NOW_DIR}/3.CC_Program
Lib_DIR=${NOW_DIR}/5.CC_lib

RELY = \
	${Build_DIR}/main_cc.o \
	${Build_DIR}/ExprTreeEvaluator.o \
	${Build_DIR}/ExprCppTreeLexer.o \
	${Build_DIR}/ExprCppTreeParser.o \
	$(shell ls ${Lib_DIR}/1.Need_file/*.o 2> /dev/null | tr -s '\n' ' ') 

${Program_DIR}/kscc : ${RELY}
	${CC} ${CFLAGS} ${RELY} -o ${Program_DIR}/kscc

${Build_DIR}/main_cc.o : ${Src_DIR}/main_cc.cpp ${Include_DIR}/ExprTreeEvaluator.h
	${CC} -c ${CFLAGS} ${Src_DIR}/main_cc.cpp -o ${Build_DIR}/main_cc.o 

${Build_DIR}/ExprTreeEvaluator.o : ${Src_DIR}/ExprTreeEvaluator.cpp ${Include_DIR}/ExprTreeEvaluator.h
	${CC} -c ${CFLAGS} ${Src_DIR}/ExprTreeEvaluator.cpp -o ${Build_DIR}/ExprTreeEvaluator.o 

${Build_DIR}/ExprCppTreeLexer.o : ${Lib_DIR}/ExprCppTreeLexer.c ${Lib_DIR}/ExprCppTreeLexer.h
	${CC} -c ${CFLAGS} ${Lib_DIR}/ExprCppTreeLexer.c -o ${Build_DIR}/ExprCppTreeLexer.o 


${Build_DIR}/ExprCppTreeParser.o : ${Lib_DIR}/ExprCppTreeParser.c ${Lib_DIR}/ExprCppTreeParser.h
	${CC} -c ${CFLAGS} ${Lib_DIR}/ExprCppTreeParser.c -o ${Build_DIR}/ExprCppTreeParser.o 


.PHONY : genTree install uninstall clean 

genTree : 
	java -jar ${Lib_DIR}/1.Need_file/1.Antlr_3.4/antlr-3.4-complete.jar ${Lib_DIR}/ExprCppTree.g

install : 
	sudo cp ${Program_DIR}/kscc /usr/bin/

uninstall : 
	sudo rm -rf /usr/bin/kscc

clean : 
	rm -rf ${Program_DIR}/kscc ${Build_DIR}/*.o



