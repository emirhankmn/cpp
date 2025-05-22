/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:16:15 by eakman            #+#    #+#             */
/*   Updated: 2024/10/24 07:16:15 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap frag("Warrior");
    frag.attack("enemy");
    frag.highFivesGuys();
    frag.takeDamage(30);
    frag.beRepaired(20);
    for (int i = 0; i < 10; ++i) {
        frag.attack("another enemy");
    }
    frag.takeDamage(100);
    frag.beRepaired(50);

    return 0;
}

