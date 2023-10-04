#include <iostream>

// Function to compute the discrete logarithm using brute force
int computeDiscreteLog(int base, int modulo, int target)
{
    int result = 1;
    int discreteLog = 0;
    while (result != target)
    {
        result = (result * base) % modulo;
        discreteLog++;
    }
    return discreteLog;
}

int main()
{
    char choice;
    do
    {
        int base, modulo, target;

        // Input the base, modulo, and target number
        std::cout << "Enter base: ";
        std::cin >> base;

        std::cout << "Enter modulo: ";
        std::cin >> modulo;

        std::cout << "Enter target number: ";
        std::cin >> target;

        // Compute the discrete logarithm
        int discreteLog = computeDiscreteLog(base, modulo, target);

        // Output the result
        std::cout << "Discrete logarithm of " << target << " (base " << base << " modulo " << modulo << ") is " << discreteLog << std::endl;

        // Ask the user if they want to continue
        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
