#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Rodovia.h"

using namespace N;

TEST(Teste_Rodovia, Teste_Limite){
    Rodovia r1(90, 5);
    r1.setLimite(90);
    EXPECT_EQ(r1.getLimite(), 90);
}

TEST(Teste_Rodovia, Teste_Quant){
    Rodovia r1(90, 5);
    r1.setQuant(5);
    EXPECT_EQ(r1.getQuant(), 5);
}

TEST(Teste_Rodovia, Teste_Adicionar){
    Rodovia r1(90, 5);
    r1.adicionarVeiculo();
    EXPECT_EQ(r1.getQuant(), 6);
}
