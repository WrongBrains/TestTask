#include"Engines.h"

using namespace std;
//������ ����������
float InternalCombustionEngine::CalculateEngineCooling(float OutterTemp) { return C * (OutterTemp - Temperature); };
float InternalCombustionEngine::CalculateEngineHeating() { return Torque * Hm + Velocity * Velocity * Hv; };
//set - �������
void InternalCombustionEngine::setAcceleration() { Acceleration = Torque / MomentOfInertia; };
void InternalCombustionEngine::setTemperature(float temperature) { Temperature = temperature; };
void InternalCombustionEngine::changeTemperature(float delta) { Temperature += delta; };
void InternalCombustionEngine::setProperties() //��������� ���������� ���������
{
	float container;
	ifstream fin;
	fin.open("Input.txt");
	fin >> MomentOfInertia;
	fin >> container;
	TorqueDependence.push_back(container);
	while (fin.peek() != '\n')
	{
		fin >> container;
		TorqueDependence.push_back(container);
	}
	fin >> container;
	VelocityDependence.push_back(container);
	while (fin.peek() != '\n')
	{
		fin >> container;
		VelocityDependence.push_back(container);
	}
	fin >> OverheatingTemp;
	fin >> Hm;
	fin >> Hv;
	fin >> C;
	Velocity = VelocityDependence[0];
	Torque = TorqueDependence[0];
};
//get - �������
float InternalCombustionEngine::getAcceleration() { return Acceleration; };
float InternalCombustionEngine::getTemp() { return Temperature; };

