#include <vector>
#include <iostream>
using namespace std;

template <class T>
void print_vec(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << std::endl;
}
template <class T>
void print_vec_vec(const std::vector<std::vector<T>> vecs) {
    for (const auto& vec : vecs) {
        print_vec(vec);
    }
}
