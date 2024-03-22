#include <iostream>
#include <vector>

using namespace std;

void insert_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; ++i)
    {
        temp = a[i];
        for (j = i - 1; temp < a[j] && j >= 0; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

void print_array(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void shell_sort(int a[], int len)
{
    int h, temp, j;
    for (h = len / 2; h > 0; h = h / 2)
    {
        for (int i = h; i < len; i++)
        {
            temp = a[i];
            for (j = i - h; (j >= 0 && temp < a[j]); j -= h)
            {
                a[j + h] = a[j];
            }
            a[j + h] = temp;
        }
    }
}

void bubble_sort(int a[], int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int exchange = 0;

    for (i = 0; i < len - 1; i++)
    {
        exchange = 0;
        for (j = len - 1; j > i; j--)
        { // 修改内层循环的终止条件
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                exchange = 1;
            }
        }
        if (exchange != 1)
        {
            break;
        }
    }
}

void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low];
        int i = low;
        int j = high;

        while (i < j)
        {
            while (i < j && a[j] >= pivot)
            {
                j--;
            }
            if (i < j)
            {
                a[i++] = a[j];
            }
            while (i < j && a[i] <= pivot)
            {
                i++;
            }
            if (i < j)
            {
                a[j--] = a[i];
            }
        }

        a[i] = pivot;
        quick_sort(a, low, i - 1);
        quick_sort(a, i + 1, high); // 将右子数组的起始位置设置为 i + 1
    }
}

void select_sort(int a[], int len)
{
    int i, j, min_index, temp;
    for (i = 0; i < len; i++)
    {
        min_index = i;
        for (j = i + 1; j < len; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
}

int heapSize = 0;
int Left(int index) { return ((index) << 1) + 1; }
int Right(int index) { return ((index) << 1) + 2; }

void swap(int *a, int *b)
{
    if (a == b)
    {
        return;
    }
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// 用最大值替换array[index], index 表示堆顶索引
void maxHeapify(int array[], int index)
{
    int largest = 0;
    int left = Left(index);
    int right = Right(index);

    // 把largest赋给堆顶与其左子节点的较大者
    if ((left <= heapSize) && (array[left] > array[index]))
    {
        largest = left;
    }
    else
    {
        largest = index;
    }
    // 把largest赋给堆顶与其右子节点的较大者
    if ((right <= heapSize) && (array[right] > array[largest]))
    {
        largest = right;
    }

    // 此时largest为堆顶,左子节点,右子节点比较后的最大
    if (largest != index)
    {
        // 如果堆顶不是最大者,则交换,并递归调整堆
        swap(&array[index], &array[largest]);
        maxHeapify(array, largest);
    }
}

void buildMaxHeap(int array[], int length)
{
    int i;
    heapSize = length;
    for (i = (length >> 1); i >= 0; i--)
    {
        maxHeapify(array, i);
    }
}

void heap_sort(int array[], int length)
{
    int i;

    // 初始化堆
    buildMaxHeap(array, (length - 1));

    for (i = (length - 1); i >= 1; i--)
    {
        swap(&array[0], &array[i]);
        heapSize--;
        maxHeapify(array, 0); // 重建堆
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// 对数组按照指定的位数进行计数排序
void countSort(int arr[], int n, int exp)
{
    vector<int> output(n);
    int count[10] = {0};

    // 计算每个元素的出现次数
    for (int i = 0; i < n; ++i)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // 计算累加次数
    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    // 从后往前遍历原数组，根据计数数组将元素放入输出数组中
    for (int i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将输出数组拷贝回原数组
    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
}

// 基数排序
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    // 对每一位进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void ex_1()
{
    int a[] = {7, 3, 5, 8, 9, 1, 2, 4, 6};
    cout << "before insert sort:" << endl;
    print_array(a, 9);
    insert_sort(a, 9);
    cout << "after insert sort:" << endl;
    print_array(a, 9);
    cout << "after shell sort:" << endl;
    shell_sort(a, 9);
    print_array(a, 9);
    cout << "after bubble sort:" << endl;
    bubble_sort(a, 9);
    print_array(a, 9);
    cout << "after quick sort:" << endl;
    int a1[9] = {54, 38, 96, 23, 15, 72, 60, 45, 83};
    quick_sort(a1, 0, 8);
    print_array(a1, 9);
    cout << "after select sort:" << endl;
    bubble_sort(a1, 9);
    print_array(a1, 9);
}

int main()
{

    ex_1();

    return 0;
}