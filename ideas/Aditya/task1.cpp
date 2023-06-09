#include <cstdint>
#include <vector>

namespace sorts{

template <typename T>
void swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void bubble_sort(std::vector<T>& v){
	int32_t len = v.size();
	for(int32_t i = 0; i < len-1; i++){
		for(int32_t j = 0; j < len - 1 - i; j++){
			if(v[j] > v[j+1]){
				swap(v[j], v[j+1]);
			}
		}
	}
}

template <typename T>
void insertion_sort(std::vector<T>& v){
	int32_t len = v.size();
	for(int32_t i = 0; i < len-1; i++){
		if(v[i] > v[i+1]){
			swap(v[i], v[i+1]);
			for(int32_t j = i; j > 0; j--){
				if(v[j-1] > v[j]){
					swap(v[j-1], v[j]);
				}
			}
		}
	}
}

template <typename T>
void sort(void (*sorting_algo)(std::vector<T>&), std::vector<T>& v){
	(*sorting_algo)(v);
}

}

int main() {
  std::vector<double> v = {3, 1, 5, 2, 0};
  sorts::sort(sorts::bubble_sort, v);
  sorts::sort(sorts::insertion_sort, v);
}