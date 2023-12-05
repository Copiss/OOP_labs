#ifndef __ARRAY3D_H__
#define __ARRAY3D_H__
#include <iostream>
#include <vector>
template<class T>
class Array3d
{
    //private
    std::vector<T> data;
    int dim0, dim1, dim2;
public:
    // Конструктор класса Array3d
    Array3d(int dim0, int dim1, int dim2) : dim0(dim0), dim1(dim1), dim2(dim2), data(dim0* dim1* dim2) {}
    // Индексатор для доступа к элементам массива по трехмерным координатам (i, j, k)
    T& operator()(int i, int j, int k)
    {
        return data[i * dim1 * dim2 + j * dim2 + k];
    }
    // Метод GetValues0(int i): возвращает срез массива по первой координате (i, .., ..)
    std::vector<T> GetValues0(int i) const;
    // Метод GetValues1(int j): возвращает срез массива по второй координате (.., j, ..)
    std::vector<T> GetValues1(int j) const;
    // Метод GetValues2(int k): возвращает срез массива по третьей координате (.., .., k)
    std::vector<T> GetValues2(int k) const;
    // Метод GetValues01(int i, int j): возвращает срез массива по первой и второй координатам (i, j, ..)
    std::vector<T> GetValues01(int i, int j) const;
    // Метод GetValues02(int i, int k): возвращает срез массива по первой и третьей координатам (i, .., k)
    std::vector<T> GetValues02(int i, int k) const;
    // Метод GetValues12(int j, int k): возвращает срез массива по второй и третьей координатам (.., j, k)
    std::vector<T> GetValues12(int j, int k) const;
    // Метод SetValues0(int i, [][]arr): устанавливает значения в массиве для заданной первой координаты
    void SetValues0(int i, const std::vector<std::vector<T>>& arr);
    // Метод SetValues1(int j, [][]arr): устанавливает значения в массиве для заданной второй координаты
    void SetValues1(int j, const std::vector<std::vector<T>>& arr);
    // Метод SetValues2(int k, [][]arr): устанавливает значения в массиве для заданной третьей координаты
    void SetValues2(int k, const std::vector<std::vector<T>>& arr);
    // Метод SetValues01(int i, int j, [][]arr): устанавливает значения в массиве для заданных первой и второй координат
    void SetValues01(int i, int j, const std::vector<std::vector<T>>& arr);
    // Метод SetValues02(int i, int k, [][]arr): устанавливает значения в массиве для заданных первой и третьей координат
    void SetValues02(int i, int k, const std::vector<std::vector<T>>& arr);
    // Метод SetValues12(int j, int k, [][]arr): устанавливает значения в массиве для заданных второй и третьей координат
    void SetValues12(int j, int k, const std::vector<std::vector<T>>& arr);
};
template<typename T>
std::vector<T> Array3d<T>::GetValues0(int i)  const
{
    std::vector<T> slice(dim1 * dim2);
    for (int j = 0; j < dim1; j++)
    {
        for (int k = 0; k < dim2; k++)
        {
            slice[j * dim2 + k] = data[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return slice;
}
template<typename T>
std::vector<T> Array3d<T>::GetValues1(int j) const
{
    std::vector<T> slice(dim0 * dim2);
    for (int i = 0; i < dim0; i++)
    {
        for (int k = 0; k < dim2; k++)
        {
            slice[i * dim2 + k] = data[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return slice;
}
// Метод GetValues2(int k): возвращает срез массива по третьей координате (.., .., k)
template<typename T>
std::vector<T> Array3d<T>::GetValues2(int k) const
{
    std::vector<T> slice(dim0 * dim1);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            slice[i * dim1 + j] = data[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return slice;
}
// Метод GetValues01(int i, int j): возвращает срез массива по первой и второй координатам (i, j, ..)
template<typename T>
std::vector<T> Array3d<T>::GetValues01(int i, int j) const
{
    std::vector<T> slice(dim2);
    for (int k = 0; k < dim2; k++)
    {
        slice[k] = data[i * dim1 * dim2 + j * dim2 + k];
    }
    return slice;
}
// Метод GetValues02(int i, int k): возвращает срез массива по первой и третьей координатам (i, .., k)
template<typename T>
std::vector<T> Array3d<T>::GetValues02(int i, int k) const
{
    std::vector<T> slice(dim1);
    for (int j = 0; j < dim1; j++)
    {
        slice[j] = data[i * dim1 * dim2 + j * dim2 + k];
    }
    return slice;
}

// Метод GetValues12(int j, int k): возвращает срез массива по второй и третьей координатам (.., j, k)
template<typename T>
std::vector<T> Array3d<T>::GetValues12(int j, int k) const
{
    std::vector<T> slice(dim0);
    for (int i = 0; i < dim0; i++)
    {
        slice[i] = data[i * dim1 * dim2 + j * dim2 + k];
    }
    return slice;
}

// Метод SetValues0(int i, [][]arr): устанавливает значения в массиве для заданной первой координаты
template<typename T>
void Array3d<T>::SetValues0(int i, const std::vector<std::vector<T>>& arr)
{
    for (int j = 0; j < dim1; j++)
    {
        for (int k = 0; k < dim2; k++)
        {
            data[i * dim1 * dim2 + j * dim2 + k] = arr[j][k];
        }
    }
}

// Метод SetValues1(int j, [][]arr): устанавливает значения в массиве для заданной второй координаты
template<typename T>
void Array3d<T>::SetValues1(int j, const std::vector<std::vector<T>>& arr)
{
    for (int i = 0; i < dim0; i++)
    {
        for (int k = 0; k < dim2; k++)
        {
            data[i * dim1 * dim2 + j * dim2 + k] = arr[i][k];
        }
    }
}

// Метод SetValues2(int k, [][]arr): устанавливает значения в массиве для заданной третьей координаты
template<typename T>
void Array3d<T>::SetValues2(int k, const std::vector<std::vector<T>>& arr)
{
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            data[i * dim1 * dim2 + j * dim2 + k] = arr[i][j];
        }
    }
}

// Метод SetValues01(int i, int j, [][]arr): устанавливает значения в массиве для заданных первой и второй координат
template<typename T>
void Array3d<T>::SetValues01(int i, int j, const std::vector<std::vector<T>>& arr)
{
    for (int k = 0; k < dim2; k++)
    {
        data[i * dim1 * dim2 + j * dim2 + k] = arr[k];
    }
}

// Метод SetValues02(int i, int k, [][]arr): устанавливает значения в массиве для заданных первой и третьей координат
template<typename T>
void Array3d<T>::SetValues02(int i, int k, const std::vector<std::vector<T>>& arr)
{
    for (int j = 0; j < dim1; j++)
    {
        data[i * dim1 * dim2 + j * dim2 + k] = arr[j];
    }
}

// Метод SetValues12(int j, int k, [][]arr): устанавливает значения в массиве для заданных второй и третьей координат
template<typename T>
void Array3d<T>::SetValues12(int j, int k, const std::vector<std::vector<T>>& arr)
{
    for (int i = 0; i < dim0; i++)
    {
        data[i * dim1 * dim2 + j * dim2 + k] = arr[i];
    }
}

// Методы для создания массива с одинаковыми элементами
template<typename T>
Array3d<T> ones(int dim0, int dim1, int dim2)
{
    Array3d<T> arr(dim0, dim1, dim2);
    T one = static_cast<T>(1);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                arr(i, j, k) = one;
            }
        }
    }
    return arr;
}


template<typename T>
Array3d<T> zeros(int dim0, int dim1, int dim2)
{
    Array3d<T> arr(dim0, dim1, dim2);
    T zero = static_cast<T>(0);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                arr(i, j, k) = zero;
            }
        }
    }
    return arr;
}

template<typename T>
Array3d<T> fill(int dim0, int dim1, int dim2, T value)
{
    Array3d<T> arr(dim0, dim1, dim2);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                arr(i, j, k) = value;
            }
        }
    }
    return arr;
}


#endif