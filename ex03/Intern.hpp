#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();

        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& formName, const std::string& target) const;

    private:
        typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

        AForm* createShrubbery(const std::string& target) const;
        AForm* createRobotomy(const std::string& target) const;
        AForm* createPardon(const std::string& target) const;
};

#endif