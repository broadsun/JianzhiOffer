#include <iostream>
using namespace std;

static void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(int data[], int len) {
    if (data && len > 0)
    {
        int k = len;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i < k; ++i) {
                if (data[i] < data[i-1]) {
                    swap(data[i], data[i-1]);
                    flag = true;
                }
            }
            --k;
        }
    }
}

void InsertSort(int data[], int len) {
    if (data&&len)
    {
        for (int i = 1; i < len; ++i)
            for (int j = i-1; j >=0 && data[j]>data[j+1]; --j)
                swap(data[j],data[j+1]);
    }
}

void ShellSort(int data[], int len)
{
    if (data&&len)
    {
        for (int gap = len/2; gap > 0; gap /= 2)
        {
            for (int i = gap;i < len; ++i)
            {
                for (int j = i-gap ; j>=0 && data[j]>data[j+gap];j-=gap )
                {
                    swap(data[j],data[j+gap]);
                }
            }
        }
    }
}

void MergeArray(int data[], int first, int mid, int last, int temp[]) {
    int i = first; int m = mid;
    int j = mid+1; int n = last;
    int k = 0;
    while (i <= m && j <= n) {    
        if (data[i] <= data[j])
            temp[k++] = data[i++];
        else
            temp[k++] = data[j++];
    }
    while (i <= m)
        temp[k++] = data[i++];
    while (j <= n)
        temp[k++] = data[j++];  
    
    for (int l=0; l < k; ++l)
        data[first+l] = temp[l];
}

void MergeSort(int data[], int first, int last, int temp[]) {
    if (first < last)
    {
        int mid = (first+last)/2;
        MergeSort(data, first, mid, temp);
        MergeSort(data,mid+1,last,temp);
        MergeArray(data,first,mid,last,temp);
    }
}

bool MergeSort(int data[], int len) {
    int *temp = new int[len];
    if (temp)
    {
        MergeSort(data,0,len-1,temp);
        delete[] temp;
        return true;
    }
    delete[] temp;
    return false;
}

void MinHeapFixdown(int data[],int i, int n)
    {
        int temp = data[i];  
        int j = 2 * i + 1;  
        while (j < n)  
        {  
            if (j + 1 < n && data[j + 1] < data[j]) //在左右孩子中找最小的  
                j++;  
            if (data[j] >= temp)  
                break;  
            data[i] = data[j];     //把较小的子结点往上移动,替换它的父结点  
            i = j;
            j = 2 * i + 1;  
        }  
        data[i] = temp;
    }
    void MakeMinHeap(int data[], int n)  
    {  
        for (int i = n / 2 - 1; i >= 0; i--)  
            MinHeapFixdown(data, i, n);  
    }
    void MinheapsortTodescendarray(int data[], int length)  
    {  
        MakeMinHeap(data, length);
        for (int i = length - 1; i >= 1; i--)  
        {  
            swap(data[i], data[0]);  
            MinHeapFixdown(data, 0, i);  
        }  
    }  

int main() {
    int testdata[10] = {11,23,1,5,7,3,0,29,26,100};
    //BubbleSort(testdata,10);
    //MergeSort(testdata, 10); 
    MinheapsortTodescendarray(testdata,10);
    for (int i = 0; i < 10; ++i)
    {
        cout<<testdata[i]<<"\t";
    }
    cout<<endl;
    return 0;
}