#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include <set>

void write_uint(int x){
  int i;
  static char buf[12];
  if(x==0){
    putchar_unlocked('0');
    return;
  }

  for(i=10; x; i--){
    buf[i] = '0' + x % 10;
    x /= 10;
  }
  fputs_unlocked(buf+1+i, stdout);
}

void write_uints(int x, int y){
  write_uint(x);
  putchar_unlocked(' ');
  write_uint(y);
  putchar_unlocked('\n');
}


int main(){
  int seed, n, d;
  std::set<std::pair<int,int> > edges;
  std::vector<int> a;
  std::vector<int> r;
  std::size_t os, ns;

  scanf("%d %d %d", &seed, &n, &d);
  if((n*d)&0x1) return 1;

  std::mt19937 gen(seed);

  do {
    edges.clear();
    a.clear();
    for(int i = 0; i < n*d; i++){
      a.push_back(i%n);
    }
    os = ns = n*d;
    do {
      std::vector<int>::iterator it;

//    std::cout << a.size() << std::endl;

//    std::random_shuffle(a.begin(), a.end());
      std::shuffle(a.begin(), a.end(), gen);
      for(it = a.begin(); it != a.end(); it+=2){
        std::pair<int, int> edge(std::minmax(*it, *(it+1)));
        if(*it == *(it+1) || edges.count(edge)) { r.push_back(*it); r.push_back(*(it+1)); }
        else { edges.insert(edge); }
      }
      a.clear();
      r.swap(a);
      os = ns;
      ns = a.size();
    } while(ns != 0 && ns != os);
  } while(ns != 0);

  for(std::set<std::pair<int, int> >::iterator it = edges.begin(); it != edges.end(); ++it){
//    std::cout << (*it).first << " " << (*it).second << std::endl;
    write_uints((*it).first, (*it).second);
  }

  return 0;
}
