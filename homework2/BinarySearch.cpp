#include <iostream>
#include <vector>
using namespace std;
int Binary_search(vector<int>x, int target) {
    int maximum = (x.size()) - 1;
    int minimum = 0;
    int mean;
    while (maximum > minimum) {
        mean = (maximum + minimum) / 2;
        if (x[mean] == target) {
            return true;
        }
        else if (x[mean] > target) {
            maximum = (mean - 1);
        }
        else {
            minimum = (mean + 1);
        }
    }
    return false;
}
int main() {
    unsigned int i;
    int n;
    vector<int>x;
    cout << "Enter the amount of numbers you want to evaluate: ";
    cin >> i;
    cout << "Enter your numbers to be evaluated: " << endl;
    while (x.size() < i && cin >> n) {
        x.push_back(n);
    }
    int target;
    cout << "Enter the target you want to search for in the selected array \n";
    cin >> target;
    if (Binary_search(x, target)) {
        cout << "Your result is found!";
    }
    else {
        cout << "Your result is not found!";
    }
    return 0;
}