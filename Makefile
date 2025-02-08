a.out: project2.cpp AvlTree.h AvlTree.cpp
	g++ project2.cpp AvlTree.h

test: a.out
	@echo -e "\n"
	@echo "#################### TEST CASE 1 #############################"
	@./a.out < input1
	@echo -e "\n"
	@echo "#################### TEST CASE 2 #############################"
	@./a.out < input2

turnin: project2.cpp
	@/export/home/public/zhang/csc402/turnin/turnin-project2 project2.cpp AvlTree.h AvlTree.cpp Makefile input* dsexceptions.h

clean:
	rm -f a.out AvlTree.h.gch *~