#include "..\Headers\MySoundBuffer.h"

MySoundBuffer::MySoundBuffer(Type type) : type(type) {}

const MySoundBuffer::Type MySoundBuffer::GetType() const 
{ 
	return type; 
}