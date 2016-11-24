#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <algorithm>
#include <numeric>

int solve(std::vector< std::vector<int> > & tiles)
{
    int h = tiles.size();
    int w = tiles[0].size();

    if (w == 1)
    {
        for (int i = h - 2; i >= 0; --i)
        {
            tiles[i][0] += tiles[i + 1][0];
        }
    }
    else if (w == 2)
    {
        for (int i = h - 2; i >= 0; --i)
        {
            tiles[i][0] += std::max(tiles[i + 1][0], tiles[i + 1][1]);
            tiles[i][w - 1] += std::max(tiles[i + 1][w - 2], tiles[i + 1][w - 1]);
        }
    }
    else
    {
        for (int i = h - 2; i >= 0; --i)
        {
            for (int j = 1; j < w - 1; ++j)
            {
                tiles[i][j] += std::max(std::max(tiles[i + 1][j], tiles[i + 1][j + 1]), tiles[i + 1][j - 1]);
            }
            tiles[i][0] += std::max(tiles[i + 1][0], tiles[i + 1][1]);
            tiles[i][w - 1] += std::max(tiles[i + 1][w - 2], tiles[i + 1][w - 1]);
        }
    }
    return *std::max_element(tiles[0].begin(), tiles[0].end());
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int h, w;
        std::cin >> h >> w;
        std::vector< std::vector<int> > tiles(h, std::vector<int>(w, -1));
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                std::cin >> tiles[i][j];
            }
        }
        std::cout << solve(tiles) << std::endl;
    }

    return 0;
}
