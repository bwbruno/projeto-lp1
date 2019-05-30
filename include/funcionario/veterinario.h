#ifndef __VETERINARIO_H__
#define __VETERINARIO_H__

#include "funcionario/funcionario.h"

/// Essa classe representa o funcionario que possui um 'código CRMV'.
/**
 * ![Diagrama de classe Veterinario](veterinario.png)
 */
class Veterinario : public Funcionario {
	private:
		std::string crmv; ///< Código CRMV

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		//! @brief Construtor padrão seta os valores nulos da função limpar()
		//! @see limpar()
		Veterinario();

		//! @brief O construtor padrão instancia o veterinario a partir do id e arquivo CSV informados
		//Veterinario(int id);

		//! @brief Esse construtor instancia o veterinário com os valores de uma linha de um arquivo CSV
		/**
		 * @code
		 * 	// EXEMPLO:
		 * 	Veterinario v("2;Veterinario;Daniel Oscar;123.456.789-10;30;O;+;Felinos;CRMV-GO 0406;;");
		 * 	cout << v;
		 * 
		 * 	// SAÍDA:
		 * 	Id: 2
		 * 	Nome: Daniel Oscar
		 * 	CPF: 123.456.789-10
		 * 	Idade: 30
		 * 	Tipo sanguíneo: O
		 * 	Fator RH: +
		 * 	Especialidade: Felinos
		 * 	CRMV: CRMV-GO 0406
		 * @endcode
		*/
		//! @param linhaCSV linha do arquivo CSV
		Veterinario(std::string linhaCSV);


		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{

		//! @brief Retorna o código CRMV do veterinário.
		std::string getCRMV();


		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{

		//! @brief Esse método permite que o usuário especifique o código CRMV do veterinário
		//! @param c código CRMV do veterinário
		void setCRMV(std::string c);
	
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{

		//! @brief Seta 'espaço' em todos os atributos do tipo string e '-1' em todos os de tipo numérico
		//! @note Ajuda na hora de imprimir a classe na tela, mesmo que não tenha todos os atributos já definidos.
		//! @see operator<<()
		void limpar();

		//! @brief Retorna o tipo do funcionário, se é Tratador ou Veterinario
		//! @brief Útil na hora de filtrar as linhas do arquivo CSV de acordo com a classe passada no template<>
		std::string getTipo();

		//! @brief Grava no arquivo CSV informado os valores da classe
		//! @exception Excecao caso o arquivo não exista ou haja alguma falha de execução
		//! @param enderecoArquivo endereco do arquivo CSV
		std::string getStringCSV();

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
		 * Veterinario v;
		 * cin >> v;	// 1a chamada: Insere no v.id
		 * cin >> v;	// 2a chamada: Insere no v.nome
		 * cin >> v;	// 3a chamada: Insere no v.cpf
		 * cin >> v;	// 4a chamada: Insere no v.idade
		 * cin >> v;	// ...
		 * cin >> v;	// 8a chamada: Insere no v.crmv
		 * @endcode
		 * @see setContadorCin()
		 */
		friend std::istream& operator>> (std::istream &i, Veterinario &v);

		//! @brief Operador de extração da classe.
		friend std::ostream& operator<< (std::ostream &o, Veterinario const v);

		//---------------------------------------------------------------------- ///@}
};

#endif // __VETERINARIO_H__