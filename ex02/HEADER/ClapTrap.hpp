/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:46:00 by jisokim2          #+#    #+#             */
/*   Updated: 2026/03/01 18:22:48 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
    
public:
	ClapTrap();
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);
    explicit ClapTrap(const std::string &name);
    ClapTrap(std::string name, unsigned int hp, unsigned int mp, unsigned int attackDamage);

    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    void set_name(const std::string &name);
    void set_hp(int hp);
    void set_mp(int mp);
    void set_attackDamage(int attackDamage);

protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

};	

#endif