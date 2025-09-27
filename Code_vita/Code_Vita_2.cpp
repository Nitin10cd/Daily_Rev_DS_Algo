#include <bits/stdc++.h>
using namespace std;

/*
📌 QUESTION:
We need to calculate the EMI for a loan with different interest slabs.

Input:
- Principal amount (P)
- Total number of years
- Number of slabs (n1)

For each slab:
- Period in years
- Interest rate for that period

Output:
- EMI for each slab
- Total EMI sum

📊 Example:
Enter the principal amount and years: 100000 10
Enter the number of slabs: 2

Slab 1:
Enter the period: 5
Enter the rate of interest: 10

Slab 2:
Enter the period: 5
Enter the rate of interest: 12

Output:
Slab 1 EMI: 2124.70
Slab 2 EMI: 2224.45
Total EMI sum: 4349.15
*/

// 📌 EMI Calculation Function
double calculateEMI(double principal, double annualRate, int years) {
    double monthlyRate = annualRate / (12 * 100.0); // annual % → monthly fraction
    int months = years * 12;                        // total months

    // EMI formula: P * r * (1 + r)^n / ((1 + r)^n - 1)
    double emi = principal * monthlyRate * pow(1 + monthlyRate, months) /
                 (pow(1 + monthlyRate, months) - 1);
    return emi;
}

int main() {
    double p;
    int totalYears;
    cout << "Enter the principal amount and total years: ";
    cin >> p >> totalYears;

    int n1;
    cout << "Enter the number of slabs: ";
    cin >> n1;

    double totalEMI = 0;

    for (int i = 0; i < n1; i++) {
        cout << "\n--- Slab " << i + 1 << " ---" << endl;
        int yrs;
        cout << "Enter the period (in years): ";
        cin >> yrs;

        double rate;
        cout << "Enter the annual rate of interest (%): ";
        cin >> rate;

        double emi = calculateEMI(p, rate, yrs);
        totalEMI += emi;

        cout << "Slab " << i + 1 << " EMI: " << fixed << setprecision(2) << emi << endl;
    }

    cout << "\n📊 Total EMI sum across all slabs: " << fixed << setprecision(2) << totalEMI << endl;

    return 0;
}
