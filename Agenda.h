#ifndef AGENDA_H
#define AGENDA_H

#include "Contato.h"
#include <string>

class Agenda
{
	private:

		int tam = 0;

	public:
		Agenda(){}

		Contato busca(std::string name);
		
		int altera(std::string name, std::string telefone, std::string endereco, std::string relacao);
		int insere(std::string name, std::string telefone = "", std::string endereco = "", std::string 			relacao = "");
		int remove(std::string name);
		void listar();
		int salvarecupera(std::string name, std::string telefone, std::string endereco, std::string relacao, int x);
};

#endif
