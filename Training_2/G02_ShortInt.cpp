#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int *A, int left, int right){
    int pivot = A[left]; 
    int i = left, j = right - 1;
    while(i<j){
        while(i<=right && A[i]<=pivot)i++;
        while(j>=left && A[j]>pivot)j--;
        if(i<j) swap(A[i], A[j]);
    }
    swap(A[j], A[left]);
    return j; 
} 

void quickSort(int *A, int left, int right){
    if (left < right){
        int pivot = Partition(A, left, right);
        quickSort(A, left, pivot);
        quickSort(A, pivot+1, right); 
    }
}

int main(int argc, char **argv){
    int num = 0; cin >> num;
    int array[num];

    //input
    for (int i = 0; i < num; ++i){
        cin >> array[i];
    }

    quickSort(array, 0, num);

    for (int i : array){
        cout << i << " ";
    }

    return 0;
}