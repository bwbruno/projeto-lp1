#ifndef __AVE_H__
#define __AVE_H__

#include "animal/animal.h"

/// Animal que possui registro do tamanho do bico em cm e a envergadura das asas.
class Ave : public Animal {
	protected:
		double tamanho_do_bico_cm; ///< Tamanho do bico em CM
		double envergadura_das_asas_cm; ///< Envergadura das asas em CM
		
	public:
		/// Construtor de Ave sem parâmetros.
		Ave();

		/// Destrutor de Ave.
		~Ave();
};

#endif // __AVE_H__