#include <vector>
#include <random>
#include <ostream>

std::ostream& operator<<(std::ostream& out, std::vector<int>& data);

namespace my {
    std::vector<int> randomIntegers(int lowerBound, int upperBound, int size);

    std::vector<int>::const_iterator find(std::vector<int>::const_iterator it, std::vector<int>::const_iterator end, int item);
    std::vector<int>::const_iterator binary_search(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int item);
}