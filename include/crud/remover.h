#ifndef __REMOVER_H__
#define __REMOVER_H__

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <istream>
#include <queue>

#include "excecao/excecao.h"
#include "painel/painel.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"

// Funções de remoção usando UM arquivo

template <typename CLASSE>
void confirmarRemover(int id, std::string enderecoArquivo, std::deque<std::string> caminho){
    
	Painel detalhes;
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::string linha = csv.consultarLinha(id);
	CLASSE classe(linha);
	std::string continuar;

    caminho.push_back("DETALHES");

	detalhes.setTitulo("DETALHES");
	detalhes.setCaminho(caminho);

    std::cout << detalhes;
	std::cout << classe;
	std::cout << "\nCONFIRMAR REMOÇÃO (s/n): ";
	std::cin >> continuar;

    if(continuar == "s"){
		
		csv.removerLinha(id);

		throw Excecao("Removido com sucesso.");

	} else {
		throw Excecao("A remoção não foi efetuada. Tente novamente.");
	}
    
}

template <typename CLASSE>
void remover(std::string enderecoArquivo, std::deque<std::string> caminho){
	
	Painel consulta;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<std::string, std::string> opcoes = csv.getOpcoes();
	std::string opcao;
    
    caminho.push_back("REMOVER");

	consulta.setTitulo("REMOVER");
	consulta.setCaminho(caminho);
	consulta.setOpcoes(opcoes);
	consulta.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(consulta.getAbrir()){

        opcoes = csv.getOpcoes();
        consulta.setOpcoes(opcoes);

		try{
			std::cout << consulta;					// Imprime o cabeçalho, as opções e a pergunta
			std::cin >> opcao;						// Lê a resposta
			consulta.setResposta(opcao);

            if(opcao != "0")
                break;
		}
		catch(Excecao& e){
			consulta.setExcecao(e);
		}

	}

    if(opcao != "0"){
        int id = atoi(opcao.c_str());
        confirmarRemover<CLASSE>(id, enderecoArquivo, caminho);
    }
}

// Funções de remoção usando DOIS arquivos

template <typename CLASSE>
void confirmarRemover(int id, std::string enderecoArquivo, std::string endArqDetalhes, std::deque<std::string> caminho){
    
	Painel detalhes;
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
	OperacoesCSV<CLASSE> csvDetalhes(endArqDetalhes);
    std::string linha = csv.consultarLinha(id);
    std::string linhaDetalhes = csvDetalhes.consultarLinha(id);
	CLASSE classe(linha, linhaDetalhes);
	std::string continuar;

    caminho.push_back("DETALHES");

	detalhes.setTitulo("DETALHES");
	detalhes.setCaminho(caminho);

    std::cout << detalhes;
	std::cout << classe;
	std::cout << "\nCONFIRMAR REMOÇÃO (s/n): ";
	std::cin >> continuar;

    if(continuar == "s"){
		
		csv.removerLinha(id);
		csvDetalhes.removerLinha(id);

		throw Excecao("Removido com sucesso.");

	} else {
		throw Excecao("A remoção não foi efetuada. Tente novamente.");
	}
    
}

template <typename CLASSE>
void remover(std::string enderecoArquivo, std::string endArqDetalhes, std::deque<std::string> caminho){
	
	Painel consulta;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<std::string, std::string> opcoes = csv.getOpcoes();
	std::string opcao;
    
    caminho.push_back("REMOVER");

	consulta.setTitulo("REMOVER");
	consulta.setCaminho(caminho);
	consulta.setOpcoes(opcoes);
	consulta.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(consulta.getAbrir()){

        opcoes = csv.getOpcoes();
        consulta.setOpcoes(opcoes);

		try{
			std::cout << consulta;					// Imprime o cabeçalho, as opções e a pergunta
			std::cin >> opcao;						// Lê a resposta
			consulta.setResposta(opcao);

            if(opcao != "0")
                break;
		}
		catch(Excecao& e){
			consulta.setExcecao(e);
		}

	}

    if(opcao != "0"){
        int id = atoi(opcao.c_str());
        confirmarRemover<CLASSE>(id, enderecoArquivo, endArqDetalhes, caminho);
    }
}

#endif