/*
Ciel and Receipt Solution in C++
Author: Shourya Gupta

Question Link: https://www.codechef.com/problems/CIELRCPT/
*/

#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int a[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
    for(int i=0;i<T;i++){
        int p,sum=0,counter=0,amax,temp;
        cin>>p;
        temp=p;
        while(p != sum){
                    for(int j=0;j<12;j++){
                        if((a[j])<=temp){
                            amax=a[j];
                        }
                        else
                            break;
                    }
                    temp=temp-amax;
                    sum=sum+amax;
                    counter=counter+1;
        }
        cout<<counter<<endl;
    }

}
