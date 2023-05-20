#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <algorithm>
#include <chrono>

template <typename Container>
void print_container(const Container& container)
{
    for (const auto& element : container)
        std::cout << element << " ";
    std::cout << std::endl;
}

template <typename Container>
void sort_sequence(Container& container, const std::string& container_name)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::sort(container.begin(), container.end());
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << container_name << " sorted with std::sort in ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;

}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> v = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    print_container(v);
    sort_sequence(v, "vector");
    /*
    std::list<int> lst = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    print_container(lst);
    sort_sequence(lst, "list");
    */
    std::deque<int> dq = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    print_container(dq);
    sort_sequence(dq, "deque");

    std::array<int, 10> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    print_container(arr);
    sort_sequence(arr, "array");

    std::string str = "3141592653";
    std::cout << str << std::endl;
    sort_sequence(str, "string");
    
    
    std::cout << "Функция-член sort есть только у list, а std::sort она не принимает из-за другого итератора, её результаты:";
    std::list<int> lst = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    std::chrono::steady_clock::time_point beg = std::chrono::steady_clock::now();
    lst.sort();
    std::chrono::steady_clock::time_point en = std::chrono::steady_clock::now();
    std::cout << "list sorted with sort() in ";
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(en - beg).count() << " microseconds" << std::endl;

}
