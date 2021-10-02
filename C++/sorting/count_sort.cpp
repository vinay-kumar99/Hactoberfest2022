#include<iostream>
#include<climits>
using namespace std;

int findMax(int arr[],int n)
{
    int maxi = INT_MIN;
    int i;
    for(i =0; i < n; i++)
    {
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}
void CountSort(int arr[],int n)
{
    int i ,j, maxi,*auxi;
    maxi = findMax(arr,n);
    auxi = new int[maxi+1];
    for(i =0;i < maxi+1; i++)
    {
        auxi[i] = 0;
    }
    for(i =0; i < n; i++)
    {
        auxi[arr[i]]++;
    }
    i =0;
    j =0;
    while(j < maxi+1)
    {
        if(auxi[j] > 0)
        {
            arr[i++]=j;
            auxi[j]--;
        }else{
            j++;
        }
    }
    delete [] auxi;
}
int main()
{
    int n;
    cout << "Enter the size of Array : ";
    cin >> n;
    
    int arr[n];
    
    cout << "Enter elements in Array : ";
    
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    
    CountSort(arr,n);
 
    for(auto x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
