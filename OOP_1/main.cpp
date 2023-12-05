#include "Integrals.hpp"
int main()
{
    SetConsoleOutputCP(1251); // Для русского языка в консоли
    SetConsoleOutputCP(CP_UTF8);
    // Подынтегральное выражение: x^3 + x
    auto f = [](double x)
    {
        return x * x * x + x;
    };
    // Создание объектов для расчета интегралов разными методами (Берём 100 точек, шаг = 0.01 и почность в 1 милионную)
    TrapezoidalIntegral trapezoidal(100, 0.01, 0.000001);
    SimpsonIntegral simpson(100, 0.01, 0.000001);
    // Задание верхней и нижней границ интегрирования
    double lowerBound = 0.0;
    double upperBound = 1.0;
    // Вычисление интегралов обоими способами
    double integralTrapezoidal = trapezoidal.Calc(f, lowerBound, upperBound);
    double integralSimpson = simpson.Calc(f, lowerBound, upperBound);
    // Вывод результатов
    std::cout << "Интеграл (метод трапеций): " << integralTrapezoidal << std::endl;
    std::cout << "Интеграл (метод Симпсона): " << integralSimpson << std::endl;
    return 0;
}