/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:10:44 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/09/04 16:51:47 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream.io>
#include <string>

class RobotomyRequestForm
{
	private:
		int _grade;
		int _exec;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(int _grade, int _exec);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

			
		class RobotizationFail : std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
}