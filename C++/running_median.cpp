#include <bits/stdc++.h>
using namespace std;
/* You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median. */

void findMedian(int *arr, int n) {
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    if(n==0)
        return;
    max.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max.top())
            min.push(arr[i]);
        else
            max.push(arr[i]);
        if(int(min.size()-max.size())>1)
        {
            max.push(min.top());
            min.pop();
        }
        else if(int(max.size()-min.size())>1)
        {
            min.push(max.top());
            max.pop();
        }
        if(i%2!=0)
        {
            cout<<(max.top()+min.top())/2<<" ";
        }
        else{
            int val=max.size()>min.size()?max.top():min.top();
         	cout<<val<<" ";
        }
    }
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
