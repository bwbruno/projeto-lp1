#ifndef __AVE_NATIVO_H__
#define __AVE_NATIVO_H__

#include "animal/ave/ave.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe AveNativo
/**
 * Detailed description starts here.
 */
class AveNativo : public Ave, AnimalNativo {
	public:
		/// Construtor de AveNativo sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		AveNativo();
		/// Destrutor de AveNativo.
		/**
		*  A more elaborate description of the destructor.
		*/
		~AveNativo();
};

#endif // __AVE_NATIVO_H__