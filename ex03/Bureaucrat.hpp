#ifndef BUREACRAT_HPP
#define BUREACRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const std::string& name);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat& other);
        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& form);
        void executeForm(AForm const & form) const;
        class GradeTooHighException : public std::exception
        {
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif