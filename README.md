# Lab 7: Maps

## Overview
Lab 7 is a comprehensive C++ project focused on demonstrating the practical use of the Standard Template Library's (STL) map data structure. Through manipulating and visualizing state demographic data stored in CSV files, this lab showcases the power of maps in organizing and accessing structured data efficiently.

## Repository Structure
- **main.cpp**: The core application file showcasing operations like generating random numbers and managing state demographic data using STL maps.
- **main.h**: Header file for main.cpp, potentially used for function declarations.
- **states.csv**: A CSV file containing demographic data for various states, including information on per capita income, population, median household income, and the number of households.
- **Lab 7.pdf**: Provides documentation and guidelines for the lab, including objectives and detailed instructions.

## Features
- **Random Number Generation**: Demonstrates how to generate random numbers within a specified range, showcasing basic usage of the `<random>` library in C++.
- **State Demographic Data Management**: Utilizes STL maps to load, store, and query demographic information from a CSV file (states.csv), illustrating efficient data handling and access patterns.
- **Custom Class States**: Defines a States class to encapsulate state demographic data, offering methods to access state information, including population, income, and household data.
- **Interactive Menu**: Presents an interactive command-line menu allowing users to choose between generating random numbers and querying state demographic data.

## Usage
To run Lab 7:
1. **Compile the C++ Code**: Use a compatible C++ compiler supporting C++11 or later.
2. **Execute the Program**: Run the compiled application, and use the interactive menu to explore the functionalities offered.

## Key Functionalities
```
// Generate random numbers within a specified range
int Random(int min, int max);

// Load state data from CSV and store it in a map
void LoadStateData(const std::string& filename);

// Display state demographic data
void DisplayStateData(const std::map<std::string, States>& stateMap);
```
## Conclusion
Lab 7: Maps provides a hands-on experience with the C++ STL map data structure, emphasizing its application in real-world data handling scenarios. Through interactive examples and practical data manipulation, users can appreciate the utility and efficiency of maps in software development.

## Acknowledgments
This project was developed as part of a C++ programming course, focusing on data structures and algorithms. Special thanks to the course instructors and contributors for their guidance and support.
