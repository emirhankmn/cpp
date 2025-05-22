/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:47:09 by eakman            #+#    #+#             */
/*   Updated: 2024/11/01 18:47:09 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WrongCat.hpp
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();                            // Varsayılan kurucu
    WrongCat(const WrongCat& other);       // Kopya kurucu
    WrongCat& operator=(const WrongCat& other); // Kopya atama operatörü
    ~WrongCat();                           // Yıkıcı

    void makeSound() const; // Bu işlev virtual değil, bu yüzden polymorphism çalışmayacak
};

#endif

