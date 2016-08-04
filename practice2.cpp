#include <iostream>
#include <cmath>
#include <iomanip>

class Particle
{
private:
	float mass, x, y;
public:
	Particle();

	void values();
	int check();
	float getX();
	float getY();
	float getMass();
};

class Force
{
private:
	float deltaX, deltaY, distance, force;
public:
	float findDistance(Particle, Particle);
	float findForce(Particle, Particle);
};

Particle::Particle()
{
	std::cout << "Enter values:" << std::endl;
	std::cin >> mass;
	std::cin >> x;
	std::cin >> y;
}

void Particle::values()
{
	std::cout << "Enter values:" << std::endl;
	std::cin >> mass;
	std::cin >> x;
	std::cin >> y;
}

int Particle::check()
{
	int errorCounter = 0;

	if ((mass < 0.001) || (mass > 100.0))
		errorCounter++;
	if ((x < -100.0) || (x > 100.0))
		errorCounter++;
	if ((y < -100.0) || (y > 100.0))
		errorCounter++;

	return errorCounter;
}

float Particle::getX()
{
	return x;
}

float Particle::getY()
{
	return y;
}

float Particle::getMass()
{
	return mass;
}

float Force::findDistance(Particle one, Particle two)
{
	deltaX = one.getX() - two.getX();
	deltaY = one.getY() - two.getY();

	distance = sqrt((deltaX*deltaX) + (deltaY*deltaY));
	return distance;
}

float Force::findForce(Particle one, Particle two)
{
	force = (one.getMass()*two.getMass()) / (distance*distance);
	std::cout << std::setprecision(4) << force << std::endl;
	return force;
}

int main()
{
	Particle p1, p2;
	Force findForce;

	while (p1.check() > 0)
		p1.values();
	while (p2.check() > 0)
		p2.values();
	
	findForce.findDistance(p1, p2);
	findForce.findForce(p1, p2);
	return 0;
}
