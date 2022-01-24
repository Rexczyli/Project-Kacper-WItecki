#include <iostream>
#include <vector>

using namespace std;

void InputInt(string message, int& Variable) {
	cout << message;
	cin >> Variable;
}
void InputString(string message, string& Variable) {
	cout << message;
	cin >> Variable;
}

class Auto {
public:
	int EngineCapacity = 0;
	int Vmax = 0;
	int FuelConsumption = 0;
	int DistanceTravelled = 0;
	int FuelCapacity = 0;
	int CurrentFuel = 0;
	int CurrentSpeed = 0;
	int Weight = 0;

	string brand, model, VehicleType;
	string CurrentDirection = "North";

	Auto() {
		InputString("What brand is this vehicle? ", this->brand);
		InputString("What is the model of the vehicle? ", this->model);
		InputInt("What is the engine capacity? (cc)", this->EngineCapacity);
		InputInt("What is the Vmax? (km/h)", this->Vmax);
		InputInt("How much fuel does this vehicle consume? (liters/100km)", this->FuelConsumption);
		InputInt("How much fuel can it take? (liters)", this->FuelCapacity);
		InputInt("How much does it weight? (Kg)", this->Weight);
		this->CurrentFuel = this->FuelCapacity;
		cout << endl;
	}
	~Auto() {

	}
	void PrintVehicleInfo(string version = "") {
		if (version != "Short") {
			cout << this->brand << " " << this->model << endl;
			cout << "EngineCapacity: " << this->EngineCapacity << " cc" << endl;
			cout << "Vmax: " << this->Vmax << "Km/h" << endl;
			cout << "FuelConsumption: " << this->FuelConsumption << " Liters per 100 km" << endl;
			cout << "DistanceTravelled: " << this->DistanceTravelled << "km" << endl;
			cout << "FuelCapacity: " << this->FuelCapacity << "Liters" << endl;
			cout << "Weight: " << this->Weight << "Kg" << endl;
			cout << endl;
		}
		else {
			cout << this->brand << " " << this->model << endl;
			cout << endl;
		}
	}
	void PrintRange() {
		cout << "Fuel will last for: " << (this->CurrentFuel / this->FuelConsumption) * 100 << " km" << endl;
	}
	void setSpeed(int Speed) {
		if (Speed <= this->Vmax && Speed >= 0) {
			cout << "Speed was set to: " << Speed << endl;
			this->CurrentSpeed = Speed;
		}
		else
		{
			cout << "This Speed exceeds Vmax of the vehicle!" << endl;
		}
	}
	void SkipTime(int Hours) {
		for (int i = 0; i < Hours; i++) {
			this->DistanceTravelled += this->CurrentSpeed;
			this->CurrentFuel -= this->FuelConsumption;
			if (this->CurrentFuel <= 0) {
				cout << "Vehicle ran out of fuel!" << endl;
				break;
			}
		}
	}
	void Refuel(int Liters) {
		for (int i = 0; i < Liters; i++) {
			if (this->CurrentFuel >= this->FuelCapacity) {
				cout << "Tank is full!" << endl;
				break;
			}
			else {
				this->CurrentFuel++;
			}
		}
	}
	void Turn(int Where) {
		if (Where == 1) {
			if (this->CurrentDirection == "North") {
				this->CurrentDirection = "West";
				return;
			}
			else if (this->CurrentDirection == "West") {
				this->CurrentDirection = "South";
				return;
			}
			else if (this->CurrentDirection == "South") {
				this->CurrentDirection = "East";
				return;
			}
			else if (this->CurrentDirection == "East") {
				this->CurrentDirection = "North";
				return;
			}
		}
		else if (Where == 2) {
			if (this->CurrentDirection == "North") {
				this->CurrentDirection = "East";
				return;
			}
			else if (this->CurrentDirection == "West") {
				this->CurrentDirection = "North";
				return;
			}
			else if (this->CurrentDirection == "South") {
				this->CurrentDirection = "West";
				return;
			}
			else if (this->CurrentDirection == "East") {
				this->CurrentDirection = "South";
				return;
			}
		}
	}
private:
	int Speed = 0;
};
class Car : public Auto {
public:
	int NumberOfSeats = 0;
	Car() {
		VehicleType = "Car";
	}
};
class Truck : public Auto {
public:
	int capacity = 0;
	Truck() {
		VehicleType = "Truck";
	}
};

