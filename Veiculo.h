#ifndef VEICULO_H
#define VEICULO_H

#include <string>

namespace N 
{
    class Veiculo {
        private:
            std::string Nome, Tipo;
            int Velocidade, Posicao;

        public:
            // Métodos especiais
            void setNome(std::string nome);
            std::string getNome();
            void setTipo(std::string tipo);
            std::string getTipo();
            void setVel(int velocidade);
            int getVel();
            void setPosicao(int posicao);
            int getPosicao();

            // Funções de um veículo
            void acelerar();
            void reduzir();
            void criarVeiculo();

            // Construtor
            Veiculo();
        };
}

#endif