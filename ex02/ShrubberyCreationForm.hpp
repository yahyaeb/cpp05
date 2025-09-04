/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:50 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 16:47:57 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream.io>
#include <string>

class ShrubberyCreationForm
{	
	private:
		std::string _target;
		virtual void	performAction() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(int _grade, int _exec);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
	
		class OpenFileException : std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};
