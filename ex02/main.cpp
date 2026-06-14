#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 100);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << shrub << std::endl;
    boss.signForm(shrub);
    boss.executeForm(shrub);

    worker.signForm(robot);
    boss.signForm(robot);
    worker.executeForm(robot);
    boss.executeForm(robot);

    intern.signForm(pardon);
    boss.signForm(pardon);
    intern.executeForm(pardon);
    boss.executeForm(pardon);

    return 0;
}