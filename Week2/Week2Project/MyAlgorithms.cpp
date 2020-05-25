#include "MyAlgorithms.h"
#include <iostream>

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
        static std::uniform_int_distribution range{ lowerBound, upperBound };

        std::vector<int> integers;
        for (int i = 0; i < size; i++) {
            integers.push_back(range(engine));
        }

        return integers;
    }

    std::vector<int>::const_iterator find(std::vector<int>::const_iterator it, std::vector<int>::const_iterator end, int number) {
        for (; it != end; ++it) {
            if (*it == number) {
                return it;
            }
        }

        return end;
    }

    std::vector<int>::const_iterator binary_search(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int item) {
        std::vector<int>::const_iterator notFound = end;
        while (std::distance(begin, end) > 0) {
            std::vector<int>::const_iterator midpoint = begin;
            std::advance(midpoint, std::distance(begin, end) / 2);

            if (*midpoint == item) {
                return midpoint;
            }
            else if (*midpoint < item) {
                begin = midpoint;
                begin++;
            }
            else {
                end = midpoint;
            }
        }

        return notFound;
    }
}