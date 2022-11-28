#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Product
{
private:
    char name[80];
    int price;
    float weight;
public:
    Product()
    {
        strcpy(name, "");
        price = 0;
        weight = 0;
    }
    Product(const char * str, int pr, float wgh)
    {
        strcpy(name, str);
        price = pr;
        weight = wgh;
    }
    int getPrice()  const
    {
        return price;
    }
    float getWeight()  const
    {
        return weight;
    }
    void showData()   const
    {
        cout << left << setw(18) << "\nТовар:" << name;
        cout << setw(18) << "\nЦена:" << setw(8) << price << " руб";
        cout << setw(18) << "\nВес:" << setw(8) << weight << " кг" << endl;
    }
};

class Buy :public Product
{
private:
    int col;
    int total_price;
    float total_weight;
public:
    Buy() :Product()
    {
        col = 0;
        total_price = 0;
        total_weight = 0;
    }
    Buy(int c)
    {
        col = c;
        int temp1 = getPrice();
        float temp2 = getWeight();
        total_price = temp1 * c;
        total_weight = temp2 * c;
    }
    Buy(const char* n, int p, float w, int c) : Product(n, p, w)
    {
        col = c;
        total_price = c * getPrice();;
        total_weight = c * getWeight();
    }

    void showData()   const
    {
        cout << "\nТовара куплено:  " << setw(8) << col << " кг";
        cout << "\nНа сумму:        " << setw(8) << total_price << " руб";
        cout << "\nОбщий вес:       " << setw(8) << total_weight << " кг" << endl;
    }
};

class Check :private Buy
{
public:
    Check() : Buy()
    {
    }
    Check(const char* n, int p, float w, int cl) : Buy(n, p, w, cl)
    {
    }
    void showData()  const
    {
        Product::showData();
        Buy::showData();
    }
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    Check s1("пельмешки", 235, 3.5, 5);
    s1.showData();

    return 0;
}