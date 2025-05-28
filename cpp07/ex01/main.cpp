/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:25:22 by eakman            #+#    #+#             */
/*   Updated: 2025/05/27 19:25:22 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Her eleman için çalışacak fonksiyon
template<typename T>
void print(T &x) {
    std::cout << x << " ";
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    std::string arr2[] = {"apple", "banana", "cherry"};

    std::cout << "Int array: ";
    ::iter(arr1, 5, print);
    std::cout << std::endl;

    std::cout << "String array: ";
    ::iter(arr2, 3, print);
    std::cout << std::endl;

    return 0;
}
