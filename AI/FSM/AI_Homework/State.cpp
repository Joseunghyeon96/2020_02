#include "State.h"

State::State()
{
	state = HOUSE;
	location = "House";
}

State::~State()
{
}

void State::SetState(int i)
{
	switch (i)
	{
	case HOUSE:
		state = HOUSE;
		location = "House";
		break;
	case SCHOOL:
		state = SCHOOL;
		location = "School";
		break;
	case PC:
		state = PC;
		location = "PC";
		break;
	default:
		state = -1;
		location = "?????";
	}
}

int State::GetSpace()
{
	return state;
}

string State::GetLocation()
{
	return location;
}
