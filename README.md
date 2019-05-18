# projeto-lp1

## Autores

    Bruno Wagner
    José Alex
	Pedro Augusto

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
	│   ├── animal.h
	│   ├── ave
	│   │   ├── ave_exotico.h
	│   │   ├── ave.h
	│   │   └── ave_nativo.h
	│   ├── mamifero
	│   │   ├── mamifero_exotico.h
	│   │   ├── mamifero.h
	│   │   └── mamifero_nativo.h
	│   └── reptil
	│       ├── reptil_exotico.h
	│       ├── reptil.h
	│       └── reptil_nativo.h
	├── animal_silvestre
	│   ├── animal_exotico.h
	│   ├── animal_nativo.h
	│   └── animal_silvestre.h
	├── crud
	│   ├── cadastrar.h
	│   ├── consultar.h
	│   └── operacoes_csv.h
	├── excecao
	│   └── excecao.h
	├── funcionario
	│   ├── funcionario.h
	│   ├── tratador.h
	│   └── veterinario.h
	├── paineis.h
	├── painel
	│   └── painel.h
	└── utilitarios.h

#### Diagrama do diretório include

.. figure:: doc/arquivos_include.jpg

## Compilação

### Compilar e executar o código no terminal

	make
	make run

### Compilar documentação
É necessário ter o Doxygen e Graphviz instalado na sua plataforma.

	cd doc/
	doxygen

## Objetivos

- [ ] Cadastro de um novo animal a ser comercializado;
- [ ] o Remoção de um animal da lista após a sua comercialização;
- [ ] o Alteração dos dados cadastrais de um animal;
- [ ] o Consulta aos dados cadastrais de um determinado animal ou por uma classe de animais;
- [ ] o Consulta de animais sob a responsabilidade de um determinado Veterinário ou Tratador;
- [ ] o Todas as atividades relacionadas ao cadastro de Veterinários e Tratadores.

## Avaliação

| Critério 																							| Nota 	  |
| :------- 																							| :-----: |
| readme	 																						| [0, 10] |
| legibilidade, organização e documentação de código fonte 											| [0, 10] |
| Modularização 																					| [0, 10] |
| Classes: atributos e métodos; construtores e destrutores; níveis de acesso e métodos de acesso 	| [0, 10] |
| Sobrecarga de funções e operadores 																| [0, 10] |
| Templates  de classes 																			| [0, 10] |
| Herança, polimorfismo e classes abstratas 														| [0, 10] |
| Uso consistente de alocação dinâmica de memória 													| [0, 10] |
| Uso do container  map  da STL (ou outro TAD) 														| [0, 10] |
| Criação e utilização de biblioteca* 																| [0, 10] |
| Manipulação de arquivos 																			| [0, 10] |
| Tratamento de exceções* 																			| [0, 10] |
| Uso adequado de Makefile 																			| [0, 10] |
| corretude, saída em conformidade com a especificação e as entradas de dados fornecidas 			| [0, 10] |
| **Nota final** 																					| `(média simples)` |

