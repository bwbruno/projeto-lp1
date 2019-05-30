#ifndef __REPTIL_EXOTICO_H__
#define __REPTIL_EXOTICO_H__

#include "animal/reptil/reptil.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe réptil exótico
class ReptilExotico : public Reptil, AnimalExotico {
	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		//! @brief O construtor padrão instancia o animal com a função limpar() já aplicada
		//! @see limpa
		ReptilExotico();
		
		//! @brief Esse construtor instancia o animal com os valores das linhas dos arquivos CSV
		/**
		 * @code
		 *  // EXEMPLO:
		 *  string linhaCSV = "1;Mammalia;Leão;Panthera leo;M;2;Carne;0;1;Simba";
		 *  string linhaDetalhesCSV = "1;Mammalia;Amarelo";
		 * 	Animal a(linhaCSV, linhasDetalhesCSV);
		 * 	cout << a;
		 * 
		 * 	// SAÍDA:
		 * 	Id: 1
		 *  Classe: Mammalia
		 * 	Espécie: Leão
		 *  Nome científico: Penthera leo
		 *  Sexo: M
		 *  Tamanho: 2
		 *  Dieta: Carne
		 *  Veterinário: 0
		 *  Tratador: 1
		 *  Nome de batismo: Simba
		 *  Cor pelo: Amarelo
		 * @endcode
		*/
		//! @param linhaCSV linha do arquivo CSV
		//! @param linhaDetalhesCSV linha do arquivo CSV
		ReptilExotico(std::string linhaCSV, std::string linhaDetalhesCSV);

		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Seta espaço em branco em todos os atributos do tipo string e -1 em todos os de tipo numérico
		//! @note Ajuda na hora de imprimir a classe na tela, mesmo que não tenha todos os atributos já definidos.
		//! @see operator<<()
		void limpar();

		//! @brief Grava no arquivo CSV informado os valores da classe
		//! @exception Excecao caso o arquivo não exista ou haja alguma falha de execução
		//! @param enderecoArquivo endereco do arquivo CSV
		std::string getStringCSV();

		//! @brief Grava no arquivo CSV informado os detalhes das classes que herdam de animal
		//! @exception Excecao caso o arquivo não exista ou haja alguma falha de execução
		//! @param enderecoArquivo endereco do arquivo CSV
		std::string getStringDetalhesCSV();

		//! @brief Retorna um vector com os atributos da classe
		//! @note Útil para exibir as opções na hora de alterar
		std::vector<std::string> vectorAtributos();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Operador de inserção da classe. Só insere um atributo por vez.
		/**
		 * Por exemplo:
		 * @code
		 * Animal a;
		 * cin >> a;	// 1a chamada: Insere no a.especie
		 * cin >> a;	// 2a chamada: Insere no a.nome_cientifico
		 * cin >> a;	// 3a chamada: Insere no a.sexo
		 * cin >> a;	// 4a chamada: Insere no a.tamanho
		 * cin >> a;	// ...
		 * cin >> a;	// 8a chamada: Insere no a.nome_batismo
		 * @endcode
		 * @see setContadorCin()
		 */
		friend std::istream& operator>> (std::istream &i, ReptilExotico &r);
    	
		//! @brief Operador de extração da classe.
		friend std::ostream& operator<< (std::ostream &o, ReptilExotico const r);


		//---------------------------------------------------------------------- ///@}
};

#endif // __REPTIL_EXOTICO_H__