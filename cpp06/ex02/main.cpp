/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:04:52 by eakman            #+#    #+#             */
/*   Updated: 2025/05/22 13:04:52 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "Identify.hpp"

int main() {
    Base* obj = generate();     // Rastgele A, B veya C oluştur
    identify(obj);              // Pointer ile tanımla
    identify(*obj);             // Referans ile tanımla

    delete obj;
    return 0;
}
