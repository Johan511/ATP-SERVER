#include <cstdint>
#include <iostream>
#include <vector>

struct BubbleSort {
    template <typename T> void sort(std::vector<T> &v) const {
        int n = v.size();
        for (std::size_t i = 0; i < n; i++) {
            for (std::size_t j = i + 1; j < n; j++) {
                if (v[i] > v[j])
                    std::swap(v[i], v[j]);
            }
        }
    }
};

struct InsertionSort {
    template <typename T> void sort(std::vector<T> &v) const {
        int n = v.size();
        for (std::size_t i = 1; i < n; i++) {
            int64_t j = i - 1;
            const T key = v[i];

            while (j >= 0 && v[j] > key) {
                std::swap(v[j + 1], v[j--]);
                j--;
            }
        }
    }
};

struct Sort {
    template <typename SortTy, typename T>
    void operator()(SortTy &&sort_ty, std::vector<T> &v) const {
        sort_ty.sort(v);
    }
};

namespace sorts {
static constexpr InsertionSort insertion_sort = InsertionSort();
static constexpr BubbleSort bubble_sort = BubbleSort();
static constexpr Sort sort = Sort();
}; // namespace sorts

int main() {
    std::vector<double> v = {3, 1, 5, 2, 0};
    sorts::sort(sorts::bubble_sort, v);
    sorts::sort(sorts::insertion_sort, v);
    for (double d : v)
        std::cout << d << " ";
}