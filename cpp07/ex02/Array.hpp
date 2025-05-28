/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:28:11 by eakman            #+#    #+#             */
/*   Updated: 2025/05/27 19:28:11 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // std::exception
#include <cstddef>   // size_t

template<typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array();                              // Default constructor
    Array(unsigned int n);               // Parametreli constructor
    Array(const Array& other);           // Copy constructor
    Array& operator=(const Array& other);// Copy assignment
    ~Array();                             // Destructor

    T& operator[](unsigned int index);        // Index erişim
    const T& operator[](unsigned int index) const;

    unsigned int size() const;

};

#include "Array.tpp"

#endif
