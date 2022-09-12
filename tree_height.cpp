#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>


int main() {

  size_t size;
  std::cin >> size;

  std::vector<std::vector<int>> children(size);


  int root = 0;

  for(size_t i = 0; i < size; ++i)
  {
    int parent;
    std::cin >> parent;
    if (parent != -1)
    {
      children[parent].push_back(i);
    }
    else root = i;
  }
  std::map<int, int> vis;
  std::queue<std::pair<int, int>> q;
  int max_level_reached = 0;

  q.push({ root, 0 });
  std::pair<int, int> p;

  while(!q.empty())
  {
    p = q.front();
    vis[p.first] = 1;

    max_level_reached = std::max(max_level_reached,
                                 p.second);
    q.pop();

    for(auto child: children[p.first])
    {
      if(!vis[child])
      {
        q.push({child, p.second + 1});
      }
    }
  }
  std::cout << max_level_reached + 1;
  return 0;
}
