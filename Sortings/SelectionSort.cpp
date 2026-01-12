void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++) {
     int minEle = i;
     
     for (int j = 0; j < n; j++)}{
         if (arr[j] < arr[minEle]){
             minEle = j;
         }
     }
     
     int temp = arr[minEle];
     arr[minEle] = arr[i];
     arr[i] = temp;
    }
}
