// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Window.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 15:40:35 by yfuks             #+#    #+#             //
//   Updated: 2015/06/20 15:40:35 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Window.class.hpp"
#include <ncurses.h>
#include <stdlib.h>

Window::Window(void) : _clock(clock()) {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	_y = getmaxy(stdscr);
	_x = getmaxx(stdscr);
	cbreak();
	int a;
	for(int x = 0; x < 1000; x += 2)
	{
		a = rand() % 20;
		if (a < 18)
			_backgroundTop.append("~~");
		else
			_backgroundTop.append("\\/");
	}
	for(int x = 0; x < 1000; x += 2)
	{
		a = rand() % 20;
		if (a < 18)
			_backgroundBot.append("~~");
		else
			_backgroundBot.append("/\\");
	}
}

Window::Window(Window & src) {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	cbreak();
	nodelay(stdscr, TRUE);
	_x = src.getX();
	_y = src.getY();
}

Window::~Window(void) {
	endwin();
}

int 	Window::getX(void) {
	return this->_x;
}

int 	Window::getY(void) {
	return this->_y;
}

Window & Window::operator=(Window & rhs) {
	this->_y = rhs.getY();
	this->_x = rhs.getX();
	return *this;
}

void Window::refreshSize(void) {
	_y = getmaxy(stdscr);
	_x = getmaxx(stdscr);
}

void 	Window::Clear(void) {
	clear();
}

void 	Window::Refresh(void) {
	refresh();
}

void 	Window::putSprite(Sprite & s) {
	std::string str = s.getForm();
	int 	line  = 0;
	int 	col   = 0;

	move(s.getY(), s.getX());
	for(int i = 0; str[i] != 0; i++)
	{
		if(str[i] == '\n')
		{
			line++;
			col = 0;
		}
		else if (s.getY() + line >= 0 && s.getX() + col >= 0 && s.getY() + line < _y && s.getX() + col < _x)
		{
			move(s.getY() + line, s.getX() + col);
			addch(str[i]);
			col++;
		}
		else
			col++;
	}
}

void 	Window::putSprite(Bullet & bullet, Vagina vagina[20]) {
			std::string str = bullet.getForm();
			bullet.move();
			int 	line  = 0;
			int 	col   = 0;

			move(bullet.getY(), bullet.getX());
			for (int i = 0; i < 20; i++) {
				if (bullet.isTouching(vagina[i].getX(), vagina[i].getY())) {
					vagina[i].reset();
					bullet.setX(Window::_x);
				}
					
			}
			for(int i = 0; str[i] != 0; i++)
			{
				if(str[i] == '\n')
				{
					line++;
					col = 0;
				}
				else if (bullet.getY() + line >= 0 && bullet.getX() + col >= 0 && bullet.getY() + line < _y && bullet.getX() + col < _x)
				{
					move(bullet.getY() + line, bullet.getX() + col);
					addch(str[i]);
					col++;
				}
				else
					col++;
			}
}

void 	Window::putSprite(Vagina vagina[20], Penis & P) {
	for(int i = 0; i < 20; i++)
	{
		if (!P.isTouching(vagina[i].getX(), vagina[i].getY()) && !P.isTouching(vagina[i].getX() + 4, vagina[i].getY()))
			putSprite(vagina[i]);
		else
		{
			vagina[i].reset();
			P.minuslife();
		}
	}
}

void 	Window::putSprite(Vagina & s) {
	std::string str = s.getForm();
	move(s.getY(), s.getX() + 4);
	addch(' ');
	s.move();
	int 	line  = 0;
	int 	col   = 0;

	move(s.getY(), s.getX());
	for(int i = 0; str[i] != 0; i++)
	{
		if(str[i] == '\n')
		{
			line++;
			col = 0;
		}
		else if (s.getY() + line >= 0 && s.getX() + col >= 0 && s.getY() + line < _y && s.getX() + col < _x)
		{
			move(s.getY() + line, s.getX() + col);
			addch(str[i]);
			col++;
		}
		else
			col++;
	}
}

void 	Window::putBackground(void) {
	if (((20) * (clock() - _clock)) / CLOCKS_PER_SEC > 1)
    {
    	_clock = clock();
    	Clear();
		int x = 0;
		for(int i = _pos; i < _x + _pos && i < (int)_backgroundTop.size(); i++)
		{
			move(0, x);
			if (i > 1000)
				addch(_backgroundTop[i - 1000]);
			else
				addch(_backgroundTop[i]);
			x++;
		}
		x = 0;
		for(int i = _pos; i < _x + _pos && i < (int)_backgroundBot.size(); i++)
		{
			move(_y - 1, x);
			if (i > 1000)
				addch(_backgroundBot[i - 1000]);
			else
				addch(_backgroundBot[i]);
			x++;
		}
		_pos++;
		if (_pos > 1000)
			_pos = 0;
	}
}

void 	Window::putLife(Penis & P) {
	move(1, 3);
	printw("%d",P.getLife());
}

int Window::_pos = 0;
int Window::_x = 0;
int Window::_y = 0;
/*

~∽~∽~∽~∽~∽~∽~∽~∽~∽~∽~∽\/~∽~∽~∽~∽\/~∽~∽~∽~∽~∽~∽-~∽~∽\/~∽~∽~∽~∽~∽~∽~∽~∽\/~∽~∽~∽


~∽~∽~∽~∽~∽/\~∽~∽~∽~∽~∽~∽~∽~∽/\~∽~∽~∽~∽~∽~∽~∽~∽/\~∽~∽~∽~∽~∽/\~∽~∽~∽~∽~∽~∽~∽~∽/\
({})

( . y . )

 //______                   
   ____|_) ~∽o
_)_)

 */