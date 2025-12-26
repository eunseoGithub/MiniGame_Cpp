#pragma once
#include"Global.h"

template<typename T>
shared_ptr<T> LockOrNull(const weak_ptr<T> &w)
{
	return w.lock();
}

template<typename T>
vector<shared_ptr<T>> LockAlive(const vector<weak_ptr<T>>& ws) 
{
	vector<shared_ptr<T>> alive;
	alive.reserve(ws.size());

	for (auto& w : ws)
	{
		if (auto sp = w.lock())
		{
			alive.push_back(move(sp));
		}
	}
	return alive;
}