#ifndef __CONSULTAR_H__
#define __CONSULTAR_H__

#include "excecao/excecao.h"
#include "painel/painel.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"

template <typename CLASSE>
void consultar(std::string enderecoArquivo, std::deque<std::string> caminho){
	
	Painel consulta;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<std::string, std::string> opcoes = csv.getOpcoes();
	std::string opcao;
    
    caminho.push_back("CONSULTAR");

	consulta.setTitulo("CONSULTAR");
	consulta.setCaminho(caminho);
	consulta.setOpcoes(opcoes);
	consulta.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(consulta.getAbrir()){

		try{
			std::cout << consulta;
			std::cin >> opcao;
			consulta.setResposta(opcao);


			if(opcao != "0"){
				int id = atoi(opcao.c_str());
            	painelDetalhes(id, csv, caminho);	
			}
		}
		catch(Excecao& e){
			consulta.setExcecao(e);
		}

	}
   
}

template <typename CLASSE>
void painelDetalhes(int id, OperacoesCSV<CLASSE> &csv, std::deque<std::string> caminho){
    
	Painel detalhes;
	std::string opcao;

    caminho.push_back("DETALHES");

	detalhes.setTitulo("DETALHES");
	detalhes.setCaminho(caminho);
    
	while(detalhes.getAbrir()){

		try{
			std::cout << detalhes; 										// Cabecalho
            std::cout << csv.consultar(id); 							// Corpo
            std::cout << "\nPARA VOLTAR INSIRA O NÚMERO ZERO [0]: "; 	// Pergunta
            std::cin >> opcao; 											// Resposta
			detalhes.setResposta(opcao);
	
		}
		catch(Excecao& e){
			detalhes.setExcecao(e);
		}
			
	}
}

#endif // __CONSULTAR_H__