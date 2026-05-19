#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int yr)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle()
    {
        totalVehicles--;
    }

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    void setManufacturer(string manu)
    {
        manufacturer = manu;
    }

    void setModel(string mod)
    {
        model = mod;
    }

    void setYear(int yr)
    {
        year = yr;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    virtual void display()
    {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() : Vehicle()
    {
        fuelType = "";
    }

    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr)
    {
        fuelType = fuel;
    }

    void display()
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string manu, string mod, int yr,
                string fuel, int battery)
        : Car(id, manu, mod, yr, fuel)
    {
        batteryCapacity = battery;
    }

    void display()
    {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0;
    }

    SportsCar(int id, string manu, string mod, int yr,
              string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery)
    {
        topSpeed = speed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel)
    {
    }

    void display()
    {
        cout << "\n----- Sedan -----" << endl;
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel)
    {
    }

    void display()
    {
        cout << "\n----- SUV -----" << endl;
        Car::display();
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(int range)
    {
        flightRange = range;
    }

    void displayAircraft()
    {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string mod, int yr,
              string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range)
    {
    }

    void display()
    {
        cout << "\n----- Flying Car -----" << endl;
        Car::display();
        displayAircraft();
    }
};

class VehicleRegistry
{
private:
    Vehicle *vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle *v)
    {
        vehicles[count] = v;
        count++;
    }

    void displayVehicles()
    {
        if (count == 0)
        {
            cout << "\nNo vehicles found!\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << "\n======================" << endl;
            vehicles[i]->display();
        }
    }

    void searchVehicle(int id)
    {
        bool found = false;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle Found!" << endl;
                vehicles[i]->display();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nVehicle Not Found!\n";
        }
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
    }
};

int main()
{
    VehicleRegistry registry;

    int choice;

    do
    {
        cout << "\n========== VEHICLE REGISTRY SYSTEM ==========";
        cout << "\n1. Add Sedan";
        cout << "\n2. Add SUV";
        cout << "\n3. Add Electric Car";
        cout << "\n4. Add Sports Car";
        cout << "\n5. Add Flying Car";
        cout << "\n6. View All Vehicles";
        cout << "\n7. Search Vehicle by ID";
        cout << "\n8. Total Vehicles";
        cout << "\n9. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            int id, year;
            string manu, model, fuel;

            cout << "Enter Vehicle ID: ";
            cin >> id;

            cout << "Enter Manufacturer: ";
            cin >> manu;

            cout << "Enter Model: ";
            cin >> model;

            cout << "Enter Year: ";
            cin >> year;

            cout << "Enter Fuel Type: ";
            cin >> fuel;

            if (choice == 1)
            {
                registry.addVehicle(
                    new Sedan(id, manu, model, year, fuel));
            }

            else if (choice == 2)
            {
                registry.addVehicle(
                    new SUV(id, manu, model, year, fuel));
            }

            else if (choice == 3)
            {
                int battery;

                cout << "Enter Battery Capacity: ";
                cin >> battery;

                registry.addVehicle(
                    new ElectricCar(id, manu, model, year,
                                    fuel, battery));
            }

            else if (choice == 4)
            {
                int battery, speed;

                cout << "Enter Battery Capacity: ";
                cin >> battery;

                cout << "Enter Top Speed: ";
                cin >> speed;

                registry.addVehicle(
                    new SportsCar(id, manu, model, year,
                                  fuel, battery, speed));
            }
            else if (choice == 5)
            {
                int range;

                cout << "Enter Flight Range: ";
                cin >> range;

                registry.addVehicle(
                    new FlyingCar(id, manu, model, year,
                                  fuel, range));
            }
            cout << "\nVehicle Added Successfully!\n";
        }
        else if (choice == 6)
        {
            registry.displayVehicles();
        }

        else if (choice == 7)
        {
            int id;

            cout << "Enter Vehicle ID to Search: ";
            cin >> id;

            registry.searchVehicle(id);
        }

        else if (choice == 8)
        {
            cout << "\nTotal Vehicles: "
                 << Vehicle::totalVehicles << endl;
        }

        else if (choice == 9)
        {
            cout << "\nExiting Program...\n";
        }

        else
        {
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 9);
}

/*
	output
	
	========== VEHICLE REGISTRY SYSTEM ==========
1. Add Sedan
2. Add SUV
3. Add Electric Car
4. Add Sports Car
5. Add Flying Car
6. View All Vehicles
7. Search Vehicle by ID
8. Total Vehicles
9. Exit
Enter Choice: 1
Enter Vehicle ID: 2020
Enter Manufacturer: tata
Enter Model: nexon
Enter Year: 2012
Enter Fuel Type: petrol

Vehicle Added Successfully!

========== VEHICLE REGISTRY SYSTEM ==========
1. Add Sedan
2. Add SUV
3. Add Electric Car
4. Add Sports Car
5. Add Flying Car
6. View All Vehicles
7. Search Vehicle by ID
8. Total Vehicles
9. Exit
Enter Choice: 6

======================

----- Sedan -----

Vehicle ID: 2020
Manufacturer: tata
Model: nexon
Year: 2012
Fuel Type: petrol

========== VEHICLE REGISTRY SYSTEM ==========
1. Add Sedan
2. Add SUV
3. Add Electric Car
4. Add Sports Car
5. Add Flying Car
6. View All Vehicles
7. Search Vehicle by ID
8. Total Vehicles
9. Exit
Enter Choice: 8

Total Vehicles: 1

========== VEHICLE REGISTRY SYSTEM ==========
1. Add Sedan
2. Add SUV
3. Add Electric Car
4. Add Sports Car
5. Add Flying Car
6. View All Vehicles
7. Search Vehicle by ID
8. Total Vehicles
9. Exit
Enter Choice: 7
Enter Vehicle ID to Search: 2020

Vehicle Found!

----- Sedan -----

Vehicle ID: 2020
Manufacturer: tata
Model: nexon
Year: 2012
Fuel Type: petrol

========== VEHICLE REGISTRY SYSTEM ==========
1. Add Sedan
2. Add SUV
3. Add Electric Car
4. Add Sports Car
5. Add Flying Car
6. View All Vehicles
7. Search Vehicle by ID
8. Total Vehicles
9. Exit
Enter Choice: 9

Exiting Program...

--------------------------------
Process exited after 118.5 seconds with return value 0
Press any key to continue . . .

*/