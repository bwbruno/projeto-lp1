#ifndef __MAMIFERO_NATIVO_H__
#define __MAMIFERO_NATIVO_H__

#include "animal/mamifero/mamifero.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe MamiferoNativo
/**
 * Detailed description starts here.
 */
class MamiferoNativo : public Mamifero, AnimalNativo {
	public:
		/// Construtor de MamiferoNativo sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		MamiferoNativo();
		/// Destrutor de MamiferoNativo.
		/**
		*  A more elaborate description of the destructor.
		*/
		~MamiferoNativo();
};

#endif // __MAMIFERO_NATIVO_H__