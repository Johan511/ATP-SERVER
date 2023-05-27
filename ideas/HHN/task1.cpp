#include <cstdint>
#include <vector>


int main() {
  std::vector<double> v = {3, 1, 5, 2, 0};
  sorts::sort(sorts::bubble_sort, v);
  sorts::sort(sorts::insertion_sort, v);
}