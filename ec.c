#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STEP1 10.95

int main (void) {
    printf ("enter first 10.95 mw/H price: ");
    double firstStep;
    scanf ("%lf", &firstStep);

    printf ("enter second 10.95 mw/H price: ");
    double secondStep;
    scanf ("%lf", &secondStep);

    printf ("other rate after: ");
    double restStep;
    scanf ("%lf", &restStep);

    printf ("enter daily service charge: ");
    double serviceCharge;
    scanf ("%lf", &serviceCharge);

    printf ("enter daily average mw/h: ");
    double mwh;
    scanf ("%lf", &mwh);

    printf ("enter days: ");
    int totalDays;
    scanf ("%d", &totalDays);

    char cc;
    int boolean;
    printf ("CC? [1/0]: ");
    scanf ("%d", &boolean);
    if (boolean == 1) {
        cc = 'y';
    } else {
        cc = 'n';
    }
    assert (cc == 'y' || cc == 'n');

    double firstStepAmount = 0;
    double secondStepAmount = 0;
    double thirdStepAmount = 0;
    if (mwh <= STEP1) { 
        firstStepAmount = mwh;
    } else if (mwh <= STEP1 * 2) {
        firstStepAmount = STEP1;
        secondStepAmount = mwh - STEP1;
        thirdStepAmount = 0;
    } else if (mwh > STEP1 * 2) {
        firstStepAmount = STEP1;
        secondStepAmount = STEP1;
        thirdStepAmount = mwh - 2 * STEP1;
        assert (thirdStepAmount >= 0);
    } else {
        assert (0);
    }

    double total = (firstStepAmount * firstStep);
    total += (secondStepAmount * secondStep);
    total += (thirdStepAmount * restStep);
    total += serviceCharge;
    // CC surcharge?
    if (cc == 'y') {
        total = total * 1.01; // 1% CC
    }

    // Multiply by days in billing period
    total = total * totalDays;

    // Divide by 100 cents per dollar
    total = total / 100;

    printf ("GRAND TOTAL: %lf\n", total);

    return EXIT_SUCCESS;
}
