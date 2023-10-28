#include<iostream>
using namespace std;
int main(){
    int arr[4];
    int i;
    for ( i = 0; i<=3; i++)
    {
        cout<<"Enter the value: \n";
        cin>>arr[i];
    }
    while (i--)
    {
        cout<<""<<arr[i];
    }
    return 0;
}