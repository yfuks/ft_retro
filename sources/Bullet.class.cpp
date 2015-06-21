// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: spariaud <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/21 17:07:23 by spariaud          #+#    #+#             //
//   Updated: 2015/06/21 17:07:25 by spariaud         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bullet.class.hpp"
#include "Window.class.hpp"
#include <unistd.h>
#include <ncurses.h>

Bullet::Bullet(void) : Sprite("~O", 10, 1), _clock(clock()) {
	this->move();
}

Bullet::Bullet(std::string form, int x, int y) : Sprite(form, x, y), _clock(clock()) {
	this->move();
}

Bullet::Bullet(Bullet & src) : Sprite(src) {
	*this = src;
}

Bullet::~Bullet(void) {

}

Bullet &	Bullet::operator=(Bullet & src) {
	this->_x = src.getX();
	this->_y = src.getY();
	this->_form = src.getForm();
	return *this;
}

void		Bullet::move() {
	if (this->getX() < Window::_x) {
		if (((60) * (clock() - _clock)) / CLOCKS_PER_SEC > 1)
	    {
	    	_clock = clock();
	    	_x++;
    	}
    }
}