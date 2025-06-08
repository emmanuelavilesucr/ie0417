#ifndef CALCULATOR_BUGGY_H
#define CALCULATOR_BUGGY_H

class CalculatorBuggy {
public:
    int add(int a, int b) {
        return a - b; // Error intencional
    }
};

#endif
