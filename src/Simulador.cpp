#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Veiculo.h"
#include "Rodovia.h"
#include "Simulador.h"

using namespace std;
using namespace N;

    // Métodos especiais
    void Simulacao::setNum(int num) { NumInter = num; }
    int Simulacao::getNum() { return NumInter; }

    // Outros métodos
    void Simulacao::simulacao() {
        srand(time(0));
        int i = 0, opc = 0, numVet = 0;
        vector<string> vetNome;
        vector<int> vetVel;

        configurarRodovia();

        // Criação dos veículos
        while (i < getNum()) {
            cout << "\n---------------------------------\n";
            criarVeiculo();
            adicionarVeiculo();
            cout << getNome() << " adicionado!";
            cout << "\n---------------------------------\n";
            cout << "         [Status da Rodovia]       \n";
            cout << "\n-> Numero de veículos = " << getQuant();

            vetNome.push_back(getNome());
            vetVel.push_back(getVel());

            i++;
        }

        // Simulação de interações
        i = 0;
        while (i < getNum()) {
            numVet = rand() % getQuant();
            
            opc = rand() % 2;

            setNome(vetNome[numVet]);
            setVel(vetVel[numVet]);

            if (getVel() > getLimite()) {
                cout << "\n---------------------------------\n";
                cout << "O veículo [ " << getNome() << " ] foi multado por excesso de velocidade!";
                cout << "Diminua a velocidade IMEDIATAMENTE!";
                reduzir();
                reduzir();
            }

            switch (opc) {
            case 0:
                acelerar();
                cout << "\n---------------------------------\n";
                cout << getNome() << " Acelerou!\n";
                cout << "Velocidade atual = " <<  getVel() << "\n";
                vetVel[numVet] = getVel();
                break;
            default:
                reduzir();
                cout << "\n---------------------------------\n";
                cout << getNome() << " Reduziu!\n";
                cout << "Velocidade atual = " <<  getVel() << "\n";
                vetVel[numVet] = getVel();
                break;
            }

            numVet++;
            i++;
        }
    }

    // Construtor
    Simulacao::Simulacao(int interacoes) : Veiculo(), Rodovia(0, 0), NumInter(interacoes) {}
