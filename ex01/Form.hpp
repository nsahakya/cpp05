#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _execute_grade;
    public:
        Form();
        Form(const std::string& name, const int sign_grade, const int execute_grade);
        Form(const Form &other);
        ~Form();

        Form &operator=(const Form &other);

        void beSigned(const Bureaucrat& b);

        std::string getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        class GradeTooHighException : public std::exception
        {
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif