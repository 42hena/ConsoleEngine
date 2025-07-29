#ifndef __INTERFACE_CAN_PLAYER_MOVE_H__
#define __INTERFACE_CAN_PLAYER_MOVE_H__

#include "Core.h"

#include "Math/Vector2.h"

class ICanPlayerMove
{
public:
	virtual ~ICanPlayerMove() ABSTRACT

public:
	virtual bool CanPlayerMove(const Vector2& playerPosition, const Vector2& newPosition) ABSTRACT
};

#endif
