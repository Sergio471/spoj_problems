#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int k = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> k;
        ans ^= k;
    }
    std::cout << ans << std::endl;

    return 0;
}
