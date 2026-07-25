#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int stockbuySell(vector<int>&price){

    int mini=price[0];

    int profit=0;

    for (int i = 1; i < price.size(); i++)
    {
        int diff=price[i]-mini;

        profit=max(profit,diff);

        mini=min(mini,price[i]);
    }
    return profit;
    
}
int main()
{
     vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << stockbuySell(prices) << endl;
 return 0;
}