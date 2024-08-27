#include "Agenda.h"
#include "Contato.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

	Contato contatos[100];
	int tam = 0;
	
	Contato Agenda::busca(string nome)
	{
		for(int i = 0; i <= tam; i++)
		{
			if(contatos[i].getNome() == nome)
			{
				return contatos[i];
			}
		}
		return Contato();
	}
	
	int Agenda::altera(string nome, string telefone, string endereco, string relacao)
	{
		for(int i = 0; i <= tam; i++)
		{
			if(contatos[i].getNome() == nome)
			{
				contatos[i].setNome(nome); contatos[i].setEnd(endereco);
				contatos[i].setTel(telefone); contatos[i].setRel(relacao);
				return 1;
			}
		}
		return 0;
	}
	
	int Agenda::insere(string nome, string telefone, string endereco, string relacao)
{
		Contato contatoBuscado = busca(nome);
		if (contatoBuscado.getNome() == nome)
		{
				return altera(nome, telefone, endereco, relacao);
		}
		else
		{
				if (tam <= 100) // Verifica se há espaço no vetor
				{
						contatos[tam].setNome(nome);
						contatos[tam].setEnd(endereco);
						contatos[tam].setTel(telefone);
						contatos[tam].setRel(relacao);
						tam++;
						return 1;
				}
				else
				{
						cout << "Agenda cheia!" << endl;
						return -1;
				}
		}
}
	
	int Agenda::remove(string nome)
	{
		for(int i = 0; i < tam; i++)
		{
			if(contatos[i].getNome() == nome)
			{
				Contato aux;
				aux = contatos[i];
				contatos[i] = contatos[tam];
				contatos[tam] = aux;
				
				tam--;
				return 1;
			}
		}
		return 0;
	}
	
	void Agenda::listar()
	{
		for(int i = 0; i <= tam; i++)
		{
			if (!contatos[i].getNome().empty())
				{
					contatos[i].toString();
				}
		}
	}
	
	int Agenda::salvarecupera(string nome, string telefone, string endereco, string relacao, int x) // 0 = salvar, 1 = recuperar
	{
		if(x == 0)
		{
			ofstream arquivo("contatos.txt", ios::app); // Modo de anexar ao arquivo, não apaga o conteúdo anterior escreve em baixo
			if (!arquivo.is_open()) {
				cout << "Erro ao abrir o arquivo para salvar" << endl;
				return -1;
			}
			
			arquivo << nome << "," << telefone << "," << endereco << "," << relacao << endl;
			arquivo.close();
		}
		else
		{
			ifstream arquivo("contatos.txt");
			if (!arquivo.is_open()) {
				cout << "Erro ao abrir o arquivo para recuperar" << endl;
				return -1;
			}

			string linha;
			getline(arquivo, linha);
			size_t pos;

			// Recupera o nome
			pos = linha.find(',');
			contatos[tam].setNome(linha.substr(0, pos));
			linha = linha.substr(pos + 1);

			// Recupera o telefone
			pos = linha.find(',');
			contatos[tam].setTel(linha.substr(0, pos));
			linha = linha.substr(pos + 1);

			// Recupera o endereço
			pos = linha.find(',');
			contatos[tam].setEnd(linha.substr(0, pos));
			linha = linha.substr(pos + 1);

			// Recupera a relação
			contatos[tam].setRel(linha);

			arquivo.close();
		}

		return 0;
	}