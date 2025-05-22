/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:11:30 by eakman            #+#    #+#             */
/*   Updated: 2025/05/08 23:11:30 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Canonical Form

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("DefaultTarget") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute function

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);  // Check signed and grade

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << target << "_shrubbery" << std::endl;
        return;
    }

    file <<
        "      /\\\n"
        "     /  \\\n"
        "    /++++\\\n"
        "   /  ()  \\\n"
        "  /--------\\\n"
        "      ||\n"
        "      ||\n";

    file.close();
    std::cout << "ShrubberyCreationForm: Tree has been planted in " << target << "_shrubbery" << std::endl;
}
