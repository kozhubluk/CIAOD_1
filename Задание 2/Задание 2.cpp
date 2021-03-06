#include <iostream>
#include"malloc.h"
using namespace std;

unsigned int* creat_arr(int& n);
void input(unsigned int arr[], int n);
void output(unsigned int arr[], int n);
bool simple(unsigned int n);
bool krat_7(unsigned int n);
int c_kr7(unsigned int arr[], int n);
int simple_index(unsigned int arr[], int n);
void insert_elem(unsigned int*& arr, int& n, unsigned int& n_el);
void delete_elem(unsigned int*& arr, int& n);

int main()
{
    int k;
    unsigned int new_element;
    unsigned int* a = creat_arr(k);
    input(a, k);
    delete_elem(a, k);
    insert_elem(a, k, new_element);
    output(a, k);
    delete[] a;
    return 0;
}

unsigned int* creat_arr(int& n) // Создание динамического массива
{
    cout << "Vvedite kol-vo elementov: ";
    cin >> n;
    unsigned int* arr = new unsigned int[n];
    return arr;
}

void input(unsigned int arr[], int n) // Заполнение массива
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }
}

void output(unsigned int arr[], int n) // Вывод массива
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = " << arr[i] << "\n";
    }
}

bool simple(unsigned int n) // Проверяет, является ли число простым 
{
    if ((n == 0) || (n == 1))
    {
        return false;
    }
    else
    {
        for (int i = 2; i < (n / 2 + 1); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

bool krat_7(unsigned int n) // Проверяет число на кратность числу 7
{
    if (n % 7 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int c_kr7(unsigned int arr[], int n) // Нахождение кол-ва чисел в массиве, кратных 7
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (krat_7(arr[i]))
        {
            c++;
        }
    }
    return c;
}

int simple_index(unsigned int arr[], int n) // Поиск индекса первого простого числа в массиве 
{
    int ans_i = -1;
    for (int i = 0; i < n; i++)
    {
        if (simple(arr[i]))
        {
            ans_i = i;
            return ans_i;
        }
    }
    return ans_i;
}

void insert_elem(unsigned int*& arr, int& n, unsigned int& n_el) // Вставка нового элемента в массив после первого найденного простого числа
{
    cout << "Vstavit' noviy element: ";
    cin >> n_el;
    int i_index = simple_index(arr, n);
    if (i_index != -1)
    {
        arr = (unsigned int*)realloc((unsigned int*)arr, (n + 1) * sizeof(unsigned int));
        for (int i = n; i >= i_index + 2; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[i_index + 1] = n_el;
        n++;
    }
}

void delete_elem(unsigned int*& arr, int& n) // Удаление ВСЕХ элементов массива, кратных числу 7
{
    int j = 0;
    int dif = c_kr7(arr, n);
    int dif = c_kr7(arr, n);
    for (int i = 0; i < (n - dif); i++)
    {
        int j = i;
        while (krat_7(arr[j]))
        {
            j++;
        }
        swap(arr[i], arr[j]);
    }
    arr = (unsigned int*)realloc((unsigned int*)arr, (n - dif) * sizeof(unsigned int));
    n = n - dif;
}


