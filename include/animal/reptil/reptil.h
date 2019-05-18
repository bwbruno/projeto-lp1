#ifndef __REPTIL_H__
#define __REPTIL_H__

#include <string>

#include "animal/animal.h"

/// Animal que também possui registro sobre a produção de veneno ou não.
class Reptil : public Animal {
	protected:
		bool venenoso; ///< Se é venenoso ou não
		std::string tipo_veneno; ///< Tipo do veneno
		
	public:
		/// Construtor de Reptil sem parâmetros.
		Reptil();

		/// Destrutor de Reptil.
		~Reptil();
};

#endif // __REPTIL_H__