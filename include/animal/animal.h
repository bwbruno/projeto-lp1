#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

#include "funcionario/veterinario.h"
#include "funcionario/tratador.h"

/// Classe Animal
class Animal{
	protected:
		int id; ///< Identificador do animal
		std::string classe; ///< Classe do animal
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
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{

		Animal(int cod, std::string clas);
		Animal();
		~Animal();

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
		
		int getId();
		std::string getClasse();
		std::string getNome_Cientifico();
		char getSexo();
		double getTamanho();
		std::string getDieta();
		Veterinario getVeterinario();
		Tratador getTratador();
		std::string getNome_Batismo();
		int getContadorCin();		
		
		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
		
		void setId(int id);
		void setClasse(std::string clas);
		void setNome_Cientifico(std::string cientific_name);
		void setSexo(char gender);
		void setTamanho(double size);
		void setDieta(std::string diet);
		void setVeterinario(int idVeterinario);
		void setTratador(int idTratador);
		void setNome_Batismo(std::string baptism_name);
		void setContadorCin(int c);


		//---------------------------------------------------------------------- ///@}
		/// @name Métodos utilitários
		//---------------------------------------------------------------------- ///@{

		virtual void limpar() = 0;
		virtual std::string getTipo() = 0;
		virtual std::string getStringFormatoCSV() = 0;
		
		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_H__