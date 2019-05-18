#ifndef __AVE_NATIVO_H__
#define __AVE_NATIVO_H__

#include "animal/ave/ave.h"
#include "animal_silvestre/animal_nativo.h"

/// Classe AveNativo
class AveNativo : public Ave, AnimalNativo {
	public:
		/// Construtor de AveNativo sem parâmetros.
		AveNativo();
		
		/// Destrutor de AveNativo.
		~AveNativo();
};

#endif // __AVE_NATIVO_H__