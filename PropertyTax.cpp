#include <iostream>
using namespace std;

// Function to calculate property tax amount
double CalculatePropertyTax(double houseCost, double propertyTaxRate) {
    return houseCost * propertyTaxRate / 100.0;
}

// Function to calculate annual after-tax cost
double CalculateAfterTaxCost(double houseCost, double propertyTaxRate, double insurancePercentage) {
    double propertyTax = CalculatePropertyTax(houseCost, propertyTaxRate);
    double insuranceCost = houseCost * (insurancePercentage / 100.0);
    return houseCost + propertyTax + insuranceCost;
}

int main() {
    int numberOfHouses = 0;
    double propertyTaxRate, insurancePercentage;

    while (true) {
        double houseCost;

        // Input house cost
        cout << "Enter the cost of the house: $";
        cin >> houseCost;

        // Input property tax rate
        cout << "Enter the property tax rate (%): ";
        cin >> propertyTaxRate;

        // Input insurance percentage
        cout << "Enter the insurance cost percentage (%): ";
        cin >> insurancePercentage;

        // Calculate and display the annual after-tax cost
        double annualAfterTaxCost = CalculateAfterTaxCost(houseCost, propertyTaxRate, insurancePercentage);
        cout << "Annual After-Tax Cost: $" << annualAfterTaxCost << endl;

        numberOfHouses++;

        // Ask if the user wants to calculate for another house
        char choice;
        cout << "Calculate for another house? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break; // Exit the loop if the user doesn't want to calculate for another house
        }
    }

    // Display summary if at least one house was calculated
    if (numberOfHouses > 0) {
        cout << "Summary: Calculated for " << numberOfHouses << " houses." << endl;
    } else {
        cout << "No houses were calculated." << endl;
    }

    return 0;
}
