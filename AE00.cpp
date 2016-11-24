#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int get_divisors_num(int n)
{
    int res = 1;

    for (int i = 2; i <= n; ++i)
    {
        int exp = 0;
        while (n % i == 0)
        {
            ++exp;
            n /= i;
        }
        res *= exp + 1;
    }

    return res;
}

int solve(int n)
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += (get_divisors_num(i) + 1) / 2;
    }

    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << solve(n) << std::endl;
    return 0;
}
