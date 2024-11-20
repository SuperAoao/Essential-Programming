#include <iostream>

struct Vertex
{
	float Position[3];
	float Normal[3];
	float TexCoords[2];
};

int main()
{
	Vertex v;
	std::cout << "offsetof Posistion:" << offsetof(Vertex, Position) << std::endl;
	std::cout << "offsetof Normal:" << offsetof(Vertex, Normal) << std::endl;
	std::cout << "offsetof TexCoords:" << offsetof(Vertex, TexCoords) << std::endl;

	std::cout << "test Normal offset: " << (unsigned int)(((Vertex*)0)->Normal) << std::endl;
	return 0;
}