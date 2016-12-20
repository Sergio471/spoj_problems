#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int h, w;

std::vector<std::vector<int>> mem(50, std::vector<int>(50, -1));

bool valid(const std::pair<int, int> &p)
{
    return p.first >= 0 && p.second >= 0 && p.first < h && p.second < w;
}

int find_len(std::vector<std::vector<char>> &matr, int i, int j)
{
    if (mem[i][j] != -1) return mem[i][j];

    std::vector<std::pair<int, int>> nbrs = {
        {i - 1, j - 1}, {i - 1, j}, {i - 1, j + 1},
        {i,     j - 1}, /*......*/  {i,     j + 1},
        {i + 1, j - 1}, {i + 1, j}, {i + 1, j + 1},
    };

    int len = 1;
    for (auto & nbr : nbrs)
    {
        if (valid(nbr) && (matr[i][j] + 1 == matr[nbr.first][nbr.second]))
        {
            int new_len = 1 + find_len(matr, nbr.first, nbr.second);
            len = std::max(len, new_len);
        }
    }

    return mem[i][j] = len;
}

int solve(std::vector<std::vector<char>> &matr)
{
    int max = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (matr[i][j] == 'A')
            {
                max = std::max(max, find_len(matr, i, j));
            }
        }
    }
    return max;
}

int main()
{
    std::cin >> h >> w;
    int t = 1;
    while (h != 0)
    {
        std::vector<std::vector<char>> matr(h, std::vector<char>(w, 0));
        for (auto & row : matr)
            for (auto & el : row)
                std::cin >> el;
        std::cout << "Case " << t++ << ": " << solve(matr) << std::endl;
        for (auto & v : mem) std::fill(v.begin(), v.end(), -1);

        std::cin >> h >> w;
    }
    return 0;
}
