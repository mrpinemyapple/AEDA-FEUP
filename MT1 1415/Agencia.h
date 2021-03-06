/*
 * Agencia.h
 */

#ifndef AGENCIA_H_
#define AGENCIA_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Cliente;

class Conta {
protected:
  int numConta;
  float saldo;
  int numTransacoes;
  Cliente *titular2;
public:
	Conta(int nConta, float sd=0, int nTrans=0);
	int getNumConta() const;
	float getSaldo() const;
	int getNumTransacoes() const;
	Cliente *getTitular2() const;
	void setTitular2(Cliente *cli2);
	virtual bool levantamento(float valor) = 0;
	void deposito(float valor);
	virtual string getTipo() const = 0;
};

class Normal: public Conta {
public:
   Normal(int nConta, float sd=0, int nTrans=0);
   bool levantamento(float valor);
   string getTipo() const { return "N"; }
};


class DeOperacao: public Conta {
  float taxa;
public:
  DeOperacao(int nConta, float tx, float sd=0, int nTrans=0);
  bool levantamento(float valor);
  string getTipo() const { return "Op"; }
};


class Cliente {
  vector<Conta *> contas;
public:
	string nome;

  Cliente(string nm);
  string getNome() const;
  vector<Conta *> getContas() const;
  void adicionaConta(Conta *c1);

};


class Gerente {
  int ID;
  string nome;
  vector<Cliente *> meusClientes;
public:
  Gerente(string nm);
  int getID() const;
  string getNome() const;
  void setID(int id);

};


class Agencia {
	static int IDgerente;
  string designacao;
  vector<Cliente *> clientes;
  vector<Gerente> gerentes;
public:
  Agencia(string desig);
  string getDesignacao() const;
  vector<Cliente *> getClientes() const;
  vector<Gerente> getGerentes() const;
  void adicionaCliente(Cliente *cli1);
  Conta *levantamento(string nomeCli, float valor);
  float fimMes() const;
  vector<Conta*> removeCliente(string nomeCli);
  float operator<(const Agencia &a1);
  float operator()(string name);
  int setGerenteID (int IDinicio);
  void adicionaGerente(string nomeGer);
};



#endif /* AGENCIA_H_ */
