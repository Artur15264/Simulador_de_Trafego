#include <iostream>
#include "Veiculo.h"
#include <string>

using namespace std;
using namespace N;


    // Métodos especiais
    void Veiculo::setNome(string nome) { Nome = nome; }
    string Veiculo::getNome() { return Nome; }
    void Veiculo::setTipo(string tipo) { Tipo = tipo; }
    string Veiculo::getTipo() { return Tipo; }
    void Veiculo::setVel(int velocidade) {
        if (velocidade >= 0) {
            Velocidade = velocidade;
        } else {
            cout << "Velocidade inválida!\n\n";
            Velocidade = 0;
        }
    }
    int Veiculo::getVel() { return Velocidade; }
    void Veiculo::setPosicao(int posicao) { Posicao = posicao; }
    int Veiculo::getPosicao() { return Posicao; }

    // Funções de um veículo
    void Veiculo::acelerar() {
        setPosicao(getPosicao() + 1);
        Velocidade += 10;
    }
    void Veiculo::reduzir() {
        setPosicao(getPosicao() - 1);
        Velocidade -= 10;
    }
    void Veiculo::criarVeiculo() {
        string nomeVeiculo = "";
        string tipoVeiculo = "";
        int velocidadeVeiculo = 0;

        cout << "Digite o nome do veículo: ";
        cin >> nomeVeiculo;
        setNome(nomeVeiculo);
        cout << "Digite o tipo de veículo: ";
        cin >> tipoVeiculo;
        setTipo(tipoVeiculo);
        cout << "Digite a velocidade inicial do veículo: ";
        cin >> velocidadeVeiculo;
        setVel(velocidadeVeiculo);

        if (velocidadeVeiculo < 0){
            criarVeiculo();
        }
    }

    // Construtor
    Veiculo::Veiculo() : Nome(""), Tipo(""), Velocidade(0), Posicao(0) {}