#make file for the insertion of bst
editor: editor functions.o checker.o editor_finalee.o
	gcc -o editor functions.o checker.o editor_finalee.o
functions.o:functions.c
	gcc -c functions.c
editor_finalee.o:editor_finalee.c
	gcc -c editor_finalee.c
checker.o:checker.c
	gcc -c checker.c
	
