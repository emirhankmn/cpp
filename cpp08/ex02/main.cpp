/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:55:49 by eakman            #+#    #+#             */
/*   Updated: 2025/05/29 19:55:49 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    MutantStack<std::string> mstack2;
    mstack2.push("Hello");
    mstack2.push("World");
    mstack2.push("!");
    mstack2.push("MutantStack");

    std::cout << "Size: " << mstack.size() << std::endl;

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;


    std::cout << "Elements in mstack2:" << std::endl;
    for (MutantStack<std::string>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
        std::cout << *it << std::endl;
    
    
    return 0;
}
