#include<iostream>

using namespace std;
void mergeSort(int *arr, int first, int last);
void merge(int *arr, int first, int mid, int last);


int main(){

    int arr[10];
    mergeSort(arr,1,2);
    cin.get();
    return 0;
}

void mergeSort(int *arr, int first, int last)
{
    // check if first and last are within the bounds of the arr
    if (first<last)
    {
        // if the length of arr is odd, the length of the left subdivision will equal
        // the length of the right subdivision - 1.
        int mid = (first+last-1)/2;     
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, first, mid, last);
    }
}

// merge() creates two new arrays, leftArr and rightArr.
// leftArr and rightArr are be used to sort arr.
void merge(int *arr, int first, int mid, int last)
{
    int *leftArr = new int(mid-first+1);
    int *rightArr = new int(last - mid);
    
    // copy first half of arr into leftArr, second half of arr into rightArr
    for (size_t i = 0; i < mid; i++)
    {
        return;
    }
    

    return;
}

// https://stackoverflow.com/questions/5724171/passing-an-arr-by-reference
// https://www.guru99.com/cpp-dynamic-array.html#:~:text=In%20C%2B%2B%2C%20we%20can,of%20items%20will%20be%20allocated.
// void foo(int (&myArray)[100])
// {
// }

// int main()
// {
//     int a[100];
//     foo(a);
// }