/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:13:00 by eakman            #+#    #+#             */
/*   Updated: 2025/05/08 23:13:00 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

// Canonical Form

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("DefaultTarget") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute function

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecution(executor);  // Kontroller

    std::cout << "BZZZZT... drilling noises...\n";

    // %50 şans için random sayı
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully\n";
    else
        std::cout << "Robotomy failed on " << target << std::endl;
}
