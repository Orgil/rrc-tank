/*
 * Intro.cpp
 *
 *  Created on: Apr 3, 2012
 *      Author: sharavsambuu
 */

#include "Intro.hpp"
#include "../util/Util.hpp"
#include "../system/Engine.hpp"
#include "stdio.h"

Intro::Intro()
{
	isEntered = true;
}

Intro::~Intro()
{
}

void Intro::Pause()
{
	isEntered = false;
}
void Intro::Resume()
{
	isEntered   = true;
	enteredTime = 0.0f;

	char str[30];
	sprintf(str, "entered Intro state.");
	glfwSetWindowTitle(str);
}

void Intro::Update()
{
	if (isEntered)
	{
		enteredTime += APP.GetDeltaTime();
		if (enteredTime>0.5f)
		{
			isEntered   = false;
			enteredTime = 0.0;
		}
	}
	bool spaceButton = APP.GetKey(GLFW_KEY_F1);
	if (spaceButton&&!isEntered)
	{
		Engine *engine = Engine::Instance();
		engine->ChangesState("game");
	}

}
void Intro::Render()
{
	glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
