/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:34:57 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/02 13:47:17 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("defualt", 100, 50, 20), _isGateKeeperMode(false)
{
    std::cout << "ScavTrap " << _name << " constructor" << std::endl; 
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20), _isGateKeeperMode(false)
{
    std::cout << "ScavTrap " << this->_name << " HP : " << _hitPoints << " MP : " << _energyPoints << " attackDamage : " << _attackDamage << " created" << std::endl; 
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " Default destructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _isGateKeeperMode(other._isGateKeeperMode)
{
    std::cout << "ScavTrap Copy Constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_isGateKeeperMode = other._isGateKeeperMode;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    this->_isGateKeeperMode = true;
    std::cout << "ScavTrap " << this->_name << " in Gate keeper mode" << std::endl;
}
