
#include <iostream>
#include <stdexcept> // For exception handling

class DigitCalculator {
public:
    // Function to compute X + XX + XXX + XXXX
    int calculatePatternSum(int X) {
        if (X < 0 || X > 9) {
            throw std::invalid_argument("Error: Input must be a single decimal digit (0-9).");
        }


        return X*(1+11+111+1111);
    }
};

int main() {
    DigitCalculator calculator;
    int X;

    std::cout << "Enter a decimal digit (0-9): ";
    std::cin >> X;

    try {
        int result = calculator.calculatePatternSum(X);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
