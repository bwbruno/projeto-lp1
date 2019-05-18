#ifndef __REPTIL_H__
#define __REPTIL_H__

#include <string>

#include "animal/animal.h"

/// Classe Reptil
/**
 * O Reptil é um Animal que além das características comuns, possui o registro sobre
 * a produção de veneno ou não.
 */
class Reptil : public Animal {
	public:
		/// Construtor de Reptil sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		Reptil();
		/// Destrutor de Reptil.
		/**
		*  A more elaborate description of the destructor.
		*/
		~Reptil();

	protected:
		bool venenoso; ///< Se é venenoso ou não
		std::string tipo_veneno; ///< Tipo do veneno
		
};

#endif // __REPTIL_H__