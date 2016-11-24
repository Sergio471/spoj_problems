#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <set>
#include <unordered_set>
#include <stack>

void dfs(const std::vector<std::vector<int>> &graph, int i, std::unordered_set<int> &visited)
{
    std::stack<int> st;
    for (auto nbr : graph[i])
    {
        if (visited.count(nbr) == 0)
        {
            st.push(nbr);
        }
    }
    while (!st.empty())
    {
        int cur_nbr = st.top();
        visited.insert(cur_nbr);
        st.pop();
        dfs(graph, cur_nbr, visited);
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    bool is_tree = true;

    if (m != n - 1) 
    {
        is_tree = false;
    }
    else 
    {
        std::vector<std::vector<int>> graph(n + 1);
        std::vector<int> v(n, 0);
        for (int i = 0; i < m; ++i) {
            int from, to;
            std::cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        std::unordered_set<int> visited;
        int num_of_conn_comp = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (visited.count(i) == 0)
            {
                if (num_of_conn_comp == 1)
                {
                    is_tree = false;
                    break;
                }
                else// if (num_of_conn_comp == 0)
                {
                    ++num_of_conn_comp;
                    dfs(graph, i, visited);
                }
            }
        }
        if (num_of_conn_comp != 1) is_tree = false;
    }

    if (is_tree) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

    return 0;
}
