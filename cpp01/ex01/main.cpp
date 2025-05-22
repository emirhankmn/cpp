/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:46:32 by eakman            #+#    #+#             */
/*   Updated: 2024/08/10 19:46:32 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int getimput(void) {
    int N;
    std::cout << "Enter the number of zombies: ";
    std::cin >> N;
    return N;
}

int main(void) {
    std::cout << "Welcome to the Zombie Horde!" << std::endl;
    int a = getimput();
    Zombie* zombie = zombieHorde(a, "Zombie");
    for (int i = 0; i < a; i++) {
        zombie[i].announce();
    }
    delete[] zombie;
    return 0;
}