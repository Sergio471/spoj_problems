#include <iostream>
#include <istream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

std::vector<long long> mem(1000000, -1);

long long get_ans(int x)
{
    if (x < mem.size() && mem[x] != -1) return mem[x];

    long long ans = get_ans(x/2) + get_ans(x/3) + get_ans(x/4);
    if (x < mem.size()) mem[x] = ans;
    return ans;
}

int main()
{
    for (int i = 0; i < 12; ++i) mem[i] = i;
    int n;
    while(std::cin>>n)
    {
        std::cout<<get_ans(n)<<std::endl;
    }
    return 0;
}
