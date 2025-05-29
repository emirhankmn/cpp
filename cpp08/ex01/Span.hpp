/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:08:18 by eakman            #+#    #+#             */
/*   Updated: 2025/05/29 19:08:18 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {
public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template<typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Too many elements to add.");
        _numbers.insert(_numbers.end(), begin, end);
    }

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#endif
