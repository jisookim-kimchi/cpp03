/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:43:37 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/04 16:16:16 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	virtual ~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap &other);
    explicit FragTrap(const std::string &name);
    void highFivesGuys(void);

private:
    
};
#endif