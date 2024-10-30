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

// main.cpp
#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("JhonnyLash");

    clap.attack("Enemy1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.attack("Enemy2");
    clap.takeDamage(10);
    clap.beRepaired(5);

    return 0;
}
