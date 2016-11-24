#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

static const int max_stall_loc = 1000000000;

bool ok(const std::vector<int> &stalls, int c, int d)
{
    int i = 0, j = 1;
    --c;
    while (j < stalls.size() && c > 0)
    {
        while (j < stalls.size() && stalls[j] - stalls[i] < d) ++j;
        if (j < stalls.size())
        {
            i = j++;
            --c;
        }
    }
    return c == 0;
}

int solve(std::vector<int> &stalls, int c)
{
    std::sort(stalls.begin(), stalls.end());
    int max = (*stalls.rbegin() - *stalls.begin()) / (c - 1);
    int min = 1;

    while (min != max)
    {
        int mid = (min + max) / 2;
        if (mid == min)
        {
            min = ok(stalls, c, max) ? max : min;
            break;
        }
        else if (ok(stalls, c, mid))
        {
            min = mid;
        }
        else
        {
            max = mid;
        }
    }
    return min;
}

int main()
{
//    std::cout << ok({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}, 3, 5) << std::endl;
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, c;
        std::cin >> n >> c;
        std::vector<int> stalls(n, -1);
        for (int j = 0; j < n; ++j)
        {
            std::cin >> stalls[j];
        }

        std::cout << solve(stalls, c) << std::endl;
    }
    return 0;
}
