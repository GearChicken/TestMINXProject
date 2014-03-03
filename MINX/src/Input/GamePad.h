/*
    MINX - A C++ Graphics and Input Wrapper Library
    Copyright (C) 2013-2014  MINX Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	*/
#ifndef _GAMEPAD_H
#define _GAMEPAD_H

#define GENERIC_GAMEPAD 0
#define XBOX_360_GAMEPAD 1
//#ifdef XBOX_360_GAMEPAD
#define CONTROLLER_A 0
#define CONTROLLER_X 1
#define CONTROLLER_Y 2
#define CONTROLLER_O 3
#define CONTROLLER_LB 4
#define CONTROLLER_RB 5
#define CONTROLLER_BACK 6
#define CONTROLLER_START 7
#define CONTROLLER_LEFTSTICK 8
#define CONTROLLER_RIGHTSTICK 9
#define CONTROLLER_LEFTAXIS_X 0
#define CONTROLLER_LEFTAXIS_Y 1
#define CONTROLLER_LEFTTRIGGER 3:1
#define CONTROLLER_RIGHTTRIGGER 3:-1
#define CONTROLLER_RIGHTSTICK_Y 3
#define CONTROLLER_RIGHTSTICK_X 4
//#endif
#include "IGenericHID.h"
#include "../Game.h"
#include <functional>

namespace MINX
{
	namespace Input
	{
		/** A GamePad class that handles input from a USB gamepad
		*/
		class GamePad : public IGenericHID
		{
			public:
				/** Creates a new GamePad instance.
				 *	@param deviceIndex The Index of the GamePad to get an instance of.
				 *	@param game A pointer to an instance of the game object.
				 */
				GamePad(unsigned int deviceIndex, Game* game);
				
				/** Creates a new Gamepad instance.
				 *	@param deviceIndex The Index of the GamePad to get an instance of.
				 *	@param game A pointer to an instance of the game object.
				 *	@param gamePadType The Type of GamePad that is being Instantiated
				 */
				GamePad(unsigned int deviceIndex, Game* game, unsigned int gamePadType);
				
				/** Returns the name of the gamepad
				 *	@return GLFW's stored name for the gamepad
				 */
				const char * GetName();
				
				/** Checks is the GamePad's state has changed, and saves the data properly.
				 */
				void Update(GameTime * gameTime);
				
				/** Gets the Button at the specified index
				 */
				Button GetButton(unsigned int buttonID);
				
				/** Gets the Axis at the specified index
				 */
				Axis GetAxis(unsigned int axisID);
				
			private:
				bool isConnected;
				unsigned int deviceIndex;
				unsigned int gamePadType;
		};

	}

}
#endif