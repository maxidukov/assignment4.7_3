#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

bool is_cyclic(const std::vector<std::vector<bool>>& graph, const int& vertex, std::vector<bool>& visited, const int& prev);

bool has_cycle(const std::vector<std::vector<bool>>& graph);

int main() {
  std::vector<std::string> fnames = {"input.txt","input2.txt"};
  for(const auto& fname:fnames){
  //std::ifstream infile("input.txt");
  std::ifstream infile(fname);
  int size{};
  infile >> size;
  //std::cout<<size<<"\n";
  std::vector<std::vector<bool>> graph(size);
  int i{};
  std::string str;
  while(std::getline(infile,str)){
    //std::cout<<str<<"\n";
    if(str.empty()) continue;
    std::istringstream ss(str);
    bool v{};
    while(ss>>v){
       graph[i].push_back(v);
    }
    i++;
  }
  std::cout << "В графе c матрицей смежности в файле \"" << fname << "\" " << (has_cycle(graph) ? "есть цикл(ы)!\n" : "нет циклов\n");
}
}

bool is_cyclic(const std::vector<std::vector<bool>>& graph, const int& vertex, std::vector<bool>& visited, const int& prev){
   visited[vertex] = true;
   for(int v{}; v<graph.size(); v++){
     if(graph[vertex][v]){
       if(!visited[v]){
         return is_cyclic(graph,v,visited,vertex);
       }else if(v != prev){
         return true;
       }
    }
  }
  return false;
}


bool has_cycle(const std::vector<std::vector<bool>>& graph){
  std::vector<bool> visited(graph.size(),false);
  for(int v{}; v<graph.size();v++){
    if(!visited[v]){
      visited[v] = true;
      return is_cyclic(graph,v,visited,-1);
    }
  }
  return false;
}
