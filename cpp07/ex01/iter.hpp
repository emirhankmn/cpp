/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:23:18 by eakman            #+#    #+#             */
/*   Updated: 2025/05/27 19:23:18 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t için

template<typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif
