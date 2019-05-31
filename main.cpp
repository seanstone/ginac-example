#include <stdlib.h>
#include <iostream>
#include <ginac/ginac.h>
#include <functional>
using namespace std;
using namespace std::placeholders;
using namespace GiNaC;

class xidx : public varidx
{
public:
    xidx(const char* str) : varidx(symbol(str), 4, true) {}
    ex operator~ () const { return this->toggle_variance(); }
};

int main(int argc, char **argv)
{
    xidx mu("mu"), nu("nu"), rho("rho"), sigma("sigma");
    auto g = bind(lorentz_g, _1, _2, false);

    cout << g(~mu, nu) << "\n";

    return 0;
}