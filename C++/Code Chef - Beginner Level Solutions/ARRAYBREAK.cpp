/* Problem link: 
    https://www.codechef.com/problems/ARRAYBREAK
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long n;
	    cin>>n;
	    vector<long> arr;
	    long e=0,f=0;
	    for(int i=0;i<n;i++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	        if(arr[i]%2==0){
	            e++;
	        }
	    }
	    if(e==n){
	        cout<<"0\n";
	    }else{
	        cout<<e<<endl;
	    }
	}
	return 0;
}
