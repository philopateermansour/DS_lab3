#include <iostream>

using namespace std;

int binarySearch(int arr[],int Size, int item){
    int Start=0,End=Size-1,mid=0;
    while(Start<=End){
        mid=(Start+End)/2;
        if(arr[mid]==item){
            return mid;
        }
        else if(arr[mid]>item){
            End=mid-1;
        }
        else{
            Start=mid+1;
        }
    }
    return -1;
}


//int main(){
//
//    int arr[]={10,20,40,60,80};
//    int index=binarySearch(arr,5,100);
//    index==-1?cout<<"that element is not in the list"<<endl:cout<<index<<endl;
//    index=binarySearch(arr,5,60);
//    index==-1?cout<<"that element is not in the list"<<endl:cout<<index<<endl;
//    return 0;
//}
