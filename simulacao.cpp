#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Veiculo {
private:
    string Nome, Tipo;
    int Velocidade, Posicao;

public:
    // Métodos especiais
    void setNome(string nome) { Nome = nome; }
    string getNome() const { return Nome; }
    void setTipo(string tipo) { Tipo = tipo; }
    string getTipo() const { return Tipo; }
    void setVel(int velocidade) {
        if (velocidade >= 0) {
            Velocidade = velocidade;
        } else {
            cout << "Velocidade inválida!\n";
            Velocidade = 0;
        }
    }
    int getVel() const { return Velocidade; }
    void setPosicao(int posicao) { Posicao = posicao; }
    int getPosicao() { return Posicao; }

    // Funções de um veículo
    void acelerar() {
        setPosicao(getPosicao() + 1);
        Velocidade += 10;
    }
    void reduzir() {
        setPosicao(getPosicao() - 1);
        Velocidade -= 10;
    }
    void criarVeiculo() {
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
    }

    // Construtor
    Veiculo() : Nome(""), Tipo(""), Velocidade(0), Posicao(0) {}
};

class Rodovia {
private:
    int LimiteVelocidade, QuantVeiculos;

public:
    // Métodos especiais
    void setLimite(int limiteVelocidade) {
        if (limiteVelocidade >= 60) {
            LimiteVelocidade = limiteVelocidade;
        } else {
            cout << "Limite de velocidade não permitido!\n";
            cout << "Digite um valor acima de 60 Km/h!\n";
        }
    }
    int getLimite() { return LimiteVelocidade; }
    void setQuant(int quantVeiculos) { QuantVeiculos = quantVeiculos; }
    int getQuant() { return QuantVeiculos; }

    // Outros métodos
    void adicionarVeiculo() {
        setQuant(getQuant() + 1);
    }
    void configurarRodovia() {
        int velocidade = 0;

        cout << "Defina a velocidade máxima da rodovia: ";
        cin >> velocidade;

        setLimite(velocidade);
    }

    // Construtor
    Rodovia(int limite, int quant) : LimiteVelocidade(limite), QuantVeiculos(quant) {}
};

class Simulacao : public Veiculo, public Rodovia {
private:
    int NumInter;

public:
    // Métodos especiais
    void setNum(int num) { NumInter = num; }
    int getNum() { return NumInter; }

    // Outros métodos
    void simulacao() {
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

            switch (opc) {
            case 0:
                acelerar();
                cout << "\n---------------------------------\n";
                cout << getNome() << " Acelerou!\n";
                cout << "Velocidade atual = " <<  getVel() << "\n";
                setVel(getVel());
                break;
            default:
                reduzir();
                cout << "\n---------------------------------\n";
                cout << getNome() << " Reduziu!\n";
                cout << "Velocidade atual = " <<  getVel() << "\n";
                setVel(getVel());
                break;
            }
            
            numVet++;
            i++;
        }
    }

    // Construtor
    Simulacao(int interacoes) : Veiculo(), Rodovia(0, 0), NumInter(interacoes) {}
};

int main() {
    Simulacao S1(3);

    S1.simulacao();
    
    
    return 0;
}
