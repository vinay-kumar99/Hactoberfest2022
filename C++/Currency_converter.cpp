#include <iostream>

using namespace std;

int main(){

    string currency;

    string currency2;

    double amount;

    double amount2;

    cout << "What currency would you like to convert? \n";

    cout << "The currencies are: Rupees, Dollars, Pesos, and Euros. \n";

    cin >> currency;

    cout << "What currency would you like to convert to? \n";

    cin >> currency2;

    cout << "How much money would you like to convert? \n";

    cin >> amount;


    if (currency == "dollars"){

        if (currency2 == "rupees"){

            amount2 = amount * 72.51;

            cout << amount << "$ is equal to " << amount2 << "₹\n";

        }else if (currency2 == "pesos"){

            amount2 = amount * 19.95;

            cout << amount << "$ is equal to " << amount2 << "Mex$\n";

        }else if (currency2 == "euros"){

            amount2 = amount * .82;

            cout << amount << "$ is equal to " << amount2 << "€\n";

        }

    }else if (currency == "rupees"){
        
        if (currency2 == "dollars"){

            amount2 = amount * .014;

            cout << amount << "₹ is equal to " << amount2 << "$\n";

        }else if (currency2 == "pesos"){

            amount2 = amount * .28;

            cout << amount << "₹ is equal to " << amount2 << "Mex$\n";

        }else if (currency2 == "euros"){

            amount2 = amount * .011;

            cout << amount << "₹ is equal to " << amount2 << "€\n";

        }

    }else if (currency == "pesos"){

            if (currency2 == "dollars"){

                amount2 = amount * .050;

                cout << amount << " Mex$ is equal to " << amount2 << "$\n";

            }else if (currency2 == "rupees"){

                amount2 = amount * 3.64;

                cout << amount << " Mex$ is equal to " << amount2 << "₹\n";

            }else if (currency2 == "euros"){

                amount2 = amount * .041;

                cout << amount << "Mex$ is equal to " << amount2 << "€\n";

            }

    }else if (currency == "euros"){

        if (currency2 == "dollars"){

            amount2 = amount * 1.22;

            cout << amount << "€ is equal to " << amount2 << "$\n";

        }else if (currency2 == "pesos"){

            amount2 = amount * 24.39;

            cout << amount << "€ is equal to " << amount2 << "Mex$\n";

        }else if (currency2 == "rupees"){

            amount2 = amount * 88.68;

            cout << amount << "€ is equal to " << amount2 << "₹\n";

        }

    }else{

        cout << "Invalid entry. (check spelling!)\n";

    }

}
