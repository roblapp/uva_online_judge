#include <iostream>
/*
Accepted: 0.000s
Description: ad hoc
*/

#define MAXLEN 100
using namespace std;

int main() {
    int i, loanLength, nRecords, monthNum;
    double paymentAmount, loanAmount, depreciationValue, carValue, amountOwed, prev;
    double depValues[MAXLEN + 1];
    bool solved;
    while (1) {
        cin >> loanLength >> paymentAmount >> loanAmount >> nRecords;
        if (loanLength < 0) break;
        for (i = 0; i <= MAXLEN; i++) depValues[i] = -1.0;
        carValue = paymentAmount + loanAmount;
        amountOwed = loanAmount;
        for (i = 0; i < nRecords; i++) {
            cin >> monthNum >> depreciationValue;
            depValues[monthNum] = (1.0 - depreciationValue);
        }
        solved = false;
        monthNum = -1;
        paymentAmount = loanAmount / loanLength;
        for (i = 0; !solved and i <= loanLength; i++) {
            monthNum++;
            if (depValues[i] != -1.0) prev = depValues[i];
            carValue = carValue*prev;
            if (carValue > amountOwed) solved = true;
            else amountOwed -= paymentAmount;
        }
        if (solved) (monthNum == 1) ? cout << "1 month" << endl : cout << monthNum << " months" << endl;
    }
    return 0;
}
