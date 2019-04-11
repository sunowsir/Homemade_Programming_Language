CC 		= g++
CFLAGS 	= -g -I include 
VPATH 	= ../:../src/:../include/:../lib/

RELY = \
	main.o \
	CC_SynTree.o \
	CC_Types.o \
	CC_VarStore.o \
	CC_ResponChain.o \
	ExprCppTreeLexer.o \
	ExprCppTreeParser.o \
	$(shell ls ../lib/1.Need_file/*.o 2> /dev/null | tr -s '\n' ' ') 

kscc : ${RELY}
	@echo "[\033[1;32mLINK\033[0m] cc -g -I include -Wall *.o"
	@${CC} ${CFLAGS} -Wall ${RELY} -o kscc

main.o : main.cpp
	@echo "[\033[1;32mBuilding\033[0m] cc -c -g -I include -Wall main.cpp"
	@${CC} -c ${CFLAGS} -Wall $<

CC_ResponChain.o : CC_ResponChain.cpp CC_ResponChain.h
	@echo "[\033[1;32mBuilding\033[0m] cc -c -g -I include -Wall CC_ResponChain.cpp"
	@${CC} -c ${CFLAGS} -Wall $< 

CC_SynTree.o : CC_SynTree.cpp CC_SynTree.h
	@echo "[\033[1;32mBuilding\033[0m] cc -c -g -I include -Wall CC_SynTree.cpp"
	@${CC} -c ${CFLAGS} -Wall $< 

CC_Types.o : CC_Types.cpp CC_Types.h
	@echo "[\033[1;32mBuilding\033[0m] cc -c -g -I include -Wall CC_Types.cpp"
	@${CC} -c ${CFLAGS} -Wall $<

CC_VarStore.o : CC_VarStore.cpp CC_VarStore.h
	@echo "[\033[1;32mBuilding\033[0m] cc -c -g -I include -Wall CC_VarStore.cpp"
	@${CC} -c ${CFLAGS} -Wall $<

ExprCppTreeLexer.o : ExprCppTreeLexer.c ExprCppTreeLexer.h
	@echo "[\033[1;32mBuilding\033[0m] cc -c -g -I include ExprCppTreeLexer.c"
	@${CC} -c ${CFLAGS} $<


ExprCppTreeParser.o : ExprCppTreeParser.c ExprCppTreeParser.h
	@echo "[\033[1;32mBuilding\033[0m] cc -c -g -I include ExprCppTreeParser.c"
	@${CC} -c ${CFLAGS} $<


.PHONY : genTree install remove clean 

genTree : 
	@echo "[\033[1;33mJAVA\033[0m] Build Syntax Tree"
	@java -jar ../lib/1.Need_file/1.Antlr_3.4/antlr-3.4-complete.jar ../lib/ExprCppTree.g

install : 
	@echo "[\033[1;34mINSTALL\033[0m] copy 'kscc' to '/usr/bin'"
	@sudo cp kscc /usr/bin/

remove : 
	@echo "[\033[1;35mREMOVE\033[0m] remove 'kscc' from '/usr/bin'"
	@sudo rm -rf /usr/bin/kscc

clean : 
	@echo "[\033[1;36mCLEAN\033[0m] clean 'kscc' and '*.o'"
	@rm -rf kscc *.o


