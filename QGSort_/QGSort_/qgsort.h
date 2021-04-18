#pragma once

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
#include <stack>
#include<string.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
template<typename T>
void insertSort(T* a, int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
template<typename T>
void MergeArray(T* a, int begin, int mid, int end, T* temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
template<typename T>
void MergeSort(T* a, int begin, int end, T* temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
template<typename T>
void QuickSort_Recursion(T* a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
template<typename T>
void QuickSort(T* a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
template<typename T>
int Partition(T* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
template<typename T>
void CountSort(T* a, int size, int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
template<typename T>
void RadixCountSort(T* a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
template<typename T>
void ColorSort(T* a, int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
template<typename T>
T FindKmin(T* a, int begin, int end, int k);

template<typename T>
T FindKmax(T* a, int begin, int end, int k);


//插入排序算法
template<typename T>
void insertSort(T* a, int n)
{
    int j;
    T temp;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}


//归并排序（合并数组）
template<typename T>
void MergeArray(T* a, int begin, int mid, int end, T* temp)
{
    int k = begin;
    int i = begin;
    int j = mid + 1;
    while (i <= mid && j <= end) {
        temp[k++] = a[i] < a[j] ? a[i++] : a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= end)
        temp[k++] = a[j++];
    for (int t = begin; t <= end; t++)
        a[t] = temp[t];
}


//归并排序
template<typename T>
void MergeSort(T* a, int begin, int end, T* temp)
{
    int i = begin, j = end;
    if (i >= j)
    {
        return;
    }
    else
    {
        int mid = (j - i) / 2 + i;
        MergeSort(a, i, mid, temp);
        MergeSort(a, mid + 1, j, temp);
        MergeArray(a, i, mid, end, temp);
    }
    
}


//快速排序（递归版）
template<typename T>
void QuickSort_Recursion(T* a, int begin, int end)
{
    int i = begin, j = end;
    if (a == NULL || begin < 0 || end <= 0 || begin>end)
        return;
    int k = Partition(a, i, j);
    //递归实现
    if (k > begin)
        QuickSort_Recursion(a, begin, k - 1);
    if (k < end)
        QuickSort_Recursion(a, k + 1, end);
}


//快速排序（非递归版）
template<typename T>
void QuickSort(T* a, int size)
{
    std::stack< int> st;
    int low = 0, high = size - 1;
    int mid;
    st.push(low);
    st.push(high);
    while (st.size() > 1) {
        high = st.top();
        st.pop();
        low = st.top();
        st.pop();
        mid = Partition(a, low, high);
        if (low < mid - 1) {
            st.push(low);
            st.push(mid - 1);
        }
        if (mid + 1 < high) {
            st.push(mid + 1);
            st.push(high);
        }
    }
}




//快速排序（枢轴存放）从小到大
template<typename T>
int Partition(T* a, int begin, int end)
{
    int i = begin, j = end;
    /*if (a == NULL || begin < 0 || end <= 0 || begin >= end)
        return -1;*/

    T priot = a[i];
    T temp;
    while (i < j)
    {
        while (i < j && a[j] >= priot)
            j--;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        while (i < j && a[i] <= priot)
            i++;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    return i;
}

//从大到小
template<typename T>
int Partition2(T* a, int begin, int end)
{
    int i = begin, j = end;
    /*if (a == NULL || begin < 0 || end <= 0 || begin >= end)
        return -1;*/
    T priot = a[i];
    T temp;
    while (i < j)
    {
        while (i < j && a[j] <= priot)
            j--;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        while (i < j && a[i] >= priot)
            i++;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    return i;
}


//计数排序
template<typename T>
void CountSort(T* a, int size, int max)
{
    
    //给计数器和已排序数组分配空间
    T* count = new T[200000]();
    T* sorted = new T[200000]();
    if (count == NULL || sorted == NULL)
    {
        std::cout << "内存分配失败!" << std::endl;
        std::system("pause");
        exit(0);
    }

    int max_ = a[0], min = a[0];
    for (int i = 0; i < size; ++i)
    {
        if (a[i] > max_)
        {
            max_ = a[i];
        }

        if (a[i] < min)
        {
            min = a[i];
        }
    }
    int range = max_ - min + 1;
    
    memset(count, 0, sizeof(int) * range);

    for (int i = 0; i < size; ++i)
    {
        count[a[i] - min]++;
    }

    int j = 0;
    for (int i = 0; i < range; ++i)
    {
        while (count[i]--)
        {
            a[j++] = i + min;
        }
    }



    ////计数数组初始化为0
    //for (i = 0; i < max + 1; i++)
    //{
    //    count[i] = 0;
    //}
    ////收集原数组中每种值的个数
    //for (i = 0; i < size; i++)
    //{
    //    count[a[i]]++;
    //}
    ////统计所有小于等于该值的元素个数
    //for (i = 1; i < max + 1; ++i)
    //{
    //    count[i] += count[i - 1];
    //}
    ////将所有元素按收集表分配到对应位置，反向填充目标数组
    //for (i=size-1; i>=0; i--)
    //{
    //    //先将计数数组中对应值-1
    //    sorted[count[a[i]]-1] = a[i];
    //    count[a[i]]--;
    //}
    ////已排序数组替代原数组
    //for (i = 0; i < size; i++)
    //{
    //    a[i] = sorted[count[a[i]]];
    //}

    //释放内存
    delete[] count;
    delete[] sorted;
}


//求数组最大值
template<typename T>
int arrayMax(T* a, int size)
{
    int i, max = a[0];
    for (i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

//基数计数排序
template<typename T>
void RadixCountSort(T* a, int size)
{
    int i, index, max;
    int rad = 1; //从个位开始


    //计算数组中的最大值
    max = arrayMax(a, size);

    //给计数器和已排序数组分配空间
    T* count = new T[10];
    T* sorted = new T[size];
    if (count == NULL || sorted == NULL)
    {
        std::cout << "内存分配失败!" << std::endl;
        std::system("pause");
        exit(0);
    }

    while (max / rad > 0)
    {
        //计数数组初始化为0
        for (i = 0; i < 10; i++)
        {
            count[i] = 0;
        }
        //统计当前位上每个数值出现的次数
        for (i = 0; i < size; i++)
        {
            index = a[i] / rad % 10;
            count[index]++;
        }
        //统计所有小于等于该值的元素个数
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        //将所有元素按收集表分配到对应位置
        for (i = size - 1; i >= 0; i--)
        {
            index = a[i] / rad % 10;
            count[index]--;
            sorted[count[index]] = a[i];
        }
        //已排序数组替代原数组
        for (i = 0; i < size; i++)
        {
            a[i] = sorted[i];
        }
        rad *= 10; //位数乘10
    }

    //释放内存
    delete[] count;
    delete[] sorted;
}


//数据交换
template<typename T>
void Swap(T* x, T* y)
{
    T temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//颜色排序
template<typename T>
void ColorSort(T* a, int size)
{
    //定义元素0的初始最左指针
    int index0 = 0;
    //定义当前指针
    int cur = 0;
    //定义元素2的初始最右指针
    int index2 = size - 1;
    //判断循环条件，不要忘记是<=,否则最后一个元素的位置确定不了
    while (cur <= index2) {
        //发现元素0，交换完毕后两个指针都要增加，因为交换到cur的元素只能是1
        if (a[cur] == 0) {
            Swap(a + cur, a + index0);
            index0++;
            cur++;
        }
        //发现元素2，交换完注意cur指针不能增加，因为从cur之后交换过来的元素可能是0，需要再次判断cur指向的值
        else if (a[cur] == 2) {
            Swap(a + cur, a + index2);
            index2--;
        }
        //发现元素1，直接后移当前指针
        else
            cur++;
    }
}


//找到第K小的数
template<typename T>
T FindKmin(T* a, int begin, int end, int k)
{
    /*return a[k-1];*/
    
    if (begin <= end)
    {
        int pivot = Partition(a, begin, end);
        if (pivot + 1 == k)
            return a[pivot];
        else if (pivot + 1 > k)
            FindKmin(a, begin, pivot - 1, k);
        else
            FindKmin(a, pivot + 1, end, k);
    }
    /*else
        return -1;*/
}


//找到第K大的数
template<typename T>
T FindKmax(T* a, int begin, int end, int k)
{
    /*return a[k-1];*/
    if (begin <= end)
    {
        int pivot = Partition2(a, begin, end);
        if (pivot + 1 == k)
            return a[pivot];
        else if (pivot + 1 > k)
            FindKmax(a, begin, pivot - 1, k);
        else
            FindKmax(a, pivot + 1, end, k);
    }
    /*else
        return -1;*/
}




#endif // QUEUE_H_INCLUDED
