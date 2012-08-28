# executable files for this directory
OBJECTS = main.out

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../../GNU_makefile_template

main.out: TextQuery.o main.o
	$(CC) $(CCFLAGS) TextQuery.o main.o -o main.out
	rm *.gch
tags: 
	ctags -R --c++-kinds=+p --fields=+iaS --extra=+q 
