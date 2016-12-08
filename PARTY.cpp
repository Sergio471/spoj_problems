#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

//std::vector< std::vector< std::pair<int, int> > > mem(501, std::vector< std::pair<int, int> >(100, std::make_pair(-1, -1)));

// m is a current money budget
// i - [1..i] items (or parties) are considered
// returns <money spent, fun got> s.t. fun is maximized
/*
std::pair<int, int> solve(int m, int i, const std::vector<int> &costs, const std::vector<int> &fun)
{
    if (i == 0) return (m >= costs[i]) ? std::make_pair(costs[i], fun[i]) : std::make_pair(0, 0);

    if (mem[m][i].first != -1) return mem[m][i];

    // Subsolutions

    auto ith_excluded = solve(m, i - 1, costs, fun);

    if (costs[i] > m) return ith_excluded;
    auto ith_included = solve(m - costs[i], i - 1, costs, fun); 
    ith_included.first += costs[i];
    ith_included.second += fun[i];

    if (ith_excluded.second == ith_included.second) // both subsolutions give the same value of fun
    {
        // get the cheapest with the same value
        mem[m][i] = (ith_excluded.first < ith_included.first) ? ith_excluded : ith_included;
    }
    else
    {
        mem[m][i] = (ith_excluded.second > ith_included.second) ? ith_excluded : ith_included;
    }

    return mem[m][i];
}*/

std::pair<int, int> solve(int m, const std::vector<int> &costs, const std::vector<int> &fun)
{
    const int n_of_parties = costs.size();

    // Prepare matrices
    std::vector< std::vector<int> > money_spent(m + 1, std::vector<int>(n_of_parties, 0));
    std::fill(money_spent[0].begin(), money_spent[0].end(), 0);
    for (int i = 0; i <= m; ++i)    money_spent[i][0] = (i >= costs[0]) ? costs[0] : 0;

    std::vector< std::vector<int> > fun_got(m + 1, std::vector<int>(n_of_parties, 0));
    std::fill(fun_got[0].begin(), fun_got[0].end(), 0);
    for (int i = 0; i <= m; ++i)    fun_got[i][0] = (i >= costs[0]) ? fun[0] : 0;
    ///////////////////

    // Find solution
    for (int i = 1; i <=m; ++i) // current money in dispense
    {
        for (int j = 1; j < n_of_parties; ++j) // current subset of parties
        {
            int without_jth = fun_got[i][j - 1];
            int with_jth = (costs[j] <= i) ? fun_got[i - costs[j]][j - 1] + fun[j] : 0;
            if (without_jth == with_jth)
            {
                int spent_without_jth = money_spent[i][j - 1];
                money_spent[i][j] = std::min(spent_without_jth, (costs[j] <= i) ? money_spent[i - costs[j]][j - 1] + costs[j] 
                                                                                : spent_without_jth);
            }
            else if (without_jth > with_jth)
            {
                money_spent[i][j] = money_spent[i][j - 1];
            }
            else
            {
                money_spent[i][j] = money_spent[i - costs[j]][j - 1] + costs[j];
            }
            fun_got[i][j] = std::max(without_jth, with_jth);
        }
    }
    return std::make_pair(money_spent[m][n_of_parties - 1], fun_got[m][n_of_parties - 1]);
}

int main()
{
    int m, n;
    std::cin >> m >> n;

    while (!(m == 0 && n == 0))
    {
        std::vector<int> costs(n), fun(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> costs[i] >> fun[i];
        }
        //auto sol = solve(m, costs.size() - 1, costs, fun);
        auto sol = solve(m, costs, fun);
        std::cout << sol.first << " " << sol.second << std::endl;

        //for (auto &v : mem) std::fill(v.begin(), v.end(), std::make_pair(-1, -1));
        std::cin >> m >> n;
    }

    return 0;
}
