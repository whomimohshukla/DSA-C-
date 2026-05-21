#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int reverseInteger(int &n){

    int reverseNumber=0;

    while (n>0)
    {

        // to find the last digit number

       int lastDigit=n%10;

       reverseNumber=reverseNumber*10+lastDigit;

       //remove the last digit from number

       n=n/10;

    }
    return reverseNumber;
    

}
int main()
{
    int n=12345;

    int ans=reverseInteger(n);

    cout<<"Reversed interger"<<ans<<endl;
 return 0;
}