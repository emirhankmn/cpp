/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:18:19 by eakman            #+#    #+#             */
/*   Updated: 2024/11/02 00:18:19 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &oyher);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif