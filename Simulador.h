#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Veiculo.h"
#include "Rodovia.h"

namespace N
{
    class Simulacao : public Veiculo, public Rodovia {
        private:
            int NumInter;

        public:
            // Métodos especiais
            void setNum(int num);
            int getNum();

            // Outros métodos
            void simulacao();

            // Construtor
            Simulacao(int interacoes);
        };
} 

#endif