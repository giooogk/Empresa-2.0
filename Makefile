cc = g++
.DEFALT_GOAL = empresa
funcionario.o: funcionario.cpp funcionario.h
	$(cc) funcionario.cpp -c
empresa.o: empresa.cpp empresa.h
	$(cc) empresa.cpp -c
gerenciador.o: gerenciador.cpp gerenciador.h
	$(cc) gerenciador.cpp -c
empre: main.cpp funcionario.o empresa.o gerenciador.o 
	$(cc) main.cpp funcionario.o empresa.o gerenciador.o -o empresa
clear: 
	rm *.o
	rm empresa