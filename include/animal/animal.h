#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

#include "funcionario/veterinario.h"
#include "funcionario/tratador.h"

/// Classe Animal
/** 
 * Conjunto de atributos comuns a todos os animais da Pet Fera.
 */
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

	public:
		///@name Construtores e destrutor
		///@{

		//! @brief Construtor de Animal com parâmetros.
		Animal(int cod, std::string clas);
		
		//! @brief Construtor de Animal sem parâmetros.
		Animal();

		//! @brief Destrutor de Animal.
		~Animal();

		///@}
		///@name Getters
		///@{
		//! @brief Médotos para acessar atributos protegidos.
		
		//! @brief Médoto para pegar o atributo protegido id
		int getId();
		
		//! @brief Médoto para pegar o atributo protegido classe
		std::string getClasse();
		
		//! @brief Médoto para pegar o atributo protegido nome_cientifico
		std::string getNome_Cientifico();
		
		//! @brief Médoto para pegar o atributo protegido sexo
		char getSexo();
		
		//! @brief Médoto para pegar o atributo protegido tamanho
		double getTamanho();
		
		//! @brief Médoto para pegar o atributo protegido dieta
		std::string getDieta();
		
		//! @brief Médoto para pegar o atributo protegido veterinario
		Veterinario getVeterinario();
		
		//! @brief Médoto para pegar o atributo protegido tratador
		Tratador getTratador();
		
		//! @brief Médoto para pegar o atributo protegido nome_batismo
		std::string getNome_Batismo();
		
		
		///@}
		///@name Setters
		///@{
		//! @brief Médotos para acessar atributos protegidos.
		
		//! @brief Médoto para setar o atributo protegido id
		//! @param id identificador do Animal
		void setId(int id);

		//! @brief Médoto para setar o atributo protegido class
		/**
		 * String, onde é uma das seguintes: 
		 *  - *Amphibia* (anfíbio)
		 *  - *Reptilia* (réptil)
		 *  - *Aves* (ave)
		 *  - *Mammalia* (mamífero)
		 */
		//! @param clas classe do Animal
		void setClasse(std::string clas);

		//! @brief Médoto para setar o atributo protegido nome_cientifico
		//! @param cientific_name nome científico do Animal
		void setNome_Cientifico(std::string cientific_name);

		//! @brief Médoto para setar o atributo protegido sexo
		/**
		* Sexo é um dos seguintes:
		*  - M (macho)
		*  - F (fêmea)
		*/
		//! @param gender sexo do Animal
		void setSexo(char gender);

		//! @brief Médoto para setar o atributo protegido tamanho
		//! @param size tamanho do Animal
		void setTamanho(double size);

		//! @brief Médoto para setar o atributo protegido dieta
		//! @param diet diete do Animal
		void setDieta(std::string diet);

		//! @brief Médoto para setar o veterinario associado ao animal
		/**
		 * Onde @b idVeterinario é um dos seguintes:
		 *  - 0 (indica que não há veterinário associado)
		 *  - maior ou igual a 1 (indica o id do veterinário associado a esse animal)
		 */
		//! @exception Caso não exista veterinário com o id informado.
		//! @param idVeterinario id do veterinário
		void setVeterinario(int idVeterinario);

		//! @brief Médoto para setar o atributo protegido tratador
		//! @param caregiver tratador do Animal
		void setTratador(Tratador caregiver);

		//! @brief Médoto para setar o atributo protegido nome_batismo
		//! @param baptismo_name nome de batismo do Animal
		void setNome_Batismo(std::string baptism_name);
		
		///@}
};

#endif // __ANIMAL_H__