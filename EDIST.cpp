#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <utility>

std::vector<std::vector<int>> mem(2000, std::vector<int>(2000, -1));

void clear_mem()
{
    for (auto &v : mem) std::fill(v.begin(), v.end(), -1);
}

int solve(const std::string &a, const std::string &b, int i, int j)
{
    if (i == -1) return j + 1;
    else if (j == -1) return i + 1;

    if (mem[i][j] != -1) return mem[i][j];

    if (a[i] == b[j])
    {
        mem[i][j] = solve(a, b, i - 1, j - 1);
        return mem[i][j];
    }
    else
    {
        int add_j = solve(a, b, i, j - 1) + 1;
        int add_i = solve(a, b, i - 1, j) + 1;
        int edit = solve(a, b, i - 1, j - 1) + 1;
        mem[i][j] = std::min(std::min(add_j, add_i), edit);
        return mem[i][j];
    }
}

int main()
{
    int t;
    std::cin >> t;
    std::string a, b;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> a >> b;
        std::cout << solve(a, b, a.size() - 1, b.size() - 1) << std::endl;
        clear_mem();
    }

    return 0;
}
