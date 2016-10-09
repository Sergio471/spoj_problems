#include <iostream>
#include <algorithm>
#include <vector>

using ull = unsigned long long;

ull z(ull n)
{
    ull res = 0;

    ull d = 5;
    ull r = n / d;
    while (r != 0)
    {
        res += r;
        d *= 5;
        r = n / d;
    }

    return res;
}

int main()
{
    int t;
    std::cin >> t;

    std::vector<ull> vec;
    vec.resize(t);

    for (int i = 0; i < t; ++i)
    {
        std::cin >> vec[i];
    }

    for (const auto& s : vec)
    {
        std::cout << z(s) << std::endl;
    }

    return 0;
}
