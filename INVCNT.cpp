#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <cassert> 

typedef unsigned long long ull;

ull solve(std::vector<int> &vec, std::vector<int> &buf, int s, int e)
{
    if (s >= e) return 0;

    int mid = (s + e) / 2;
    ull li = solve(vec, buf, s, mid);
    ull ri = solve(vec, buf, mid + 1, e);

    int i = 0, l = s, r = mid + 1, buf_size = e - s + 1;
    ull inv_cnt = 0;
    for (; i < buf_size && l <= mid && r <= e; ++i)
    {
        if (vec[l] <= vec[r])
        {
            buf[i] = vec[l++];
        }
        else
        {
            inv_cnt += mid - l + 1;
            buf[i] = vec[r++];
        }
    }
    for (; i < buf_size; ++i) buf[i] = vec[l == mid + 1 ? r++ : l++]; 
    for (i = 0; i < buf_size; ++i) vec[s + i] = buf[i]; 

    return li + ri + inv_cnt;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> vec(n, 0);
        std::vector<int> buf = vec;
        for (int i = 0; i < n; ++i)
            std::cin >> vec[i];
        std::cout << solve(vec, buf, 0, vec.size() - 1) << std::endl;
    }
    return 0;
}
