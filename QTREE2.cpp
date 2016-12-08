#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <stack>

using edge_t = std::pair<int, int>; // to, cost
using gr_t = std::vector< std::vector<edge_t> >;
using path_t = std::vector<int>;

// what is ans depends on k
void solve(int from, int to, const gr_t &gr, int &ans, int k = -1)
{
    std::stack<int> st;
    // x=parent[i] indicates that i was visited by x.first with cost x.second
    std::vector< std::pair<int, int> > parent(gr.size(), {-1, -1});
    st.push(from);

    bool found = false;
    while (!st.empty() && !found)
    {
        int v = st.top();
        st.pop();
        for (auto & e : gr[v])
        {
            if (parent[e.first].first == -1 && e.first != from)
            {
                st.push(e.first);
                parent[e.first] = {v, e.second};
                if (e.first == to)
                {
                    found = true;
                    break;
                }
            }
        }
    }

    if (k == -1)
    {
        ans = 0;
        while (parent[to].first != -1)
        {
            ans += parent[to].second;
            to = parent[to].first;
        }
    }
    else
    {
        path_t path;
        while (parent[to].first != -1)
        {
            path.push_back(parent[to].first);
            to = parent[to].first;
        }
        if (k == path.size() + 1) ans = to;
        else ans = path[path.size() - k];
    }
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        gr_t gr(n + 1, std::vector<edge_t>{});
        for (int i = 0; i < n - 1; ++i)
        {
            int from, to, cost;
            std::cin >> from >> to >> cost;
            gr[from].push_back({to, cost});
            gr[to].push_back({from, cost});
        }
        while (true)
        {
            std::string command;
            std::cin >> command;
            int ans;
            if (command == "DIST")
            {
                int from, to;
                std::cin >> from >> to;
                solve(from, to, gr, ans);
            }
            else if (command == "KTH")
            {
                int from, to, k;
                std::cin >> from >> to >> k;
                solve(from, to, gr, ans, k);
            }
            else
            {
                break;
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
