/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:15:15 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 14:15:16 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

// Implementation using a general template for the function type.
// This allows passing functions, function objects, or instantiated function templates
// that accept the element type (by value, reference, or const reference).

template <typename T, typename F>
void iter(T *array, size_t length, F func) {
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

// Note: If strict function pointers were required, we would need overloads:
// template <typename T> void iter(T *arr, size_t len, void (*f)(T &));
// template <typename T> void iter(const T *arr, size_t len, void (*f)(const T &));
// But the subject mentions "instantiated function template" which works naturally with typename F.

#endif
