#ifndef __AVE_EXOTICO_H__
#define __AVE_EXOTICO_H__

#include "animal/ave/ave.h"
#include "animal_silvestre/animal_exotico.h"

/// Classe AveExotico
class AveExotico : public Ave, AnimalExotico {
	public:
		/// Construtor de AveExotico sem parâmetros.
		AveExotico();
		
		/// Destrutor de AveExotico.
		~AveExotico();
};

#endif // __AVE_EXOTICO_H__