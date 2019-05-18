#ifndef __REPTIL_NATIVO_H__
#define __REPTIL_NATIVO_H__

#include "animal/reptil/reptil.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe ReptilNativo
/**
 * Detailed description starts here.
 */
class ReptilNativo : public Reptil, AnimalNativo {
	public:
		/// Construtor de ReptilNativo sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		ReptilNativo();
		/// Destrutor de ReptilNativo.
		/**
		*  A more elaborate description of the destructor.
		*/
		~ReptilNativo();
};

#endif // __REPTIL_NATIVO_H__