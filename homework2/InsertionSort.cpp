#include <iostream>
#include <vector>

using namespace std;


void insertionSort(vector<int> data, int n)
{
    int i, j, tmp;

    for (i = 1; i < n; i++)
    {
        j = i;
        tmp = data[i];
        while (j > 0 && tmp < data[j - 1])
        {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> numberVectors;
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    cout << "Введите числа через Enter: ";
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        numberVectors.push_back(temp);

    }
    insertionSort(numberVectors, n);
    for (auto e : numberVectors)
    {
        std::cout << e << " ";
    }
}

