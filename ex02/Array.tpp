/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:16:01 by albbermu          #+#    #+#             */
/*   Updated: 2026/01/27 14:16:04 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(new T[0]()), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(0) {
    if (other._size > 0) {
        this->_elements = new T[other._size]();
        for (unsigned int i = 0; i < other._size; i++) {
            this->_elements[i] = other._elements[i];
        }
    } else {
        this->_elements = new T[0]();
    }
    this->_size = other._size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] this->_elements;
        if (other._size > 0) {
            this->_elements = new T[other._size]();
            for (unsigned int i = 0; i < other._size; i++) {
                this->_elements[i] = other._elements[i];
            }
        } else {
            this->_elements = new T[0]();
        }
        this->_size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] this->_elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->_size) {
        throw OutOfBoundsException();
    }
    return this->_elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= this->_size) {
        throw OutOfBoundsException();
    }
    return this->_elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->_size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Index out of bounds";
}

#endif
