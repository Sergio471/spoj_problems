#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int rev(int n)
{
    int res = 0;

    while (n)
    {
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    
    return res;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> res;
    res.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int m,n;
        std::cin >> m >> n;
        res.push_back(rev(rev(m) + rev(n)));
    }

    for (auto a : res)
    {
        std::cout << a << std::endl;
    }

    return 0;
}
