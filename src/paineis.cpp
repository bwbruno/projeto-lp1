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


// Animais ---------------------------
void painelAnimais(deque<string> caminho){
	caminho.push_back("ANIMAIS");
	string titulo = "ANIMAIS";
	vector<string> opcoes;
	opcoes.push_back("VOLTAR");
	opcoes.push_back("CADASTRAR");
	opcoes.push_back("REMOVER");
	opcoes.push_back("ALTERAR");
	opcoes.push_back("CONSULTAR");
	string opcao;
	Painel animais(titulo, opcoes, caminho);
	animais.setPergunta("Selecione uma das opções: ");
	void selecionarClasse(deque<string> caminho);
	while(animais.getAbrir()){

		


		try{
			cout << animais;
			cin >> opcao;
			animais.setResposta(opcao);

			if(opcao == "1"){
				selecionarClasse(caminho);
				

			} else if(opcao == "2"){
				/* string titulo = "VETERINARIOS";
				painelFuncionarios<Veterinario>(titulo, caminho); */
			}
		}
		catch(Excecao& e){
			animais.setExcecao(e);
		}
		

		/* animais.printPainel();
		string opcao = animais.getSelecao();

		if(opcao == "1"){
			animais.setMensagem("CADASTRAR");

		} else if(opcao == "2"){
			animais.setMensagem("REMOVER");

		} else if(opcao == "3"){
			animais.setMensagem("ALTERAR");

		} else if(opcao == "4"){
			painelAnimaisConsulta(caminho);
		} */
	}
}

void selecionarClasse(deque<string> caminho){
	vector <string> opcoes;
	opcoes.push_back("Voltar");
	opcoes.push_back("Anfíbio");
	opcoes.push_back("Ave");
	opcoes.push_back("Mamífero");
	opcoes.push_back("Réptil");
	
	string titulo = "CLASSES";
	string selecao;
	Painel classes(titulo, caminho);
	caminho.push_back("CADASTRAR");
	classes.setCaminho(caminho);
	classes.setPergunta("Escolha a classe do animal: ");
	classes.setOpcoes(opcoes);

	while(classes.getAbrir()){
		
		try{
			cout << classes;
			cin >> selecao;
			classes.setResposta(selecao);

			if(selecao == "1"){
				// Chamar crud para criar um animal anfíbio
			} else if(selecao == "2"){
				// Chamar crud para criar um animal ave
			} else if(selecao == "3"){
				// Chamar crud para criar um animal mamífero
			} else if(selecao == "4"){
				// Chamar crud para criar um animal réptil
			}
		}
		catch(Excecao& e)
		{
			classes.setExcecao(e);
		}
		
	}
	
}
/* 
void painelAnimaisConsulta(deque<string> caminho){
	caminho.push_back("CONSULTAR");
	string titulo = "CONSULTAR ANIMAIS POR";
	string vetor_opcoes[] = {"VOLTAR", "NOME DE BATISMO", "ESPÉCIE", "CLASSE", "VETERINÁRIO RESPONSÁVEL", "TRATADOR RESPONSÁVEL"};
	vector<string> opcoes(vetor_opcoes, vetor_opcoes + sizeof(vetor_opcoes) / sizeof(string));
	Painel consultar(titulo, opcoes, caminho);
	
	while(consultar.getAbrir()){
		consultar.printPainel();
		string opcao = consultar.getSelecao();

		if(opcao == "1"){
			consultar.setMensagem("NOME DE BATISMO");

		} else if(opcao == "2"){
			consultar.setMensagem("ESPÉCIE");

		} else if(opcao == "3"){
			consultar.setMensagem("CLASSE");

		} else if(opcao == "4"){
			consultar.setMensagem("VETERINÁRIO RESPONSÁVEL");

		}  else if(opcao == "5"){
			consultar.setMensagem("TRATADOR RESPONSÁVEL");
		}
	}
}

 */