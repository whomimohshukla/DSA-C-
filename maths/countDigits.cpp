#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countAll(int n){
    
    int count=0;

    while (n>0)
    {
        count=count+1;

        n=n/10;
    }
    return count;
    
}
int main()
{
    int n=12345;

    cout<<countAll(n)<<endl;



 return 0;
}