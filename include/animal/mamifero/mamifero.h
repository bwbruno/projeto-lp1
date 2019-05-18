#ifndef __MAMIFERO_H__
#define __MAMIFERO_H__

#include <string>

#include "animal/animal.h"

/// Animal que também possui registro da cor do pelo.
class Mamifero : public Animal {
	protected:
		std::string cor_pelo; ///< Cor do pelo

	public:
		/// Construtor de Mamifero sem parâmetros.
		Mamifero();

		/// Destrutor de Mamifero.
		~Mamifero();
};

#endif // __MAMIFERO_H__