/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:47:06 by eakman            #+#    #+#             */
/*   Updated: 2024/10/23 17:47:06 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ClapTrap.hpp
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string name;  // Sınıfın adı
    unsigned int hitPoints;   // Vuruş puanları
    unsigned int energyPoints; // Enerji puanları
    unsigned int attackDamage; // Saldırı hasarı

public:
    ClapTrap(std::string name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
