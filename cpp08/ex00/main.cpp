/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:39:45 by eakman            #+#    #+#             */
/*   Updated: 2025/05/29 18:39:45 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(55);
    vec.push_back(5);
    vec.push_back(7);

    try {
        std::vector<int>::const_iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(vec, 42); // Not found
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
