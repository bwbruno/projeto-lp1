#ifndef __REPTIL_EXOTICO_H__
#define __REPTIL_EXOTICO_H__

#include "animal/reptil/reptil.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe ReptilExotico
/**
 * Detailed description starts here.
 */
class ReptilExotico : public Reptil, AnimalExotico {
	public:
		/// Construtor de ReptilExotico sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		ReptilExotico();
		/// Destrutor de ReptilExotico.
		/**
		*  A more elaborate description of the destructor.
		*/
		~ReptilExotico();
};

#endif // __REPTIL_EXOTICO_H__