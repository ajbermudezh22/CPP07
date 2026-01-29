/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:15:43 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/29 11:46:44 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "--- Test 1: Simple Type (int) & Deep Copy ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
    // Fill both arrays
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // Check deep copy (Scope block)
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    } // tmp and test are destroyed here. If deep copy failed, numbers would be corrupted.

    // Verify values match
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Data verification successful! Deep copy works." << std::endl;

    // Test Exceptions
    std::cout << "\n--- Test 2: Out of Bounds Exceptions ---" << std::endl;
    
    std::cout << "1. Testing negative index [-2]: ";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "2. Testing index too high [MAX_VAL]: ";
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    // Cleanup for int test
    delete [] mirror;


    // Complex Type Test
    std::cout << "\n--- Test 3: Complex Type (std::string) ---" << std::endl;
    
    Array<std::string> strings(3);
    
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "42";
    
    std::cout << "Original String Array:" << std::endl;
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << "[" << i << "] " << strings[i] << std::endl;
    }

    // Test modification of copy
    std::cout << "\nTesting Deep Copy with Strings:" << std::endl;
    Array<std::string> copyStrings = strings;
    copyStrings[0] = "Modified";
    
    std::cout << "Original[0]: " << strings[0] << " (Expected: Hello)" << std::endl;
    std::cout << "Copy[0]:     " << copyStrings[0] << " (Expected: Modified)" << std::endl;

    if (strings[0] == "Hello" && copyStrings[0] == "Modified")
        std::cout << "SUCCESS: Deep copy validated for complex types." << std::endl;
    else
        std::cerr << "FAILURE: Deep copy failed for complex types!" << std::endl;

    return 0;
}
