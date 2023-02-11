// Jason Whitlow
// csci115 lab3 mergeSort-selectionSort
// this program contains two algorithms to sort an array, mergeSort() and selectionSort().
// the program demonstrates the difference in runtime in each algorithm. 

#include <iostream>
#include <chrono>
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

int main()
{
    // RANDOMIZE NUMBERS----------------------------------------------------------------
    int arr1[8] = {6, -90, 10, 7, 11, 2, 5, 9};
    int arr2[8] = {6, -90, 10, 7, 11, 2, 5, 9};

    // mergeSort()
    int len = sizeof(arr1)/sizeof(arr1[0]);
    auto start = high_resolution_clock::now();
    mergeSort(arr1, 0, len-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "mergeSort() time elapsed: " <<  duration.count() << " nanoseconds" << endl;

    // selectionSort()
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    start = high_resolution_clock::now();
    selectionSort(arr2, len2);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    cout << "mergeSort() time elapsed: " <<  duration.count() << " nanoseconds" << endl;


    cin.get();
    return 0;
}

// recursively sorts an array by dividing it into a left and right array.
void mergeSort(int *arr, const int first, const int last)
{
    if (first < last)
    {
        // if the length of the array is odd, the length of the left partition will equal the length of the right partition - 1.
        int mid = (first + last - 1) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

// combines two partitions of an array.
void merge(int *arr, const int first, const int mid, const int last)
{
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
    
    // merge leftArr and rightArr.
    int i = 0;
    int j = 0;
    int k = first;
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
}

// sorts an array using a nested for loop. 
void selectionSort(int *arr, const int length)
{
    int temp;
    for (size_t i = 0; i < length-1; i++)
    {
        for(size_t j=i+1; j < length; j++)
            if (arr[j]<arr[i])
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

// https://stackoverflow.com/questions/5724171/passing-an-arr-by-reference
// https://www.guru99.com/cpp-dynamic-array.html#:~:text=In%20C%2B%2B%2C%20we%20can,of%20items%20will%20be%20allocated.
// biggest learning experience was how to translate sentinels into code when working with a limited space
// https://www.geeksforgeeks.org/merge-sort/