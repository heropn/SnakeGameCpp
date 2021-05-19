#include "MyFont.h"

MyFont::MyFont(Type type) : type(type) {}

const MyFont::Type MyFont::GetType() const
{
	return type;
}