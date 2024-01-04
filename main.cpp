#include "Simulador.h"
#include "Veiculo.h"
#include "Rodovia.h"
#include "backward.hpp"
#define BACKWARD_HAS_BFD 1

backward::SignalHandling sh;

using namespace std;
using namespace N;

int main() {

    backward::StackTrace st;
    st.load_here();
    backward::Printer printer;

    Simulacao S1(3);

    S1.simulacao();
    
    printer.print(st, stderr);
    
    return 0;
}
