#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <stdio.h>
#include <algorithm>

void get_int(int &out)
{
    char c = getchar_unlocked();
    while(c < '0' || c > '9')
    {
        c = getchar_unlocked();
    }
    
    out = 0;
    while(c >= '0' && c <= '9')
    {
        out *= 10;
        out += c - '0';
        c = getchar_unlocked();
    }
}

void get_str(std::string &str)
{
    char c = getchar_unlocked();
    while (c == '\n' ||c == '\r' || c == ' ') c = getchar_unlocked();
    while (c >= 'a' && c <= 'z')
    {
        str += c;
        c = getchar_unlocked();
    }
}

void put_int(int n)
{
    std::vector<char> v;
    v.reserve(10);
    while (n)
    {
        v.push_back('0' + n % 10);
        n /= 10;
    }
    std::for_each(v.rbegin(), v.rend(), putchar_unlocked);
}

//////////// Main algorithm ///////////////
#define BIG 999999999
typedef std::pair<int, int> edge; // to, cost

int path(const std::vector<std::vector<edge>> &graph, int source, int dest)
{
    std::vector<int> min_weights(graph.size(), BIG);
    min_weights[source] = 0;
    std::set<std::pair<int, int>> actives; // cost, id
    actives.insert(std::make_pair(0, source));

    while (actives.begin()->second != dest)
    {
        int cur_cost = actives.begin()->first;
        int cur_id = actives.begin()->second;
        min_weights[cur_id] = cur_cost;
        for (const edge &e : graph[cur_id])
        {
            int new_w = cur_cost + e.second;
            if (new_w < min_weights[e.first])
            {
                actives.erase({min_weights[e.first], e.first});
                actives.insert(std::make_pair(new_w, e.first));
                min_weights[e.first] = new_w;
            }
        }
        actives.erase(actives.begin());
    }

    return actives.begin()->first;
}
///////////////////////////////////////////

int main()
{
    std::vector<int> answers;
    answers.reserve(1500);

    int t;
    get_int(t);

    for (int i = 0 ; i < t; ++i) // test cases
    {
        int n; // #cities
        get_int(n);
        std::vector<std::vector<edge>> cities(n, std::vector<edge>{});
        std::unordered_map<std::string, int> name_to_id;
        for (int j = 0; j < n; ++j) // citites
        {
            std::string name;
            get_str(name);
            name_to_id[name] = j;

            int n_edges;
            get_int(n_edges);
            cities[j].resize(n_edges);
            for (int k = 0; k < n_edges; ++k) // edges
            {
                edge e;
                get_int(e.first);
                get_int(e.second);
                --e.first;
                cities[j][k] = e;
            }
        }
        int paths;
        get_int(paths);
        for (int l = 0; l < paths; ++l)
        {
            std::string src, dst;
            get_str(src);
            get_str(dst);

            answers.push_back(path(cities, name_to_id[src], name_to_id[dst]));
        }
    }
 
    for (auto a : answers)
    {
        put_int(a);
        putchar_unlocked('\n');
    }
 
    return 0;
}
