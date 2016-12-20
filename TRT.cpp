#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

std::vector<std::vector<int>> mem(2000, std::vector<int>(2000, -1));

int solve(std::vector<int> &items, int s, int e, int age)
{
    if (s == e) return age * items[s];
    if (mem[s][e] != -1) return mem[s][e];

    int l = age * items[s] + solve(items, s + 1, e, age + 1);
    int r = age * items[e] + solve(items, s, e - 1, age + 1);
    mem[s][e] = std::max(l, r);
    return mem[s][e];
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> items(n, 0);
    for (int i = 0; i < n; ++i) std::cin >> items[i];
    std::cout << solve(items, 0, n - 1, 1) << std::endl;
    return 0;
}
