/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:25:54 by eakman            #+#    #+#             */
/*   Updated: 2025/01/21 22:25:54 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Canonical Form ===" << std::endl;

    // Default constructor test
    Bureaucrat defaultBureaucrat;
    std::cout << "Default Bureaucrat: " << defaultBureaucrat << std::endl;
    
    std::cout << std::endl;
    // Parameterized constructor test
    try {
        Bureaucrat john("John", 50);
        std::cout << "Parameterized Bureaucrat: " << john << std::endl;
        
        // Increment and decrement tests
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;
        
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Copy constructor test
    try {
        Bureaucrat jane("Jane", 100);
        Bureaucrat copyOfJane(jane); // Copy constructor
        std::cout << "Original Bureaucrat: " << jane << std::endl;
        std::cout << "Copied Bureaucrat: " << copyOfJane << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    // Copy assignment operator test
    try {
        Bureaucrat bob("Bob", 120);
        Bureaucrat assignedBureaucrat;
        assignedBureaucrat = bob;
        std::cout << "Original Bureaucrat: " << bob << std::endl;
        std::cout << "Assigned Bureaucrat: " << assignedBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "=== Testing Exception Handling ===" << std::endl;
    
    std::cout << std::endl;
    // GradeTooHighException test
    try {
        Bureaucrat tooHigh("TooHigh", 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    // GradeTooLowException test
    try {
        Bureaucrat tooLow("TooLow", 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "=== Testing Increment/Decrement Exceptions ===" << std::endl;
    
    std::cout << std::endl;
    try{
        Bureaucrat test("Test", 1);
        test.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    try{
        Bureaucrat test("Test", 150);
        test.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    try {
        Bureaucrat a("A", 50);
        Bureaucrat b("B", 0);
        Bureaucrat c("C", 151);
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Low: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "High: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Other: " << e.what() << std::endl;
    }

    return 0;
}
