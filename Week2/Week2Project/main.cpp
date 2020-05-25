#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "MyAlgorithms.h"

using namespace std;

template <typename Callable>
double averageTime(int iterations, Callable func) {
    auto sum = 0.;
    for (int i = 0; i < iterations; i++) {
        auto before = std::chrono::steady_clock::now();
        func();
        std::chrono::duration<double, std::milli> milliseconds{ std::chrono::steady_clock::now() - before };
        sum += milliseconds.count();
    }
    return sum / iterations;
}

int main() {

    int test = 0;
    std::cout << "Hello World!\n\n";
    std::cout << "Enter the value you'd like to search for out of 10: ";
    std:cin >> test;


    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";


    std::cout << "1. Sequential Search \n";
    std::cout << "--------------------------------------------------- \n\n";
    std::vector<int> values{ 5, 7, 4, 1, 3, 9, 2, 8, 6, 0, 10 };
    if (auto it = my::find(std::cbegin(values), std::cend(values), test); it != std::cend(values)) {
        std::cout << "Here is the Sequential list:    5, 7, 4, 1, 3, 9, 2, 8, 6, 0, 10 \n\n";
        std::cout << "found the value " << *it << " at index: " << std::distance(std::cbegin(values), it) << "\n";
    }
    else {
        std::cout << "did NOT find the value, can you count to 10?\n";
    }


    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";


    std::cout << "2. Binary Search \n";
    std::cout << "--------------------------------------------------- \n\n";
    std::vector<int> valz{ 3,4,8,9,1,5,2,6,7,10 };
    std::sort(std::begin(values), std::end(values));
    if (auto it = my::binary_search(std::cbegin(values), std::cend(values), test); it != std::cend(values)) {
        std::cout << "Here is the Binary list:    1, 2, 3, 4, 5, 6, 7, 8, 9, 10   \n\n";
        std::cout << "found the value " << *it << " at index: " << std::distance(std::cbegin(values), it)-1 << "\n";
    }
    else {
        std::cout << "the value was NOT found\n";
    }


    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";


    std::cout << "3.    std::find_if  & std::binary_search \n";
    std::cout << "--------------------------------------------------- \n\n";


    for (int i = 0; i < 5; i++) {
        auto integers = my::randomIntegers(0, 1000000, 1000000);
        size_t compares = 0;
        std::find_if(std::begin(integers), std::end(integers), [&compares](const int& value) {
            compares++;
            return value == 100;
            });
        std::cout << "Size " << compares << "\n";

        auto ms = averageTime(10, [&integers]() {
            std::find(std::begin(integers), std::end(integers), 100);
            });
        std::cout << "Sequential Find Took: " << ms << " milliseconds\n";

        auto before = std::chrono::steady_clock::now();
        std::sort(std::begin(integers), std::end(integers));
        std::chrono::duration<double> seconds{ std::chrono::steady_clock::now() - before };
        std::cout << "Sortin List Took: " << seconds.count() << " seconds\n";


        auto bms = averageTime(10, [&integers]() {
            std::binary_search(std::begin(integers), std::end(integers), 100);
            });
        std::cout << "Binary Search Took: " << bms << " milliseconds\n\n";

    }

}