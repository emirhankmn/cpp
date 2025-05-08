/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:09:56 by eakman            #+#    #+#             */
/*   Updated: 2025/05/08 23:09:56 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Canonical Form

AForm::AForm()
    : name("DefaultForm"), isSigned(false), gradeToSign(75), gradeToExecute(75) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
        // name, gradeToSign, gradeToExecute const olduğu için atanamaz
    }
    return *this;
}

AForm::~AForm() {}

// Getters

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

// Functions

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exceptions

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form is not signed!";
}

// Protected: checkExecution

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

// Operator overload

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form '" << f.getName()
       << "', signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
