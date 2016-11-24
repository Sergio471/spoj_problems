#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

std::string solve(const std::vector<int> &cars)
{
    for (int i = 0; i < cars.size() - 2; ++i)
    {
        int j = i + 1;
        while (j < cars.size() - 1)
        {
            if (cars[j] > cars[i])
            {
                int k = j + 1;
                while (k < cars.size())
                {
                    if (cars[k] < cars[i])
                        return "no";
                    ++k;
                }
            }
            ++j;
        } 
    }
    return "yes";
}

int main()
{
    std::string line;
    while (std::getline(std::cin, line) && line != "0") 
    {
        int n = std::stoi(line);
        std::vector<int> cars(n, -1);
        for (int j = 0; j < n; ++j)
            std::cin >> cars[j];
        std::cout << solve(cars) << std::endl;
        std::getline(std::cin, line);
    }
    return 0;
}
