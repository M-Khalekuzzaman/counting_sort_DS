#include<bits/stdc++.h>
using namespace std;
int main()
{
    //array size
    int size;
    cin>>size;
    //array input part
    int *arr = new int[size] {0};
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }
    //search maximum number
    int mx = arr[0];
    for(int i = 1; i<size; i++)
    {
        if(arr[i]>mx) mx = arr[i];
    }
    //frequency array count korte hbe
    int *counter = new int[mx+1] {0};
    for(int i = 0; i<size; i++)
    {
        int val = arr[i];
        counter[val]++;
    }
    // prefix sum array banate hbe frequency array thake
    int *prefix = new int[mx+1] {0};
    int sum = 0,k = 0;
    for(int i = 0; i<=mx; i++)
    {
        sum += counter[i];
        prefix[k] = sum;
        k++;
    }
    //final array banate hbe main array size niye
    int *final = new int[size]{0};
    for(int i = size-1;i>=0;i--){
       int value = arr[i];
       prefix[value]--;
       int k = prefix[value];
       final[k] = value;
    }
    for(int i = 0;i<size;i++){
        cout<<final[i]<<" ";
    }



    return 0;
}
