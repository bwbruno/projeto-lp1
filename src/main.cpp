/*!
 * @mainpage Pet Fera
 * @authors Bruno Wagner
 * @authors José Alex
 * @authors Pedro Augusto
 * @section intro_sec Introdução
 *  Programa de cadastro de animais para a loja de animais silvestres Pet Fera.
 * 
 * @section compile_sec Compilação
 *  Descrevemos aqui, como compilar esse código usando Make
 * @subsection Make
 *  Abra o terminal, acesse a passa raiz deste projeto e use o comando make
 * 
 * @bug
 * @warning
 * 
 */

#include "paineis.h"

using namespace std;

/// Função principal.
/** 
 * Para iniciar o programa, deve-se verificar se existem dois arquivos no formato CSV,
 * com os dados dos animais e dos funcionarios.
 * Caso existam, serão lidos. Caso contrário, serão criados na pasta csv.
 */
int main(int argc, const char* argv[]){
	
	painelPrincipal();

	return 0;
}