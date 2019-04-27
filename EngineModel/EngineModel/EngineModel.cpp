#include<locale>
#include<iomanip>
#include"Engines.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1, time = 0;
	bool isFinite = true; //Возможность перегрева
	InternalCombustionEngine engine;
	float OutterTemp;
	engine.setProperties();
	cout << "Введите температуру среды в град. по Цельсию: ";
	cin >> OutterTemp;
	engine.setTemperature(OutterTemp);
	engine.setAcceleration();
	while (engine.getTemp() < engine.getOverheatingTemp() && isFinite) //Пока двигатель не перегрелся, но имеет возможность перегрева
	{
		time++;
		engine.Velocity += engine.getAcceleration();    //Каждую секунду скорость увеличивается в соответствии с ускорением
		if (i == engine.VelocityDependence.size() || engine.Velocity < engine.VelocityDependence[i])    //Если скорость ниже следующего табличного значения...
		{
			auto delta = engine.CalculateEngineCooling(OutterTemp) + engine.CalculateEngineHeating();
			engine.changeTemperature(delta);     //...изменить лишь температуру в соответствии с формулами
			if (delta < 0.0001)      //Если изменения температуры незначительны или температура начала падать...
				isFinite = false;     //...сообщить, что температура перегрева не достигнется
		}
		else //Если скорость больше или равна след. табличному значению...
		{
			engine.Torque = engine.TorqueDependence[i];    //...изменить момент силы на соответствующее скорости табличное значение
			engine.setAcceleration();
			auto delta = engine.CalculateEngineCooling(OutterTemp) + engine.CalculateEngineHeating();
			engine.changeTemperature(delta);
			i++;
		}

	}
	if (isFinite)//Если перегрев достигнут..
		cout << "Двигатель перегреется спустя " << time << " сек." << endl;    //..вернуть время работы до перегрева
	else
		cout << "Температура двигателя не превысит ~ " << fixed << setprecision(1) << engine.getTemp() << " град. по Цельсию" << endl;
	system("pause");
}

