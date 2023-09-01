#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

struct CodePoint {
    double interest_Rate;
    double inflation_Rate;
};

int main() {
    // Read data from the CSV file and store it in a vector of DataPoint structs
    CodePoint data[70];
    int index=0;
    ifstream file("spain_data.csv");
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
        
    }

    string line;
    getline(file, line);  // Skip the header line
    while (getline(file, line)) {
        CodePoint dp;
        stringstream ss(line);
        string token;

        // Skip the sequence number and the year
        getline(ss, token, ','); // seq no
        getline(ss, token, ','); // Year

        getline(ss, token, ','); // Interest rate
        dp.interest_Rate = stod(token);
        getline(ss, token, ','); // Inflation rate
        dp.inflation_Rate = stod(token);

        data[index++] = dp;
    
    }
    double investmentAmount;
    int investmentYear,temp;
    int cnt = 0;
    cout << "Enter the investment amount: ";
    cin >> investmentAmount;
    
    // ask user for year of investment
    do {
        cout << "Enter the year of investment (>= 1960 and <= 2022): ";
        cin >> investmentYear;
        cnt++;
        if(cnt == 5) {
            cout << "Attempt exhausted\n";
            return 0;
        }
    } while(investmentYear < 1960 && investmentYear > 2022);

    // print the invested amount
    cout << "The amount of money invested by the user: " << investmentAmount << "\n";


    // variables to calculate amount received after 2022 and value of money using inflation rate
    double amount_received = investmentAmount;
    double value_of_money = investmentAmount;

    while(investmentYear != 2023)
    {   
        if(investmentYear==2002)
        {
            amount_received = amount_received/166.0;
            value_of_money = value_of_money/166.0;
        }
        amount_received+=amount_received*(data[investmentYear-1960].interest_Rate)/100.0;
        value_of_money+=value_of_money*(data[investmentYear-1960].interest_Rate - data[investmentYear-1960].inflation_Rate)/100.0;
        investmentYear++;
    }

    cout << "The amount received after 2022: " << amount_received << "\n";
    cout << "The value of money that is using inflation rate as well: " << value_of_money << "\n";

    double x=5000;
    temp=1960;
    while(temp!=1978)
    {
        x = x*(1.0 + data[temp-1960].inflation_Rate/100.0);
        temp++;
    }
    cout<<"growth rate of dictatorial era: "<<(x-5000)/18000.0<<"%\n";

    x=5000;
    while(temp!=2022)
    {
        x = x*(1.0 + data[temp-1960].inflation_Rate/100.0);
        temp++;
    }
    cout<<"growth rate of monarchy era : "<<(x-5000)/45000.0<<"%\n";

     return 0;
}