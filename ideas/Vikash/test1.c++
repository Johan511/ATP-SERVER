#include <cstdint>
#include <vector>
#include <bits/stdc++.h>

namespace sorts{
    template<typename T>
    void bubble_sort(std::vector<T>& v){
        int64_t n=v.size();
        for(int64_t i=0;i<n-1;i++){
            for(int64_t j=0;j<n-1-i;j++){
                if(v[j]>v[j+1]){
                    T temp=v[j];
                    v[j]=v[j+1];
                    v[j+1]=temp;
                }
            }
        }
    }
    template<typename T>
    void insertion_sort(std::vector<T>& v){
        int64_t n=v.size();
        for(int64_t i=0;i<n-1;i++){
            T temp=v[i+1];
            int64_t k=i;
            while(k>=0){
                if(temp<v[k]){
                    v[k+1]=v[k];
                    k--;
                }
                else{
                    v[k+1]=temp;
                    break;
                }
            }
            if(k<0){
                v[k+1]=temp;
            }
        }
    }
    template<typename T>
    void sort(void(*fun)(std::vector<T>&),std::vector<T>& v){
        (*fun)(v);
    }
}

int main(){
    std::vector<double> v = {3, 1, 5, 2, 0};
    sorts::sort(sorts::bubble_sort, v);
    sorts::sort(sorts::insertion_sort, v);
}
