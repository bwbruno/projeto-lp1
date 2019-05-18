#ifndef __MAMIFERO_NATIVO_H__
#define __MAMIFERO_NATIVO_H__

#include "animal/mamifero/mamifero.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe MamiferoNativo
class MamiferoNativo : public Mamifero, AnimalNativo {
	public:
		/// Construtor de MamiferoNativo sem parâmetros.
		MamiferoNativo();
		
		/// Destrutor de MamiferoNativo.
		~MamiferoNativo();
};

#endif // __MAMIFERO_NATIVO_H__