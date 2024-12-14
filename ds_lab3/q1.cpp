#include <iostream>

using namespace std;

int* linerSearch(int arr[],int Size, int item,int& counter){
    static int indexs[100];
    for(int i=0;i<Size;i++){
        if(arr[i]==item){
            indexs[counter]=i;
            counter++;
        }
    }
    return indexs;
}

//int main()
//{
//    int arr[]={1,2,2,2,3,4,5,2};
//    int counter=0;
//    int* indexs= linerSearch(arr,8,2,counter);
//    for(int i=0;i<counter;i++){
//        cout<<indexs[i]<<" ";
//    }
//
//    return 0;
//}
