#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("Name"), _signed(false), _sign_grade(75), _execute_grade(75) {}

AForm::AForm(const std::string& name, const int sign_grade, const int execute_grade) : _name(name), _signed(false), 
            _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (this->_sign_grade < 1 || this->_execute_grade < 1)
        throw AForm::GradeTooHighException();
    if (this->_sign_grade > 150 || this->_execute_grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), 
                                _execute_grade(other._execute_grade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _signed = other._signed;
        return *this;
    }
    return *this;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _sign_grade)
        _signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::string AForm::getName() const {return this->_name;}

bool AForm::getSigned() const {return this->_signed;}

int AForm::getSignGrade() const {return this->_sign_grade;}

int AForm::getExecuteGrade() const {return this->_execute_grade;}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low";
}


std::ostream& operator<<(std::ostream &out, const AForm &f)
{
    return out
           << f.getName() << (f.getSigned() ? ", already signed" : ", isn't signed")
           << ", required to sign " << f.getSignGrade()
           << ", required to execute " << f.getExecuteGrade() << ".";
}

