#ifndef _INPUT_LISTENER_H
#define _INPUT_LISTENER_H

class InputListener
{
public:
	InputListener() = default;
	~InputListener() = default;

	// KEYBOARD pure virtual callback functions
	virtual void onKeyDown(int key) = 0;
	virtual void onKeyUp(int key) = 0;
};

#endif // !_INPUT_LISTENER_H