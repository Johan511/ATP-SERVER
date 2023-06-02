#include <cstdint>
#include<iostream>
#include <vector>

namespace sorts{
template <typename T>
void bubble_sort(std::vector<T>& v){
   
int x=v.size();
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<x-1;j++){
            if(v[j]>v[j+1]){std::swap(v[j],v[j+1]);}
        }
    }


 }


template <typename T>
void insertion_sort(std::vector<T>& v){

int x=v.size();
int i,j;
for(i=1;i<x;i++){
    int k=v[i];
j=i-1;
while(j>=0 && v[j]>=k){
    std::swap(v[j+1],v[j]);
    j=j-1;
}
}
     for (int i = 0; i < v.size(); i++)
       std::cout << v[i] << " ";

}

template <typename T>
   void sort(void (*fxn)(std::vector<T>& v), std::vector<T> v2){
(*fxn)(v2);

   };
}

int main() {
  std::vector<char> v = {'a','g','j','k','e','f','x','k'};
  sorts::sort(sorts::bubble_sort, v);
  sorts::sort(sorts::insertion_sort, v);
}
