/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:01:34 by eakman            #+#    #+#             */
/*   Updated: 2025/05/22 01:01:34 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Base.hpp
#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif

