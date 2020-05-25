#include <iostream>
#include <vector>
#include <algorithm>
#include "MyAlgorithms.h"
#include <chrono>

using namespace std::chrono;

int main() {
    int runs = 50;

    for (int i = 1; i < runs;)
    {
        auto list = my::randomIntegers(0, 50000, i * 1000);


        //selection_sort
        for (int i = 1; i < 2;)
        {
            auto start = high_resolution_clock::now();
            my::selection_sort(std::begin(list), std::end(list));
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << "Time taken by selection_sort: " << duration.count() << " microseconds" << "\n";
            i++;
        }


        //insertion_sort
        for (int i = 1; i < 2;)
        {
            auto start = high_resolution_clock::now();
            my::insertion_sort(std::begin(list), std::end(list));
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << "Time taken by insertion_sort: " << duration.count() << " microseconds" << "\n";
            i++;
        }


        //quicksort
        for (int i = 1; i < 2;)
        {
            auto start = high_resolution_clock::now();
            int comparisons = 0;
            int swaps = 0;
            my::quicksort(std::begin(list), std::end(list), [&comparisons](const int& a, const int& b) {
                ++comparisons;
                return a < b;
                }, swaps);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << "Time taken by quicksort: " << duration.count() << " microseconds" << "\n";
            i++;
        }


        //merge_sort
        for (int i = 1; i < 2;)
        {
            auto start = high_resolution_clock::now();
            my::merge_sort(std::begin(list), std::end(list), [](const int& a, const int& b) {
                return a < b;
                });
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << "Time taken by merge_sort: " << duration.count() << " microseconds" << "\n";
            i++;
        }


        //bubble_sort
        using namespace std;
        int n;
        cout << "Enter number of element you want to store: ";
        cin >> n;
        int arr[n], i, j;
        cout << "Enter array values:\n";
        //taking the array value 
        //from user
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        //Now we will sort the array
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                //checking if previous value is
                //grater than next one or not
                if (arr[j] > arr[j + 1])
                {
                    //temp will temporarly store
                    //the value of arr[j]
                    //then we will swap the values
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "After Bubble sort the array is:\n";
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        return 0;


        //sort
        for (int i = 1; i < 2;)
        {
            auto start = high_resolution_clock::now();
            std::sort(std::begin(list), std::end(list), [](const int& a, const int& b) {
                return a < b;
                });
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << "Time taken by sort: " << duration.count() << " microseconds" << "\n";
            i++;
        }


        //stable_sort
        for (int i = 1; i < 2;)
        {
            auto start = high_resolution_clock::now();
            std::stable_sort(std::begin(list), std::end(list), [](const int& a, const int& b) {
                return a < b;
                });
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            std::cout << "Time taken by stable_sort: " << duration.count() << " microseconds" << "\n\n\n";
            i++;
        }
        i++;
    }
}

/*
At the end, you can look at the duration in the CMD output
*/