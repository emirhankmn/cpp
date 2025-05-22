/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:00:33 by eakman            #+#    #+#             */
/*   Updated: 2025/05/22 13:00:33 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate() {
    std::srand(std::time(NULL));
    int random = std::rand() % 3;

    if (random == 0) {
        std::cout << "[Generated] A\n";
        return new A;
    } else if (random == 1) {
        std::cout << "[Generated] B\n";
        return new B;
    } else {
        std::cout << "[Generated] C\n";
        return new C;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Identified via pointer: A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified via pointer: B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified via pointer: C\n";
    else
        std::cout << "Identified via pointer: Unknown\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified via reference: A\n";
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified via reference: B\n";
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified via reference: C\n";
    } catch (std::bad_cast&) {}
}
