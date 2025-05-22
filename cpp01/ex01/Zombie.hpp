/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:45:10 by eakman            #+#    #+#             */
/*   Updated: 2024/08/10 19:45:10 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
   private:
        std::string name;
    public:
        void announce(void);
        ~Zombie(void);
        void setName(std::string);
};

Zombie* zombieHorde(int N, std::string name);

#endif