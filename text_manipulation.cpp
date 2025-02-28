#include <iostream>

class FibonacciCalculator {
private:
    // Function to compute the sum of the first N even Fibonacci numbers
    long long calculateEvenFibonacciSum(int n) {
        long long sum = 0;
        long long a = 2, b = 8; // First two even Fibonacci numbers
        int count = 0;

        while (count < n) {
            sum += a;
            long long nextEvenFib = 4 * b + a; // Formula for even Fibonacci numbers
            a = b;
            b = nextEvenFib;
            count++;
        }
        return sum;
    }

public:
    void run() {
        int n = 100; // First 100 even Fibonacci numbers
        std::cout << "Sum of the first " << n << " even Fibonacci numbers: " 
                  << calculateEvenFibonacciSum(n) << std::endl;
    }
};

int main() {
    FibonacciCalculator calculator;
    calculator.run();
    return 0;
}
