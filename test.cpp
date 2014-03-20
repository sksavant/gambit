#include "src/libgambit/libgambit.h"
#include "boost/lexical_cast.hpp"

using boost::lexical_cast;

int main(){
    Gambit::Rational y;
    std::string s = "1.5e2";
    y = Gambit::lexical_cast<Gambit::Rational>(s);
    std::cerr << "MAIN " << y << "\n";
    return 0;
}
