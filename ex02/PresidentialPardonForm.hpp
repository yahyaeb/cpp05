/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:38 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 16:57:25 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream.hpp>

class PresidentialPardonForm : public AForm
{	
	private:
		std::string _target;
		virtual void	performAction() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(int _grade, int _exec);
		PresidentialPardonForm(const ShrubberyCreationForm& other);
		PresidentialPardonForm& operator=(const ShrubberyCreationForm& other);
		~PresidentialPardonForm();
	
		class OpenFileException : std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
