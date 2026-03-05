/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:55:44 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/01 18:20:25 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor" << std::endl; 
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Default destructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap Copy Constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(std::string const &target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead can't attack" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energyPoints can't attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attack " << target << " casuing " << _attackDamage << " points of damage!"<< std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{  
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
        return;
    }

    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
         std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " critical damage! hitPoints left: "
              << _hitPoints << std::endl;
    }
    else
    {
        _hitPoints -= amount;
          std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " damage! hitPoints left: "
              << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead can't beRepaired" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " no energyPoints can't beReapired" << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "Claptrap " << _name << " beRepaired " << amount << std::endl;
    std::cout << "energyPoints : " << _energyPoints << std::endl;    
}

