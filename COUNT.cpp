#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

using ull = unsigned long long;
static const ull empty = 0;

std::vector<std::vector<ull>> mem(5001, std::vector<ull>(5001, empty));

ull ff(ull n, ull k)
{
    if (n == 0 || k == 1) return 1;
    if (k == 0) return 0;
    if (mem[n][k] != empty) return mem[n][k];

    return mem[n][k] = ff(n, k - 1) + (n >= k ? ff(n - k, k) : 0);
}

ull solve(ull n, ull k)
{
    return ff(n - k, k);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    while (n)
    {
        std::cout << solve(n, k) << std::endl;

        for (auto &v : mem) std::fill(v.begin(), v.end(), empty);
        std::cin >> n >> k;
    }
    return 0;
}
