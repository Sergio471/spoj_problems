#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

using gr_t = std::vector<std::vector<int>>;

// returns <vertex, length>
std::pair<int, int> solve(const gr_t &gr, int start, int from)
{
    int vtx = start, max = -1;

    for (auto nbr : gr[start])
    {
        if (nbr != from)
        {
            auto p = solve(gr, nbr, start);
            if (p.second > max)
            {
                max = p.second;
                vtx = p.first;
            }
        }
    }

    return std::make_pair(vtx, max + 1);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> gr(n + 1, std::vector<int>{});

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    auto fst_sol = solve(gr, 1, -1);
    auto final_sol = solve(gr, fst_sol.first, -1);

    std::cout << final_sol.second << std::endl; 

    return 0;
}
