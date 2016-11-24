#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int main()
{
    int l;
    std::cin >> l;
    while (l)
    {
        std::cout << std::fixed << std::setprecision(2) << (l*l)/(2*3.14159265358979323846) << std::endl;
        std::cin >> l;
    }
    return 0;
}
