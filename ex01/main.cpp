/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:15:19 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 14:15:20 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Simple function to print element
template <typename T>
void print(const T &x) {
    std::cout << x << " ";
}

// Function to increment element
template <typename T>
void increment(T &x) {
    x++;
}

int main() {
    std::cout << "Test 1: Integer array with increment" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(int);

    std::cout << "Original: ";
    ::iter(arr, len, print);
    std::cout << std::endl;

    ::iter(arr, len, increment);

    std::cout << "Modified: ";
    ::iter(arr, len, print<int>);
    std::cout << std::endl << std::endl;

    std::cout << "Test 2: Const Integer array" << std::endl;
    const int const_arr[] = {10, 20, 30};
    size_t const_len = sizeof(const_arr) / sizeof(int);

    std::cout << "Values: ";
    ::iter(const_arr, const_len, print);
    std::cout << std::endl << std::endl;

    std::cout << "Test 3: String array" << std::endl;
    std::string str_arr[] = {"Hello", "World", "42"};
    size_t str_len = 3;

    std::cout << "Strings: ";
    ::iter(str_arr, str_len, print);
    std::cout << std::endl;

    return 0;
}
