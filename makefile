all: ./build/main.o ./build/excecao.o ./build/utilitarios.o ./build/painel.o ./build/funcionario.o ./build/animais.o ./build/paineis.o
	g++ -Wall -ansi -pedantic -g -o ./bin/program.out ./build/*.o

./build/main.o:
	g++ -c ./src/main.cpp -I ./include -o ./build/main.o

./build/utilitarios.o:
	g++ -c ./src/utilitarios.cpp -I ./include -o ./build/utilitarios.o

./build/excecao.o:
	g++ -c ./src/excecao/excecao.cpp -I ./include -o ./build/excecao.o

./build/painel.o:
	g++ -c ./src/painel/painel.cpp -I ./include -o ./build/painel.o

./build/funcionario.o:
	g++ -c ./src/funcionario/funcionario.cpp -I ./include -o ./build/funcionario.o
	g++ -c ./src/funcionario/tratador.cpp -I ./include -o ./build/tratador.o
	g++ -c ./src/funcionario/veterinario.cpp -I ./include -o ./build/veterinario.o

./build/animais.o: ./build/animal.o ./build/animal_silvestre.o ./build/animal_exotico.o ./build/animal_nativo.o

./build/animal.o:
	g++ -c ./src/animal/animal.cpp -I ./include -o ./build/animal.o
	g++ -c ./src/animal/anfibio/anfibio.cpp -I ./include -o ./build/anfibio.o
	g++ -c ./src/animal/ave/ave.cpp -I ./include -o ./build/ave.o
	g++ -c ./src/animal/mamifero/mamifero.cpp -I ./include -o ./build/mamifero.o
	g++ -c ./src/animal/reptil/reptil.cpp -I ./include -o ./build/reptil.o

./build/animal_silvestre.o:
	g++ -c ./src/animal_silvestre/animal_silvestre.cpp -I ./include -o ./build/animal_silvestre.o
	g++ -c ./src/animal_silvestre/animal_nativo.cpp -I ./include -o ./build/animal_nativo.o
	g++ -c ./src/animal_silvestre/animal_exotico.cpp -I ./include -o ./build/animal_exotico.o

./build/animal_exotico.o:
	g++ -c ./src/animal/anfibio/anfibio_exotico.cpp -I ./include -o ./build/anfibio_exotico.o
	g++ -c ./src/animal/ave/ave_exotico.cpp -I ./include -o ./build/ave_exotico.o
	g++ -c ./src/animal/mamifero/mamifero_exotico.cpp -I ./include -o ./build/mamifero_exotico.o
	g++ -c ./src/animal/reptil/reptil_exotico.cpp -I ./include -o ./build/reptil_exotico.o

./build/animal_nativo.o:
	g++ -c ./src/animal/anfibio/anfibio_nativo.cpp -I ./include -o ./build/anfibio_nativo.o
	g++ -c ./src/animal/ave/ave_nativo.cpp -I ./include -o ./build/ave_nativo.o
	g++ -c ./src/animal/mamifero/mamifero_nativo.cpp -I ./include -o ./build/mamifero_nativo.o
	g++ -c ./src/animal/reptil/reptil_nativo.cpp -I ./include -o ./build/reptil_nativo.o


./build/paineis.o:
	g++ -c ./src/paineis.cpp -I ./include -o ./build/paineis.o

clear:
	rm ./build/*
	rm ./bin/*

run:
	./bin/program.out