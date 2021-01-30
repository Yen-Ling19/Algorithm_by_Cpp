#include <iostream>
using namespace std;

class Quadratic
{
    public:
        Quadratic();
        Quadratic(int a, int b, int c);
        int get_two() { return two; }
        int get_one() { return one; }
        int get_con() { return con; }
        void Eval(int x);
        friend istream &operator>>(istream &input, Quadratic &func);
        friend ostream &operator<<(ostream &output, Quadratic &func);
    private:
        int two; //二次方
        int one; //一次方
        int con; //常數
};

Quadratic operator+(Quadratic &a, Quadratic &b);

Quadratic operator+(Quadratic &a, Quadratic &b)
{
    int sum2 = a.get_two() + b.get_two();
    int sum1 = a.get_one() + b.get_one();
    int sum0 = a.get_con() + b.get_con();
    return Quadratic(sum2, sum1, sum0);
}

istream& operator >> (istream &input, Quadratic &func)
{
    int T, O, C;
    input >> T >> O >> C;
    func.two = T;
    func.one = O;
    func.con = C;
    return input;
}

ostream &operator<<(ostream &output, Quadratic &func)
{
    output << func.two << "x^2";
    if (func.one>=0)
        output << "+" << func.one << "x";
    else
        output << func.one << "x";
    if(func.con>=0)
        output << "+" << func.con << endl;
    else
        output << func.con << endl;
    return output;
}

Quadratic::Quadratic()
{
    two = 0;
    one = 0;
    con = 0;
}

Quadratic::Quadratic(int a, int b, int c)
{
    two = a;
    one = b;
    con = c;
}

void Quadratic::Eval(int x)
{
    int sum = two * x * x + one * x + con;
    cout << sum;
}

int main()
{
    Quadratic first_equation;
    Quadratic second_equation;
    cin >> first_equation;
    cin >> second_equation;
    Quadratic total_equation;
    total_equation = first_equation + second_equation;
    cout << total_equation;
    int x;
    cin >> x;
    total_equation.Eval(x);
}
