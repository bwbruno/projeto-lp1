# projeto-lp1

## Autores

    Bruno Wagner
    José Alex
	Pedro Augusto

## Compilação

### Compilar e executar o código no terminal

	make
	make run

### Compilar documentação
É necessário ter o Doxygen e Graphviz instalados na sua plataforma.

	cd doc/
	doxygen

## Diretórios

	.
	├── bin
	├── build
	├── csv
	├── doc
	├── include
	└── src

### Conteúdo de cada diretório

- **bin**: Arquivos executáveis
- **build**: Arquivos objetos *.o
- **csv**: Arquivos csv para persistência dos dados do programa *.csv
- **doc**: Arquivo de configuração do Doxyfile para gerar a documentação usando Doxygen
- **include**: Arquivos de cabeçalho *.h
- **src**: Todos os códigos fontes *.cpp

#### Diretório include detalhado

	.
	├── animal
	│   ├── anfibio
	│   │   ├── anfibio_exotico.h
	│   │   ├── anfibio.h
	│   │   └── anfibio_nativo.h
	│   │
	│   ├── ave
	│   │   ├── ave_exotico.h
	│   │   ├── ave.h
	│   │   └── ave_nativo.h
	│   │
	│   ├── mamifero
	│   │   ├── mamifero_exotico.h
	│   │   ├── mamifero.h
	│   │   └── mamifero_nativo.h
	│   │
	│   ├── reptil
	│   │   ├── reptil_exotico.h
	│   │   ├── reptil.h
	│   │   └── reptil_nativo.h
	│   │
	│   └── animal.h
	│ 
	├── animal_silvestre
	│   ├── animal_exotico.h
	│   ├── animal_nativo.h
	│   └── animal_silvestre.h
	│ 
	├── crud
	│   ├── cadastrar.h
	│   ├── consultar.h
	│   └── operacoes_csv.h
	│ 
	├── excecao
	│   └── excecao.h
	│ 
	├── funcionario
	│   ├── funcionario.h
	│   ├── tratador.h
	│   └── veterinario.h
	│ 
	├── painel
	│   └── painel.h
	│ 
	├── paineis.h
	└── utilitarios.h

#### Diagrama do diretório include

![Diagrama do diretório include](doc/img/arquivos_include.jpg?raw=true)
