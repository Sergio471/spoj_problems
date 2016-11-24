#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int get_ans(int x, int y)
{
    if (x < 0 || y < 0) return -1;
    if (x == y + 2)
    {
        // bottom
        int pair_num = x / 2 - 1;
        int pair_start = 2 + pair_num * 4; // arithm seq
        if (x % 2 == 0) return pair_start;
        else return pair_start + 1;

    }
    else if (x == y)
    {
        // top
        int pair_num = x / 2;
        int pair_start = 4 * pair_num; // arithm seq
        if (x % 2 == 0) return pair_start;
        else return pair_start + 1;
    }
    else return -1;
}

int main()
{
    int t;
    std::cin >> t;
    std::vector<int> ans(t, 0);

    int x, y;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> x >> y;
        ans[i] = get_ans(x, y);
    }

    for (auto a : ans)
    {
        if (a == -1)
            std::cout << "No Number" << std::endl;
        else
            std::cout << a << std::endl;
    }

    return 0;
}
