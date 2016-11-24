#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string a, b, c, dum;
        std::cin >> a >> dum >> b >> dum >> c;
        if (a.find("machula") != std::string::npos)
        {
            std::cout << (std::stoi(c) - std::stoi(b)) << " + " << b << " = " << c << std::endl;
        }
        else if (b.find("machula") != std::string::npos)
        {
            std::cout << a << " + " << (std::stoi(c) - std::stoi(a)) << " = " << c << std::endl;
        }
        else if (c.find("machula") != std::string::npos)
        {
            std::cout << a << " + " << b << " = " << (std::stoi(a) + std::stoi(b)) << std::endl;
        }
    }

    return 0;
}
