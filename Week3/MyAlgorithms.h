#include <vector>
#include <ostream>
#include <functional>

std::ostream& operator<<(std::ostream& out, std::vector<int>& data);

namespace my {
    std::vector<int> randomIntegers(int lowerBound, int upperBound, int size);

    void selection_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    void insertion_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    void quicksort(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::function<bool(const int&, const int&)> comparator, int& swapCounter);

    void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::function<bool(const int&, const int&)> comparator);
}