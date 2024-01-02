#ifndef RODOVIA_H
#define RODOVIA_H

namespace N
{
    class Rodovia {
        private:
            int LimiteVelocidade, QuantVeiculos;

        public:
            // Métodos especiais
            void setLimite(int limiteVelocidade);
            int getLimite();
            void setQuant(int quantVeiculos);
            int getQuant();

            // Outros métodos
            void adicionarVeiculo();
            void configurarRodovia();

            // Construtor
            Rodovia(int limite, int quant);
        };
} 

#endif