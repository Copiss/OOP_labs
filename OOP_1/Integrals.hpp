#ifndef __METHODS_H__
#define __METHODS_H__
#include <iostream>
#include <functional> // Для использования шаблонов функций (то, что под интегралом)
#include <Windows.h>  // Для подключения русского языка
#include <cmath>
/// Класс Integral для интегрирования
class Integral
{
protected:
    int numPoints;    // Число точек
    double step;      // Шаг
    double tolerance; // Точность
public:
    // Конструктор (деструктор создаётся по умолчанию)
    Integral(int nPoints, double h, double tol) : numPoints(nPoints), step(h), tolerance(tol) {}
    // Виртуальный метод Calc для вычисления интеграла
    virtual double Calc(std::function<double(double)> f, double lowerBound, double upperBound) = 0;
};
/// Класс TrapezoidalIntegral, наследник класса Integral, для интегрирования методом трапеций
class TrapezoidalIntegral : public Integral
{
public:
    // Конструктор (деструктор создаётся по умолчанию)
    TrapezoidalIntegral(int nPoints, double h, double tol) : Integral(nPoints, h, tol) {}
    // Переопределённый метод Calc для интегрирования методом трапеций
    double Calc(std::function<double(double)> f, double lowerBound, double upperBound) override;
};
/// Класс SimpsonIntegral, наследник класса Integral, для интегрирования методом Симпсона
class SimpsonIntegral : public Integral
{
public:
    // Конструктор (деструктор создаётся по умолчанию)
    SimpsonIntegral(int nPoints, double h, double tol) : Integral(nPoints, h, tol) {}
    // Переопределённый метод Calc для интегрирования методом Симпсона
    double Calc(std::function<double(double)> f, double lowerBound, double upperBound) override;
};
#endif