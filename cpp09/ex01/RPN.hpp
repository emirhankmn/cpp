/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:18:46 by eakman            #+#    #+#             */
/*   Updated: 2025/06/17 00:18:46 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN
{
private:
    std::stack<int> _stack;
    
    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    int performOperation(int a, int b, const std::string& op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int calculate(const std::string& expression);
};

#endif