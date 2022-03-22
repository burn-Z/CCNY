#include<iostream>
#include<string>

using namespace std;

class Computer {
public:
	Computer(string c = "None",double cS = 0,int r = 0,int s = 0,double p = 0):
			cpu(c), clockSpeed(cS), ram(r), storage(s), price(p) {};
	void setCPU(string c) {	this->cpu = c;	}
	void setClockSpeed(double cS) {	this->clockSpeed = cS;	}
	void setRAM(int r) {	this->ram = r;	}
	void setStorage(int s) {	this->storage = s;	}
	void setPrice(double p) {	this->price = p;	}

	string getCPU() const {	return this->cpu;	}
	double getClockSpeed() const {	return this->clockSpeed;	}
	int getRAM() const {	return this->ram;	}
	int getStorage() const {	return this->storage;	}
	double getPrice() const {	return this->price;	}

	virtual void print() {
		cout << "CPU:\t\t" << this->cpu << endl;
		cout << "Clock Speed:\t" << this->clockSpeed << " GHz" << endl;
		cout << "RAM:\t\t" << this->ram << " GB" << endl;
		cout << "Storage:\t" << this->storage << " GB" << endl;
		cout << "Price:\t\t$" << this->price << endl;
	}
private:
	string cpu;
	double clockSpeed;
	int ram;
	int storage;
	double price;
};

class Desktop : public Computer {
public:
	Desktop(string tS = "None",int w = 0,int p = 0):
	towerSize(tS), warranty(w), PSU(p) {};

	void setTowerSize(string tS) {	this->towerSize = tS;	}
	void setWarranty(int w) {	this->warranty = w;	}
	void setPSU(int p) {	this->PSU = p;	}

	string getTowerSize() const {	return this->towerSize;	}
	int getWarranty() const {	return this->warranty;	}
	int getPSU() const {	return this->PSU;	}

	virtual void print() {
		this->Computer::print();
		cout << "Tower size:\t" << this->towerSize << endl;
		cout << "Warranty:\t" << this->warranty << " years" << endl;
		cout << "PSU:\t\t" << this->PSU << " watts" << endl;
	}
private:
	string towerSize;
	int warranty;
	int PSU;
};

class Laptop : public Computer {
public:
	Laptop(double sS = 0,double w = 0,int bL = 0):
	screenSize(sS), weight(w), batteryLife(bL) {};

	void setScreenSize(double sS) {	this->screenSize = sS;	}
	void setWeight(double w) {	this->weight = w;	}
	void setBatteryLife(int bL) {	this->batteryLife = bL;	}

	double getScreenSize() const {	return this->screenSize;	}
	double getWeight() const {	return this->weight;	}
	int getBatteryLife() const {	return this->batteryLife;	}

	void print() {
		this->Computer::print();
		cout << "Screen size:\t" << screenSize << " -inch(diagonal)" << endl;
		cout << "Weight: \t" << weight << " lbs" << endl;
		cout << "Battery life:\t" << batteryLife << " hours" << endl;
	}
private:
	double screenSize;
	double weight;
	int batteryLife;
};

class Dell : public Desktop {
public:
	void setModel(string m) {	this->model = m;	}
	string getModel() const { return this->model;	}

	void print() {
		cout << "Model:\t\t" << this->model << endl;
		this->Desktop::print();
	}
private:
	string model;
};

class HP : public Desktop {
public:
	void setModel(string m) {	this->model = m;	}
	string getModel() const { return this->model;	}

	void print() {
		cout << "Model:\t\t" << this->model << endl;
		this->Desktop::print();
	}
private:
	string model;
};

class Apple : public Laptop {
public:
	void setMake(string m) {	this->make = m;	}
	string getMake() const { return this->make;	}

	void print() {
		cout << "Make:\t\t" << this->make << endl;
		this->Laptop::print();
	}
private:
	string make;
};

class Lenovo : public Laptop {
public:
	void setMake(string m) {	this->make = m;	}
	string getMake() const { return this->make;	}

	void print() {
		cout << "Make:\t\t" << this->make << endl;
		this->Laptop::print();
	}
private:
	string make;
};


int main() {
	Dell c1;
	c1.setModel("Dell Inspiron");
	c1.setCPU("Intel Core i5-11600K");
	c1.setClockSpeed(3.8);
	c1.setRAM(32);
	c1.setStorage(2048);
	c1.setPrice(1699.99);
	c1.setTowerSize("Super");
	c1.setWarranty(3);
	c1.setPSU(500);

	HP c2;
	c2.setModel("HP Envy");
	c2.setCPU("Intel Core i7-4720HQ");
	c2.setClockSpeed(2.6);
	c2.setRAM(8);
	c2.setStorage(1024);
	c2.setPrice(1300);
	c2.setTowerSize("Mini");
	c2.setWarranty(5);
	c2.setPSU(300);

	Apple c3;
	c3.setMake("Macbook pro");
	c3.setCPU("M1");
	c3.setClockSpeed(3.1);
	c3.setRAM(16);
	c3.setStorage(512);
	c3.setPrice(1499.99);
	c3.setScreenSize(13.3);
	c3.setWeight(3);
	c3.setBatteryLife(17);

	Lenovo c4;
	c4.setMake("Lenovo Y547");
	c4.setCPU("AMD Ryzen 9 4900HS");
	c4.setClockSpeed(4.2);
	c4.setRAM(16);
	c4.setStorage(1024);
	c4.setPrice(899.99);
	c4.setScreenSize(17);
	c4.setWeight(5);
	c4.setBatteryLife(8);

	cout << "TESTING: Dell Class" << endl;
	cout << "------------------------------------------" << endl;
	c1.print();
	cout << "------------------------------------------" << endl;

	cout << "TESTING: HP Class" << endl;
	cout << "------------------------------------------" << endl;
	c2.print();
	cout << "------------------------------------------" << endl;

	cout << "TESTING: Apple Class" << endl;
	cout << "------------------------------------------" << endl;
	c3.print();
	cout << "------------------------------------------" << endl;

	cout << "TESTING: Lenovo Class" << endl;
	cout << "------------------------------------------" << endl;
	c4.print();
	cout << "------------------------------------------" << endl;


	return 0;
}