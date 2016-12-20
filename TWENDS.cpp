#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

std::vector<std::vector<int>> mem(1000, std::vector<int>(1000, -1));

int solve(std::vector<int> &v, int s, int e)
{
    if (mem[s][e] != -1) return mem[s][e];

    if (s + 1 == e) return mem[s][e] = std::abs(v[s] - v[e]);
    if (s == e) return mem[s][e] = v[s];

    int w = v[s];
    if (v[s + 1] >= v[e])
    {
        w -= v[s + 1];
        w += solve(v, s + 2, e);
    }
    else
    {
        w -= v[e];
        w += solve(v, s + 1, e - 1);
    }

    int w2 = v[e];
    if (v[s] >= v[e - 1])
    {
        w2 -= v[s];
        w2 += solve(v, s + 1, e - 1);
    }
    else
    {
        w2 -= v[e - 1];
        w2 += solve(v, s, e - 2);
    }

    return mem[s][e] = std::max(w, w2);
}

int main()
{
    int t = 1;
    int n;
    std::cin >> n;
    while (n)
    {
        std::vector<int> vec(n, 0);
        for (auto &e : vec) std::cin >> e;
        std::cout << "In game " << t++ << ", the greedy strategy might lose by as many as " << solve(vec, 0, vec.size() - 1) << " points.\n";
        for (auto &m : mem) std::fill(m.begin(), m.end(), -1);
        std::cin >> n;
    }

    return 0;
}
