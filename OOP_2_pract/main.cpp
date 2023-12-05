#include <iostream>
class NaturalFraction
{
private:
    int numerator; //Числитель
    int denominator; //Знаменатель
public:
    NaturalFraction(int n, int d);                       //Конструктор
    void simplify();                                     // метод упрощения дроби
    NaturalFraction add(NaturalFraction other);          // метод сложения дробей
    NaturalFraction subtract(NaturalFraction other);     // метод вычитания дробей
    NaturalFraction multiply(NaturalFraction other);     // метод умножения дробей
    NaturalFraction divide(NaturalFraction other);       // метод деления дробей
    bool isEqualTo(NaturalFraction other);               // метод сравнения на равенство
    bool isGreaterThan(NaturalFraction other);           // метод сравнения на больше-меньше
    double toDecimal();                                  // метод превращения в десятичную дробь
    static NaturalFraction fromDecimal(double decimal);  // метод генерации дроби из десятичной дроби
    void toMixed();                                      // метод превращения в дробь с целой частью
};
//Нахождение наибольшего общего делителя
int nod(int n, int d)
{
    if (d == 0)	return n;
    else return nod(d, n % d);
}
//Конструктор
NaturalFraction::NaturalFraction(int n, int d)
{
    numerator = n;
    denominator = d;
}
// Mетод упрощения дроби
void NaturalFraction::simplify()
{
    int gcd = nod(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}
// Mетод сложения дробей
NaturalFraction NaturalFraction::add(NaturalFraction other)
{
    int n = numerator * other.denominator + other.numerator * denominator;
    int d = denominator * other.denominator;
    NaturalFraction result(n, d);
    result.simplify();
    return result;
}
// Mетод вычитания дробей
NaturalFraction NaturalFraction::subtract(NaturalFraction other)
{
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    NaturalFraction result(num, den);
    result.simplify();
    return result;
}
// Mетод умножения дробей
NaturalFraction NaturalFraction::multiply(NaturalFraction other)
{
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    NaturalFraction result(num, den);
    result.simplify();
    return result;
}
// Mетод деления дробей
NaturalFraction NaturalFraction::divide(NaturalFraction other)
{
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    NaturalFraction result(num, den);
    result.simplify();
    return result;
}
// Mетод сравнения на равенство
bool NaturalFraction::isEqualTo(NaturalFraction other)
{
    return numerator == other.numerator && denominator == other.denominator;
}
// Mетод сравнения на больше-меньше
bool NaturalFraction::isGreaterThan(NaturalFraction other)
{
    int num1 = numerator * other.denominator;
    int num2 = other.numerator * denominator;
    return num1 > num2;
}
// Mетод превращения в десятичную дробь
double NaturalFraction::toDecimal()
{
    return (double)numerator / (double)denominator;
}
// Mетод превращения в дробь с целой частью
void NaturalFraction::toMixed()
{
    int whole = numerator / denominator;
    numerator %= denominator;
    std::cout << whole << " " << numerator << "/" << denominator << std::endl;
}

// Примерчик
int main() {
    NaturalFraction f1(2, 3);
    NaturalFraction f2(3, 4);
    NaturalFraction sum = f1.add(f2);
    NaturalFraction diff = f1.subtract(f2);
    NaturalFraction prod = f1.multiply(f2);
    NaturalFraction quot = f1.divide(f2);
    bool equal = f1.isEqualTo(f2);
    bool greater = f1.isGreaterThan(f2);
    double decimal = f1.toDecimal();
    NaturalFraction from_dec = NaturalFraction::fromDecimal(0.75);
    sum.toMixed();
    return 0;
}
