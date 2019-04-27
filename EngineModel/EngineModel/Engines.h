#ifndef  ENGINES_H
#define ENGINES_H

#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

class Engine
{
public:
	virtual void setProperties() = 0;
};
class InternalCombustionEngine:Engine
{
public:
	//Поля
	float Velocity;
	float Torque;
	vector<int> TorqueDependence;
	vector<int> VelocityDependence;
	//Методы установки, получения и изменения значений полей
	//get - функции
	float getOverheatingTemp() { return OverheatingTemp; };
	float getAcceleration();
	float getTemp();
	//set - функции
	void setProperties();
	void setAcceleration();
	void setTemperature(float temperature);
	void changeTemperature(float delta);
	//Методы вычислений 
	float CalculateEngineCooling(float OutterTemp);
	float CalculateEngineHeating();
private:
	//Поля
	float Acceleration;
	float Temperature;
	float MomentOfInertia;
	float OverheatingTemp;
	float Hm;
	float Hv;
	float C;
};

#endif 
