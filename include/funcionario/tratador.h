#ifndef __TRATADOR_H__
#define __TRATADOR_H__

#include "funcionario/funcionario.h"

/// Essa classe representa o funcionario que possui um 'nivel de segurança' para tratar os animais.
/**
 * Nível de segurança representa o grau de experiência do tratador na manipulação de certos animais.
 */
class Tratador : public Funcionario {
	private:
		int nivel_de_seguranca; ///< Indica quais animais o tratador pode tratar.

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		//! @brief O construtor padrão instancia o tratador com a função limpar() já aplicada
		//! @see limpar()
		Tratador();

		//! @brief O construtor padrão instancia o tratador a partir do id informado e a partir do id e arquivo CSV informados
		//Tratador(int id);

		//! @brief Esse construtor instancia o tratador com os valores de uma linha de um arquivo CSV
		/**
		 * @code
		 * 	// EXEMPLO:
		 * 	Tratador t("1;Tratador;João Alberto;007.404.200-98;45;AB;-;Répteis e Aves;;1;");
		 * 	cout << t;
		 * 
		 * 	// SAÍDA:
		 * 	Id: 1
		 * 	Nome: João Alberto
		 * 	CPF: 007.404.200-98
		 * 	Idade: 45
		 * 	Tipo sanguíneo: AB
		 * 	Fator RH: -
		 * 	Especialidade: Répteis e Aves
		 * 	Nível de segurança: 1
		 * @endcode
		*/
		//! @param linhaCSV linha do arquivo CSV
		Tratador(std::string linhaCSV);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Retorna o 'nível de segurança' do tratador.
		int getNivelDeSeguranca();
		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Seta o 'nível de segurança' do tratador
		/*!
		 * O nivel de segurança deve ser um inteiro[0, 2], onde:
		 *  - 0 (indica que pode manipular aves)
		 *  - 1 (indica que pode tratar aves, mamíferos e répteis)
		 *  - 2 (pode manipular animais venenosos ou perigosos)
		 */
		//! @exception Excecao caso não seja uma das anteriores.
		//! @param nds nível de segurança do tratador
		void setNivelDeSeguranca(int nds);
		
		//---------------------------------------------------------------------- ///@}
		/// @name Métodos
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Seta 'espaço' em todos os atributos do tipo string e '-1' em todos os de tipo numérico
		//! @note Ajuda na hora de imprimir a classe na tela, mesmo que não tenha todos os atributos já definidos.
		//! @see operator<<()
		void limpar();
		
		std::string getTipo();

		std::string getStringCSV();

		//---------------------------------------------------------------------- ///@}
		/// @name Operadores
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Operador de inserção da classe. Só insere um atributo por vez.
		/**
		 * Por exemplo:
		 * @code
		 * Tratador t;
		 * cin >> t;	// 1a chamada: Insere no t.id
		 * cin >> t;	// 2a chamada: Insere no t.nome
		 * cin >> t;	// 3a chamada: Insere no t.cpf
		 * cin >> t;	// 4a chamada: Insere no t.idade
		 * cin >> t;	// ...
		 * cin >> t;	// 8a chamada: Insere no t.nivel_de_seguranca
		 * @endcode
		 * @see setContadorCin()
		 */
		friend std::istream& operator>> (std::istream &i, Tratador &t);

		//! @brief Operador de extração da classe.
		friend std::ostream& operator<< (std::ostream &o, Tratador const t);

		std::vector<std::string> vectorAtributos();

		///@}
};

#endif // __TRATADOR_H__