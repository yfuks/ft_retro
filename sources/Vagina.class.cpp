// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vagina.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/21 19:20:51 by yfuks             #+#    #+#             //
//   Updated: 2015/06/21 19:20:52 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vagina.class.hpp"
#include "Window.class.hpp"

Vagina::Vagina(void) : Sprite("({})", Window::_x + rand() % 400, 1 + (rand() % (Window::_y - 3))), _clock(clock()) {
	std::string s[3] = {"({})", "(.y.)", "0~~"};
	this->_form = s[rand() % 3];
}

Vagina::Vagina(int x, int y) : Sprite("({})", x, y), _clock(clock()) {

}

Vagina::~Vagina(void) {

}

Vagina & Vagina::operator=(Vagina & src) {
	this->_x = src.getX();
	this->_y = src.getY();
	this->_form = src.getForm();
	return *this;
}

void 	Vagina::move(void) {
	if (this->getX() > -4)
	{
		if (((40) * (clock() - _clock)) / CLOCKS_PER_SEC > 1)
	    {
	    	_clock = clock();
	    	_x--;
    	}
    }
    else
    	this->moveTo(Window::_x + rand() % 20, 1 + (rand() % (Window::_y - 2)));
    	
}

void 	Vagina::reset(void) {
	std::string s[3] = {"({})", "(.y.)", "0~~"};
	this->_x =  Window::_x + rand() % 400;
	this->_y = 1 + (rand() % (Window::_y - 3));
	this->_form = s[rand() % 3];
}