// Tutorial 023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Get height from user
double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double towerHeight{};
    std::cin >> towerHeight; 
    return towerHeight;
}

// Return height from ground after amount of seconds 
double calculateHeight(double towerHeight, int seconds)
{
    constexpr double gravity{ 9.8 };

    // Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
    const double distanceFallen{ (gravity * (seconds * seconds)) / 2.0 }; 
    const double currentHeight{ towerHeight - distanceFallen }; 

    return currentHeight; 
}

// Prints every seconds until ball has reached the ground 
void printHeight(double height, int seconds)
{
    if (height > 0.0)
        std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is on the ground"; 
}

void calculateAndPrintHeight(double towerHeight, int seconds)
{
    const double height{ calculateHeight(towerHeight, seconds) }; 
    printHeight(height, seconds); 
}
    

int main()
{
    const double towerHeight{ getTowerHeight() }; 

    calculateAndPrintHeight(towerHeight, 0); 
    calculateAndPrintHeight(towerHeight, 1);
    calculateAndPrintHeight(towerHeight, 2);
    calculateAndPrintHeight(towerHeight, 3);
    calculateAndPrintHeight(towerHeight, 4); 
    calculateAndPrintHeight(towerHeight, 5);

    return 0; 
}

