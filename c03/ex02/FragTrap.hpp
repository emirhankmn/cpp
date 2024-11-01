/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:13:47 by eakman            #+#    #+#             */
/*   Updated: 2024/10/24 07:13:47 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Constructors and Destructor
    FragTrap();                             // Default constructor
    FragTrap(const std::string& name);      // Parameterized constructor
    FragTrap(const FragTrap& other);        // Copy constructor
    FragTrap& operator=(const FragTrap& other); // Copy assignment operator
    ~FragTrap();                            // Destructor

    // Member functions
    void attack(const std::string& target); // Overridden attack function
    void highFivesGuys();                   // New function for High Five request
};

#endif
