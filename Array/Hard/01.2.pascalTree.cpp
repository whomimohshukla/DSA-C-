#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> getNthRow(int N) {

    vector<long long>row;

    //first value of the row is always one 

    long long val = 1;

    row.push_back(val);

    //compute remaining values using the relation 

    // c(n,k)=c(n,k-1)*(n-k)/k

    for (int k = 1; k <N; k++)
    {
        val=val*(N-k)/k;
        row.push_back(val);

    }
    return row;
    
}
int main()
{
    int N = 5; // Example: 5th row
    // Solution sol;
    vector<long long> result = getNthRow(N);

    // Print the row
    for (auto num : result)
    {
        cout << num << " ";
    }
    return 0;
}