#ifndef __ANIMAL_NATIVO_H__
#define __ANIMAL_NATIVO_H__

#include <string>

#include "animal_silvestre/animal_silvestre.h"

/// Classe AnimalNativo
/**
 * AnimalNativo é a classe onde se registra as permissões para manutenção e o
 * uso dos animais nativos da fauna brasileira, além do estado brasileiro de
 * origem desses animais.
 */
class AnimalNativo : public AnimalSilvestre {
	public:
		/// Construtor de AnimalNativo sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AnimalNativo();
		/// Construtor de AnimalNativo com parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AnimalNativo(std::string UO, std::string auth);
		/// Destrutor de AnimalNativo.
		/**
		*  A more elaborate description of the destructor.
		*/
		~AnimalNativo();
		
		
		///@name Getter
		///@{
		//! @brief Esse método permite que o usuário verifique a UF de origem.

		//! @brief Esse método permite que o usuário verifique a UF de origem.
		std::string getUf_Origem();
		
		//! @brief Esse método permite que o usuário verifique a Autorização.
		std::string getAutorizacao();
		
		///@}
		///@name Método setter
		///@{
		
		//! @brief Esse método permite que o usuário especifique a UF de origem. 
		//! @param UO 
		void setUf_Origem(std::string UO);
		//! @brief Esse método permite que o usuário especifique a Autorização.
		//! @param auth 
		void setAutorizacao(std::string auth);
		///@}
		 
		
		
		

	protected:
		std::string uf_origem; ///< Estado de origem
		std::string autorizacao; ///< Autorização do IBAMA
		
};

#endif // __ANIMAL_NATIVO_H__