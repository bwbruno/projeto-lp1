#ifndef __AVE_EXOTICO_H__
#define __AVE_EXOTICO_H__

#include "animal/ave/ave.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe AveExotico
/**
 * Detailed description starts here.
 */
class AveExotico : public Ave, AnimalExotico {
	public:
		/// Construtor de AveExotico sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AveExotico();
		/// Destrutor de AveExotico.
		/**
		*  A more elaborate description of the destructor.
		*/
		~AveExotico();
};

#endif // __AVE_EXOTICO_H__