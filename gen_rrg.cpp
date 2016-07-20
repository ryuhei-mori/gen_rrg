#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include <set>

int main(){
  int seed, n, d;
  std::set<std::pair<int,int> > edges;
  std::vector<int> a;
  std::vector<int> r;

  scanf("%d %d %d", &seed, &n, &d);

  if((n*d)&0x1) return 1;

  for(int i = 0; i < n*d; i++){
    a.push_back(i%n);
  }
//  std::random_shuffle(a.begin(), a.end());

  std::shuffle(a.begin(), a.end(), std::mt19937(seed));

  do {
    std::vector<int>::iterator it;
    for(it = a.begin(); it != a.end() && it + 1 != a.end();){
      std::pair<int, int> edge(*it, *(it+1));
      if(*it == *(it+1) || edges.count(edge)) { r.push_back(*it); ++it; }
      else { edges.insert(edge); it+=2; }
    }
    if(it != a.end()) { r.push_back(*it); }
    a.clear();
    r.swap(a);
  } while(!a.empty());

  for(std::set<std::pair<int, int> >::iterator it = edges.begin(); it != edges.end(); ++it){
    std::cout << (*it).first << " " << (*it).second << std::endl;
  }

  return 0;
}
