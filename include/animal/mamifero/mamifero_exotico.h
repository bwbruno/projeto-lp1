#ifndef __MAMIFERO_EXOTICO_H__
#define __MAMIFERO_EXOTICO_H__

#include "animal/mamifero/mamifero.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe MamiferoExotico
/**
 * Detailed description starts here.
 */
class MamiferoExotico : public Mamifero, AnimalExotico {
	public:
		/// Construtor de MamiferoExotico sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		MamiferoExotico();
		/// Destrutor de MamiferoExotico.
		/**
		*  A more elaborate description of the destructor.
		*/
		~MamiferoExotico();
};

#endif // __MAMIFERO_EXOTICO_H__