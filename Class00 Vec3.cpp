#include <stdlib.h>
#include <iostream>

template <typename T>

class Vec3
{

	T x, y, z;


public:
	Vec3<T>() { x = y = z = 0; };

	Vec3<T>(T x2, T y2, T z2) { x = x2; y = y2; z = z2; };



	T getx() { return x; };
	T gety() { return y; };
	T getz() { return z; };

	Vec3<T> operator+() {
		return Vec3<T>(*this);
	}

	Vec3<T> operator+(const Vec3<T>& other) {

		return Vec3<T>(this->x + other.x, this->y + other.y, this->z + other.z);

	}

	Vec3<T> operator-() {
		return Vec3<T>(-this->x, -this->y, -this->z);
	}

	Vec3<T> operator-(const Vec3<T>& other) {

		return Vec3<T>(this->x - other.x, this->y - other.y, this->z - other.z);

	}

	
	Vec3<T> operator+=(const Vec3<T>& other) {
		
		return Vec3<T>(this->x += other.x, this->y += other.y, this->z += other.z);
	}

	Vec3<T> operator-=(const Vec3<T>& other) {

		return Vec3<T>(this->x -= other.x, this->y -= other.y, this->z -= other.z);
	}

	Vec3<T> operator=(const Vec3<T>& other) {

		return Vec3<T>(this->x = other.x, this->y = other.y, this->z = other.z);
	}

	bool operator==(const Vec3<T>& other) {
		return this->x == other.x && this->y == other.y && this->z == other.z;
	}

	T Module() {
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	Vec3<T>& Normalize() {
		T Mod = Module();
		Vec3<T>* res = new Vec3<T>();
		res->x = this->x / Mod;
		res->y = this->y / Mod;
		res->z = this->z / Mod;
		return *res;
	}

	Vec3<T>& Zero() {
		Vec3<T>* res = new Vec3<T>();
		res->x = 0;
		res->y = 0;
		res->z = 0;
		return *res;
	}

	bool isZero() {
		return this->x == 0 && this->y == 0 && this->z == 0;
	}

	float DistanceTo(Vec3<T> other) {
		Vec3<T> diff = *this - other;
		return diff.Module();
	}

};

int main(){

	Vec3<float> v(7, 9, 2);
	Vec3<float> J(9, 5, 4);

	std::cout << "Print Vector" << std::endl;
	std::cout << v.getx() << " " << v.gety() << " " << v.getz() << std::endl;
	std::cout << std::endl;
	if (v == J) {
		std::cout << "Igual" << std::endl;
	
	}

	else {
		std::cout << "Diferente" << std::endl;
		v = J;
		std::cout << v.getx() << " " << v.gety() << " " << v.getz() << std::endl;
		std::cout << std::endl;
	};


	std::cout << "Suma" << std::endl;
	Vec3<float>x = v + J;
	std::cout << x.getx()  << " " << x.gety() << " " << x.getz() << std::endl;
	std::cout << std::endl;

	std::cout << "Module x" << std::endl;
	std::cout << x.Module() << std::endl;
	std::cout << std::endl;

	Vec3<float>k = x.Normalize();

	std::cout << "x normalized" << std::endl;
	std::cout << k.getx() << " " << k.gety() << " " << k.getz() << std::endl;
	std::cout << std::endl;


	std::cout << "Zero function" << std::endl;
	x = x.Zero();
	std::cout << x.getx() << " " << x.gety() << " " << x.getz() << std::endl;
	std::cout << std::endl;



	std::cout << "Distance" << std::endl;
	std::cout << J.DistanceTo(k) << std::endl;
	std::cout << std::endl;

	

	system("pause");
	return 0;
}