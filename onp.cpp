#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

std::string get_operand(const std::string &s)
{
    if (s[0] == '(')
    {
        int pc = 1;
        int i = 0;
        while (pc > 0)
        {
            ++i;
            if (s[i] == ')') --pc;
            else if (s[i] == '(') ++pc;
        }
        return s.substr(1, i - 1);
    }
    else
    {
        int i = 0;
        while (s[i] <= 'z' && s[i] >= 'a') ++i;
        return s.substr(0, i);
    }
}

std::string rev(const std::string &s)
{
    if (s.size() == 3) return std::string{} + s[0] + s[2] + s[1];
    else if (s.size() == 1) return s;

    std::string left = get_operand(s);
    int more = (s[0] == '(') ? 2 : 0;
    std::string right = get_operand(s.substr(left.size() + 1 + more));

    return rev(left) + rev(right) + s[left.size() + more];
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> ans(n, "");
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        s = s.substr(1, s.size() - 2);

        ans[i] = rev(s);
    }
    for (auto &a : ans)
    {
        std::cout << a << std::endl;
    }

    return 0;
}
