/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:19:06 by eakman            #+#    #+#             */
/*   Updated: 2025/06/17 00:19:06 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token)
{
    if (token.empty())
        return false;
    
    for (size_t i = 0; i < token.length(); i++)
    {
        if (!isdigit(token[i]))
            return false;
    }
    
    int num = atoi(token.c_str());
    return num < 10;
}

int RPN::performOperation(int a, int b, const std::string& op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator");
}

int RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (isNumber(token))
        {
            _stack.push(atoi(token.c_str()));
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Invalid expression");
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            int result = performOperation(a, b, token);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Invalid token");
        }
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    
    return _stack.top();
}