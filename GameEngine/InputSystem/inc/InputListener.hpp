#ifndef _INPUT_LISTENER_H
#define _INPUT_LISTENER_H

// Forward declaration of Point
class Point;

class InputListener
{
public:
	InputListener() = default;
	~InputListener() = default;

	// KEYBOARD pure virtual callback functions
	virtual void onKeyDown(int key) = 0;
	virtual void onKeyUp(int key) = 0;

	// MOUSE pure virtual callback functions
	virtual void onMouseMove(const Point& deltaMousePose) = 0;
	// Mouse button events
	virtual void onLeftMouseDown(const Point& mousePos) = 0;
	virtual void onLeftMouseUp(const Point& mousePos) = 0;
	virtual void onRightMouseDown(const Point& mousePos) = 0;
	virtual void onRightMouseUp(const Point& mousePos) = 0;
};

#endif // !_INPUT_LISTENER_H