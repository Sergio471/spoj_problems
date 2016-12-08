#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <stack>

long long solve(std::vector<long long> &heights)
{
    long long max = 0;
    std::stack<int> st;

    int i = 0;
    while (i < heights.size())
    {
        if (st.empty() || heights[i] >= heights[st.top()])
        {
            st.push(i++);
        }
        else
        {
            int cur = st.top();
            st.pop();
            max = std::max(heights[cur] * (st.empty() ? i : i - st.top() - 1), max);
        }
    }

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();
        max = std::max(heights[cur] * (st.empty() ? i : i - st.top() - 1), max);
    }

    return max;
}

int main()
{
    int n;
    std::vector<long long> heights;
    std::cin >> n;
    while (n != 0)
    {
        heights.resize(n);
        for (int i = 0; i < n; ++i) std::cin >> heights[i];

        std::cout << solve(heights) << std::endl;

        std::cin >> n;
    }

    return 0;
}
