// Jason Whitlow
// csci115 lab3 mergeSort-selectionSort
// this program contains two algorithms to sort an array, mergeSort() and selectionSort().
// the program demonstrates the difference in runtime in each algorithm by comparing 3 conditions:
//  1. when the arrays are sorted
//  2. when the arrays are half sorted
//  3. when the arrays are in reverse order
// the program also makes comparisons with arrays of size 10, 100 and 1000.

#include <iostream>
#include <chrono>
#include<ctime>
using namespace std;
using namespace std::chrono;

// if the length of the array is 5, first should equal 0, and last should equal 4.
// first and last should not be set outside the scope of the array.
// mergeSort is capable of sorting subarrays of arr.
void mergeSort(int *arr, const int first, const int last);
void merge(int *arr, const int first, const int mid, const int last);
void printArr(const int *arr, const int first, const int last);

// if arr[5] then length must equal 5.
// length should not be set smaller or larger than the length of the array.
void selectionSort(int *arr, const int length);

// used in main to print the results of each recursive call.
// if arr[5] then length must equal 5, alg should be set to 'm' for mergeSort(), 's' for selectionSort()
void clockAndPrint(int *arr, const int length, const char alg);

int main()
{
    int arr1[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // sorted
    int arr2[10] = {10, 20, 30, 40, 50, 100, 90, 70, 80, 60}; // half-sorted
    int arr3[10] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10}; // unsorted
    
    int arr4[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // sorted
    int arr5[10] = {10, 20, 30, 40, 50, 100, 90, 70, 80, 60}; // half-sorted
    int arr6[10] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10}; // unsorted
    
    // int arr7[50] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, // unsorted
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,};

    // int arr8[200] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, // unsorted
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,};
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,
    //                 100, 90, 80, 70, 60, 50, 40, 30, 20, 10,};

    // sorted comparison between mergeSort() and selectionSort().
    cout << "Sorted Comparison, Length = 10" << endl;
    int len = sizeof(arr1) / sizeof(arr1[0]);
    clockAndPrint(arr1, len, 'm');
    len = sizeof(arr4) / sizeof(arr4[0]);
    clockAndPrint(arr4, len, 's');
    cout << endl;

    // half-sorted comparison between mergeSort() and selectionSort().
    cout << "Half-Sorted Comparison, Length = 10" << endl;
    len = sizeof(arr2) / sizeof(arr2[0]);
    clockAndPrint(arr2, len, 'm');
    len = sizeof(arr5) / sizeof(arr5[0]);
    clockAndPrint(arr5, len, 's');
    cout << endl;

    // unsorted comparison between mergeSort() and selectionSort().
    cout << "Unsorted Comparison, Length = 10" << endl;
    len = sizeof(arr3) / sizeof(arr3[0]);
    clockAndPrint(arr3, len, 'm');
    len = sizeof(arr6) / sizeof(arr6[0]);
    clockAndPrint(arr6, len, 's');
    cout << endl;

    // // unsorted comparison between mergeSort() and selectionSort().
    // cout << "Unsorted Comparison, Length = 50" << endl;
    // clockAndPrint(arr7, 50, 'm');
    // clockAndPrint(arr7, 50, 's');
    // cout << endl;

    // // unsorted comparison between mergeSort() and selectionSort(), length = 100.
    // cout << "Unsorted Comparison, Length = 100" << endl;
    // len = sizeof(arr7) / sizeof(arr7[0]);
    // clockAndPrint(arr7, len, 'm');
    // len = sizeof(arr8) / sizeof(arr8[0]);
    // clockAndPrint(arr8, len, 's');
    // cout << endl;

    cin.get();
    return 0;
}

// recursively sorts an array by dividing it into a left and right array.
void mergeSort(int *arr, const int first, const int last)
{
    // // code to clock function
    // auto start = high_resolution_clock::now();

    if (first < last)
    {
        // if the length of the array is odd, the length of the left partition will equal the
        // length of the right partition - 1.
        int mid = (first + last - 1) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }

    // // code to clock function
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<nanoseconds>(stop - start);
    // cout << "mergeSort() time elapsed (nanoseconds): " << duration.count() << endl;

}

// combines two partitions of an array.
void merge(int *arr, const int first, const int mid, const int last)
{
    // // code to clock function
    // auto start = high_resolution_clock::now();

    int leftArrLength = mid - first + 1;
    int rightArrLength = last - mid;
    int *leftArr = new int(leftArrLength);
    int *rightArr = new int(rightArrLength);

    // copy first half of arr into leftArr.
    for (size_t i = 0; i < leftArrLength; i++)
        leftArr[i] = arr[first + i];

    // copy second half of arr into rightArr.
    for (size_t i = 0; i < rightArrLength; i++)
        rightArr[i] = arr[mid + 1 + i];

    // merge 
    int i = 0;          // index for leftArr      
    int j = 0;          // index for rightArr
    int k = first;      // index for arr
    while (i < leftArrLength && j < rightArrLength)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    // merge the rest of leftArr.
    while (i < leftArrLength)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // merge the rest of rightArr.
    while (j < rightArrLength)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // code to clock function
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<nanoseconds>(stop - start);
    // cout << "merge without dynamic array creation: " << duration.count() << endl;
    
}

// sorts an array using a nested for loop.
void selectionSort(int *arr, const int length)
{
    int temp;
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = i + 1; j < length; j++)
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    }
}

// prints an array from arr[first] to arr[last]
void printArr(const int *arr, const int first, const int last)
{
    int pos = first;
    while (pos <= last)
    {
        cout << "array[" << pos << "]: " << arr[pos] << endl;
        pos += 1;
    }
}

// uses chronos to time the duration of mergeSort() and selectionSort().
void clockAndPrint(int *arr, const int length, const char alg)
{
    // mergeSort()
    if (alg == 'm' || alg == 'M')
    {
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, length - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "mergeSort()     time elapsed (nanoseconds): " << duration.count() << endl;
    }
    // selectionSort()
    else if (alg == 's' || alg == 'S')
    {
        auto start = high_resolution_clock::now();
        selectionSort(arr, length);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "selectionSort() time elapsed (nanoseconds): " << duration.count() << endl;
    }
    else
    {
        cout << "clockAndPrint() error: alg must be set to 'm' or 's'" << endl;
    }
}

// https://stackoverflow.com/questions/5724171/passing-an-arr-by-reference
// https://www.guru99.com/cpp-dynamic-array.html#:~:text=In%20C%2B%2B%2C%20we%20can,of%20items%20will%20be%20allocated.
// biggest learning experience was how to translate sentinels into code when working with a limited space
// https://www.geeksforgeeks.org/merge-sort/