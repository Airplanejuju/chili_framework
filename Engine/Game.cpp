/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	// 255, 0 , 0 - red // 0, 255, 0 - green // 0, 0, 255 - blue      //RGB
	//color

	/*
	if (wnd.kbd.KeyIsPressed(VK_TAB))
	{
		//black
		r = 0;
		g = 0;
		b = 0;
	}
	*/


	//movement

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight)
		{
			//do nothing 
		}
		else
		{
			vx += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{
			//do nothing
		}
		else
		{
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{
			//do nothing
		}
		else
		{
			vy += 1;
			inhibitDown = true;
		}	
	}
	else
	{
		inhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{
			//do nothing
		}
		else
		{
			vy -= 1;
			inhibitUp = true;
		}	
	}
    else
	{
		inhibitUp = false;
	}

	x += vx;
	y += vy;

	
	// setting boundaries
	if (x + 5 >= gfx.ScreenWidth) // if (x + 5 >= 800){x = 800 - 6} //or x > 799 { x = 799 - 5}
	{
		x = gfx.ScreenWidth - 6;
		vx = 0;
	}

	if (x - 5 < 0)
	{
		x = 5;
		vx = 0;
	}

	if (y + 4 >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 5;
		vy = 0;
	}

	if (y - 4 < 0)
	{
		y = 4;
		vy = 0;
	}


	//changing colors
	if (x > 400 && y <= 300) //quadrant 1
	{
		r = 0;
		g = 255;
		b = 0;
	}

	if (x <= 400 && y <= 300) //quadrant 2
	{
		r = 255;
		g = 0;
		b = 0;
	}

	if (x <= 400 && y > 300) //quadrant 3
	{
		r = 255;
		g = 255;
		b = 0;
	}

	if (x > 400 && y > 300) //quadrant 4
	{
		r = 0;
		g = 0;
		b = 255;
	}

	if (x == 400 && y == 300) // mid white
	{
		r = 255;
		g = 255;
		b = 255;
	}

}


void Game::ComposeFrame()
{	
	//shape

	if (cond1)
	{

		gfx.PutPixel(x, (y - 4), r, g, b);
		gfx.PutPixel(x, (y - 3), r, g, b);
		gfx.PutPixel(x, (y - 2), r, g, b);
		gfx.PutPixel(x, (y + 2), r, g, b);
		gfx.PutPixel(x, (y + 3), r, g, b);
		gfx.PutPixel(x, (y + 4), r, g, b);
		gfx.PutPixel((x + 3), y, r, g, b);
		gfx.PutPixel((x + 4), y, r, g, b);
		gfx.PutPixel((x + 5), y, r, g, b);
		gfx.PutPixel((x - 3), y, r, g, b);
		gfx.PutPixel((x - 4), y, r, g, b);
		gfx.PutPixel((x - 5), y, r, g, b);
	}

	else
	{
		gfx.PutPixel(x + 1, y - 2, r, g, b);
		gfx.PutPixel(x, y - 2, r, g, b);
		gfx.PutPixel(x, y - 1, r, g, b);
		gfx.PutPixel(x, y + 2, r, g, b);
		gfx.PutPixel(x, y + 3, r, g, b);
		gfx.PutPixel(x + 1, y + 3, r, g, b);
		gfx.PutPixel(x + 4, y - 2, r, g, b);
		gfx.PutPixel(x + 5, y - 2, r, g, b);
		gfx.PutPixel(x + 5, y - 1, r, g, b);
		gfx.PutPixel(x + 5, y + 2, r, g, b);
		gfx.PutPixel(x + 5, y + 3, r, g, b);
		gfx.PutPixel(x + 4, y + 3, r, g, b);
	}
}