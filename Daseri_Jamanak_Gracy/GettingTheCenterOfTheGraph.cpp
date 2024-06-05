#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<int>>;

std::vector<int> getCenter(const Graph& g)
{
    std::vector<char> deleted(g.size(), 0);

    std::vector<std::pair<int, int>> degrees(g.size());//vertex, degree

    for (std::size_t i = 0; i < degrees.size(); ++i)
    {
        degrees[i].first = i;
        degrees[i].second = g[i].size();
    }

    int left = degrees.size();

    while (left > 2)
    {
        std::cout << "vertexes left: " << left << std::endl;
        for (std::size_t i = 0; i < degrees.size(); ++i)
        {
            if (!deleted[degrees[i].first])
            {
                --degrees[i].second;
            }
            if (0 == degrees[i].second && !deleted[degrees[i].first])
            {
                std::cout << "deleted " << degrees[i].first << " \n";
                deleted[degrees[i].first] = true;
                --left;
            }
        }
    }

    std::vector<int> result;
    for (std::size_t i = 0; i < degrees.size(); ++i)
    {
        if (!deleted[degrees[i].first])
        {
            result.push_back(degrees[i].first);
        }
    }

    return result;
}

int main()
{
    int n = 0;

    std::cout << "Enter n\n";
    std::cin >> n;

    Graph g(n);

    const int m = n - 1;

    for (int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        // std::cout << "enter next" << std::endl;
    }

    std::cout << "graph initialized\n";

    auto cent = getCenter(g);
    std::cout << "center found ";
    for (std::size_t i : cent)
    {
        std::cout << i << ' ';
    }
    return 0;
}