#include "src/libgambit/libgambit.h"
//#include "boost/lexical_cast.hpp"
#include <cstring>

//using boost::lexical_cast;

int main(){
    Gambit::Rational y;
    int i=0;
    std::string s;

    std::cerr << "Test cin\n";
    try{
        std::cin >> y;
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "MAIN CIN " << y << "\n";

    std::cerr << "Test cin\n";
    try{
        std::cin >> y;
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "MAIN CIN " << y << "\n";
    return 0;
    s = "1.573e2blahblah";
    std::cerr << "Test " << i++ << " " << s << "\n";
    try{
        y = Gambit::lexical_cast<Gambit::Rational>(s);
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "MAIN " << y << "\n";

    s = "5/0";
    std::cerr << "Test " << i++ << " " << s << "\n";
    try{
        y = Gambit::lexical_cast<Gambit::Rational>(s);
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "MAIN " << y << "\n";

    s = "1.573e";
    std::cerr << "Test " << i++ << " " << s << "\n";
    try{
        y = Gambit::lexical_cast<Gambit::Rational>(s);
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "lexical " << y << "\n";

    s = "1.573/";
    std::cerr << "Test " << i++ << " " << s << "\n";
    try{
        y = Gambit::lexical_cast<Gambit::Rational>(s);
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "lexical " << y << "\n";

    s = "5/2";
    std::cerr << "Test " << i++ << " " << s << "\n";
    try{
        y = Gambit::lexical_cast<Gambit::Rational>(s);
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "lexical " << y << "\n";

    s = "1.531e2";
    std::cerr << "Test " << i++ << " " << s << "\n";
    try{
        y = Gambit::lexical_cast<Gambit::Rational>(s);
    }catch(Gambit::ValueException e){
        std::cerr << "EXCEPTON\n";
    }
    std::cerr << "lexical " << y << "\n";
    return 0;
}
