/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:59:44 by eakman            #+#    #+#             */
/*   Updated: 2024/10/23 17:59:44 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    
    ClapTrap robot1("Clappy");
    ClapTrap robot2("Trappy");

    // Başlangıç durumu
    std::cout << "\n--- Beginning situation ---\n";
    robot1.attack("enemy");        
    robot1.takeDamage(3);   
    robot1.beRepaired(5);

    // Enerji puanlarının tükenmesi testi
    std::cout << "\n--- Energy Depletion Test ---\n";
    for (int i = 0; i < 10; ++i) {
        robot1.attack("enemy");
    }

    // Can puanı tükenmesi testi
    std::cout << "\n--- Life Exhaustion Test ---\n";
    robot1.takeDamage(15);
    robot1.attack("enemy");
    robot1.beRepaired(10);

    
    std::cout << "\n--- Copy Constructar Test ---\n";
    ClapTrap robot3(robot1);

    // Kopya atama operatörü testi
    std::cout << "\n--- Copy Assigment Test ---\n";
    robot2 = robot1;

    return 0;
}


