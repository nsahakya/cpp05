#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("Name"), _signed(false), _sign_grade(75), _execute_grade(75) {}

Form::Form(const std::string& name, const int sign_grade, const int execute_grade) : _name(name), _signed(false), 
            _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (this->_sign_grade < 1 || this->_execute_grade < 1)
        throw Form::GradeTooHighException();
    if (this->_sign_grade > 150 || this->_execute_grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), 
                                _execute_grade(other._execute_grade) {}

Form::~Form() {}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _signed = other._signed;
        return *this;
    }
    return *this;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _sign_grade)
        _signed = true;
    else
        throw Form::GradeTooLowException();
}

std::string Form::getName() const {return this->_name;}

bool Form::getSigned() const {return this->_signed;}

int Form::getSignGrade() const {return this->_sign_grade;}

int Form::getExecuteGrade() const {return this->_execute_grade;}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}


std::ostream& operator<<(std::ostream &out, const Form &f)
{
    return out
           << f.getName() << (f.getSigned() ? ", already signed" : ", isn't signed")
           << ", required to sign " << f.getSignGrade()
           << ", required to execute " << f.getExecuteGrade() << ".";
}

