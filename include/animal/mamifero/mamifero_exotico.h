#ifndef __MAMIFERO_EXOTICO_H__
#define __MAMIFERO_EXOTICO_H__

#include "animal/mamifero/mamifero.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe MamiferoExotico
class MamiferoExotico : public Mamifero, AnimalExotico {
	public:
		/// Construtor de MamiferoExotico sem parâmetros.
		MamiferoExotico();
		
		/// Destrutor de MamiferoExotico.
		~MamiferoExotico();
};

#endif // __MAMIFERO_EXOTICO_H__