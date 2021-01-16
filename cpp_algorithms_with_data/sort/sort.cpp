/**************************************************************************

Copyright: SenseTime

Author: Peng Liu

Date:2021-01-09

Description: this file achieve all of sort algorithm  

**************************************************************************/

#include <iostream>
using namespace std;

#define DATA_LENGTH 16

int shell_sort(int *data, int length)
{
    /*sort data by shell sort */
    int gap = 0;
    int i = 0, j = 0;
    int temp = 0;
    for (gap = length / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < length; i++)
        {
            temp = data[i];
            for (j = i - gap; j >= 0 && temp < data[j]; j = j - gap)
            {
                data[j + gap] = data[j];
            }
            data[j + gap] = temp;
        }
    }
    return 0;
}
// void merge_back_sort(int *data, int *temp, int length, int start, int end)
// {
//     ;
// }
// void merge_sort(int *data, int *temp, int length, int start, int end)
// {
//     int middle;
//     int temp;
//     if (start < end)
//     {
//         middle = start + (end - start);
//         {
//             merge_sort(data, temp, start, middle);
//             merge_sort(data, temp, middle + 1, end);
//         }
//     }
// }

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubble_sort(int *data, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length - 1; j++)
        {
            if (data[i] > data[j])
                swap(data, j, i); //每次i后面的元素比array[i]小就交换。
        }
    }
}


void insertion_sort(int arr[],int len){
        for(int i=1;i<len;i++){
                int key=arr[i];
                int j=i-1;
                while((j>=0) && (key<arr[j])){
                        arr[j+1]=arr[j];
                        j--;
                }
                arr[j+1]=key;
        }
}


void selection_sort(int arr[],int len)
{
    for(int i =0 ; i<len ; i++)
    {
        int min = i;
        for(int j=i+1; j< len ; j++)
        {
            if(arr[i]>arr[j])
            {
                min = j;
            }
            std::swap(arr[i],arr[min]);
        }
    }
}


int quick_sort_sub(int data[],int left, int right)
{
    if(right < left) return -1;
    int i  = left;
    int j = right;
    int key = data[left];
    while(i!=j)
    {
        while(i < j && key <=data[j])
        {
            j--;
        }
        data[i] = data[j];
        while(i<j && key >= data[j])
        {
            i++;
        }
        data[j] = data[i];
    }
    data[i] = key;
    quick_sort_sub(data,left,i-1);
    quick_sort_sub(data,i+1, right);
    return 0;
}

int quick_sort(int* data, int length)
{
    quick_sort_sub(data,0,length-1);
    return 0;
}

int main()
{

        int data[DATA_LENGTH] = {23, 64, 24, 12, 19, 16, 53, 66, 88, 11, 55, 66, 222, 1, 44, 55};
        quick_sort(data, DATA_LENGTH);
        int i = 0;
        for (i = 0; i < DATA_LENGTH; i++)
        {
            printf("%4d", data[i]);
        }
    return 0;
}
