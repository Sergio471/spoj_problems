#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

int solve(std::string &s)
{
    std::vector<std::string> sufs(s.size(), std::string{});
    for (int i = 0; i < s.size(); ++i)
    {
        sufs[i] = s.substr(i, s.size() - i);
    }
    std::sort(sufs.begin(), sufs.end());

    int ans = sufs[0].size();
    for (int i = 1; i < sufs.size(); ++i)
    {
        int j = -1;
        while (sufs[i - 1][j + 1] == sufs[i][j + 1]) ++j;
        ans += sufs[i].size() - j - 1;
    }
    return ans;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string s;
        std::cin >> s;
        std::cout << solve(s) << std::endl;
    }
    return 0;
}
