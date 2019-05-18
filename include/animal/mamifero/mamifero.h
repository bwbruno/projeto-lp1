#ifndef __MAMIFERO_H__
#define __MAMIFERO_H__

#include <string>

#include "animal/animal.h"

/// Classe Mamifero
/**
 * O Mamifero é um Animal que além dos atributos comuns, possui o registro da
 * cor do pelo.
 */
class Mamifero : public Animal {
	public:
		/// Construtor de Mamifero sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		Mamifero();
		/// Destrutor de Mamifero.
		/**
		*  A more elaborate description of the destructor.
		*/
		~Mamifero();

	protected:
		std::string cor_pelo; ///< Cor do pelo
		
};

#endif // __MAMIFERO_H__