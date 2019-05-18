#ifndef __ANIMAL_EXOTICO_H__
#define __ANIMAL_EXOTICO_H__

#include <string>

#include "animal_silvestre/animal_silvestre.h"

/// Classe AnimalExotico
/**
 * AnimalNativo é a classe onde se registra o páís de origem de animais exóticos
 * que entraram em território brasileiro espontaneamente, além das permissões para
 * manutenção e o uso desses animais.
 */
class AnimalExotico : public AnimalSilvestre {
	public:
		/// Construtor de AnimalExotico sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AnimalExotico();
		/// Construtor de AnimalExotico com parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AnimalExotico(std::string PO, std::string auth);
		/// Destrutor de AnimalExotico.
		/**
		*  A more elaborate description of the destructor.
		*/
		~AnimalExotico();
		///@name Método getter
		///@{
		//! @brief Esse método permite que o usuário verifique o país de origem
		std::string getPais_Origem();
		///@}
		///@name Método setter
		///@{
		//! @brief Esse método permite que o usuário especifique o país de origem
		//! @param PO país de origem
		void setPais_Origem(std::string PO);
		///@}
		
	protected:
		std::string pais_origem; ///< País de origem
		std::string autorizacao; ///< Autorização do IBAMA
		
};

#endif // __ANIMAL_EXOTICO_H__