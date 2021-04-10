#### binary_search

```python
def binary_search(list, item):
    # low and high keep track of which part of the list you'll search in.
    low = 0
    high = len(list) - 1
    while low <= high:
        mid = (low + high) // 2
        guess = list[mid]
        if guess == item:
            return mid
        # The guess was too high.
        if guess > item:
            high = mid - 1
        # The guess was too low.
        else:
            low = mid + 1
    return None


my_list = [1, 3, 5, 7, 9]
print(binary_search(my_list, 3))  # => 1

# 'None' means nil in Python. We use to indicate that the item wasn't found.
print(binary_search(my_list, -1))  # => None
```



```c
#include "iostream"
using namespace std;
void binarySearch(int data_array[], int element, int len) {
	int low = 0;
	int high = len;
	while (low < high) {
		int mid = (low + high) / 2;
		int guess = data_array[mid];
		if (guess == element) {
			cout << "Element found at " << mid << " th index" << endl;
			return;
		}
		else if (guess > element) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	cout << "Element Not Found" << endl;
	return; //number not found
}

int binarySearchRecursive(int data_array[], int element, int len) {
	if (0 == len) {
		return INT_MIN;
	}
	if (element == data_array[len / 2]) {
		return len / 2;
	}
	else if (element < data_array[len / 2]) {	//在前半部分找: 范围是[0,len/2)
		return  binarySearchRecursive(data_array, element, len / 2);
	}
	else {										//在后半部分找; 范围是(len/2,len)
		return len / 2 + 1 + binarySearchRecursive(data_array + len / 2 + 1, element, (len - 1) / 2);
        //if (1 == len % 2)
        //	return len / 2 + 1 + binarySearchRecursive(data_array + len / 2 + 1, element, len / 2);
        //if (0 == len % 2)
        //	return len / 2 + 1 + binarySearchRecursive(data_array + len / 2 + 1, element, len / 2 - 1);
	}
}
// 首元素指针与尾后指针
int binarySearchRecursivePlus(int* begin, int* end, int element) {
	if (begin == end) {
		return INT_MIN;
	}
	int midIndex = (end - begin) / 2;
	if (element == begin[midIndex]) {
		return midIndex;
	}
	else if (element < begin[midIndex]) {	//在前半部分找: 范围是[begin,begin+midIndex)
		return  binarySearchRecursivePlus(begin, begin + midIndex, element);
	}
	else {								//在后半部分找; 范围是(begin+midIndex,end)
		return midIndex + 1 + binarySearchRecursivePlus(begin + midIndex + 1, end, element);
	}
}

int main() {
	int data_array[] = { 0,1,2,4 };
	int length = sizeof(data_array) / sizeof(*data_array);

	binarySearch(data_array, 3, length);
	binarySearch(data_array, 2, length);
	binarySearch(data_array, 1, length);

	cout << binarySearchRecursive(data_array, 3, length) << endl;
	cout << binarySearchRecursive(data_array, 2, length) << endl;
	cout << binarySearchRecursive(data_array, 1, length) << endl;

	cout << binarySearchRecursivePlus(data_array, data_array + length, 3) << endl;
	cout << binarySearchRecursivePlus(data_array, data_array + length, 2) << endl;
	cout << binarySearchRecursivePlus(data_array, data_array + length, 1) << endl;
}
```





#### selection_sort

```python
# Finds the smallest value in an array
def findSmallest(arr):
    # Stores the smallest value
    smallest = arr[0]
    # Stores the index of the smallest value
    smallest_index = 0
    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest_index = i
            smallest = arr[i]
    return smallest_index


# Sort array
def selectionSort(arr):
    newArr = []
    for i in range(len(arr)):
        # Finds the smallest element in the array and adds it to the new array
        smallest = findSmallest(arr)
        newArr.append(arr.pop(smallest))
    return newArr


print(selectionSort([5, 3, 6, 2, 10]))
```



```c
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
// Finds the smallest value in an array
template <typename T>
int find_smallest(const std::vector<T>& arr) {
	T smallest = arr[0];
	int smallest_index = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < smallest) {
			smallest = arr[i];
			smallest_index = i;
		}
	}
	return smallest_index;
}

template <typename T>
std::vector<T> selection_sort(std::vector<T> arr) {
	std::vector<T> sorted;
	while (!arr.empty()) {
		int smallest_index = find_smallest(arr);
		sorted.push_back(arr[smallest_index]);
		arr.erase(arr.begin() + smallest_index);
	}
	return sorted;
}

int main() {
	std::vector<float> arr = { 1.2, 1.0, 3, 0, -1, 0.5, 100, -99 };
	std::vector<float> sorted = selection_sort(arr);
	for (float num : sorted) {
		cout << num << " ";
	}
	cout << endl;
}
```



#### quick_sort



```python
def quicksort(array):
    if len(array) < 2:
        # base case, arrays with 0 or 1 element are already "sorted"
        return array
    else:
        # recursive case
        pivot = array[0]
        # sub-array of all the elements less than the pivot
        less = [i for i in array[1:] if i <= pivot]
        # sub-array of all the elements greater than the pivot
        greater = [i for i in array[1:] if i > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)


print(quicksort([10, 5, 2, 3]))
```



```cpp
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template <typename T>
std::vector<T> quicksort(const std::vector<T>& arr) {
    // base case, arrays with 0 or 1 element are already "sorted"
    if (arr.size() < 2)
        return arr;
    // recursive case
    const T* pivot = &arr.front() + arr.size() / 2 - 1;
    std::vector<T> less;
    std::vector<T> greater;

    for (const T* item = &arr.front(); item <= &arr.back(); item++) {
        if (item == pivot)
            continue;
        if (*item <= *pivot)
            less.push_back(*item);
        else
            greater.push_back(*item);
    }

    std::vector<T> sorted_less = quicksort(less);
    std::vector<T> sorted_greater = quicksort(greater);
    // concatenate less part, pivot and greater part
    sorted_less.push_back(*pivot);
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(),
                       sorted_greater.end());

    return sorted_less;
}

int main() {
    std::vector<int> arr = {69, 60, 38, 82, 99, 15, 8,  94, 30, 42, 35, 40,
                            63, 1,  49, 66, 93, 83, 20, 32, 87, 6,  78, 17,
                            2,  61, 91, 25, 7,  4,  97, 31, 23, 67, 95, 47,
                            55, 92, 37, 59, 73, 81, 74, 41, 39};
    std::vector<int> sorted = quicksort(arr);
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
}
```

