#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a=10;

    int* p=&a;

    cout<<a;
    cout<<endl;
    cout<<"address of a:"<<&a;
    cout<<endl;

    cout<<"address of a:"<<p;

    cout<<endl;

    cout<<"value of a:"<<*p<<endl;

    *p=30;


    cout<<"value of a is changed:"<<a;

    int* ptr=nullptr;

    // cout<<*ptr<<endl;

    int arr[]={10,20,30,40,50};

    int* q=arr;

   cout << *q;       // 10
   cout << *(q+1);  // 20
   cout << *(q+2);  // 30






 return 0;
}