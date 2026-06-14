#include <exception>
#include "Bureaucrat.hpp"

int main()
{
    try //too low error
    {
        Bureaucrat a("Narek", 151);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try //no error
    {
        Bureaucrat a("Narek", 100);
        std::cout << a << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try //too high error
    {
        Bureaucrat a("Narek", 0);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try  //too low error
    {
        Bureaucrat a("Narek", 150);
        try
        {
            a.decrementGrade();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << a << std::endl;

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try  //too high
    {
        Bureaucrat a("Narek", 1);
        try
        {
            a.incrementGrade();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << a << std::endl;

    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}