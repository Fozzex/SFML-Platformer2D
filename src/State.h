#pragma once
class State
{
public:

	State() {}
	virtual ~State() {}

	virtual void handleInput(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;

};