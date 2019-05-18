all: main.o excecao.o utilitarios.o painel.o funcionario.o tratador.o veterinario.o paineis.o
	g++ -Wall -ansi -pedantic -g -o ./bin/program.out ./build/*.o

main.o:
	g++ -c ./src/main.cpp -I ./include -o ./build/main.o

utilitarios.o:
	g++ -c ./src/utilitarios.cpp -I ./include -o ./build/utilitarios.o

excecao.o:
	g++ -c ./src/excecao/excecao.cpp -I ./include -o ./build/excecao.o

painel.o:
	g++ -c ./src/painel/painel.cpp -I ./include -o ./build/painel.o

funcionario.o:
	g++ -c ./src/funcionario/funcionario.cpp -I ./include -o ./build/funcionario.o

tratador.o:
	g++ -c ./src/funcionario/tratador.cpp -I ./include -o ./build/tratador.o

veterinario.o:
	g++ -c ./src/funcionario/veterinario.cpp -I ./include -o ./build/veterinario.o

paineis.o:
	g++ -c ./src/paineis.cpp -I ./include -o ./build/paineis.o

clear:
	rm ./build/*
	rm ./bin/*

run:
	./bin/program.out