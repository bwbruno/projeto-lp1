#ifndef __AVE_H__
#define __AVE_H__

#include "animal/animal.h"

/// Classe Ave
/**
 * O Ave é um Animal que além dos atributos comuns, possui o registro do
 * tamanho do bico em cm e a envergadura das asas.
 */
class Ave : public Animal {
	public:
		/// Construtor de Ave sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		Ave();
		/// Destrutor de Ave.
		/**
		*  A more elaborate description of the destructor.
		*/
		~Ave();

	protected:
		double tamanho_do_bico_cm; ///< Tamanho do bico em CM
		double envergadura_das_asas_cm; ///< Envergadura das asas em CM
		
};

#endif // __AVE_H__