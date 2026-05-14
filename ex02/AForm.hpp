#ifndef AForm_HPP
#define AForm_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _execute_grade;
    public:
        AForm();
        AForm(const std::string& name, const int sign_grade, const int execute_grade);
        AForm(const AForm &other);
        ~AForm();

        AForm &operator=(const AForm &other);

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

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif