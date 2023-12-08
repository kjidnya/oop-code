
#include<iostream>
using namespace std;

template<typename T>
void selectionSort(T arr[],int size){
    for(int i=0;i<size-1;++i){
        int minIndex=i;
         
for(int j=i+1;j<size;++j){
             if(arr[j]<arr[minIndex]){
                 minIndex=j;
             }
         }
         if(minIndex!=i){
             swap(arr[i],arr[minIndex]);
         }
    }
}

template<typename T>
void displayArray(const T arr[],int size){
    for(int i=0;i<size;++i){
        cout<<arr[i]<<"";
    }
    cout<<endl;
}

int main(){
    cout<<"Jidnyasa Kale"<<endl;
    const int intArraySize=5;
    const int floatArraySize=6;
    
    int intArray[intArraySize]={45,12,78,34,22};
    float floatArray[floatArraySize]={3.4,1.2,5.6,2.3,4.1,0.9};
    
    cout<<"Original integer array :";
    displayArray(intArray,intArraySize);
    selectionSort(intArray,intArraySize);
    cout<<"Sorted integer array :";
    displayArray(intArray,intArraySize);
    
    cout<<"\nOrginal float array : ";
    displayArray(floatArray,floatArraySize);
    cout<<"Sorted float array :";
    displayArray(floatArray,floatArraySize);
    return 0;
}
