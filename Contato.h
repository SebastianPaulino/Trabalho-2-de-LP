#ifndef CONTATO_H
#define CONTATO_H
#include <iostream>
#include <string.h>


class Contato
{
	private:
	std::string nome;
	std::string telefone;
	std::string endereco;
	std::string relacao;

	public:
		Contato() : nome(""), telefone(""), endereco(""), relacao(""){}

		Contato(std::string nome,std::string telefone,std::string endereco,std::string relacao) : nome(nome), telefone(telefone), endereco(endereco), relacao(relacao){}
		
		void toString();
		std::string getNome();
		std::string getTel();
		std::string getEnd();
		std::string getRel();
		void setNome(std::string name);
		void setTel(std::string tel);
		void setEnd(std::string end);
		void setRel(std::string Rel);
};

#endif