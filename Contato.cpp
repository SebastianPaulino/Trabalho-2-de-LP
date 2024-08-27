#include "Contato.h"
#include <iostream>
#include <string>

using namespace std;

	string nome;
	string telefone;
	string endereco;
	string relacao;
	
	void Contato::toString()
	{
		cout << "Nome: " << nome << ", Telefone: " << telefone << ", Endereço: " << endereco << ", Relação: " << relacao << endl;
	}
	
	string Contato::getNome()
	{
		return nome;
	}
	string Contato::getTel()
	{
		return telefone;
	}
	string Contato::getEnd()
	{
		return endereco;
	}
	string Contato::getRel()
	{
		return relacao;
	}
	void Contato::setNome(string name)
	{
		nome = name;
	}
	void Contato::setTel(string tel)
	{
		telefone = tel;
	}
	void Contato::setEnd(string end)
	{
		endereco = end;
	}
	void Contato::setRel(string Rel)
	{
		relacao = Rel;
	}		