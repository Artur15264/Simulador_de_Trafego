#include "Simulador.h"
#include "Veiculo.h"
#include "Rodovia.h"
#include "backward.hpp"

backward::SignalHandling sh;

using namespace std;
using namespace N;

int main() {
    Simulacao S1(3);

    S1.simulacao();
    
    return 0;
}
