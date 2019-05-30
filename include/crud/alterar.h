#ifndef __ALTERAR_H__
#define __ALTERAR_H__

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <istream>
#include <map>

#include "excecao/excecao.h"
#include "painel/painel.h"
#include "paineis.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"
#include "funcionario/veterinario.h"
#include "funcionario/tratador.h"


// ------------------------------------------------------------------------
//		Fuções para alterar usando UM arquivo
// ------------------------------------------------------------------------

template <typename CLASSE>
void alterarAtributo(std::string opcao, CLASSE &classe, std::string enderecoArquivo, std::deque<std::string> caminho){
    
	Painel painel;
	OperacoesCSV<CLASSE> csv(enderecoArquivo);

	painel.setTitulo("ALTERAR");
	painel.setCaminho(caminho);

    int i = atoi(opcao.c_str());
    classe.setContadorCin(--i);
    
    std::cout << painel;
    std::cout << classe;
    std::cin >> classe;

    // Tratamento de erro, caso o usuário insira texto em vez de números
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(__INT_MAX__, '\n');
        throw Excecao("Valor inválido. Insira um valor númerico.");
    }

    int id = classe.getId();
    csv.removerLinha(id);

    std::string linha = classe.getStringCSV();
	csv.inserirLinha(linha);
}


template <typename CLASSE>
void selecionarAtributo(int id, std::string enderecoArquivo, std::deque<std::string> caminho){
    
	Painel painel;
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::string linha = csv.consultarLinha(id);
	CLASSE classe(linha);
	std::string opcao;

	painel.setTitulo("ALTERAR");
    painel.setOpcoes(classe.vectorAtributos());
	painel.setCaminho(caminho);

    while(classe.getContadorCin() != -1){

		try{
            std::cout << painel;
            std::cout << "\n";
            std::cout << classe;
            std::cout << "\nSELECIONE A OPÇÃO QUE DESEJA ALTERAR: ";

            std::cin >> opcao;						// Lê a resposta
			painel.setResposta(opcao);

            if(opcao == "0"){
                classe.setContadorCin(-1);
            } else {
                int id = atoi(opcao.c_str());
                alterarAtributo<CLASSE>(opcao, classe, enderecoArquivo, caminho);
            }
    
		}
		catch(Excecao& e){
			
			classe.setContadorCin(classe.getContadorCin()-1);
			painel.setExcecao(e);
		}
			
	}

}

template <typename CLASSE>
void alterar(std::string enderecoArquivo, std::deque<std::string> caminho){
	
	Painel painel;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<std::string, std::string> opcoes = csv.gerarOpcoes();
	std::string opcao;
    
    caminho.push_back("ALTERAR");

	painel.setTitulo("ALTERAR");
	painel.setCaminho(caminho);
	painel.setOpcoes(opcoes);
	painel.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(painel.getAbrir()){

        opcoes = csv.gerarOpcoes();
        painel.setOpcoes(opcoes);

		try{
			std::cout << painel;					// Imprime o cabeçalho, as opções e a pergunta
			std::cin >> opcao;						// Lê a resposta
			painel.setResposta(opcao);

            if(opcao != "0")
                break;
		}
		catch(Excecao& e){
			painel.setExcecao(e);
		}

	}

    if(opcao != "0"){
        int id = atoi(opcao.c_str());
        selecionarAtributo<CLASSE>(id, enderecoArquivo, caminho);
    }
}


// ------------------------------------------------------------------------
//		Fuções para alterar usando DOIS arquivos
// ------------------------------------------------------------------------

template <typename CLASSE>
void alterarAtributo(std::string opcao, CLASSE &classe, std::string enderecoArquivo, std::string endArqDetalhes, std::deque<std::string> caminho){
    
	Painel painel;
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
	OperacoesCSV<CLASSE> csvDetalhes(endArqDetalhes);

	painel.setTitulo("ALTERAR");
	painel.setCaminho(caminho);

    int i = atoi(opcao.c_str());
    classe.setContadorCin(--i);
    
    std::cout << painel;
    std::cout << classe;
    std::cin >> classe;

    // Tratamento de erro, caso o usuário insira texto em vez de números
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(__INT_MAX__, '\n');
        throw Excecao("Valor inválido. Insira um valor númerico.");
    }

    int id = classe.getId();
    csv.removerLinha(id);
    csvDetalhes.removerLinha(id);

    std::string linha = classe.getStringCSV();
    std::string linhaDetalhes = classe.getStringDetalhesCSV();
	csv.inserirLinha(linha);
    csvDetalhes.inserirLinha(linhaDetalhes);
}

template <typename CLASSE>
void selecionarAtributo(int id, std::string enderecoArquivo, std::string endArqDetalhes, std::deque<std::string> caminho){
    
	Painel painel;
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
	OperacoesCSV<CLASSE> csvDetalhes(endArqDetalhes);
    std::string linha = csv.consultarLinha(id);
    std::string linhaDetalhes = csvDetalhes.consultarLinha(id);
	CLASSE classe(linha, linhaDetalhes);
	std::string opcao;

	painel.setTitulo("ALTERAR");
    painel.setOpcoes(classe.vectorAtributos());
	painel.setCaminho(caminho);

    while(classe.getContadorCin() != -1){

		try{
            std::cout << painel;
            std::cout << "\n";
            std::cout << classe;
            std::cout << "\nSELECIONE A OPÇÃO QUE DESEJA ALTERAR: ";

            std::cin >> opcao;						// Lê a resposta
			painel.setResposta(opcao);

            if(opcao == "0"){
                classe.setContadorCin(-1);
            } else {
                int id = atoi(opcao.c_str());
                alterarAtributo<CLASSE>(opcao, classe, enderecoArquivo, endArqDetalhes, caminho);
            }
    
		}
		catch(Excecao& e){
			
			classe.setContadorCin(classe.getContadorCin()-1);
			painel.setExcecao(e);
		}
			
	}

}

template <typename CLASSE>
void alterar(std::string enderecoArquivo, std::string endArqDetalhes, std::deque<std::string> caminho){
	
	Painel painel;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<std::string, std::string> opcoes = csv.gerarOpcoes();
	std::string opcao;
    
    caminho.push_back("ALTERAR");

	painel.setTitulo("ALTERAR");
	painel.setCaminho(caminho);
	painel.setOpcoes(opcoes);
	painel.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(painel.getAbrir()){

        opcoes = csv.gerarOpcoes();
        painel.setOpcoes(opcoes);

		try{
			std::cout << painel;					// Imprime o cabeçalho, as opções e a pergunta
			std::cin >> opcao;						// Lê a resposta
			painel.setResposta(opcao);

            if(opcao != "0")
                break;
		}
		catch(Excecao& e){
			painel.setExcecao(e);
		}

	}

    if(opcao != "0"){
        int id = atoi(opcao.c_str());
        selecionarAtributo<CLASSE>(id, enderecoArquivo, endArqDetalhes, caminho);
    }
}

#endif