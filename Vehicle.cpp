/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle
{
  string model;
  double efficiency;
public:
    Vehicle (string model, double e):model (model), efficiency (e)
  {
  }
  double get_efficiency () const
  {
	return efficiency;
  }
  void display_info () const
  {
	cout << "Model: " << model << endl;
	cout << "Efficiency: " << get_efficiency () << endl;
  }
  void print_model() {
      cout << model <<endl;
  }
  virtual double get_remain_range() const = 0;
};

class ElectricVehicle: virtual public Vehicle
{
protected:
  int battery_level;			//0-100%
  int battery_capacity;			//kWh

public:
    ElectricVehicle (string model, int bl, int bc, double e):Vehicle (model,
																	  e)
  {
	this->battery_level = bl;
	this->battery_capacity = bc;
  }

  void charge (int c)
  {
	battery_level += c;
  }

  bool drive (int distance)
  {
	if (get_remain_range () < distance)
	  {
		battery_level -=
		  ((distance / get_efficiency ()) / battery_capacity) * 100;
		return true;

	  }
	battery_level = 0;
	return false;

  }

  double get_remain_range () const
  {
	return get_efficiency () * (battery_level * battery_capacity) / 100;
  }

  void display_info () const
  {
	Vehicle::display_info ();
	cout << "Range: " << get_remain_range () << endl;
	cout << "Battery: " << battery_level << endl;

  }
};

class CombustionVehicle: virtual public Vehicle
{
  int fuel;						//l
  int tank_capacity;			//l

public:
    CombustionVehicle (string model, int f, int tc, double e): Vehicle(model, e)
  {
	this->fuel = f;
	this->tank_capacity = tc;
  }

  void charge (int l)
  {
	fuel += l;
  }

  bool drive (int distance)
  {
	if (get_remain_range () < distance)
	  {
		fuel -= (distance / 100 * get_efficiency());
		return true;

	  }
	fuel = 0;
	return false;

  }

  double get_remain_range () const
  {
	return fuel / get_efficiency() * 100;
  }

  void display_info () const
  {
	Vehicle::display_info();
	cout << "Range: " << get_remain_range() << endl;
	cout << "Fuel: " << fuel << endl;
  }
};

class HybridVehicle:public ElectricVehicle, public CombustionVehicle
{
public:
  HybridVehicle (string model, int fuel, int tc, double fe, double ee, int bl,
				 int bc): Vehicle(model, fe), ElectricVehicle (model, bl, bc, ee),
	CombustionVehicle (model, fuel, tc, fe)
  {
  }
  
  double get_remain_range() const {
      return 300;
  }

  void display_info ()
  {
	CombustionVehicle::display_info ();
	cout << "Battery efficiency: " << ElectricVehicle::
	  get_efficiency () << endl;
	cout << "Battery range: " << ElectricVehicle::get_remain_range () << endl;
	cout << "Battery: " << battery_level << endl;
  }
};

int
main ()
{
  ElectricVehicle* ev = new ElectricVehicle("Tesla 3", 100, 57, 8);
  //ev.display_info ();
  //ev.print_model();
  Vehicle* m = new CombustionVehicle("Mazda 3", 12, 50, 6);
  //m.display_info ();
  //m.print_model();
  Vehicle* h = new HybridVehicle("Hyundai", 12, 40, 6, 8, 100, 20);
  vector<Vehicle*> cars;
  cars.push_back(ev);
  cars.push_back(m);
  cars.push_back(h);
  for(int i=0; i < 3; i++) {
      cout << cars[i]->get_remain_range() << endl;
  }

  return 0;
}
