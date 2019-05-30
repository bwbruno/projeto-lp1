#ifndef __ANIMAL_EXOTICO_H__
#define __ANIMAL_EXOTICO_H__

#include <string>

#include "animal_silvestre/animal_silvestre.h"

/// Classe onde se registra o país de origem de animais exóticos, além da autorização do IBAMA.
/**
 * ![Diagrama de classe Animal Silvestre](animalsilvestre.png)
 */
class AnimalExotico : public AnimalSilvestre {
	protected:
		std::string pais_origem; ///< País de origem

	public:
		//---------------------------------------------------------------------- ///@}
		/// @name Construtores e destrutor
		//---------------------------------------------------------------------- ///@{
 
		AnimalExotico();


		//---------------------------------------------------------------------- ///@}
		/// @name Getters
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Retorna o país de origem
		std::string getPaisOrigem();
		

		//---------------------------------------------------------------------- ///@}
		/// @name Setters
		//---------------------------------------------------------------------- ///@{
 
		//! @brief Seta o país de origem
 		void setPaisOrigem(std::string PO);
		
		//---------------------------------------------------------------------- ///@}
};

#endif // __ANIMAL_EXOTICO_H__