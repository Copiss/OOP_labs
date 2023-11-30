#include "Integrals.hpp"
double TrapezoidalIntegral::Calc(std::function<double(double)> f, double lowerBound, double upperBound) // переопределяем функцию Calc для TrapezoidalIntegral
{
    double integral = 0.0;
    // Проверка корректности переданных параметров
    if (numPoints < 1 || step <= 0.0 || tolerance <= 0.0)
    {
        std::cerr << "Ошибка: некорректные параметры." << '\n';
        return 0.0;
    }
    double x = lowerBound;
    double h = (upperBound - lowerBound) / numPoints;
    // Основной цикл метода трапеций
    for (int i = 0; i <= numPoints; i++)
    {
        if (i == 0 || i == numPoints)
            integral += f(x) / 2.0;
        else
            integral += f(x);
        x += h;
    }
    integral *= h;
    return trunc(integral / tolerance) * tolerance; // выводим с определённой точностью
}
double SimpsonIntegral::Calc(std::function<double(double)> f, double lowerBound, double upperBound) // переопределяем функцию Calc для SimpsonIntegral
{
    double integral = 0.0;
    // Проверка корректности переданных параметров
    if (numPoints < 2 || numPoints % 2 != 0 || step <= 0.0 || tolerance <= 0.0)
    {
        std::cerr << "Ошибка: некорректные параметры." << '\n';
        return 0.0;
    }
    double x = lowerBound;
    double h = (upperBound - lowerBound) / numPoints;
    // Основной цикл метода Симпсона
    for (int i = 0; i <= numPoints; i++)
    {
        double coeff = (i == 0 || i == numPoints) ? 1.0 : (i % 2 == 0 ? 2.0 : 4.0);
        integral += coeff * f(x);
        x += h;
    }
    integral *= h / 3.0;
    return trunc(integral / tolerance) * tolerance; // выводим с определённой точностью
}