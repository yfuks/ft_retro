// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 15:14:37 by yfuks             #+#    #+#             //
//   Updated: 2015/06/20 15:14:38 by yfuks            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Window.class.hpp"
#include "Penis.class.hpp"
#include "Bullet.class.hpp"
#include "Vagina.class.hpp"
#include <ncurses.h>

int main(void)
{
	srand(time(NULL));
	Window	w;
	Bullet *b = new Bullet();
	Penis 	p(0, w.getY() / 2 - 1);
	Vagina  v;
	Vagina  v1;
	Vagina  v2;
	Vagina  v3;
	Vagina  v4;
	Vagina  v5;
	Vagina  v6;
	int		key;

	while ((key = getch()) != 27)
	{
		switch(key)
		{
			case KEY_UP:
			if (p.getY() > 1)
				p.moveUp();
				break;
			case KEY_DOWN:
			if (p.getY() < w.getY() - 4)
				p.moveDown();
				break;
			case KEY_RIGHT:
			if (p.getX() < w.getX() - 10)
				p.moveRight();
				break;
			case KEY_LEFT:
			if (p.getX() > 0)
				p.moveLeft();
		}
		w.refreshSize();
		w.putSprite(p);
		w.putSprite(*b);
		w.putSprite(v);
		w.putSprite(v1);
		w.putSprite(v2);
		w.putSprite(v3);
		w.putSprite(v4);
		w.putSprite(v5);
		w.putSprite(v6);			
		w.putBackground();
		w.Refresh();
	}

	return 0;
}