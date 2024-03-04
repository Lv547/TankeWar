#pragma once
#include <string>

using namespace std;

class Information
{
private:
	int _score;
	int _userHp;
	int _playTime;
	int _enemyCount;

	string *_msg;
	string *_alertMsg;

public:
	Information(void);
	~Information(void);

	string * Msg() const { return _msg; }
	void Msg(string * val) { _msg = val; }

	string * AlertMsg() const { return _alertMsg; }
	void AlertMsg(string * val) { _alertMsg = val; }

	int Score() const { return _score; }
	void Score(int val) { _score = val; }

	int UserHp() const { return _userHp; }
	void UserHp(int val) { _userHp = val; }

	int PlayTime() const { return _playTime; }
	void PlayTime(int val) { _playTime = val; }

	int EnemyCount() const { return _enemyCount; }
	void EnemyCount(int val) { _enemyCount = val; }
};
