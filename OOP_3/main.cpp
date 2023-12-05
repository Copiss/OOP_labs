#include "Array3d.hpp"

int main()
{
    // Пример использования класса Array3d

    // Создание экземпляра класса Array3d с заданными размерами (3, 3, 3)
    Array3d<int> arr(3, 3, 3);

    // Использование индексатора для доступа к элементам массива
    arr(0, 0, 0) = 1;
    arr(1, 1, 1) = 2;
    arr(2, 2, 2) = 3;

    // Метод GetValues0(int i)
    std::vector<int> slice0 = arr.GetValues0(2);
    for (int i = 0; i < slice0.size(); i++)
    {
        std::cout << slice0[i] << " ";
    }
    std::cout << '\n' << '\n';


    // Метод SetValues1(int j, [][])
    std::vector<std::vector<int>> values = { {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    arr.SetValues1(1, values);

    // Метод GetValues2(int k)
    std::vector<int> slice2 = arr.GetValues2(2);
    for (int i = 0; i < slice2.size(); i++)
    {
        std::cout << slice2[i] << " ";
    }
    std::cout << std::endl;

    // Создание массива с одинаковыми элементами
    Array3d<double> ones_arr = ones<double>(2, 2, 2);
    Array3d<float> zeros_arr = zeros<float>(2, 2, 2);
    Array3d<int> fill_arr = fill<int>(2, 2, 2, 5);

    std::vector mas1 = ones_arr.GetValues01(0,0);
    for (int i = 0; i < mas1.size(); i++)
    {
        std::cout << mas1[i] << " ";
    }

    std::cout << std::endl;

    std::vector mas2 = zeros_arr.GetValues02(0, 0);
    for (int i = 0; i < mas2.size(); i++)
    {
        std::cout << mas2[i] << " ";
    }

    std::cout << std::endl;

    std::vector mas3 = fill_arr.GetValues1(0);
    for (int i = 0; i < mas3.size(); i++)
    {
        std::cout << mas3[i] << " ";
    }


    return 0;
}
