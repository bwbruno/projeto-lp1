#include "paineis.h"

using namespace std;

void painelPrincipal(){

	Painel gerenciar;
	deque<string> caminho;
	vector<string> opcoes;
	string opcao;

	caminho.push_back("GERENCIAR");

	opcoes.push_back("SAIR");
	opcoes.push_back("ANIMAIS");
	opcoes.push_back("FUNCIONÁRIOS");

	gerenciar.setTitulo("GERENCIAR");
	gerenciar.setOpcoes(opcoes);
	gerenciar.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(gerenciar.getAbrir()){

		try
		{
			cout << gerenciar;
			cin >> opcao;
			gerenciar.setResposta(opcao);

			if(opcao == "1"){
				painelAnimais(caminho);
			} else if(opcao == "2"){
				painelFuncionarios(caminho);
			}
		}
		catch(Excecao& e)
		{
			gerenciar.setExcecao(e);
		}
			
	}
}


void painelFuncionarios(deque<string> caminho){
	
	Painel funcionarios;
	vector<string> opcoes;
	string opcao;
	
	caminho.push_back("FUNCIONÁRIOS");

	opcoes.push_back("VOLTAR");
	opcoes.push_back("TRATADORES");
	opcoes.push_back("VETERINÁRIOS");

	funcionarios.setTitulo("GERENCIAR");
	funcionarios.setCaminho(caminho);
	funcionarios.setOpcoes(opcoes);
	funcionarios.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(funcionarios.getAbrir()){

		try{
			cout << funcionarios;
			cin >> opcao;
			funcionarios.setResposta(opcao);

			if(opcao == "1"){
				string titulo = "TRATADORES";
				painelFuncionarios<Tratador>(titulo, caminho);

			} else if(opcao == "2"){
				string titulo = "VETERINARIOS";
				painelFuncionarios<Veterinario>(titulo, caminho);
			}
		}
		catch(Excecao& e){
			funcionarios.setExcecao(e);
		}
			
	}

}

Painel getPainelTipo(string titulo, deque<string> caminho){
	
	Painel painel;
	vector<string> opcoes;

	caminho.push_back(titulo);
	
	opcoes.push_back("VOLTAR");
	opcoes.push_back("NATIVO");
	opcoes.push_back("EXÓTICO");
	
	painel.setTitulo(titulo);
	painel.setCaminho(caminho);
	painel.setOpcoes(opcoes);
	painel.setPergunta("SELECIONE UMA DAS OPCOES: ");
	
	return painel;
}




template <>
void painelTipo<Anfibio>(string titulo, deque<string> caminho){
	
	Painel painel = getPainelTipo(titulo, caminho);
	string opcao;

	while(painel.getAbrir()){

		try{
			cout << painel;
			cin >> opcao;
			painel.setResposta(opcao);

			if(opcao == "1"){
				painelCrudAnimais<AnfibioNativo>("ANFÍBIO NATIVO", caminho);
			} else if(opcao == "2"){
				painelCrudAnimais<AnfibioNativo>("ANFÍBIO EXÓTICO", caminho);
			}
		}
		catch(Excecao& e){
			painel.setExcecao(e);
		}
			
	}
}


// Animais ---------------------------
void painelAnimais(deque<string> caminho){

	Painel animais;
	vector<string> opcoes;
	string opcao;
	
	caminho.push_back("ANIMAIS");

	opcoes.push_back("VOLTAR");
	opcoes.push_back("ANFÍBIO");
	opcoes.push_back("AVE");
	opcoes.push_back("MAMÍFERO");
	opcoes.push_back("RÉPTIL");

	animais.setTitulo("ANIMAIS");
	animais.setCaminho(caminho);
	animais.setOpcoes(opcoes);
	animais.setPergunta("SELECIONE UMA DAS OPCOES: ");

	while(animais.getAbrir()){
		try{
			cout << animais;
			cin >> opcao;
			animais.setResposta(opcao);
			if(opcao == "1"){
				painelTipo<Anfibio>("caminho", caminho);
			} else if(opcao == "2"){
			} else if(opcao == "3"){
			} else if(opcao == "4"){
			}
		}
		catch(Excecao& e){
			animais.setExcecao(e);
		}
	}
}
