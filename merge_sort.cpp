#include<bits/stdc++.h>
using namespace std;
void mergesorttwoarrays(int *arr, int s, int e){ //jo resultant array ho vo sorted ho uske liye ye banaya
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[e+1];
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int i = s; i<e+1; i++){
        arr[i] = temp[i];
    }
}
void mergesort(int *arr, int s, int e){ 
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr,s,mid); //baar baar array ko aadhe se todtey jao jab tak single element na bach jaaye
    mergesort(arr,mid+1,e);
    mergesorttwoarrays(arr,s,e); // phir array ko jodtey jao ki vo tutey hue array ab sorted hai

}
int main(){
    int n;
    cout<<"Enter the no of elements: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}