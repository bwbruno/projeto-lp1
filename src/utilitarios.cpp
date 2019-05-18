#include "utilitarios.h"

using namespace std;

string intParaString(int i){
	stringstream ss;
	ss << i;
	return ss.str();
}

map<string, string> vectorParaMap(vector<string> o){
	
	map<string, string> opcoes;
	pair<string, string> par;

	for (int i = 0; i < o.size(); ++i){
		par.first = intParaString(i);
		par.second = o[i];
		opcoes.insert(par);
	}

	return opcoes;
}