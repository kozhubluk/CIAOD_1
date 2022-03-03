#include <iostream>
#include <vector>
using namespace std;

void input(vector <unsigned int>& arr, int n);
void output(vector <unsigned int>& arr, int n);
bool simple(unsigned int n);
bool krat_7(unsigned int n);
int c_kr7(vector <unsigned int>& arr, int n);
int simple_index(vector <unsigned int>& arr, int n);
void insert_elem(vector <unsigned int>& arr, int& n, unsigned int& n_el);
void delete_elem(vector <unsigned int>& arr, int& n);
int main()
{
    int k;
    unsigned int new_element;
    cout << "Vvedite kol-vo elementov v massive: ";
    cin >> k;
    vector <unsigned int> a(k);

    input(a, k);
    insert_elem(a, k, new_element);
    delete_elem(a, k);
    output(a, k);

    return 0;
}

void input(vector <unsigned int>& arr, int n) // Заполнение массива
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }
}

void output(vector <unsigned int>& arr, int n) // Вывод массива
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

int c_kr7(vector <unsigned int>& arr, int n) // Нахождение кол-ва чисел в массиве, кратных 7
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

int simple_index(vector <unsigned int>& arr, int n) // Поиск индекса первого простого числа в массиве 
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

void insert_elem(vector <unsigned int>& arr, int& n, unsigned int& n_el) // Вставка нового элемента в массив после первого найденного простого числа
{
    cout << "Vstavit' noviy element: ";
    cin >> n_el;
    int i_index = simple_index(arr, n);
    if (i_index != -1)
    {
        arr.push_back(0);
        for (int i = n; i >= i_index + 2; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[i_index + 1] = n_el;
        n++;
    }
}

void delete_elem(vector <unsigned int>& arr, int& n) // Удаление ВСЕХ элементов массива, кратных числу 7
{
    int dif = c_kr7(arr, n);
    n = n - dif;
    int i = 0;
    while (i < n)
    {
        if (krat_7(arr[i]))
        {
            arr.erase(arr.begin() + i);
        }
        else
        {
            i++;
        }
    }
}
