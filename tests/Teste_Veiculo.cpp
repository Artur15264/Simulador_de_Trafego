#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Veiculo.h"

using namespace std;
using namespace N;

TEST(Teste_Veiculo, Teste_Nome) {
    Veiculo veiculo;
    veiculo.setNome("Onix");
    EXPECT_EQ(veiculo.getNome(), "Onix");
}

TEST(Teste_Veiculo, Teste_Tipo) {
    Veiculo veiculo;
    veiculo.setTipo("Carro");
    EXPECT_EQ(veiculo.getTipo(), "Carro");
}

TEST(Teste_Veiculo, Teste_Vel_Pos) {
    Veiculo veiculo;
    veiculo.setVel(50);
    EXPECT_EQ(veiculo.getVel(), 50);
}

TEST(Teste_Veiculo, Teste_Vel_Neg) {
    Veiculo veiculo;
    veiculo.setVel(-10);
    EXPECT_EQ(veiculo.getVel(), 0);
}

TEST(Teste_Veiculo, Teste_Posicao) {
    Veiculo veiculo;
    veiculo.setPosicao(5);
    EXPECT_EQ(veiculo.getPosicao(), 5);
}

TEST(Teste_Veiculo, Teste_Acelerar) {
    Veiculo veiculo;
    veiculo.acelerar();
    EXPECT_EQ(veiculo.getPosicao(), 1);
    EXPECT_EQ(veiculo.getVel(), 10);
}

TEST(Teste_Veiculo, Teste_Reduzir) {
    Veiculo veiculo;
    veiculo.reduzir();
    EXPECT_EQ(veiculo.getPosicao(), -1);
    EXPECT_EQ(veiculo.getVel(), -10);
}

TEST(Teste_Veiculo, Teste_CriarVeiculo) {
    istringstream input_stream("Onix\nCarro\n60\n");

    streambuf* orig_cin = cin.rdbuf(input_stream.rdbuf());

    Veiculo veiculo;
    veiculo.criarVeiculo();

    cin.rdbuf(orig_cin);

    EXPECT_EQ(veiculo.getNome(), "Onix");
    EXPECT_EQ(veiculo.getTipo(), "Carro");
    EXPECT_EQ(veiculo.getVel(), 60);
}