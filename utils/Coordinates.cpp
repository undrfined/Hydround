
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#include <utils/Coordinates.h>

int BlockCoordinates::getX() {
	return X;
}
int BlockCoordinates::getY() {
	return Y;
}
int BlockCoordinates::getZ() {
	return Z;
}
void BlockCoordinates::setX(int x) {
	X = x;
}
void BlockCoordinates::setY(int y) {
	Y = y;
}
void BlockCoordinates::setZ(int z) {
	Z = z;
}
float EntityCoordinates::getX() {
	return X;
}
float EntityCoordinates::getY() {
	return Y;
}
float EntityCoordinates::getZ() {
	return Z;
}
void EntityCoordinates::setX(float x) {
	X = x;
}
void EntityCoordinates::setY(float y) {
	Y = y;
}
void EntityCoordinates::setZ(float z) {
	Z = z;
}
int ChunkCoordinates::getX() {
	return X;
}
int ChunkCoordinates::getZ() {
	return Z;
}
void ChunkCoordinates::setX(int x) {
	X = x;
}
void ChunkCoordinates::setZ(int z) {
	Z = z;
}
