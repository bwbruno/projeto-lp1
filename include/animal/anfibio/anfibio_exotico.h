#ifndef __ANFIBIO_EXOTICO_H__
#define __ANFIBIO_EXOTICO_H__

#include "animal/anfibio/anfibio.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe AnfibioExotico
/**
 * Detailed description starts here.
 */
class AnfibioExotico : public Anfibio, AnimalExotico {
	public:
		/// Construtor de AnfibioExotico sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AnfibioExotico();
		/// Destrutor de AnfibioExotico.
		/**
		*  A more elaborate description of the destructor.
		*/
		~AnfibioExotico();
};

#endif // __ANFIBIO_EXOTICO_H__