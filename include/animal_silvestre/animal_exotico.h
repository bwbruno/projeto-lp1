#ifndef __ANIMAL_EXOTICO_H__
#define __ANIMAL_EXOTICO_H__

#include <string>

#include "animal_silvestre/animal_silvestre.h"

/// Classe AnimalExotico
/**
 * AnimalNativo é a classe onde se registra o país de origem de animais exóticos
 * que entraram em território brasileiro espontaneamente, além das permissões para
 * manutenção e o uso desses animais.
 */
class AnimalExotico : public AnimalSilvestre {
	protected:
		std::string pais_origem; ///< País de origem
		std::string autorizacao; ///< Autorização do IBAMA

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		/// Construtor de AnimalExotico sem parâmetros.
		AnimalExotico();
		
		/// Construtor de AnimalExotico com parâmetros.
		AnimalExotico(std::string PO, std::string auth);

		/// Destrutor de AnimalExotico.
		~AnimalExotico();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Retorna o país de origem
		std::string getPais_Origem();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Seta o país de origem
		//! @param PO país de origem
		void setPais_Origem(std::string PO);

		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_EXOTICO_H__