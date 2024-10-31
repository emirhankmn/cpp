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

// main.cpp
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // ClapTrap'i test ediyoruz
    ClapTrap clap("Robot1");
    clap.attack("Enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // FragTrap'i test ediyoruz
    FragTrap frag("FighterBot");
    frag.attack("Enemy3");
    frag.takeDamage(15);
    frag.beRepaired(5);
    frag.highFivesGuys();  // Özel FragTrap fonksiyonunu çağırıyoruz

    return 0;
}
