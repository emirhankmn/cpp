/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:00:38 by eakman            #+#    #+#             */
/*   Updated: 2025/05/09 01:00:38 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Canonical form

Intern::Intern() {
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destroyed" << std::endl;
}

// MakeForm method

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[3] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string& target) = {
        &Intern::createRobotomy,
        &Intern::createShrubbery,
        &Intern::createPardon
    };    

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Error: Form type not found" << std::endl;
    return NULL;
}

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

