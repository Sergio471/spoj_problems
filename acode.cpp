#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

std::unordered_map<std::string, unsigned int> mem;

int two_dig_s_to_n(const std::string &s)
{
    return 10*(s[0] - '0') + (s[1] - '0');
}

unsigned int get_ans(const std::string &s)
{
    if (mem.count(s) == 1) return mem[s];
    if (s.size() == 1) 
    {
        if (s[0] == '0') 
            return 0;
        else 
            return 1;
    }
    else if (s.size() == 2)
    {
        if (s[0] == '0')
            return 0;
        else if (s[1] == '0')
            return (two_dig_s_to_n(s) <= 26) ? 1 : 0;
        else
            return (two_dig_s_to_n(s) <= 26) ? 2 : 1;
    }
    else
    {
        auto fst_two = get_ans(s.substr(0, 2));
        if (fst_two == 0) return 0;
        else if (fst_two == 1)
        {
            if (s[1] == '0')
                return get_ans(s.substr(2, s.size() - 2));
            else
            {
                return get_ans(s.substr(1, s.size() - 1));
            }
        }
        else //if (fst_two == 2)
        {
            unsigned int a = 2*get_ans(s.substr(2, s.size() - 2)); // xx xxxxxx and x x xxxxxxx
            unsigned int b = 0;
            if (two_dig_s_to_n(s.substr(1, 2)) <= 26)
            {
                b = s.size() > 3 ? get_ans(s.substr(3, s.size() - 3)) : 1;// x xx xxxxxx 
            }
            mem[s] = a + b;
            return mem[s];
        }
    }
}

int main()
{
    std::string line;
    while (std::getline(std::cin, line) && line != "0")
    {
        std::cout << get_ans(line) << std::endl;
    }
    return 0;
}
