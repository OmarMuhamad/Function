/** Author Omar Mohammad **/
/** ------KNOWLEDGE is Power.. Share it with others ^_-  ------ **/
#include <iostream>
#include <functional>
using namespace std;
class Function{
public:
    virtual double evaluateAt(double value) = 0;
};

class SimpleFunction:public Function{
    function<double(double)> fun;
public:
    SimpleFunction(function<double(double)> fun){
        this->fun = fun;
    }
    double evaluateAt(double value){
        return fun(value);
    }
};
class CompostiteFunciton:public Function{
    function<double(double)> F;
    function<double(double)> G;
public:
    CompostiteFunciton(function<double(double)> f, function<double(double)> g){
       this->F = f;
       this->G = g;
    }
    double evaluateAt(double value){
        return F(G(value));
    }
};
class DerivativeDerivate:public Function{
    function<double(double)> F;
    double deltaX;
public:
    DerivativeDerivate(function<double(double)> fun, double deltax){
        this->F = fun;
        this->deltaX = deltax;
    }
    double evaluateAt(double value){
        return ((F(value + deltaX) - F(value - deltaX))/(2 * deltaX)) - 1;
    }
};
double cube(double x){
    return x*x*x;
}
double doublE(double x){
    return x*x;
}
int main()
{
    SimpleFunction s1(cube);
    cout << s1.evaluateAt(5) << endl;
    CompostiteFunciton c1(cube, doublE);
    cout << c1.evaluateAt(5) << endl;
    DerivativeDerivate d1(cube, 2);
    cout << d1.evaluateAt(5) << endl;
}
