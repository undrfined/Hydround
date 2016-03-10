
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
//	▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒
//	▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒
//	▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒
//	▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒
//	▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒
//	 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

#ifndef COORDINATES_H_
#define COORDINATES_H_

class BlockCoordinates {
private:
int X;
int Y;
int Z;
public:
BlockCoordinates(int x, int y, int z) : X(x), Y(y), Z(z) { }
int getX();
int getY();
int getZ();
void setX(int X);
void setY(int Y);
void setZ(int Z);
};

class EntityCoordinates {
private:
float X;
float Y;
float Z;
public:
EntityCoordinates(float x, float y, float z) : X(x), Y(y), Z(z) { }
float getX();
float getY();
float getZ();
void setX(float X);
void setY(float Y);
void setZ(float Z);
};

class ChunkCoordinates {
private:
int X;
int Z;
public:
ChunkCoordinates(int x, int z) : X(x), Z(z) { }
int getX();
int getZ();
void setX(int x);
void setZ(int z);
};

#endif