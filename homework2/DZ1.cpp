#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPunctuation(char ch)
{
    if (ispunct(ch) || isspace(ch))
    {
        return true;
    }
    return false;
}

vector<string> Split(const char* str)
{
    setlocale(LC_ALL, "Russian");
	vector<string> ch;
	string tmp;

    for (size_t index = 0; str[index] != '\0'; ++index)
    {
        if (!IsPunctuation(str[index]))
        {
            tmp += str[index];
        }
        else
        {
            if (tmp.length() > 0)
            {
                ch.push_back(tmp);
            }
            tmp.clear();
            if (ispunct(str[index]))
            {
                tmp += str[index];
                ch.push_back(tmp);
                tmp.clear();
            }
        }
    }
    ch.push_back(tmp);
    return ch;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const char* Text = "привет, мир!";
    std::vector<std::string> Result = Split(Text);
    for (auto e : Result)
    {
        std::cout << e << std::endl;
    }
}