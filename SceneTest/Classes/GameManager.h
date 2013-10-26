/*
 * GameManager.h
 *
 *  Created on: 2013/10/19
 *      Author: gameprogram
 */

#include "cocos2d.h";

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_


class GameManager {
public:
	GameManager();
	virtual ~GameManager();

	static GameManager* sharedInstance();

	bool init();

	inline int getStageId(){ return stage_id; }
	inline void setStageId(int id){ stage_id = id;}

private:
	int stage_id;
};

#endif /* GAMEMANAGER_H_ */