int main() {
	vector <Auto*> VehicleList;

	bool Running = true;
	bool Inside = false;
	bool Driving = false;

	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 0;

	while (Running) {
		cout << "Car simulator" << endl;
		cout << "Input a number to proceed: " << endl << endl;
		cout << "1:Create a new vehicle" << endl;
		cout << "2:List all the vehicles with full information" << endl;
		cout << "3:List all the vehicles" << endl;
		cout << "4:List all Trucks" << endl;
		cout << "5:Delete a car from the list" << endl;
		cout << "6:Enter the vehicle" << endl;
		cin >> X; cout << endl;

		switch (X) {
		case 1: {
			cout << "Do you want to create a car(1) or a truck(2)?" << endl;
			cin >> Y;
			switch (Y) {
			case 1: {
				Car* car = new(Car);
				VehicleList.push_back(car);
				break;
			}
			case 2: {
				Truck* truck = new(Truck);
				VehicleList.push_back(truck);
				break;
			}
			}
			break;
		}
		case 2: {
			for (int i = 0; i < VehicleList.size(); i++) {
				VehicleList[i]->PrintVehicleInfo();
			}
			break;
		}
		case 3: {
			for (int i = 0; i < VehicleList.size(); i++) {
				cout << i + 1 << ": ";
				VehicleList[i]->PrintVehicleInfo("Short");
			}
			break;
		}
		case 4: {
			for (int i = 0; i < VehicleList.size(); i++) {
				if (VehicleList[i]->VehicleType == "Truck") {
					cout << i + 1 << ": ";
					VehicleList[i]->PrintVehicleInfo("Short");
				}
			}
			break;
		}
		case 5: {
			for (int i = 0; i < VehicleList.size(); i++) {
				cout << i + 1 << ": ";
				VehicleList[i]->PrintVehicleInfo("Short");
			}
			cout << "Please enter index of the vehicle you want to delete" << endl;
			cin >> Y;
			VehicleList.erase(VehicleList.begin() + Y - 1);
		}
		case 6: {
			system("CLS");
			if (VehicleList.empty()) {
				cout << "There are no vehicles!" << endl;
				cout << endl;
				break;
			}
			for (int i = 0; i < VehicleList.size(); i++) {
				cout << i + 1 << ": ";
				VehicleList[i]->PrintVehicleInfo("Short");
			}
			cout << "Enter index of vehicle you want to enter" << endl;
			cin >> Y;
			if (Y > VehicleList.size()) {
				cout << "Incorrect value!" << endl;
				break;
			}

			Inside = true;
			while (Inside) {
				VehicleList[Y - 1]->PrintVehicleInfo("Short");
				cout << "Fuel :" << VehicleList[Y - 1]->CurrentFuel << "/" << VehicleList[Y - 1]->FuelCapacity << endl;
				cout << "1:Calculate max distance" << endl;
				cout << "2:Exit Vehicle" << endl;
				cout << "3:Start Engine" << endl;

				cin >> Z;
				switch (Z)
				{
				case 1:
					system("CLS");
					VehicleList[Y - 1]->PrintRange();
					break;
				case 2:
					Inside = false;
					system("CLS");
					break;
				case 3:
					Driving = true;
					system("CLS");
					break;
				}
				while (Driving) {
					cout << "Currently Heading: " << VehicleList[Y - 1]->CurrentDirection << endl;
					cout << "Current speed is: " << VehicleList[Y - 1]->CurrentSpeed << " Km/h" << endl;
					cout << "Current Fuel is: " << VehicleList[Y - 1]->CurrentFuel << "/" << VehicleList[Y - 1]->FuelCapacity << endl;
					cout << "Distance travelled is: " << VehicleList[Y - 1]->DistanceTravelled << "Km" << endl;
					cout << endl;
					cout << "Enter a number to:" << endl;
					cout << "1: Set Speed" << endl;
					cout << "2: Turn" << endl;
					cout << "3: Skip time" << endl;
					cout << "4: Refuel Vehicle" << endl;
					cout << "5: Stop the engine" << endl;
					cin >> Z;
					switch (Z) {
					case 1: {
						cout << "how fast you want to go? ";
						cin >> W;
						VehicleList[Y - 1]->setSpeed(W);
						break;
					}
					case 2: {
						cout << "Do you want to turn left(1) or right(2) ?" << endl;
						cin >> W;
						VehicleList[Y - 1]->Turn(W);
						break;
					}
					case 3: {
						cout << "How many hours do you want to skip? " << endl;
						cin >> W;
						VehicleList[Y - 1]->SkipTime(W);
						break;
					}
					case 4: {
						cout << "Current Fuel is: " << VehicleList[Y - 1]->CurrentFuel << "/" << VehicleList[Y - 1]->FuelCapacity << endl;
						cout << endl;
						cout << "How many liters do you want to pour into the tank?" << endl;
						cin >> W;
						VehicleList[Y - 1]->Refuel(W);
						break;
					}
					case 5: {
						if (VehicleList[Y - 1]->CurrentSpeed != 0) {
							cout << "You need to stop before u turn off the engine!" << endl;
							break;
						}
						else {
							Driving = false;
							break;
						}
					}
					}
				}
			}
		}
		}
	}
	return 0;
}