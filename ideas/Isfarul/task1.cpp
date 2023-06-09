#include <cstdint>

namespace sorts {

template <typename type> void bubble_sort(type &v) {
    if (v.size() != 0) {
        for (uint64_t index = 0; index < v.size(); index++) {
            for (uint64_t sub_index = 0; sub_index < v.size() - index - 1;
                 sub_index++) {
                if (v[sub_index] > v[sub_index + 1]) {
                    typename type::value_type temp = v[sub_index];
                    v[sub_index] = v[sub_index + 1];
                    v[sub_index + 1] = temp;
                }
            }
        }
    }
}

template <typename type> void insertion_sort(type &v) {
    if (v.size() != 0) {
        for (uint64_t index = 0; index < v.size(); index++) {
            typename type::value_type key = v[index];
            uint64_t sub_index = index - 1;
            while (sub_index >= 0 && key < v[sub_index]) {
                v[sub_index + 1] = v[sub_index];
                sub_index--;
            }
            v[sub_index + 1] = key;
        }
    }
}

template <typename type> void sort(void (*f)(type &), type &v) { (*f)(v); }

} // namespace sorts
