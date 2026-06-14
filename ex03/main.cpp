#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 100);
    Bureaucrat intern("Intern", 150);

    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    AForm* invalid = someRandomIntern.makeForm("unknown form", "void");

    if (shrub)
    {
        std::cout << *shrub << std::endl;
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
    }

    if (robot)
    {
        worker.signForm(*robot);
        boss.signForm(*robot);
        worker.executeForm(*robot);
        boss.executeForm(*robot);
    }

    if (pardon)
    {
        intern.signForm(*pardon);
        boss.signForm(*pardon);
        intern.executeForm(*pardon);
        boss.executeForm(*pardon);
    }

    delete shrub;
    delete robot;
    delete pardon;
    delete invalid;

    return 0;
}