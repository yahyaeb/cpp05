/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:34 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 17:01:24 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Param constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5, target)
{}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other)
{}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{}

// Action function
void PresidentialPardonForm::performAction() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
