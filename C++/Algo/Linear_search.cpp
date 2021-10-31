// Program created by Sameer Aggrawal (Github user_name = sameer-19)

// C++ program of Linear Search
    #include <iostream>
    using namespace std;

    // Linear search function to search element is present in array or not
    int Linearsearch(int a[], int n, int x)
    {
        for(int i=0;i<n;i++)
        {
          if(a[i]==x) return i; 
        }
        // if we reach here, then element was not present in the array
        return -1;
    }

    int main()
    {
        int i,n,x;
        cout<<"Enter number of elements in array: ";
        cin>>n;
        int a[n];
        cout<<"Enter array elements: ";
        for(i=0;i<n;i++)
            cin>>a[i];
        cout<<"Enter number to be searched: ";
        cin>>x;
        int flag=Linearsearch(a,n,x);
        if(flag==-1) cout<<"Searched Number not found in array";
        else cout<<"Searched Number found in array";
        return 0;
    }
