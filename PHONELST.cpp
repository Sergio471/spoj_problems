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
        int n;
        std::cin >> n;
        std::vector<std::string> vec(n, std::string{});
        for (int i = 0; i < n; ++i) std::cin >> vec[i];

        bool consistent = true;
        std::sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size() && consistent; ++i) consistent = (vec[i].find(vec[i - 1]) == std::string::npos);

        std::cout << (consistent ? "YES" : "NO") << std::endl;
    }
    return 0;
}
