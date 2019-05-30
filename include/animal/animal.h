#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "funcionario/veterinario.h"
#include "funcionario/tratador.h"

/// Classe Animal
class Animal{
	protected:
		int id; ///< Identificador do animal
		std::string classe; ///< Classe do animal
		std::string especie; ///< Classe do animal
		std::string nome_cientifico; ///< Nome científico do animal
		char sexo; ///< Sexo do animal
		double tamanho; ///< Tamanho médio em metros do animal
		std::string dieta; ///< Dieta predominante
		Veterinario veterinario; ///< Veterinário associado ao animal					 
		Tratador tratador; ///< Tratador associado ao animal			   
		std::string nome_batismo; ///< Nome de batismo do animal
		int contador_cin;

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Retorna o id 
		int getId();

		//! @brief Retorna a classe
		std::string getClasse();

		//! @brief Retorna a espécie
		std::string getEspecie();

		//! @brief Retorna o nome científico
		std::string getNome_Cientifico();

		//! @brief Retorna o sexo do animal
		char getSexo();

		//! @brief Retorna o tamanho
		double getTamanho();

		//! @brief Retorna a dieta
		std::string getDieta();

		//! @brief Retorna o veterinario
		Veterinario getVeterinario();

		//! @brief Retorna o tratador
		Tratador getTratador();

		//! @brief Retorna o nome de batismo
		std::string getNome_Batismo();

		//! @brief Retorna a quantidade de chamadas do operador de inserção da classe
		//! @note Útil para saber quais atributos já foram inseridos ou não
		int getContadorCin();	
		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
		
		//! @brief Seta o id
		void setId(int cod);

		//! @brief Seta a classe
		void setClasse(std::string clas);

		//! @brief Seta a espécie
		void setEspecie(std::string species);

		//! @brief Seta o nome científico
		void setNome_Cientifico(std::string cientific_name);

		//! @brief Seta o sexo do animal
		/*!
		 * Onde 'gender' deve ser um dos seguintes: 
		 *  - M
		 *  - F
		 */
		//! @exception Excecao caso não seja uma das anteriores.
		//! @param gender sexo do animal
		void setSexo(char gender);

		//! @brief Seta o tamanho
		void setTamanho(double size);

		//! @brief Seta a dieta
		void setDieta(std::string diet);

		//! @brief Seta o veterinario
		void setVeterinario(int idVeterinario);

		//! @brief Seta o tratador
		void setTratador(int idTratador);

		//! @brief Seta o nome de batismo
		void setNome_Batismo(std::string baptism_name);

		//! @brief Seta um valor no contador de chamadas do operador de inserção da classe
		//! @note Útil para saber quais atributos já foram inseridos ou não
		void setContadorCin(int c);


		//---------------------------------------------------------------------- ///@}
		/// @name Métodos utilitários
		//---------------------------------------------------------------------- ///@{

		//! @brief Seta espaço em branco em todos os atributos do tipo string e -1 em todos os de tipo numérico
		//! @note Ajuda na hora de imprimir a classe na tela, mesmo que não tenha todos os atributos já definidos.
		virtual void limpar() = 0;

		//! @brief Retorna a classe do animal
		//! @brief Útil na hora de filtrar as linhas do arquivo CSV de acordo com a classe passada no template<>
		std::string getTipo();

		//! @brief Grava no arquivo CSV informado os valores da classe
		//! @exception Excecao caso o arquivo não exista ou haja alguma falha de execução
		//! @param enderecoArquivo endereco do arquivo CSV
		virtual std::string getStringCSV() = 0;

		//! @brief Grava no arquivo CSV informado os detalhes das classes que herdam de animal
		//! @exception Excecao caso o arquivo não exista ou haja alguma falha de execução
		//! @param enderecoArquivo endereco do arquivo CSV
		virtual std::string getStringDetalhesCSV() = 0;

		//! @brief Retorna um vector com os atributos da classe
		//! @note Útil para exibir as opções na hora de alterar
		virtual std::vector<std::string> vectorAtributos() = 0;
		
		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_H__