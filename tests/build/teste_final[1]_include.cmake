if(EXISTS "/home/artur/Treinamento/Simulação_de_Tráfego/tests/build/teste_final[1]_tests.cmake")
  include("/home/artur/Treinamento/Simulação_de_Tráfego/tests/build/teste_final[1]_tests.cmake")
else()
  add_test(teste_final_NOT_BUILT teste_final_NOT_BUILT)
endif()
