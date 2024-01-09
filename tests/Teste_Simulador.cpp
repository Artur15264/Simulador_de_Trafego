#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Simulador.h"

using namespace N;

TEST(Teste_Simulador, Teste_Num){
    Simulacao simulacao(10);
    simulacao.setNum(5);
    EXPECT_EQ(simulacao.getNum(), 5);
}