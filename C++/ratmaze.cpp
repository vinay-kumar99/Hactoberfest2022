/* BACKTRACKING */
/*RAT IN A MAZE PROBLEM*/
/*INPUT: 1 denotes the block where he can go whereas 0 denotes the block where he can't go*/
/*OUTPUT: The path taken by the rat*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Function which checks if the block is safe for the rat to go or not.
bool isSafe(int **arr, int x, int y, int n)
{
  if (x < n && y < n && arr[x][y] == 1)
  {
    return true;
  }
  else{
    return false;
  }
}
bool rat(int **arr, int x, int y, int n, int **solArr)
{ //Applying a base condition wherein rat has arrived at the required position.
  if (x == n - 1 && y == n - 1)
  {
    solArr[x][y] = 1;
    return true;
  }
 //If rat is allowed to go to that block then putting 1 there
  else if (isSafe(arr, x, y, n))
  {
    solArr[x][y] = 1;
    //Moving in right direction and checking if we can get a solution from there.
    if (rat(arr, x + 1, y, n, solArr))
    {
      return true;
    }
    //Moving in downward direction to check if the rat is allowed to go on that block
    if (rat(arr, x, y + 1, n, solArr))
    {
      return true;
    }
    solArr[x][y] = 0;
    return false;
  }
   else {
     return false;}

}

int main()
{
  int n;
  cin >> n;
  
  int **arr = new int *[n];
  //Dynamic memory allocation of 2d matrix
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];
  }
 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  int **solArr=new int*[n];
  for (int i = 0; i < n; i++)
  {
    solArr[i]=new int[n];
    for (int j = 0; j < n; j++)
    {
      solArr[i][j] = 0;
    }
  }

  if (rat(arr, 0, 0, n, solArr))
  {// Printing solutions if rat function is true
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << solArr[i][j]<<" ";
      } cout<<endl;
    }
  }
  else{ cout<<"No possible path"<<endl;}
    return 0;
  }


/* SAMPLE CASES:
Test  Case 1:
4 
1 1 1 1
1 1 0 1
0 0 0 0
1 1 1 1
 
output: No possible path

Test Case 2:
3
1 0 1
1 1 1
1 1 1

output: 
1 0 0 
1 0 0 
1 1 1 


Test Case 3:
5
1 0 0 0 1
1 1 0 1 0
1 1 1 0 1
1 1 1 1 1
 
output:
1 0 0 0 0 
1 0 0 0 0 
1 0 0 0 0 
1 1 1 1 1 
0 0 0 0 1 */