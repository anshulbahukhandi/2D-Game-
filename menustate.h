#ifndef MENU_STATE_H_
#define MENU_STATE_H_



#include"state.h"
#include<vector>

class menuState : public state
{

protected:

	typedef void(*callBack)();
	virtual void setCallBacks(const std::vector<callBack>& callbacks)=0;
	std::vector<callBack> maCallBack;
};

#endif