#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// In-order traversal to extract sorted elements from BST
void inOrder(int *array, vector<int> &result, int size, int index)
{
    if (index >= size)
        return;

    inOrder(array, result, size, 2 * index + 1);
    result.push_back(array[index]);
    inOrder(array, result, size, 2 * index + 2);
}

// Pre-order traversal to insert into Min Heap
void preOrderFill(vector<int> &sorted, vector<int> &heap, int index, int &i)
{
    if (index >= (int)heap.size())
        return;

    heap[index] = sorted[i++];
    preOrderFill(sorted, heap, 2 * index + 1, i);
    preOrderFill(sorted, heap, 2 * index + 2, i);
}

// Heapify down for Max Heap
void heapifyDown(vector<int> &heap, int size, int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else
            break;
    }
}

// Convert BST to Min Heap
void bstToMinHeap(int *array, int size)
{
    vector<int> sorted;
    inOrder(array, sorted, size, 0); // sorted in ascending order

    vector<int> minHeap(size);
    int idx = 0;
    preOrderFill(sorted, minHeap, 0, idx);

    cout << "Min Heap: ";
    for (int val : minHeap)
        cout << val << " ";
    cout << endl;
}

// Convert BST to Max Heap
void bstToMaxHeap(int *array, int size)
{
    vector<int> sorted;
    inOrder(array, sorted, size, 0);       // sorted in ascending order
    reverse(sorted.begin(), sorted.end()); // descending for Max Heap

    vector<int> maxHeap(size);
    for (int i = 0; i < size; i++)
        maxHeap[i] = sorted[i];

    // Heapify from bottom non-leaf nodes
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyDown(maxHeap, size, i);
    }

    cout << "Max Heap: ";
    for (int val : maxHeap)
        cout << val << " ";
    cout << endl;
}

int main()
{
    cout << "Starting...\n";

    int bst[] = {30, 20, 10, 15, 8, 7, 2}; // assumed complete BST in array form
    int size = sizeof(bst) / sizeof(bst[0]);

    bstToMinHeap(bst, size);
    bstToMaxHeap(bst, size);

    return 0;
}








// 




#include <iostream>
using namespace std;

bool isMaxHeap(int *array, int size, int i)
{

    /*
    // Approach#01: Recusion
    if (i >= size)
        return true;

    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
        return false;

    return checkHT(array, size, left) && checkHT(array, size, right);
*/

    // Approach#02: Iterative (more efficient)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && array[i] < array[left])
            return false;

        if (right < size && array[i] < array[right])
            return false;
    }
    return true;
}

int main()
{
    cout << "Starting...\n";

    int array[] = {5, 3, 6, 4, 7, 8, 1};
    int size = sizeof(array) / sizeof(array[0]);

    bool isHeap = isMaxHeap(array, size, 0);
    cout << (isHeap ? "Yes it's a Heap Tree" : "No it's not a Heap Tree") << endl;

    int array1[] = {10, 9, 8, 7, 6, 5, 4};
    isHeap = isMaxHeap(array1, size, 0);
    cout << (isHeap ? "Yes it's a Heap Tree" : "No it's not a Heap Tree") << endl;

    return 0;
}




/// 


#include <iostream>
using namespace std;

// Max-heapify function (0-based indexing)
void heapify(int *arr, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

// Function to find k-th smallest element using max-heap
int kthSmallest(int *arr, int size, int k)
{
    // Step 1: Build max-heap of first k elements
    for (int i = k / 2 - 1; i >= 0; i--)
    {
        heapify(arr, k, i);
    }

    // Step 2: Process remaining elements
    for (int i = k; i < size; i++)
    {
        if (arr[i] < arr[0])
        {
            arr[0] = arr[i];
            heapify(arr, k, 0);
        }
    }

    return arr[0]; // Top of max-heap holds k-th smallest      
}

int main()
{
    cout << "Starting...\n";

    int array[] = {5, 3, 6, 4, 7, 8, 1};
    int size = sizeof(array) / sizeof(array[0]);

    int k = 2;
    int result = kthSmallest(array, size, k);

    cout << k << "th smallest element: " << result << endl;

    return 0;
}


// 






#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // Max-Heap (default)
    priority_queue<int> maxHeap;

    maxHeap.push(20);
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(5);

    cout << "Max-Heap Priority Queue: ";
    priority_queue<int> tempMax = maxHeap; // copy to display
    while (!tempMax.empty())
    {
        cout << tempMax.top() << " ";
        tempMax.pop();
    }
    cout << "\nTop element (max): " << maxHeap.top() << "\n";

    maxHeap.pop(); // remove top
    cout << "After popping max: " << maxHeap.top() << "\n";

    cout << "-----------------------\n";

    // Min-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(20);
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(5);

    cout << "Min-Heap Priority Queue: ";
    priority_queue<int, vector<int>, greater<int>> tempMin = minHeap; // copy to display
    while (!tempMin.empty())
    {
        cout << tempMin.top() << " ";
        tempMin.pop();
    }
    cout << "\nTop element (min): " << minHeap.top() << "\n";

    minHeap.pop(); // remove top
    cout << "After popping min: " << minHeap.top() << "\n";

    return 0;
}
