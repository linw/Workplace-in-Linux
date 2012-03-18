DIRS = Algorithms Cpp Java LearnMakefile

all:  
	cd Algorithms; make 
	cd Cpp; make 
	cd LearnMakefile; make 

clean: 
	cd Algorithms; make clean 
	cd Cpp; make clean 
	cd LearnMakefile; make clean 

clobber: 
	cd Algorithms;  make clobber 
	cd Cpp;  make clobber 
	cd LearnMakefile;  make clobber 

tags:
	cd Algorithms; make tags
	cd Cpp; make tags
	cd LearnMakefile; make tags
