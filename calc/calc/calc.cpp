#include "_calc_assemblage.h"


void THREAD_ONE();
void THREAD_TWO();

// CALC
OBJECT object_one;
OBJECT object_two;

VECTOR3 direction = { 1, -2, 0 };

int main() {

	object_one.position = { 2, 1, 5 };
	object_one.physicbody.mass = 7.5;

	object_two.position = { 4, -1, 6 };
	object_two.physicbody.mass = 5.2;

	std::cout << "command>";
	std::string command;
	std::cin >> command;

	try
	{

		auto start = std::chrono::high_resolution_clock::now();

		if (command == "run(calc)" || command == "/") {

			//std::thread thread_one(THREAD_ONE);
			std::thread thread_two(THREAD_TWO);

			// thread_one.join();
			thread_two.join();
		}
		else {

			std::cout << "undefined command" << std::endl;
;		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;

		std::cout << "chrono::calc_duration::repid - duration: " << elapsed.count() << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "error 404" << std::endl;;
	}

	return 0;
} 

void THREAD_ONE() {

	for (int i = 0; i < 10; i++)
	{

		object_one.position = SUM_VECTOR3(object_one.position, direction);
		std::cout << i; SAY_POSITION(object_one.position);
	}
}

void THREAD_TWO() {

	std::cout << "ptv3d::repid - physic_transform_v3_demo" << std::endl;

	SAY_POSITION(object_one.position);
	std::cout << "mass: " << object_one.physicbody.mass << std::endl;

	SAY_POSITION(object_two.position);
	std::cout << "mass: " << object_two.physicbody.mass << std::endl;

	std::cout << "sum vectors3: ";
	VECTOR3 temp = SUM_VECTOR3(object_one.position, object_two.position);
	SAY_POSITION(temp);

	double r = GET_r(object_one.position, object_two.position);
	double F = GET_F(GET_SIMPLE_G(), object_one.physicbody.mass, object_two.physicbody.mass, r);
	std::cout << "r[obj1, obj2]: " << r << ", f[obj1, obj2]: " << F << std::endl;
}