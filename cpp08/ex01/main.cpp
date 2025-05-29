/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:09:29 by eakman            #+#    #+#             */
/*   Updated: 2025/05/29 19:09:29 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(5);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    Span bigSpan(10000);
    std::vector<int> manyNumbers(10000);
    for (int i = 0; i < 10000; ++i)
        manyNumbers[i] = i * 2;
    bigSpan.addNumber(manyNumbers.begin(), manyNumbers.end());
    std::cout << "Big Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big Longest: " << bigSpan.longestSpan() << std::endl;

    return 0;
}
