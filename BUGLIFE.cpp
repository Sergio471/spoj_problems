#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <string>
#include <algorithm>
#include <chrono>

using gr_t = std::vector< std::vector<int> >;

std::string solve(gr_t &gr)
{
    // -1 -- no sex
    // 0 -- male
    // 1 -- female
    std::unordered_map<int, int> colors;
    for (int i = 1; i < gr.size(); ++i) colors[i] = -1;

    for (int i = 1; i < gr.size(); ++i)
    {
        if (colors[i] != -1) continue; // visited
        colors[i] = 0; // start with male
        std::stack<int> st;
        st.push(i);
        while (!st.empty())
        {
            int v = st.top();
            st.pop();

            for (auto nbr : gr[v])
            {
                auto it = colors.find(nbr);
                if (it->second == colors[v]) // same sex
                {
                    return "Suspicious bugs found!";
                }
                else if (it->second == -1) // no sex set, not visited
                {
                    it->second = (colors[v] + 1) % 2; // set opposite sex to nbr
                    st.push(nbr);
                }
            }
        }
    }
    return "No suspicious bugs found!";
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int n, r;
        std::cin >> n >> r;
        gr_t gr(n + 1, std::vector<int>{});
        while (r--)
        {
            int a, b;
            std::cin >> a >> b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        std::cout << "Scenario #" << t << ":" << std::endl;
        std::cout << solve(gr) << std::endl;
    }

    return 0;
}
