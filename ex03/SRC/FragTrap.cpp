/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:43:22 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/02 13:46:41 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/FragTrap.hpp"
#include <iostream>


FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30)
{
    std::cout << "FragTrap " << _name << " constructor" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " Default destructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy Constructor" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap " << this->_name << " HP : " << _hitPoints << " MP : " << _energyPoints << " attackDamage : " << _attackDamage << " created" << std::endl; 
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << "okay! HighFive !" << std::endl;
}
