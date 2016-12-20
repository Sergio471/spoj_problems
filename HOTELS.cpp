#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

typedef unsigned long long ull;

int solve(std::vector<int> &p, int m)
{
    int i = 0, j = 0;
    while (i <= p.size() && p[i] > m) j = ++i;
    ull acc = p[i], max = 0;
    while (j < p.size() - 1)
    {
        while ((j + 1 < p.size()) && (acc + p[j + 1] <= m)) acc += p[++j];
        max = std::max(acc, max);
        acc -= p[i];
        ++i;
    }
    return max;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> prices(n, 0);
    for (int i = 0; i < n; ++i) std::cin >> prices[i];
    std::cout << solve(prices, m) << std::endl;
    return 0;
}
