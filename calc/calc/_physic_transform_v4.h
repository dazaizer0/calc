// PHYSIC TRANSFORM V4
struct VECTOR3 {

	double x;
	double y;
	double z;

	double* p_x = &x;
	double* p_y = &y;
	double* p_z = &z;
};

struct PHYSICBODY {

	double mass;
	double velocity;
};

static VECTOR3 SUM_VECTOR3(VECTOR3 v3_1, VECTOR3 v3_2) {

	VECTOR3 temp;
	temp.x = v3_1.x + v3_2.x;
	temp.y = v3_1.y + v3_2.y;
	temp.z = v3_1.z + v3_2.z;

	return temp;
}

void SAY_POSITION(VECTOR3 temp) {

	std::cout << "::repid - x: " << temp.x << ", y: " << temp.y << ", z: " << temp.z << std::endl;
}

static double GET_G(double m, double kg, double s) {

	double G = 6.67430 * pow(10, -11) * ((pow(m, 3)) / (kg * pow(s, 2)));
	return G;
}

static double GET_SIMPLE_G() {

	double G = 6.67430;
	return G;
}

static double GET_F(double G, double mass1, double mass2, double r) {

	double F = G * ((mass1 * mass2) / (pow(r, 2)));
	return F;
}

static double GET_r(VECTOR3 position1, VECTOR3 position2) {

	double IXYZI = sqrt((pow((position1.x - position2.x), 2) + (pow((position1.y - position2.y), 2) + (pow((position1.z - position2.z), 2)))));
	return IXYZI;
}

// pow(position1.x - position2.x), 2)