#include "..\Headers\MyTexture.h"

MyTexture::MyTexture(Type type) : type(type) {};

const MyTexture::Type MyTexture::GetType() const
{
	return type;
}
