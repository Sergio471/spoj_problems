#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

size_t fac(size_t n)
{
    if (n == 1) return 1;
    return n * fac(n - 1);
}

int main()
{
    int t;
    std::cin >> t;
    std::vector<size_t> ans(t, 0);

    std::for_each(ans.begin(), ans.end(), [](size_t &v) { std::cin >> v; });
    std::transform(ans.begin(), ans.end(), ans.begin(), [](size_t v) { return fac(v); });
    std::for_each(ans.begin(), ans.end(), [](size_t v) { std::cout << v << std::endl; });

    return 0;
}
