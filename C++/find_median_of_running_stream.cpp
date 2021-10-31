#include<iostream>
#include<queue>
using namespace std;


int main(){
	priority_queue <int> left;//max heap
	priority_queue<int,vector<int>,greater<int> > right;//min heap
	
	int d;
	cin>>d;
	float mid = d;
	left.push(d);
	cout<<"midean : "<<mid<<endl;
	cin>>d;
	while(d!=-1){
		//logic
			
		if(left.size() > right.size()){
			if(d<mid){
			//means new data will go to left side
			right.push(left.top());
			left.pop();
			left.push(d);
			}else{
				right.push(d);
			}
			mid = (left.top()+right.top())/2.0;	
		}else if(left.size()==right.size()){
			if(d<mid){
				left.push(d);
				mid = left.top();
			}else{
				right.push(d);
				mid = right.top();
			}
		}else{
			if(d>mid){
			left.push(right.top());
			right.pop();
			right.push(d);
			}else{
				left.push(d);
			}
			mid = (left.top()+right.top())/2.0;	
		}
		cout<<"midean : "<<mid<<endl;
		cin>>d;
	
	}
	return 0;
}
