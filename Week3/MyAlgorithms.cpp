#include "MyAlgorithms.h"
#include <random>
#include <iostream>
#include <algorithm>

std::ostream& operator<<(std::ostream& out, std::vector<int>& data) {
    out << "[";
    for (const auto& item : data) {
        out << item << ", ";
    }
    out << "]";

    return out;
}

namespace my {
    std::vector<int> randomIntegers(int lowerBound, int upperBound, int size) {
        static std::mt19937 engine{ std::random_device{}() };
        static std::uniform_int_distribution range{ lowerBound, upperBound};
        std::vector<int> integers;
        for (int i = 0; i < size; i++) {
            integers.push_back(range(engine));
        }
        return integers;
    }

    void selection_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        while (begin != end) {
            auto minElement = std::min_element(begin, end);

            std::iter_swap(begin, minElement);

            ++begin;
        }
    }

    void insertion_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        auto candidate = begin;
        while (candidate != end) {
            auto following = std::upper_bound(begin, candidate, *candidate);
            std::rotate(following, candidate, std::next(candidate));

            ++candidate;
        }
    }

    void quicksort(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::function<bool(const int&, const int&)> comparator, int& swapCounter) {
        if (begin == end) return;

        auto pivot = *std::next(begin, std::distance(begin, end) / 2);
        auto lowerMiddle = std::partition(begin, end, [&pivot, &comparator, &swapCounter](const int& element) {
            auto result = comparator(element, pivot);
            if (result) ++swapCounter;
            return result;
            });
        auto upperMiddle = std::partition(lowerMiddle, end, [&pivot, &comparator, &swapCounter](const int& element) {
            auto result = !comparator(pivot, element);
            if (result) ++swapCounter;
            return result;
            });

        quicksort(begin, lowerMiddle, comparator, swapCounter);
        quicksort(upperMiddle, end, comparator, swapCounter);
    }

    void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::function<bool(const int&, const int&)> comparator) {
        if (std::distance(begin, end) > 1) {
            auto mid = std::next(begin, std::distance(begin, end) / 2);
            merge_sort(begin, mid, comparator);
            merge_sort(mid, end, comparator);
            std::inplace_merge(begin, mid, end, comparator);
        }
    }

    void BubbleSort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n - i - 1; ++j)
            {
                // Comparing consecutive data and switching values if value at j > j+1.
                if (arr[j] > arr[j + 1])
                {
                    arr[j] = arr[j] + arr[j + 1];
                    arr[j + 1] = arr[j] - arr[j + 1];
                    arr[j] = arr[j] - arr[j + 1];
                }
            }
            // Value at n-i-1 will be maximum of all the values below this index.
        }
    }
}