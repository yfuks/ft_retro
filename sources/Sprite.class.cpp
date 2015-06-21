// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sprite.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 16:15:49 by yfuks             #+#    #+#             //
//   Updated: 2015/06/20 16:15:50 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sprite.class.hpp"

Sprite::Sprite(void) : _form("0"), _x(0), _y(0), _speed(-1) {
}

Sprite::Sprite(std::string form, int x, int y) : _form(form), _x(x), _y(y), _speed(-1) {

}

Sprite::Sprite(Sprite & src) {
	this->_form = src.getForm();
	this->_x = src.getX();
	this->_y = src.getY();
}

Sprite::~Sprite(void) {
	
}

Sprite & Sprite::operator=(Sprite & src) {
	this->_form = src.getForm();
	this->_x = src.getX();
	this->_y = src.getY();
	return *this;
}

int 	Sprite::getY(void) {
	return this->_y;
}

int		Sprite::getX(void) {
	return this->_x;
}

void	Sprite::setX(int x) {
	this->_x = x;
}

std::string Sprite::getForm(void) {
	return this->_form;
}

void 	Sprite::moveTo(int x, int y) {
	this->_x = x;
	this->_y = y;
}

bool 	Sprite::isTouching(int x, int y) {
	std::string str = this->getForm();
	int 	xTmp = this->getX();
	int 	ytmp = this->getY();

	for(int i = 0; str[i] != 0; i++)
	{
		if(str[i] == '\n')
		{
			ytmp++;
			xTmp = this->getX();
		}
		else
		{
			if (x == xTmp && y == ytmp)
				return (true);
			xTmp++;
		}	
	}
	return (false);
}

void 	Sprite::moveUp(void) {
	this->moveTo(this->_x, this->_y - 1);
}

void 	Sprite::moveDown(void) {
	this->moveTo(this->_x, this->_y + 1);
}

void 	Sprite::moveRight(void) {
	this->moveTo(this->_x + 1, this->_y);
}

void 	Sprite::moveLeft(void) {
	this->moveTo(this->_x - 1, this->_y);
}