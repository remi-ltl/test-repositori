/*
 * GameManager.cpp
 *
 *  Created on: 2013/10/19
 *      Author: gameprogram
 */

#include "C:/prj/cocos2d-x-2.2/projects/SceneTest/Classes/GameManager.h"

static GameManager* s_GameManager = NULL;

GameManager::GameManager()
{
	// TODO Auto-generated constructor stub
		stage_id = 0;
}

GameManager::~GameManager() {
	// TODO Auto-generated destructor stub
}

GameManager* GameManager::sharedInstance()
{
	if(!s_GameManager)
	{
		s_GameManager = new GameManager();
		s_GameManager->init();
	}
	return s_GameManager;
}


bool GameManager::init(){
	stage_id = 0;

	return stage_id;
}

