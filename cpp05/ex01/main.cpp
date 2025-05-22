/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:46:36 by eakman            #+#    #+#             */
/*   Updated: 2025/01/22 02:46:36 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Bureaucrat and Form Tests ===" << std::endl;

    try{
        Bureaucrat a("a", 19);
        std::cout << a << std::endl;
        Form b("b", 20, 30);
        std::cout << b << std::endl;
        Form c("c", 18, 20);
        std::cout << c << std::endl;
        a.signForm(b);
        std::cout << b << std::endl;
        a.signForm(c);
        std::cout << c << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        Form contract("Contract", 40, 30);
        Form permit("Permit", 50, 20);

        std::cout << contract << std::endl;
        std::cout << permit << std::endl;

        john.signForm(contract);

        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        john.signForm(contract);
        std::cout << contract << std::endl;

        john.signForm(contract);

        Bureaucrat jane("Jane", 30);
        std::cout << jane << std::endl;

        jane.signForm(permit);
        std::cout << permit << std::endl;

        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;

        alice.signForm(contract);
        alice.signForm(permit);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Bureaucrat and Form Tests ===" << std::endl;

    // Test invalid Bureaucrat creation
    try {
        Bureaucrat invalidHigh("InvalidHigh", 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidLow("InvalidLow", 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Test invalid Form creation
    try {
        Form invalidForm1("InvalidForm1", 0, 30);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("InvalidForm2", 40, 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Boundary Tests ===" << std::endl;

    try {
        // Create a Bureaucrat at grade 1 (highest possible grade)
        Bureaucrat topBureaucrat("TopBureaucrat", 1);
        std::cout << topBureaucrat << std::endl;

        // Create a Form that requires grade 1 to sign
        Form topForm("TopForm", 1, 1);
        std::cout << topForm << std::endl;

        topBureaucrat.signForm(topForm);
        std::cout << topForm << std::endl;

        // Create a Bureaucrat at grade 150 (lowest possible grade)
        Bureaucrat lowBureaucrat("LowBureaucrat", 150);
        std::cout << lowBureaucrat << std::endl;

        // Create a Form that requires grade 150 to sign
        Form lowForm("LowForm", 150, 150);
        std::cout << lowForm << std::endl;

        lowBureaucrat.signForm(lowForm);
        std::cout << lowForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
