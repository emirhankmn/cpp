/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 04:29:08 by eakman            #+#    #+#             */
/*   Updated: 2025/01/22 04:29:08 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Default Constructor
Form::Form() : name("Unnamed"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

// Parameterized Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other) 
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// Copy Assignment Operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

// Be Signed
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (isSigned)
        throw std::runtime_error("Form is already signed.");
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exception Messages
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Overload <<
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName()
       << " (Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute()
       << ")";
    return os;
}

