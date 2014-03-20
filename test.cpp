#include "src/libgambit/libgambit.h"
#include "boost/lexical_cast.hpp"

using boost::lexical_cast;

int main(){
    Gambit::Rational y;
    int i=0;
    std::string s = "1.573e";
    std::cerr << "Test " << i++ << " " << s << "\n";
    y = Gambit::lexical_cast<Gambit::Rational>(s);
    std::cerr << "MAIN " << y << "\n";

    s = "1.573e2";
    std::cerr << "Test " << i++ << " " << s << "\n";
    y = Gambit::lexical_cast<Gambit::Rational>(s);
    std::cerr << "lexical " << y << "\n";

    s = "1.573";
    std::cerr << "Test " << i++ << " " << s << "\n";
    y = Gambit::lexical_cast<Gambit::Rational>(s);
    std::cerr << "lexical " << y << "\n";

    s = "5/2";
    std::cerr << "Test " << i++ << " " << s << "\n";
    y = Gambit::lexical_cast<Gambit::Rational>(s);
    std::cerr << "lexical " << y << "\n";
    return 0;
}
