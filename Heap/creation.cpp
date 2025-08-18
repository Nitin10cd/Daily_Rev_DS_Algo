#include<bits/stdc++.h>
using namespace std;


class MaxHeap{
    int *arr;
    int size;
    int total_size;


    // constrictor
    public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }


    //  inserting into the heap
    void insert(int value){
        if(size == total_size){
            cout<<"Heap Overflow";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // for adding in the correct position 
        while(index > 0 && arr[(index-1)/2] < arr[index]){
            // if the element is greater then the parent value
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<"is inserted into the heap\n"<<endl;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" "<<endl;
        }
    }

};

// heapfiy method
void heapify(int arr[], int index, int n){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}


/// heapsort 
void heapSort(int arr[], int n){
    for (int i = n-1; i>0; i++){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}

int main(){
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(34);
    H1.insert(40);
    H1.insert(-34);
    H1.insert(0);
    H1.insert(90);
    H1.print();
    return 0;
}