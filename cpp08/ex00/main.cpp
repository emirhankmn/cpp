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
#include <list>
#include <deque>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(55);
    vec.push_back(5);
    vec.push_back(7);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(55);
    lst.push_back(5);
    lst.push_back(7);

    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(3);
    deq.push_back(55);
    deq.push_back(5);
    deq.push_back(7);

    std::cout << "Testing with vector:" << std::endl;
    try {
        std::vector<int>::const_iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Testing with list:" << std::endl;
    try {
        std::list<int>::const_iterator it = easyfind(lst, 55);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Testing with deque:" << std::endl;
    try {
        std::deque<int>::const_iterator it = easyfind(deq, 7);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        easyfind(vec, 42); // Not found
    } catch (std::exception& e) {
        std::cerr << e.what() << "(vector)" << std::endl;
    }

    try {
        easyfind(lst, 42); // Not found
    } catch (std::exception& e) {
        std::cerr << e.what() << "(list)" << std::endl;
    }
    try {
        easyfind(deq, 42); // Not found
    } catch (std::exception& e) {
        std::cerr << e.what() << "(deque)" << std::endl;
    }

    return 0;
}
