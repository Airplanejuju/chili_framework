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
}


void Game::ComposeFrame()
{	

	const static int x = 400;
	const static int y = 300;
	
	int dx = 0;
	int dy = 0;

	int gb = 255;

	bool cond1 = wnd.kbd.KeyIsPressed(VK_SPACE);
	//bool cond2 = wnd.kbd.KeyIsPressed(VK_CONTROL);

	
	// 255, 0 , 0 - red // 0, 255, 0 - green // 0, 0, 255 - blue      //RGB
	//color

	if (wnd.kbd.KeyIsPressed(VK_TAB))
	{
		gb = 0;
	}

	
	//movement

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dx+=100;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dx-=100;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dy+=100;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dy-=100;
	}

	
	//shape

	if (cond1)
	{
		gfx.PutPixel(x + dx, (y - 4) + dy, 255, gb, gb);
		gfx.PutPixel(x + dx, (y - 3) + dy, 255, gb, gb);
		gfx.PutPixel(x + dx, (y - 2) + dy, 255, gb, gb);
		gfx.PutPixel(x + dx, (y + 2) + dy, 255, gb, gb);
		gfx.PutPixel(x + dx, (y + 3) + dy, 255, gb, gb);
		gfx.PutPixel(x + dx, (y + 4) + dy, 255, gb, gb);
		gfx.PutPixel((x + 3) + dx, y + dy, 255, gb, gb);
		gfx.PutPixel((x + 4) + dx, y + dy, 255, gb, gb);
		gfx.PutPixel((x + 5) + dx, y + dy, 255, gb, gb);
		gfx.PutPixel((x - 3) + dx, y + dy, 255, gb, gb);
		gfx.PutPixel((x - 4) + dx, y + dy, 255, gb, gb);
		gfx.PutPixel((x - 5) + dx, y + dy, 255, gb, gb);
	}

	else
	{
		gfx.PutPixel((x + dx) + 1, (y + dy) - 2, 255, gb, gb);
		gfx.PutPixel((x + dx), (y + dy) - 2,     255, gb, gb);
		gfx.PutPixel((x + dx), (y + dy) - 1,     255, gb, gb);
		gfx.PutPixel((x + dx), (y + dy) + 2,     255, gb, gb);
		gfx.PutPixel((x + dx), (y + dy) + 3,     255, gb, gb);
		gfx.PutPixel((x + dx) + 1, (y + dy) + 3, 255, gb, gb);
		gfx.PutPixel((x + dx) + 4, (y + dy) - 2, 255, gb, gb);
		gfx.PutPixel((x + dx) + 5, (y + dy) - 2, 255, gb, gb);
		gfx.PutPixel((x + dx) + 5, (y + dy) - 1, 255, gb, gb);
		gfx.PutPixel((x + dx) + 5, (y + dy) + 2, 255, gb, gb);
		gfx.PutPixel((x + dx) + 5, (y + dy) + 3, 255, gb, gb);
		gfx.PutPixel((x + dx) + 4, (y + dy) + 3, 255, gb, gb);
	}
}