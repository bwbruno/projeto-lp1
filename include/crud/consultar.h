#ifndef __CONSULTAR_H__
#define __CONSULTAR_H__

#include "excecao/excecao.h"
#include "painel/painel.h"
#include "utilitarios.h"
#include "crud/operacoes_csv.h"

// ------------------------------------------------------------------------
//		Fuções para consultar usando UN arquivo
// ------------------------------------------------------------------------

template <typename CLASSE>
void consultar(std::string enderecoArquivo, std::deque<std::string> caminho){
	
	Painel consulta;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
    std::map<std::string, std::string> opcoes = csv.gerarOpcoes();
	std::string opcao;
    
    caminho.push_back("CONSULTAR");

	consulta.setTitulo("CONSULTAR");
	consulta.setCaminho(caminho);
	consulta.setOpcoes(opcoes);
	consulta.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(consulta.getAbrir()){

		try{
			std::cout << consulta;					// Imprime o cabeçalho, as opções e a pergunta
			std::cin >> opcao;						// Lê a resposta
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
			std::cout << detalhes; 										// Imprime cabecalho
            
			std::string linha = csv.consultarLinha(id);
			CLASSE classe(linha);
			std::cout << classe;										// Imprime corpo

            std::cout << "\nPARA VOLTAR INSIRA O NÚMERO ZERO [0]: "; 	// Imprime a pergunta
            std::cin >> opcao; 											// Lê a resposta
			detalhes.setResposta(opcao);
	
		}
		catch(Excecao& e){
			detalhes.setExcecao(e);
		}
			
	}
}


// ------------------------------------------------------------------------
//		Fuções para consultar usando DOIS arquivos
// ------------------------------------------------------------------------

template <typename CLASSE>
void consultar(std::string enderecoArquivo, std::string endArqDetalhes, std::deque<std::string> caminho){
	
	Painel consulta;	
	OperacoesCSV<CLASSE> csv(enderecoArquivo);
	OperacoesCSV<CLASSE> csvDetalhes(endArqDetalhes);
    std::map<std::string, std::string> opcoes = csv.gerarOpcoes();
	std::string opcao;
    
    caminho.push_back("CONSULTAR");

	consulta.setTitulo("CONSULTAR");
	consulta.setCaminho(caminho);
	consulta.setOpcoes(opcoes);
	consulta.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(consulta.getAbrir()){

		try{
			std::cout << consulta;					// Imprime o cabeçalho, as opções e a pergunta
			std::cin >> opcao;						// Lê a resposta
			consulta.setResposta(opcao);


			if(opcao != "0"){
				int id = atoi(opcao.c_str());
            	painelDetalhes(id, csv, csvDetalhes, caminho);
			}
		}
		catch(Excecao& e){
			consulta.setExcecao(e);
		}

	}
   
}

template <typename CLASSE>
void painelDetalhes(int id, OperacoesCSV<CLASSE> &csv, OperacoesCSV<CLASSE> &csvDetalhes, std::deque<std::string> caminho){
    
	Painel detalhes;
	std::string opcao;

    caminho.push_back("DETALHES");

	detalhes.setTitulo("DETALHES");
	detalhes.setCaminho(caminho);
    
	while(detalhes.getAbrir()){

		try{
			std::cout << detalhes; 										// Imprime cabecalho

            std::string linha = csv.consultarLinha(id);
            std::string linhaDetalhes = csvDetalhes.consultarLinha(id);

			CLASSE classe(linha, linhaDetalhes);
			std::cout << classe;										// Imprime corpo
            
			std::cout << "\nPARA VOLTAR INSIRA O NÚMERO ZERO [0]: "; 	// Imprime a pergunta
            std::cin >> opcao; 											// Lê a resposta
			detalhes.setResposta(opcao);
	
		}
		catch(Excecao& e){
			detalhes.setExcecao(e);
		}
			
	}
}

#endif // __CONSULTAR_H__