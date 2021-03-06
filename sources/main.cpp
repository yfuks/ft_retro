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
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	Window	w;
	Penis 	p(0, w.getY() / 2 - 1);
	Vagina  v[20];
	Sprite 	s("                              -    .|||||.\n                                  |||||||||\n                          -      ||||||  .\n                              -  ||||||   >\n                                ||||||| -/\n                           --   ||||||'(\n                        -       .'      \\\n                             .-'    | | |\n                            /        \\ \\ \\\n              --        -  |      `---:.`.\\\n             ____________._>           \\\\_\\\\____ ,--.__\n  --    ,--\"\"           /    `-   .       |)_)    \'\\     \'\\\n     ,/               \\           .\'              '\\     |\n     | \"   \"   \"          \\         /                '\\,  /\n", -20 , w.getY() - 15);
	int		key;

	for(int i = 0; i < w.getX() + 10; i++)
	{
		s.moveRight();
		w.putSprite(s);
		w.Refresh();
		usleep(40000);
	}
	w.Clear();
	while ((key = getch()) != 27 && p.getLife() > 0 && Window::_x > 50 && Window::_y > 10)
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
				break;
			case ' ':
				p.shootBullet();
				break;
		}
		w.refreshSize();
		w.putSprite(p);
		p.putBullets(v);
		w.putSprite(v, p);
		w.putLife(p);
		w.putBackground();
		w.Refresh();
	}

	return 0;
}
