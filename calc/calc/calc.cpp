#include "_calc_assemblage.h"


void THREAD_ONE();

// CALC
OBJECT object_one;
OBJECT object_two;

VECTOR3 direction = { 1, -2, 0 };

VECTOR3 vec3_test_1 = { 4, 6, 2 };
VECTOR3 vec3_test_2 = { 6, 3, -1 };


int main() {

	std::thread thread_one(THREAD_ONE);
	thread_one.join();

	std::cout << "r::repnr -r: " << GET_r(vec3_test_1, vec3_test_2);
} 

void THREAD_ONE() {

	for (int i = 0; i < 10; i++)
	{

		object_one.position = SUM_VECTOR3(object_one.position, direction);
		std::cout << i << "::repnr - x: " << object_one.position.x << ", y: " << object_one.position.y << ", z: " << object_one.position.z << std::endl;
	}
}
