#include <iostream>
#include <string>

std::string sq_eq(float a, float b, float c)
{
    std::string answer; 
    int n = 0; // Количество решений
    int dd = std::pow(b, 2) - 4.0 * a * c;
    if (dd > 0) {
        n++;
        }
    if (dd >= 0) {
        n++;
    }
    if (n == 0) {
        answer = "Нет решений";
    }
    else if (n == 1) {
        float ans = (-b) / (2 * a);
        answer = "x = " + std::to_string(ans);
    }
    else {
        float ans1 = (-b + sqrt(dd)) / (2 * a);
        float ans2 = (-b - sqrt(dd)) / (2 * a);
        answer = "x = " + std::to_string(ans1) + " and x = " + std::to_string(ans2);
    }
    return answer;
}

int main()
{
    float _a, _b, _c;
    std::string a_s, b_s, c_s;

    setlocale(LC_ALL, "Russian");

    std::cout << "Для решения стандартного квадратного уравнения вида ax^2 + bx + c = 0 введите коэффициенты a, b и c (по одному коэффициенту в строке): " << "\n";

    std::cin >> a_s;
    _a = std::stof(a_s);
    std::cout << "\n";

    std::cin >> b_s;
    _b = std::stof(b_s);
    std::cout << "\n";

    std::cin >> c_s;
    _c = std::stof(c_s);

    std::cout << sq_eq(_a, _b, _c);
}
