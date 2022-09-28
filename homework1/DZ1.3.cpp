#include <iostream>

int main()
{
    int x, y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
    x = (x ^= y);
    y = (y ^= x); 
    x = (x ^= y); 
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y;
    return 0;
}
