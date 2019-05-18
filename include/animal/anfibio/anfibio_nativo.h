#ifndef __ANFIBIO_NATIVO_H__
#define __ANFIBIO_NATIVO_H__

#include "animal/anfibio/anfibio.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe AnfibioNativo
/**
 * Detailed description starts here.
 */
class AnfibioNativo : public Anfibio, AnimalNativo {
	public:
		/// Construtor de AnfibioNativo sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AnfibioNativo();
		/// Destrutor de AnfibioNativo.
		/**
		*  A more elaborate description of the destructor.
		*/
		~AnfibioNativo();
};

#endif // __ANFIBIO_NATIVO_H__