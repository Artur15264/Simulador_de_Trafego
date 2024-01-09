#include <iostream>
#include "Rodovia.h"

using namespace N;
using namespace std;

    // Métodos especiais
    void Rodovia::setLimite(int limiteVelocidade) {
        if (limiteVelocidade >= 60) {
            LimiteVelocidade = limiteVelocidade;
        } else {
            cout << "Limite de velocidade não permitido!\n";
            cout << "Digite um valor acima de 60 Km/h!\n";
            configurarRodovia();
        }
    }
    int Rodovia::getLimite() { return LimiteVelocidade; }
    void Rodovia::setQuant(int quantVeiculos) { QuantVeiculos = quantVeiculos; }
    int Rodovia::getQuant() { return QuantVeiculos; }

    // Outros métodos
    void Rodovia::adicionarVeiculo() {
        setQuant(getQuant() + 1);
    }
    void Rodovia::configurarRodovia() {
        int velocidade = 0;

        cout << "Defina a velocidade máxima da rodovia: ";
            cin >> velocidade;
        setLimite(velocidade);
    }

    // Construtor
    Rodovia::Rodovia(int limite, int quant) : LimiteVelocidade(limite), QuantVeiculos(quant) {}
