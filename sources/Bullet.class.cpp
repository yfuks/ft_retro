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
#include "Penis.class.hpp"
#include <unistd.h>
#include <ncurses.h>

Bullet::Bullet(void) : Sprite("~O", 10, 1), _clock(clock()), _id(0) {
	this->move();
}

Bullet::Bullet(std::string form, int x, int y, int id) : Sprite(form, x, y), _clock(clock()), _id(id) {
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

int			Bullet::getId() const {
	return this->_id;
}

void		Bullet::move() {
	if (this->_x < Window::_x) {
		if (((60) * (clock() - _clock)) / CLOCKS_PER_SEC > 1)
	    {
	    	_clock = clock();
	    	_x++;
    	}
    }
    else {
    	Penis::_isId = this->_id;
    }
}