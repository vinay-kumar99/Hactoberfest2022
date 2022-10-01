#include <iostream> 
using namespace std; 
  
// Main program 
main() 
{ 
    char op; 
    float num1, num2; 

  
    // It allows user to enter operator i.e. +, -, *, / ,%
//     cin >> op; 
  
    // It allow user to enter the operands   
  cout<<"use the operators +,-,/,+ and %"<<endl;
  cout<<"Please write any expression to calculate the value"<<endl;

    cin >> num1 >>op>> num2; 
  
    // Switch statement begins 
    switch (op) { 
          
        // If user enter +  
        case '+': 
            cout << num1 + num2; 
            break; 
          
        // If user enter -  
        case '-': 
            cout << num1 - num2; 
            break; 
          
        // If user enter * 
        case '*': 
            cout << num1 * num2; 
            break; 
          
        // If user enter / 
        case '/': 
            cout << num1 / num2; 
            break; 
         case '%': 
            cout << num1 % num2; 
            break; 
          
        // If the operator is other than +, -, * or /,  
        // error message will display 
        default: 
            cout << "Error! operator is not correct"; 
            break; 
    } // switch statement ends 

    return 0;  
} 
