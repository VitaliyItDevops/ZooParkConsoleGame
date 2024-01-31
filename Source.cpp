#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;


//Animal parent class
class Animal {
public:


	string kind_of_animal = "";
	string name = "";
	float age = 0;
	int health_status = 0;
	int hunger_level = 0;
	int level_of_love = 0;
	int fatigue_level = 0;


	//Get Attribute
	string getKindOfAnimal() const {
		return kind_of_animal;
	}
	string getName() const {
		return name;
	}
	float getAge() const {
		return age;
	}
	int getHungerLevel() const {
		return hunger_level;
	}
	int getHealthStatus() const {
		return health_status;
	}
	int getLevelOfLove() const {
		return level_of_love;
	}
	int getFatigueLevel() const {
		return fatigue_level;
	}


	//Set Attribute
	void setKindOfAnimal(string kind_of_animal) {
		this->kind_of_animal = kind_of_animal;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAge(float age) {
		this->age = age;
	}
	void setHealthStatus(int health_status) {
		this->health_status = health_status;
	}
	void setHungerLevel(int hunger_level) {
		this->hunger_level = hunger_level;
	}
	void setLevelOfLove(int level_of_love) {
		this->level_of_love = level_of_love;
	}
	void setFatigueLevel(int fatigue_level) {
		this->fatigue_level = fatigue_level;
	}



};

// Child class from animal Lion
class Lion : public Animal {
public:
	int fury = 0;

	//Get Attribute
	int getFury() const {
		return fury;
	}
	//Set Attribute
	void setFury(int fury) {
		this->fury = fury;
	}

};

// Child class from animal Elephant
class Elephant : public Animal {
public:

	int fear = 0;

	//Get Attribute
	int getFear() const {
		return fear;
	}
	//Set Attribute
	void setFear(int fear) {
		this->fear = fear;
	}


};

// Child class from animal Monkey
class Monkey : public Animal {
public:

	int rage = 0;

	//Get Attribute
	int getRage() const {
		return rage;
	}
	//Set Attribute
	void setRage(int rage) {
		this->rage = rage;
	}


};

// Child class from animal Penguin
class Penguin : public Animal {
public:

	int temperature = 0;

	//Get Attribute
	int getTemperature() const {
		return temperature;
	}
	//Set Attribute
	void setTemperature(int temperature) {
		this->temperature = temperature;
	}
};



//Parent class for animal enclosures
class Enclosure {
public:
	string type_of_enclosure = "";
	int cleanliness_of_the_enclosure = 0;

	//Vector for storing custom enclosure data type
	vector <Enclosure> EnclosureBase;

	int quantity_lion = 0;
	int quantity_elephant = 0;
	int quantity_monkey = 0;
	int quantity_penguin = 0;

	//Get Attribute
	string getTypeOfEnclosure() const {
		return type_of_enclosure;
	}
	int getQuantityLion() const {
		return quantity_lion;
	}
	int getQuantityElephant() const {
		return quantity_elephant;
	}
	int getQuantityMonkey() const {
		return quantity_monkey;
	}
	int getQuantityPenguin() const {
		return quantity_penguin;
	}
	int getCleanlinessOfTheEnclosure() const {
		return cleanliness_of_the_enclosure;
	}



	//Set Attribute
	void setTypeOfEnclosure(string type_of_enclosure) {
		this->type_of_enclosure = type_of_enclosure;
	}

	void setQuantityLion(int quantity_lion) {
		this->quantity_lion = quantity_lion;
	}
	void setQuantityElephant(int quantity_elephant) {
		this->quantity_elephant = quantity_elephant;
	}
	void setQuantityMonkey(int quantity_monkey) {
		this->quantity_monkey = quantity_monkey;
	}
	void setQuantityPenguin(int quantity_penguin) {
		this->quantity_penguin = quantity_penguin;
	}
	void setCleanlinessOfTheEnclosure(int cleanliness_of_the_enclosure) {
		this->cleanliness_of_the_enclosure = cleanliness_of_the_enclosure;
	}


};



// Child class of each type of animal and enclosure, 
// the main class of the zoo in which all methods are implemented
class Zoo : public Lion, public Elephant, public Monkey, public Penguin, public Enclosure {
public:

	int quantity_animals = 0;
	int quantity_enclosure = 0;
	int feed = 0;
	int balance = 0;
	int number_of_visitors = 0;


	//Vectors through which we will work with 
	//animal attributes
	vector <Lion> LionBase;
	vector <Elephant> ElephantBase;
	vector <Monkey> MonkeyBase;
	vector <Penguin> PenguinBase;


	// A vector with a custom Zoo data type. In it we will output 
	// information from the file and the zoo and also enter it back
	// into the file.
	vector <Zoo> ZooBase;


	// A method that retrieves a record from the previous opening 
	// of the program. The record stores how many seconds have passed 
	// since UNIX was created, and converts seconds to hours. It also leaves 
	// the result in return for further work with this information.
	int LustTime() {

		ifstream file("LastRun.txt");
		if (!file.is_open()) {
			cout << "Error opening file." << endl;
		}

		int prev_run_time;
		file >> prev_run_time;
		file.close();

		int current_time = time(nullptr);

		int seconds_since_last_run = current_time - prev_run_time;

		int minutes_since_last_run = seconds_since_last_run / 60;
		int hours_since_last_run = minutes_since_last_run / 60;

		return hours_since_last_run;
	}




	//Get Attribute
	int getQuantityAnimals() const {
		return quantity_animals;
	}
	int getBalacne() const {
		return balance;
	}
	int getNumberOfVisitiors() const {
		return number_of_visitors;
	}
	int getQuantityEnclosure() const {
		return quantity_enclosure;
	}
	int getFeed() const {
		return feed;
	}



	//Set Attribute
	void setQuantityAnimals(int quantity_animals) {
		this->quantity_animals = quantity_animals;
	}
	void setBalance(int balance) {
		this->balance = balance;
	}
	void setNumberOfVisitiors(int number_of_visitors) {
		this->number_of_visitors = number_of_visitors;
	}
	void setQuantityEnclosure(int quantity_enclosure) {
		this->quantity_enclosure = quantity_enclosure;
	}
	void setFeed(int feed) {
		this->feed = feed;
	}






	////////////////////////////////////
   /// We get the attributes of the ///
  /// Zoo Park from the file       ///
 //////////////////////////////////// 
	int getZooFile(string print) {

		ZooBase.clear();
		ZooBase.resize(0);

		ifstream getZoo("ZooBase.txt");

		int Zquantity_animals;
		int Zquantity_enclosure;
		int Zfeed;
		int Zbalance;
		int Znumber_of_visitors;
		int Zcleanliness_of_the_enclosure;

		Zoo ZooAtribute;



		while (getZoo >> Zquantity_animals >> Zquantity_enclosure >> Zfeed >> Zbalance >> Znumber_of_visitors >> Zcleanliness_of_the_enclosure) {

			ZooAtribute.setQuantityAnimals(Zquantity_animals);
			ZooAtribute.setQuantityEnclosure(Zquantity_enclosure);
			ZooAtribute.setFeed(Zfeed);
			ZooAtribute.setBalance(Zbalance);
			ZooAtribute.setNumberOfVisitiors(Znumber_of_visitors);
			ZooAtribute.setCleanlinessOfTheEnclosure(Zcleanliness_of_the_enclosure);

			ZooBase.push_back(ZooAtribute);
		}

		//If the function accepts "print", it will print all the data from the file
		if (print == "print") {

			cout << "|Quantity animals: " << Zquantity_animals << "|  "
				<< "|Quantity enclosure: " << Zquantity_enclosure << "|  "
				<< "|Feed: " << Zfeed << "|  "
				<< "|Balance: " << Zbalance << "|  "
				<< "|Number_of_visitors: " << Znumber_of_visitors << "|   "
				<< "|Cleanliness Of The Enclosure: " << Zcleanliness_of_the_enclosure << "|" << endl;

		}

		getZoo.close();

		return Zcleanliness_of_the_enclosure;

	}



	////////////////////////////////////
   /// We get the attributes of the ///
  /// Lion from the file           ///
 //////////////////////////////////// 

	int getLionFile(string print) {

		LionBase.clear();
		LionBase.resize(0);

		ifstream getAnimals("LionBase.txt");

		if (!getAnimals.is_open()) {
			cout << "Failed to open file" << endl;
		}

		Lion Lion_push;

		string Lkind_of_animal;
		string Lname;
		float Lage;
		int Lhealth_status;
		int Lhunger_level;
		int Llevel_of_love;
		int Lfatigue_level;
		int Lfury;

		int Lquantity_lion = 0;


		while (getAnimals >> Lkind_of_animal >> Lname >> Lage >> Lhealth_status >> Lhunger_level >> Llevel_of_love >> Lfatigue_level >> Lfury) {

			Lion_push.setKindOfAnimal(Lkind_of_animal);
			Lion_push.setName(Lname);
			Lion_push.setAge(Lage);
			Lion_push.setHealthStatus(Lhealth_status);
			Lion_push.setHungerLevel(Lhunger_level);
			Lion_push.setLevelOfLove(Llevel_of_love);
			Lion_push.setFatigueLevel(Lfatigue_level);
			Lion_push.setFury(Lfury);

			Lquantity_lion++;

			LionBase.push_back(Lion_push);

		}

		//If the function accepts "print", it will print all the data from the file
		if (print == "print") {

			for (const auto& data : LionBase) {
				cout << "Kind of animal: " << data.getKindOfAnimal() << "|    |"
					<< "Name: " << data.getName() << "|    |"
					<< "Age: " << data.getAge() << "|\n"
					<< "Health status: " << data.getHealthStatus() << "|    |"
					<< "Hunger level: " << data.getHungerLevel() << "|    |"
					<< "Level of love: " << data.getLevelOfLove() << "|\n"
					<< "Fatigue level: " << data.getFatigueLevel() << "|    |"
					<< "Level fury: " << data.getFury() << "|" << endl;
				cout << endl;
			}
			cout << "___________________________________________________________________________" << endl;

		}

		getAnimals.close();

		return Lquantity_lion;

	}


	////////////////////////////////////
   ///    Removing the Lion  	   ///
  ///        from the file         ///
 //////////////////////////////////// 
	void delLionFile(string lionName) {

		LionBase.clear();
		LionBase.resize(0);

		getLionFile("0");

		//The name by which the file will be deleted
		string nameLion = lionName;
		vector <Lion> dataLion;


		for (const auto& lion : LionBase) {

			if (lion.getName() != nameLion) {
				dataLion.push_back(lion);
			}

		}

		ofstream addLionFile("LionBase.txt", ios::out);

		if (!addLionFile.is_open()) {
			std::cerr << "Error opening file!" << std::endl;
		}


		for (const auto& lion : dataLion) {
			addLionFile << lion.getKindOfAnimal() << " " << lion.getName() << " "
				<< lion.getAge() << " " << lion.getHealthStatus() << " "
				<< lion.getHungerLevel() << " " << lion.getLevelOfLove() << " "
				<< lion.getFatigueLevel() << " " << lion.getFury() << endl;
		}

		addLionFile.close();
	}



	////////////////////////////////////
   /// We get the attributes of the ///
  /// Elephant from the file       ///
 //////////////////////////////////// 

	int getElephantFile(string print) {

		ElephantBase.clear();
		ElephantBase.resize(0);

		ifstream getAnimals("ElephantBase.txt");

		if (!getAnimals.is_open()) {
			cout << "Error opening file!" << endl;
		}

		Elephant Elephant_push;

		string Ekind_of_animal;
		string Ename;
		float Eage;
		int Ehealth_status;
		int Ehunger_level;
		int Elevel_of_love;
		int Efatigue_level;
		int Efear;

		int Equantity_elephant = 0;

		while (getAnimals >> Ekind_of_animal >> Ename >> Eage >> Ehealth_status >> Ehunger_level >> Elevel_of_love >> Efatigue_level >> Efear) {

			Elephant_push.setKindOfAnimal(Ekind_of_animal);
			Elephant_push.setName(Ename);
			Elephant_push.setAge(Eage);
			Elephant_push.setHealthStatus(Ehealth_status);
			Elephant_push.setHungerLevel(Ehunger_level);
			Elephant_push.setLevelOfLove(Elevel_of_love);
			Elephant_push.setFatigueLevel(Efatigue_level);
			Elephant_push.setFear(Efear);

			Equantity_elephant++;

			ElephantBase.push_back(Elephant_push);

		}

		//If the function accepts "print", it will print all the data from the file
		if (print == "print") {

			for (const auto& data : ElephantBase) {
				cout << "Kind of animal: " << data.getKindOfAnimal() << "|    |"
					<< "Name: " << data.getName() << "|    |"
					<< "Age: " << data.getAge() << "|\n"
					<< "Health status: " << data.getHealthStatus() << "|    |"
					<< "Hunger level: " << data.getHungerLevel() << "|    |"
					<< "Level of love: " << data.getLevelOfLove() << "|\n"
					<< "Fatigue level: " << data.getFatigueLevel() << "|    |"
					<< "Level fear: " << data.getFear() << "|" << endl;
				cout << endl;
			}
			cout << "___________________________________________________________________________" << endl;

		}

		getAnimals.close();

		return Equantity_elephant;

	}


	////////////////////////////////////
   ///    Removing the Elephant	   ///
  ///        from the file         ///
 //////////////////////////////////// 

	void delElephantFile(string elephantName) {

		ElephantBase.clear();
		ElephantBase.resize(0);

		getElephantFile("0");

		//The name by which the file will be deleted
		string nameElephant = elephantName;
		vector <Elephant> dataElephant;


		for (const auto& elephant : ElephantBase) {

			if (elephant.getName() != nameElephant) {
				dataElephant.push_back(elephant);
			}

		}

		ofstream addAElephantFile("ElephantBase.txt", ios::out);

		if (!addAElephantFile.is_open()) {
			std::cerr << "Error opening file!" << std::endl;
		}


		for (const auto& elephant : dataElephant) {
			addAElephantFile << elephant.getKindOfAnimal() << " " << elephant.getName() << " "
				<< elephant.getAge() << " " << elephant.getHealthStatus() << " "
				<< elephant.getHungerLevel() << " " << elephant.getLevelOfLove() << " "
				<< elephant.getFatigueLevel() << " " << elephant.getFear() << endl;
		}

		addAElephantFile.close();
	}



	////////////////////////////////////
   /// We get the attributes of the ///
  /// Monkey from the file         ///
 //////////////////////////////////// 
	int getMonkeyFile(string print) {

		MonkeyBase.clear();
		MonkeyBase.resize(0);

		ifstream getAnimals("MonkeyBase.txt");

		if (!getAnimals.is_open()) {
			cout << "Error opening file!" << endl;
		}

		Monkey Monkey_push;

		string Mkind_of_animal;
		string Mname;
		float Mage;
		int Mhealth_status;
		int Mhunger_level;
		int Mlevel_of_love;
		int Mfatigue_level;
		int Mrage;


		int Mquantity_monkey = 0;


		while (getAnimals >> Mkind_of_animal >> Mname >> Mage >> Mhealth_status >> Mhunger_level >> Mlevel_of_love >> Mfatigue_level >> Mrage) {

			Monkey_push.setKindOfAnimal(Mkind_of_animal);
			Monkey_push.setName(Mname);
			Monkey_push.setAge(Mage);
			Monkey_push.setHealthStatus(Mhealth_status);
			Monkey_push.setHungerLevel(Mhunger_level);
			Monkey_push.setLevelOfLove(Mlevel_of_love);
			Monkey_push.setFatigueLevel(Mfatigue_level);
			Monkey_push.setRage(Mrage);

			Mquantity_monkey++;

			MonkeyBase.push_back(Monkey_push);

		}

		//If the function accepts "print", it will print all the data from the file
		if (print == "print") {

			for (const auto& data : MonkeyBase) {
				cout << "Kind of animal: " << data.getKindOfAnimal() << "|    |"
					<< "Name: " << data.getName() << "|    |"
					<< "Age: " << data.getAge() << "|\n"
					<< "Health status: " << data.getHealthStatus() << "|    |"
					<< "Hunger level: " << data.getHungerLevel() << "|    |"
					<< "Level of love: " << data.getLevelOfLove() << "|\n"
					<< "Fatigue level: " << data.getFatigueLevel() << "|    |"
					<< "Level rage: " << data.getRage() << "|" << endl;
				cout << endl;
			}
			cout << "___________________________________________________________________________" << endl;

		}

		getAnimals.close();


		return Mquantity_monkey;

	}


	////////////////////////////////////
   ///    Removing the Monkey	    ///
  ///        from the file         ///
 //////////////////////////////////// 
	void delMonkeyFile(string monkeyName) {

		MonkeyBase.clear();
		MonkeyBase.resize(0);

		getMonkeyFile("0");

		//The name by which the file will be deleted
		string nameMonkey = monkeyName;
		vector <Monkey> dataMonkey;


		for (const auto& monkey : MonkeyBase) {

			if (monkey.getName() != nameMonkey) {
				dataMonkey.push_back(monkey);
			}

		}

		ofstream addMonkeyFile("MonkeyBase.txt", ios::out);

		if (!addMonkeyFile.is_open()) {
			std::cerr << "Error opening file!" << std::endl;
		}


		for (const auto& monkey : dataMonkey) {
			addMonkeyFile << monkey.getKindOfAnimal() << " " << monkey.getName() << " "
				<< monkey.getAge() << " " << monkey.getHealthStatus() << " "
				<< monkey.getHungerLevel() << " " << monkey.getLevelOfLove() << " "
				<< monkey.getFatigueLevel() << " " << monkey.getRage() << endl;
		}

		dataMonkey.clear();
		dataMonkey.resize(0);
		addMonkeyFile.close();
	}




	////////////////////////////////////
   /// We get the attributes of the ///
  /// Penguin from the file        ///
 ////////////////////////////////////
	int getPenguinFile(string print) {

		PenguinBase.clear();
		PenguinBase.resize(0);

		ifstream getAnimals("PenguinBase.txt");

		if (!getAnimals.is_open()) {
			cout << "Error opening file!" << endl;
		}

		Penguin Penguin_push;

		string Pkind_of_animal;
		string Pname;
		float Page;
		int Phealth_status;
		int Phunger_level;
		int Plevel_of_love;
		int Pfatigue_level;
		int Ptemperature;


		int Pquantity_penguin = 0;


		while (getAnimals >> Pkind_of_animal >> Pname >> Page >> Phealth_status >> Phunger_level >> Plevel_of_love >> Pfatigue_level >> Ptemperature) {

			Penguin_push.setKindOfAnimal(Pkind_of_animal);
			Penguin_push.setName(Pname);
			Penguin_push.setAge(Page);
			Penguin_push.setHealthStatus(Phealth_status);
			Penguin_push.setHungerLevel(Phunger_level);
			Penguin_push.setLevelOfLove(Plevel_of_love);
			Penguin_push.setFatigueLevel(Pfatigue_level);
			Penguin_push.setTemperature(Ptemperature);

			Pquantity_penguin++;

			PenguinBase.push_back(Penguin_push);

		}


		setQuantityPenguin(Pquantity_penguin);

		//If the function accepts "print", it will print all the data from the file
		if (print == "print") {

			for (const auto& data : PenguinBase) {
				cout << "Kind of animal: " << data.getKindOfAnimal() << "|    |"
					<< "Name: " << data.getName() << "|    |"
					<< "Age: " << data.getAge() << "|\n"
					<< "Health status: " << data.getHealthStatus() << "|    |"
					<< "Hunger level: " << data.getHungerLevel() << "|    |"
					<< "Level of love: " << data.getLevelOfLove() << "|\n"
					<< "Fatigue level: " << data.getFatigueLevel() << "|    |"
					<< "Level temperature: " << data.getTemperature() << "|" << endl;
				cout << endl;
			}
			cout << "___________________________________________________________________________" << endl;

		}

		getAnimals.close();

		return Pquantity_penguin;

	}



	////////////////////////////////////
   ///    Removing the Penguin	    ///
  ///        from the file         ///
 //////////////////////////////////// 
	void delPenguinFile(string penguinName) {

		PenguinBase.clear();
		PenguinBase.resize(0);

		getPenguinFile("0");

		//The name by which the file will be deleted
		string namePenguin = penguinName;
		vector <Penguin> dataPenguin;


		for (const auto& penguin : PenguinBase) {

			if (penguin.getName() != namePenguin) {
				dataPenguin.push_back(penguin);
			}

		}

		ofstream addPenguinFile("PenguinBase.txt", ios::out);

		if (!addPenguinFile.is_open()) {
			std::cerr << "Error opening file!" << std::endl;
		}


		for (const auto& penguin : dataPenguin) {
			addPenguinFile << penguin.getKindOfAnimal() << " " << penguin.getName() << " "
				<< penguin.getAge() << " " << penguin.getHealthStatus() << " "
				<< penguin.getHungerLevel() << " " << penguin.getLevelOfLove() << " "
				<< penguin.getFatigueLevel() << " " << penguin.getTemperature() << endl;
		}

		addPenguinFile.close();
	}

	//////////////////////////////////////
   /// Output all valiers from a file ///
  //////////////////////////////////////

	int getEnclosureFile(string print) {

		ifstream getEnclosure("EnclosureBase.txt");

		if (!getEnclosure.is_open()) {

			cout << "Error opening file!" << endl;

		}

		Enclosure enclosure_push;

		string Eenclosure_type;
		int Eenclosure_Animal_Quantity;

		int Equantity_enclosure = 0;

		while (getEnclosure >> Eenclosure_type >> Eenclosure_Animal_Quantity) {

			if (Eenclosure_type == "Lion") {
				enclosure_push.setTypeOfEnclosure(Eenclosure_type);
				enclosure_push.setQuantityLion(Eenclosure_Animal_Quantity);

				Equantity_enclosure++;

				EnclosureBase.push_back(enclosure_push);

			}
			else if (Eenclosure_type == "Elephant") {
				enclosure_push.setTypeOfEnclosure(Eenclosure_type);
				enclosure_push.setQuantityElephant(Eenclosure_Animal_Quantity);

				Equantity_enclosure++;

				EnclosureBase.push_back(enclosure_push);

			}
			else if (Eenclosure_type == "Monkey") {
				enclosure_push.setTypeOfEnclosure(Eenclosure_type);
				enclosure_push.setQuantityMonkey(Eenclosure_Animal_Quantity);

				Equantity_enclosure++;

				EnclosureBase.push_back(enclosure_push);

			}
			else if (Eenclosure_type == "Penguin") {
				enclosure_push.setTypeOfEnclosure(Eenclosure_type);
				enclosure_push.setQuantityPenguin(Eenclosure_Animal_Quantity);

				Equantity_enclosure++;

				EnclosureBase.push_back(enclosure_push);

			}

		}

		getEnclosure.close();

		//If the function accepts "print", it will print all the data from the file
		if (print == "print") {
			for (const auto& data : EnclosureBase) {
				cout << "Type of enclosure: " << data.getTypeOfEnclosure() << endl;
			}
		}

		return Equantity_enclosure;

	}

	////////////////////////////////////
   /// Checking for the presence of ///
  /// an aviary before adding it   ///
 ////////////////////////////////////

	bool ReadySetEnclosure(string Onetype) {

		ifstream GetTypeEnclosure("EnclosureBase.txt");

		if (!GetTypeEnclosure.is_open()) {
			cerr << "Error opening file!" << endl;
		}

		string dataType = Onetype;
		bool ready = false;

		string Etype_enclosure = "";
		int Equantity_animal = 0;

		while (GetTypeEnclosure >> Etype_enclosure >> Equantity_animal) {

			if (dataType == Etype_enclosure) {
				ready = true;
			}
		}

		GetTypeEnclosure.close();

		return ready;


	}

	///////////////////////////////////
   ///Add a lion enclosure to file ///
  ///////////////////////////////////

	bool setLionEnclosureFile() {

		bool Final = ReadySetEnclosure("Lion");
		bool byNo = false;

		//Checking for the presence of an aviary
		if (Final == false) {

			//If the addition was successful, the method should return 
			//true for further actions
			byNo = true;
			Enclosure EnclosureAtribute;

			ofstream setEnclosure("EnclosureBase.txt", ios::app);

			if (!setEnclosure.is_open()) {
				cout << "Error opening file!" << endl;
			}

			EnclosureAtribute.setTypeOfEnclosure("LionEnclosure");
			EnclosureAtribute.setQuantityLion(0);



			vector <Enclosure> EnclosureBaseDefaultValues;
			EnclosureBaseDefaultValues.push_back(EnclosureAtribute);

			for (const auto& enclosure : EnclosureBaseDefaultValues) {
				setEnclosure << enclosure.getTypeOfEnclosure() << " " << enclosure.getQuantityLion() << " " << endl;
			}

			setEnclosure.close();
		}
		else {
			cout << "Already purchased" << endl;
		}
		cout << "Enter something: ";
		string n;
		cin >> n;

		return byNo;
	}


	////////////////////////////////////////
   /// Add a Elephant enclosure to file ///
  ////////////////////////////////////////

	bool setElephantEnclosureFile() {

		bool Final = ReadySetEnclosure("Elephant");
		bool byNo = false;

		//Checking for the presence of an aviary
		if (Final == false) {

			//If the addition was successful, the method should return 
			//true for further actions
			byNo = true;
			Enclosure EnclosureAtribute;

			ofstream setEnclosure("EnclosureBase.txt", ios::app);

			if (!setEnclosure.is_open()) {
				cout << "Error opening file! " << endl;
			}

			EnclosureAtribute.setTypeOfEnclosure("ElephantEnclosure");
			EnclosureAtribute.setQuantityLion(0);


			vector <Enclosure> EnclosureBaseDefaultValues;
			EnclosureBaseDefaultValues.push_back(EnclosureAtribute);

			for (const auto& enclosure : EnclosureBaseDefaultValues) {
				setEnclosure << enclosure.getTypeOfEnclosure() << " " << enclosure.getQuantityLion() << " " << endl;
			}

			setEnclosure.close();

		}
		else {
			cout << "Already purchased" << endl;
		}
		cout << "Enter something: ";
		string n;
		cin >> n;

		return byNo;
	}

	///////////////////////////////////////
   /// Add a Penguin enclosure to file ///
  ///////////////////////////////////////

	bool setPenguinEnclosureFile() {

		//Checking for the presence of an aviary
		bool Final = ReadySetEnclosure("Elephant");
		bool byNo = false;


		if (Final == false) {

			//If the addition was successful, the method should return 
			//true for further actions
			byNo = true;
			Enclosure EnclosureAtribute;

			ofstream setEnclosure("EnclosureBase.txt", ios::app);

			if (!setEnclosure.is_open()) {
				cout << "Error opening file!" << endl;
			}

			EnclosureAtribute.setTypeOfEnclosure("PenguinEnclosure");
			EnclosureAtribute.setQuantityLion(0);


			vector <Enclosure> EnclosureBaseDefaultValues;
			EnclosureBaseDefaultValues.push_back(EnclosureAtribute);

			for (const auto& enclosure : EnclosureBaseDefaultValues) {
				setEnclosure << enclosure.getTypeOfEnclosure() << " " << enclosure.getQuantityLion() << " "
					<< endl;
			}

			setEnclosure.close();
		}
		else {
			cout << "Already purchased" << endl;
		}
		cout << "Enter something: ";
		string n;
		cin >> n;

		return byNo;
	}



	//////////////////////////////
   /// Add a lion to the file ///
  //////////////////////////////

	bool setLionFile() {

		int quantityLion = getLionFile("0");
		bool byNo = false;


		if (quantityLion < 5) {

			//Checking for the presence of an aviary
			bool readyTwo = ReadySetEnclosure("Lion");

			if (readyTwo == true) {

				//If the addition was successful, the method should return 
				//true for further actions
				byNo = true;
				Lion LionAtribute;

				ofstream setAnimals("LionBase.txt", ios::app);

				if (!setAnimals.is_open()) {
					cout << "Error opening file!" << endl;
				}

				LionAtribute.setKindOfAnimal("Lion");
				cout << "Enter new name: ";
				string new_name;
				cin >> new_name;
				LionAtribute.setName(new_name);
				LionAtribute.setAge(5);
				LionAtribute.setHealthStatus(10);
				LionAtribute.setHungerLevel(0);
				LionAtribute.setLevelOfLove(10);
				LionAtribute.setFatigueLevel(0);
				LionAtribute.setFury(0);


				vector <Lion> LionBaseDefaultValues;
				LionBaseDefaultValues.push_back(LionAtribute);

				for (const Lion& lion : LionBaseDefaultValues) {
					setAnimals << lion.getKindOfAnimal() << " " << lion.getName() << " "
						<< lion.getAge() << " " << lion.getHealthStatus() << " "
						<< lion.getHungerLevel() << " " << lion.getLevelOfLove() << " "
						<< lion.getFatigueLevel() << " " << lion.getFury() << endl;
				}

				setAnimals.close();
			}
			else {
				cout << "you didn't buy an enclosure for lions" << endl;
			}

		}
		else {
			cout << "You have reached the maximum number of lions" << endl;
		}
		cout << "Enter something: ";
		string n;
		cin >> n;

		return byNo;
	}

	//////////////////////////////////
   /// Add a Elephant to the file ///
  //////////////////////////////////

	bool setElephantFile() {

		int quantityElephant = getElephantFile("0");
		bool byNo = false;

		if (quantityElephant < 3) {

			//Checking for the presence of an aviary
			bool readyTwo = ReadySetEnclosure("Elephant");

			if (readyTwo == true) {


				//If the addition was successful, the method should return 
				//true for further actions
				byNo = true;
				Elephant ElephantAtribute;

				ofstream setAnimals("ElephantBase.txt", ios::app);

				if (!setAnimals.is_open()) {
					cout << "Failed to open file!" << endl;
				}

				ElephantAtribute.setKindOfAnimal("Elephant");
				cout << "Enter new name: ";
				string new_name;
				cin >> new_name;
				ElephantAtribute.setName(new_name);
				ElephantAtribute.setAge(5);
				ElephantAtribute.setHealthStatus(10);
				ElephantAtribute.setHungerLevel(0);
				ElephantAtribute.setLevelOfLove(10);
				ElephantAtribute.setFatigueLevel(0);
				ElephantAtribute.setFear(0);


				vector <Elephant> ElephantBaseDefaultValues;
				ElephantBaseDefaultValues.push_back(ElephantAtribute);

				for (const Elephant& elephant : ElephantBaseDefaultValues) {
					setAnimals << elephant.getKindOfAnimal() << " " << elephant.getName() << " "
						<< elephant.getAge() << " " << elephant.getHealthStatus() << " "
						<< elephant.getHungerLevel() << " " << elephant.getLevelOfLove() << " "
						<< elephant.getFatigueLevel() << " " << elephant.getFear() << endl;
				}

				setAnimals.close();
			}
			else {
				cout << "you didn't buy an elephant enclosure" << endl;
			}

		}
		else {
			cout << "You have reached the maximum number of elephants" << endl;
		}
		cout << "Enter something: ";
		string n;
		cin >> n;

		return byNo;
	}

	////////////////////////////////
   /// Add a Monkey to the file ///
  ////////////////////////////////

	bool setMonkeyFile() {

		int qunatityMonkey = getMonkeyFile("0");
		bool byNo = false;

		if (qunatityMonkey <= 10) {

			//Checking for the presence of an aviary
			bool readyTwo = ReadySetEnclosure("Monkey");

			if (readyTwo == true) {


				//If the addition was successful, the method should return 
				//true for further actions
				byNo = true;
				Monkey MonkeyAtribute;

				ofstream setAnimals("MonkeyBase.txt", ios::app);

				if (!setAnimals.is_open()) {
					cout << "Failed to open file!" << endl;
				}

				MonkeyAtribute.setKindOfAnimal("Monkey");
				cout << "Enter new name: ";
				string new_name;
				cin >> new_name;
				MonkeyAtribute.setName(new_name);
				MonkeyAtribute.setAge(5);
				MonkeyAtribute.setHealthStatus(10);
				MonkeyAtribute.setHungerLevel(0);
				MonkeyAtribute.setLevelOfLove(10);
				MonkeyAtribute.setFatigueLevel(0);
				MonkeyAtribute.setRage(0);


				vector <Monkey> MonkeyBaseDefaultValues;
				MonkeyBaseDefaultValues.push_back(MonkeyAtribute);

				for (const Monkey& monkey : MonkeyBaseDefaultValues) {
					setAnimals << monkey.getKindOfAnimal() << " " << monkey.getName() << " "
						<< monkey.getAge() << " " << monkey.getHealthStatus() << " "
						<< monkey.getHungerLevel() << " " << monkey.getLevelOfLove() << " "
						<< monkey.getFatigueLevel() << " " << monkey.getRage() << endl;
				}

				setAnimals.close();

			}
			else {
				cout << "You didn't buy a monkey enclosure" << endl;
			}


		}
		else {
			cout << "You bought all the monkeys" << endl;
		}

		cout << "Enter something: ";
		string n;
		cin >> n;

		return byNo;
	}

	/////////////////////////////////
   /// Add a Penguin to the file ///
  /////////////////////////////////

	bool setPenguinFile() {

		int quantityPenguin = getPenguinFile("0");
		bool byNo = false;

		if (quantityPenguin <= 8) {


			//Checking for the presence of an aviary
			bool readyTwo = ReadySetEnclosure("Monkey");

			if (readyTwo == true) {


				//If the addition was successful, the method should return 
				//true for further actions
				byNo = true;
				Penguin PenguinAtribute;

				ofstream setAnimals("PenguinBase.txt", ios::app);

				if (!setAnimals.is_open()) {
					cout << "Failed to open file!" << endl;
				}


				PenguinAtribute.setKindOfAnimal("Penguin");
				cout << "Enter new name: ";
				string new_name;
				cin >> new_name;
				PenguinAtribute.setName(new_name);
				PenguinAtribute.setAge(5);
				PenguinAtribute.setHealthStatus(10);
				PenguinAtribute.setHungerLevel(0);
				PenguinAtribute.setLevelOfLove(10);
				PenguinAtribute.setFatigueLevel(0);
				PenguinAtribute.setTemperature(0);


				vector <Penguin> PenguinBaseDefaultValues;
				PenguinBaseDefaultValues.push_back(PenguinAtribute);

				for (const Penguin& penguin : PenguinBaseDefaultValues) {
					setAnimals << penguin.getKindOfAnimal() << " " << penguin.getName() << " "
						<< penguin.getAge() << " " << penguin.getHealthStatus() << " "
						<< penguin.getHungerLevel() << " " << penguin.getLevelOfLove() << " "
						<< penguin.getFatigueLevel() << " " << penguin.getTemperature() << endl;
				}

				setAnimals.close();
			}
			else {
				cout << "You didn't buy a penguin enclosure" << endl;
			}

		}
		else {
			cout << "You bought all the penguins" << endl;
		}
		cout << "Enter something: ";
		string n;
		cin >> n;

		return byNo;
	}

	//Top 2 largest methods of this code, all our methods 
	//and zoo logic are implemented here
	string setZooFile(string mode, int Fquantity) {

		//Takes two parameters, operating mode, and 
		//quantity(we need quantity to write how much food we want to buy at the zoo)

		ZooBase.clear();
		ZooBase.resize(0);

		ifstream getZoo("ZooBase.txt");

		int Zquantity_animals;
		int Zquantity_enclosure;
		int Zfeed;
		int Zbalance;
		int Znumber_of_visitors;
		int Zcleanliness_of_the_enclosure;

		Zoo ZooAtribute;


		while (getZoo >> Zquantity_animals >> Zquantity_enclosure >> Zfeed >> Zbalance >> Znumber_of_visitors >> Zcleanliness_of_the_enclosure) {

			ZooAtribute.setQuantityAnimals(Zquantity_animals);
			ZooAtribute.setQuantityEnclosure(Zquantity_enclosure);
			ZooAtribute.setFeed(Zfeed);
			ZooAtribute.setBalance(Zbalance);
			ZooAtribute.setNumberOfVisitiors(Znumber_of_visitors);
			ZooAtribute.setCleanlinessOfTheEnclosure(Zcleanliness_of_the_enclosure);

			ZooBase.push_back(ZooAtribute);
		}

		getZoo.close();


		srand(time(nullptr));

		ofstream setZoo("ZooBase.txt", ios::out);
		string FoodAndCleaning = "";


		//Each time the program is opened, it records how many hours have passed, 
		// and, depending on the number, sets the attributes of the zoo.
		if (mode == "setAtribute") {

			for (const auto& data : ZooBase)
			{
				int quantityLion = getLionFile("0");
				int quantityElephant = getElephantFile("0");
				int quantityMonkey = getMonkeyFile("0");
				int quantityPenguin = getPenguinFile("0");

				int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

				int randomNumber = 0;
				int set_balance = 0;

				if (getQuantity_animals <= 4) {

					set_balance = LustTime() * 2 + data.getBalacne();
					randomNumber = rand() % 11 + 10;

				}
				else if (getQuantity_animals >= 4 and getQuantity_animals <= 8) {
					set_balance = LustTime() * 4 + data.getBalacne();
					randomNumber = rand() % 11 + 40;
				}
				else if (getQuantity_animals >= 8 and getQuantity_animals <= 12) {
					set_balance = LustTime() * 8 + data.getBalacne();
					randomNumber = rand() % 31 + 50;
				}
				else if (getQuantity_animals >= 12 and getQuantity_animals <= 20) {
					set_balance = LustTime() * 16 + data.getBalacne();
					randomNumber = rand() % 41 + 80;
				}
				else if (getQuantity_animals >= 20) {
					set_balance = LustTime() * 26 + data.getBalacne();
					randomNumber = rand() % 41 + 120;
				}

				setZoo << getQuantity_animals << " "
					<< getEnclosureFile("0") << " "
					<< data.getFeed() << " "
					<< set_balance << " "
					<< randomNumber << " "
					<< data.getCleanlinessOfTheEnclosure() << endl;


			}

		}
		//Purchase mode
		else if (mode == "AddMonkey") {

			for (const auto& data : ZooBase) {

				int TBalance = 4;
				int PBalance = data.getBalacne() - TBalance;

				if (PBalance >= 0) {

					bool d = setMonkeyFile();


					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;


					int Abalance = data.getBalacne();

					if (d == true) {
						Abalance = Abalance - TBalance;
					}
					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}


			}
		}
		//Purchase mode
		else if (mode == "AddLion") {

			for (const auto& data : ZooBase) {

				int TBalance = 10;

				if (data.getBalacne() - TBalance >= 0) {

					bool d = setLionFile();

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;


					int Abalance = data.getBalacne();
					if (d == true) {
						Abalance = Abalance - TBalance;
					}
					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}


			}
		}
		//Purchase mode
		else if (mode == "AddElephant") {

			for (const auto& data : ZooBase) {

				int TBalance = 13;

				if (data.getBalacne() - TBalance >= 0) {

					bool d = setElephantFile();

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;


					int Abalance = data.getBalacne();
					if (d == true) {
						Abalance = Abalance - TBalance;
					}
					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}


			}
		}
		//Purchase mode
		else if (mode == "AddPenguin") {

			for (const auto& data : ZooBase) {

				int TBalance = 15;

				if (data.getBalacne() - TBalance >= 0) {

					bool d = setPenguinFile();

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;


					int Abalance = data.getBalacne();
					if (d == true) {
						Abalance = Abalance - TBalance;
					}

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}


			}
		}
		//Purchase mode
		else if (mode == "AddEnclosureLion") {

			for (const auto& data : ZooBase) {

				int TBalance = 15;

				if (data.getBalacne() - TBalance >= 0) {

					bool d = setLionEnclosureFile();

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;


					int Abalance = data.getBalacne();
					if (d == true) {
						Abalance = Abalance - TBalance;
					}

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}


			}
		}
		//Purchase mode
		else if (mode == "AddEnclosureElephant") {

			for (const auto& data : ZooBase) {

				int TBalance = 20;

				if (data.getBalacne() - TBalance >= 0) {

					bool d = setElephantEnclosureFile();

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;


					int Abalance = data.getBalacne();
					if (d == true) {
						Abalance = Abalance - TBalance;
					}

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}


			}
		}
		//Purchase mode
		else if (mode == "AddEnclosurePenguin") {

			for (const auto& data : ZooBase) {

				int TBalance = 25;

				if (data.getBalacne() - TBalance >= 0) {

					bool d = setPenguinEnclosureFile();

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;


					int Abalance = data.getBalacne();
					if (d == true) {
						Abalance = Abalance - TBalance;
					}

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					int quantityLion = getLionFile("0");
					int quantityElephant = getElephantFile("0");
					int quantityMonkey = getMonkeyFile("0");
					int quantityPenguin = getPenguinFile("0");

					int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}


			}
		}
		//Purchase mode
		else if (mode == "AddFeed") {

			for (const auto& data : ZooBase) {

				int quantityLion = getLionFile("0");
				int quantityElephant = getElephantFile("0");
				int quantityMonkey = getMonkeyFile("0");
				int quantityPenguin = getPenguinFile("0");

				int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

				int TBalance = Fquantity * 2;

				if (data.getBalacne() - TBalance >= 0) {

					int Afeed;
					Afeed = data.getFeed();
					Afeed += Fquantity;


					int Abalance = data.getBalacne();
					Abalance = Abalance - TBalance;

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< Afeed << " "
						<< Abalance << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;

					cout << "Done!" << endl;
				}
				else {

					setZoo << getQuantity_animals << " "
						<< getEnclosureFile("0") << " "
						<< data.getFeed() << " "
						<< data.getBalacne() << " "
						<< data.getNumberOfVisitiors() << " "
						<< data.getCleanlinessOfTheEnclosure() << endl;
					cout << "No money!" << endl;
				}

				string n;
				cin >> n;
			}

		}
		//Animal feeding regimen
		else if (mode == "delFeed") {

			for (const auto& data : ZooBase) {

				int quantityLion = getLionFile("0");
				int quantityElephant = getElephantFile("0");
				int quantityMonkey = getMonkeyFile("0");
				int quantityPenguin = getPenguinFile("0");

				int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

				int feed;

				feed = data.getFeed();
				feed -= 1;

				setZoo << getQuantity_animals << " "
					<< getEnclosureFile("0") << " "
					<< feed << " "
					<< data.getBalacne() << " "
					<< data.getNumberOfVisitiors() << " "
					<< data.getCleanlinessOfTheEnclosure() << endl;

				FoodAndCleaning = "Food";

				cout << "Good job!" << endl;
				cout << "Enter something: ";
				string n;
				cin >> n;
			}

		}
		//When elephants are afraid, they scare away visitors. 
		//This mode imposes a fine on the zoo equal to half of the balance
		else if (mode == "elephantFear") {

			for (const auto& data : ZooBase) {

				int quantityLion = getLionFile("0");
				int quantityElephant = getElephantFile("0");
				int quantityMonkey = getMonkeyFile("0");
				int quantityPenguin = getPenguinFile("0");

				int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

				int ElBalance = data.getBalacne() / 2;
				int ENumberOfVisitiors = data.getNumberOfVisitiors() / 2;

				setZoo << getQuantity_animals << " "
					<< getEnclosureFile("0") << " "
					<< data.getFeed() << " "
					<< ElBalance << " "
					<< ENumberOfVisitiors << " "
					<< data.getCleanlinessOfTheEnclosure() << endl;

				cout << "Broooo(((!" << endl;
			}

		}
		//Enclosure cleaning mode
		else if (mode == "cleaning") {

			for (const auto& data : ZooBase) {

				int quantityLion = getLionFile("0");
				int quantityElephant = getElephantFile("0");
				int quantityMonkey = getMonkeyFile("0");
				int quantityPenguin = getPenguinFile("0");

				int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

				setZoo << getQuantity_animals << " "
					<< getEnclosureFile("0") << " "
					<< data.getFeed() << " "
					<< data.getBalacne() << " "
					<< data.getNumberOfVisitiors() << " "
					<< 0 << endl;

				FoodAndCleaning = "Cleaning";

				cout << "Good bro!" << endl;
				cout << "Enter something: ";
				string n;
				cin >> n;
			}

		}
		//Since I implemented the hierarchy a little incorrectly,
		//the mode for introducing the attributes of the cleanliness 
		//of enclosures had to be moved to a separate method. It is also installed when opening
		//the program along with the attributes of the zoo
		else if (mode == "TimeAtributeCleaning") {


			for (const auto& data : ZooBase) {

				int quantityLion = getLionFile("0");
				int quantityElephant = getElephantFile("0");
				int quantityMonkey = getMonkeyFile("0");
				int quantityPenguin = getPenguinFile("0");

				int getQuantity_animals = quantityLion + quantityElephant + quantityMonkey + quantityPenguin;

				int atributeClean = data.getCleanlinessOfTheEnclosure() + LustTime();

				setZoo << getQuantity_animals << " "
					<< getEnclosureFile("0") << " "
					<< data.getFeed() << " "
					<< data.getBalacne() << " "
					<< data.getNumberOfVisitiors() << " "
					<< atributeClean << endl;

			}

		}

		setZoo.close();

		return FoodAndCleaning;

	}


	//The first largest method is to set the attributes of animals.
	void setAtributeAnimals(int hours, string foodAndClining) {

		//The first largest method is to set the attributes of animals.
		//It also takes parameters that the setZooFile() method returns.Namely, 
		//cleaning the enclosure or feeding.


		//If less than one hour has passed, the attribute change points are zero.
		float agePoint = 0;
		int healthPoint = 0;
		int hungerPoint = 0;
		int levelOfLovePoint = 0;
		int fatiguePoint = 0;
		int furyPoint = 0;
		int fearPoint = 0;
		int ragePoint = 0;
		int temperaturePoint = 0;


		//If more than one hour has passed, the attribute change points are changed 
		//according to the rules of the game, after which adjustments are made to the animals
		if (hours > 0) {
			agePoint = 0.1 * hours;
			healthPoint = hours;
			hungerPoint = 2;
			levelOfLovePoint = hours;
			fatiguePoint = hours;
			furyPoint = hours;
			fearPoint = hours;
			ragePoint = hours;
			temperaturePoint = hours;
		}

		//Temporary database for dead animals
		vector <Lion> dataDeadLion;
		vector <Elephant> dataDeadElephant;
		vector <Monkey> dataDeadMonkey;
		vector <Penguin> dataDeadPenguin;

		//Animal removal container
		vector <string> DeadLion;
		vector <string> AllDeadLions;
		vector <string> DeadElephant;
		vector <string> NoMoneyElephant;
		vector <string> DeadMonkey;
		vector <string> AllDeadMonkey;
		vector <string> DeadPenguin;
		vector <string> AllDeadPenguin;


		///////// We extract the animals from the file and immediately make these adjustments  ////////////////////////////////////////////////////////////////////////////////////////////////////////

		LionBase.clear();
		LionBase.resize(0);

		ifstream getLion("LionBase.txt");

		if (!getLion.is_open()) {
			cout << "Failed to open file" << endl;
		}

		Lion Lion_push;

		string Lkind_of_animal;
		string Lname;
		float Lage;
		int Lhealth_status;
		int Lhunger_level;
		int Llevel_of_love;
		int Lfatigue_level;
		int Lfury;


		while (getLion >> Lkind_of_animal >> Lname >> Lage >> Lhealth_status >> Lhunger_level >> Llevel_of_love >> Lfatigue_level >> Lfury) {


			//Attribute changes after feeding
			if (foodAndClining == "Food") {

				Lhealth_status = Lhealth_status + 1;
				Lhunger_level = Lhunger_level - 1;
				Llevel_of_love = Llevel_of_love + 1;
				Lfatigue_level = Lfatigue_level - 1;
				Lfury = Lfury - 1;

			}


			//If, some animals have critical statistics, they must die. Therefore, we write all the names into a vector
			Lage = Lage + agePoint;
			Lhealth_status = Lhealth_status - healthPoint;
			Lhunger_level = Lhunger_level + hungerPoint;
			Llevel_of_love = Llevel_of_love - levelOfLovePoint;
			Lfatigue_level = Lfatigue_level + fatiguePoint;
			Lfury = Lfury + furyPoint;
			//////////////////////////////
			if (Lage >= 15) {
				DeadLion.push_back(Lname);
			}
			if (Lhealth_status <= 0) {
				DeadLion.push_back(Lname);
			}
			if (Llevel_of_love <= 0)
			{
				Llevel_of_love = 0;
				Lfury += furyPoint;
			}
			if (Lhunger_level > 10) {
				DeadLion.push_back(Lname);
			}
			if (Lfury > 20) {
				AllDeadLions.push_back(Lname);
			}
			//////////////////////////////
			if (Lfatigue_level < 0) {
				Lfatigue_level = 0;
			}
			if (Lhunger_level < 0) {
				Lhunger_level = 0;
			}
			if (Lfury < 0) {
				Lfury = 0;
			}
			//////////////////////////////
			if (Lhealth_status > 10) {
				Lhealth_status = 10;
			}
			if (Llevel_of_love > 10)
			{
				Llevel_of_love = 10;

			}
			if (Lfatigue_level > 10) {
				Lfatigue_level = 10;
			}



			Lion_push.setKindOfAnimal(Lkind_of_animal);
			Lion_push.setName(Lname);
			Lion_push.setAge(Lage);
			Lion_push.setHealthStatus(Lhealth_status);
			Lion_push.setHungerLevel(Lhunger_level);
			Lion_push.setLevelOfLove(Llevel_of_love);
			Lion_push.setFatigueLevel(Lfatigue_level);
			Lion_push.setFury(Lfury);

			LionBase.push_back(Lion_push);
			dataDeadLion.push_back(Lion_push);

		}

		getLion.close();



		///////// We extract the animals from the file and immediately make these adjustments  ////////////////////////////////////////////////////////////////////////////////////////////////////////


		ElephantBase.clear();
		ElephantBase.resize(0);

		ifstream getElephant("ElephantBase.txt");

		if (!getElephant.is_open()) {
			cout << "Failed to open file" << endl;
		}

		Elephant Elephant_push;

		string Ekind_of_animal;
		string Ename;
		float Eage;
		int Ehealth_status;
		int Ehunger_level;
		int Elevel_of_love;
		int Efatigue_level;
		int Efear;


		while (getElephant >> Ekind_of_animal >> Ename >> Eage >> Ehealth_status >> Ehunger_level >> Elevel_of_love >> Efatigue_level >> Efear) {


			//Attribute changes after feeding
			if (foodAndClining == "Food") {

				Ehealth_status = Ehealth_status + 1;
				Ehunger_level = Ehunger_level - 1;
				Elevel_of_love = Elevel_of_love + 1;
				Efatigue_level = Efatigue_level - 1;
				Efear = Efear - 1;

			}

			Eage = Eage + agePoint;
			Ehealth_status = Ehealth_status - healthPoint;
			Ehunger_level = Ehunger_level + hungerPoint;
			Elevel_of_love = Elevel_of_love - levelOfLovePoint;
			Efatigue_level = Efatigue_level + fatiguePoint;
			Efear = Efear + fearPoint;



			//If, some animals have critical statistics, they must die. Therefore, we write all the names into a vector
			if (Eage >= 60) {
				DeadElephant.push_back(Ename);
			}
			if (Ehealth_status <= 0) {
				DeadElephant.push_back(Ename);
			}
			if (Elevel_of_love <= 0)
			{
				Elevel_of_love = 0;
				Efear += fearPoint;
			}
			if (Ehunger_level > 10) {
				DeadElephant.push_back(Ename);
			}
			if (Efear > 20) {
				NoMoneyElephant.push_back(Ename);
				Efear = 0;
			}
			///////////////////////////////
			if (Efatigue_level < 0) {
				Efatigue_level = 0;
			}
			if (Ehunger_level < 0) {
				Ehunger_level = 0;
			}
			if (Efear < 0) {
				Efear = 0;
			}
			//////////////////////////////
			if (Ehealth_status > 10) {
				Ehealth_status = 10;
			}
			if (Elevel_of_love > 10)
			{
				Elevel_of_love = 10;

			}
			if (Efatigue_level > 10) {
				Efatigue_level = 10;
			}


			Elephant_push.setKindOfAnimal(Ekind_of_animal);
			Elephant_push.setName(Ename);
			Elephant_push.setAge(Eage);
			Elephant_push.setHealthStatus(Ehealth_status);
			Elephant_push.setHungerLevel(Ehunger_level);
			Elephant_push.setLevelOfLove(Elevel_of_love);
			Elephant_push.setFatigueLevel(Efatigue_level);
			Elephant_push.setFear(Efear);

			ElephantBase.push_back(Elephant_push);
			dataDeadElephant.push_back(Elephant_push);

		}

		getElephant.close();

		///////// We extract the animals from the file and immediately make these adjustments  ////////////////////////////////////////////////////////////////////////////////////////////////////////


		MonkeyBase.clear();
		MonkeyBase.resize(0);

		ifstream getMonkey("MonkeyBase.txt");

		if (!getMonkey.is_open()) {
			cout << "Failed to open file" << endl;
		}

		Monkey Monkey_push;

		string Mkind_of_animal;
		string Mname;
		float Mage;
		int Mhealth_status;
		int Mhunger_level;
		int Mlevel_of_love;
		int Mfatigue_level;
		int Mrage;


		while (getMonkey >> Mkind_of_animal >> Mname >> Mage >> Mhealth_status >> Mhunger_level >> Mlevel_of_love >> Mfatigue_level >> Mrage) {


			//Attribute changes after feeding
			if (foodAndClining == "Food") {

				Mhealth_status = Mhealth_status + 1;
				Mhunger_level = Mhunger_level - 1;
				Mlevel_of_love = Mlevel_of_love + 1;
				Mfatigue_level = Mfatigue_level - 1;
				Mrage = Mrage - 1;

			}

			Mage = Mage + agePoint;
			Mhealth_status = Mhealth_status - healthPoint;
			Mhunger_level = Mhunger_level + hungerPoint;
			Mlevel_of_love = Mlevel_of_love - levelOfLovePoint;
			Mfatigue_level = Mfatigue_level + fatiguePoint;
			Mrage = Mrage + ragePoint;



			//If, some animals have critical statistics, they must die. Therefore, we write all the names into a vector
			if (Mage >= 60) {
				DeadMonkey.push_back(Mname);
			}
			if (Mhealth_status <= 0) {
				DeadMonkey.push_back(Mname);
			}
			if (Mlevel_of_love <= 0)
			{
				Mlevel_of_love = 0;
				Mrage += ragePoint;
			}
			if (Mhunger_level > 10) {
				DeadMonkey.push_back(Mname);
			}
			if (Mrage > 20) {
				AllDeadMonkey.push_back(Mname);
			}
			////////////////////////////////
			if (Mfatigue_level < 0) {
				Mfatigue_level = 0;
			}
			if (Mhunger_level < 0) {
				Mhunger_level = 0;
			}
			if (Mrage < 0) {
				Mrage = 0;
			}
			//////////////////////////////
			if (Mhealth_status > 10) {
				Mhealth_status = 10;
			}
			if (Mlevel_of_love > 10)
			{
				Mlevel_of_love = 10;

			}
			if (Mfatigue_level > 10) {
				Mfatigue_level = 10;
			}


			Monkey_push.setKindOfAnimal(Mkind_of_animal);
			Monkey_push.setName(Mname);
			Monkey_push.setAge(Mage);
			Monkey_push.setHealthStatus(Mhealth_status);
			Monkey_push.setHungerLevel(Mhunger_level);
			Monkey_push.setLevelOfLove(Mlevel_of_love);
			Monkey_push.setFatigueLevel(Mfatigue_level);
			Monkey_push.setRage(Mrage);

			MonkeyBase.push_back(Monkey_push);
			dataDeadMonkey.push_back(Monkey_push);
		}

		getMonkey.close();

		///////// We extract the animals from the file and immediately make these adjustments  ////////////////////////////////////////////////////////////////////////////////////////////////////////

		PenguinBase.clear();
		PenguinBase.resize(0);

		ifstream getPenguin("PenguinBase.txt");

		if (!getPenguin.is_open()) {
			cout << "Failed to open file" << endl;
		}

		Penguin Penguin_push;

		string Pkind_of_animal;
		string Pname;
		float Page;
		int Phealth_status;
		int Phunger_level;
		int Plevel_of_love;
		int Pfatigue_level;
		int Ptemperature;

		int Pquantity_penguin = 0;


		while (getPenguin >> Pkind_of_animal >> Pname >> Page >> Phealth_status >> Phunger_level >> Plevel_of_love >> Pfatigue_level >> Ptemperature) {


			//Changes in attributes after feeding or cleaning enclosures
			if (foodAndClining == "Cleaning") {

				Page = Page + agePoint;
				Phealth_status = Phealth_status - healthPoint;
				Phunger_level = Phunger_level + hungerPoint;
				Plevel_of_love = Plevel_of_love - levelOfLovePoint;
				Pfatigue_level = Pfatigue_level + fatiguePoint;
				Ptemperature = 0;

			}
			else if (foodAndClining == "Food") {

				Page = 0;
				Phealth_status = Phealth_status + 1;
				Phunger_level = Phunger_level - 1;
				Plevel_of_love = Plevel_of_love + 1;
				Pfatigue_level = Pfatigue_level - 1;
				Ptemperature = Ptemperature + temperaturePoint + getZooFile("0");
			}
			else {
				Page = Page + agePoint;
				Phealth_status = Phealth_status - healthPoint;
				Phunger_level = Phunger_level + hungerPoint;
				Plevel_of_love = Plevel_of_love - levelOfLovePoint;
				Pfatigue_level = Pfatigue_level + fatiguePoint;
				Ptemperature = Ptemperature + temperaturePoint + getZooFile("0");
			}

			//If, some animals have critical statistics, they must die. Therefore, we write all the names into a vector
			//If the enclosures are too dirty, penguins die from high fevers
			if (Page >= 20) {
				DeadPenguin.push_back(Pname);
			}
			if (Phealth_status <= 0) {
				DeadPenguin.push_back(Pname);
			}
			if (Plevel_of_love <= 0)
			{
				Plevel_of_love = 0;
			}
			if (Phunger_level > 10) {
				DeadPenguin.push_back(Pname);
			}
			if (Ptemperature > 20) {

				AllDeadPenguin.push_back(Pname);

			}
			/////////////////////////////
			if (Pfatigue_level < 0) {
				Pfatigue_level = 0;
			}
			if (Phunger_level < 0) {
				Phunger_level = 0;
			}
			if (Ptemperature < 0) {

				Ptemperature = 0;

			}
			//////////////////////////////
			if (Phealth_status > 10) {
				Phealth_status = 10;
			}
			if (Plevel_of_love > 10)
			{
				Plevel_of_love = 10;

			}
			if (Pfatigue_level > 10) {
				Pfatigue_level = 10;
			}

			Penguin_push.setKindOfAnimal(Pkind_of_animal);
			Penguin_push.setName(Pname);
			Penguin_push.setAge(Page);
			Penguin_push.setHealthStatus(Phealth_status);
			Penguin_push.setHungerLevel(Phunger_level);
			Penguin_push.setLevelOfLove(Plevel_of_love);
			Penguin_push.setFatigueLevel(Pfatigue_level);
			Penguin_push.setTemperature(Ptemperature);

			PenguinBase.push_back(Penguin_push);
			dataDeadPenguin.push_back(Penguin_push);
		}

		getPenguin.close();

		///////// We make all changes back to the file //////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		ofstream setLions("LionBase.txt", ios::out);

		if (!setLions.is_open()) {
			cout << "Failed to open file" << endl;
		}

		for (const Lion& lion : LionBase) {
			setLions << lion.getKindOfAnimal() << " " << lion.getName() << " "
				<< lion.getAge() << " " << lion.getHealthStatus() << " "
				<< lion.getHungerLevel() << " " << lion.getLevelOfLove() << " "
				<< lion.getFatigueLevel() << " " << lion.getFury() << endl;
		}

		setLions.close();

		///////// We make all changes back to the file //////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		ofstream setElephant("ElephantBase.txt", ios::out);

		if (!setElephant.is_open()) {
			cout << "Failed to open file" << endl;
		}


		for (const Elephant& elephant : ElephantBase) {
			setElephant << elephant.getKindOfAnimal() << " " << elephant.getName() << " "
				<< elephant.getAge() << " " << elephant.getHealthStatus() << " "
				<< elephant.getHungerLevel() << " " << elephant.getLevelOfLove() << " "
				<< elephant.getFatigueLevel() << " " << elephant.getFear() << endl;
		}

		setElephant.close();

		///////// We make all changes back to the file //////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		ofstream setMonkey("MonkeyBase.txt", ios::out);

		if (!setMonkey.is_open()) {
			cout << "Failed to open file" << endl;
		}


		for (const Monkey& monkey : MonkeyBase) {
			setMonkey << monkey.getKindOfAnimal() << " " << monkey.getName() << " "
				<< monkey.getAge() << " " << monkey.getHealthStatus() << " "
				<< monkey.getHungerLevel() << " " << monkey.getLevelOfLove() << " "
				<< monkey.getFatigueLevel() << " " << monkey.getRage() << endl;
		}

		setMonkey.close();

		///////// We make all changes back to the file //////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		ofstream setPenguin("PenguinBase.txt", ios::out);

		if (!setPenguin.is_open()) {
			cout << "Failed to open file" << endl;
		}


		for (const Penguin& penguin : PenguinBase) {
			setPenguin << penguin.getKindOfAnimal() << " " << penguin.getName() << " "
				<< penguin.getAge() << " " << penguin.getHealthStatus() << " "
				<< penguin.getHungerLevel() << " " << penguin.getLevelOfLove() << " "
				<< penguin.getFatigueLevel() << " " << penguin.getTemperature() << endl;
		}

		setPenguin.close();

		int alldeadLion = 0;
		int alldeadMonkey = 0;

		int alldeadPenguin = 0;


		//remove dead animals from the file
		if (AllDeadLions.size() > 0) {
			for (const auto& data : dataDeadLion)
			{
				delLionFile(data.getName());
				cout << data.getName() << " Dead!" << endl;
				alldeadLion += 2;
			}
		}
		if (alldeadLion == 0) {
			if (DeadLion.size() > 0) {
				for (const string& data : DeadLion)
				{
					delLionFile(data);
					cout << data << " Dead!" << endl;
				}
			}
		}

		if (DeadElephant.size() > 0) {
			for (const string& data : DeadElephant) {

				delElephantFile(data);
				cout << data << " Dead!" << endl;

			}
		}

		if (NoMoneyElephant.size() > 0) {

			for (const auto& data : NoMoneyElephant) {

				setZooFile("elephantFear", 0);

			}

		}

		if (AllDeadMonkey.size() > 0) {
			for (const auto& data : dataDeadMonkey)
			{
				delMonkeyFile(data.getName());
				cout << data.getName() << " Dead!" << endl;
				alldeadMonkey += 2;
			}
		}
		if (alldeadMonkey == 0) {
			if (DeadMonkey.size() > 0) {
				for (const string& data : DeadMonkey)
				{
					delMonkeyFile(data);
					cout << data << " Dead!" << endl;
				}
			}
		}
		if (AllDeadPenguin.size() > 0) {
			for (const auto& data : dataDeadPenguin)
			{
				delPenguinFile(data.getName());
				cout << data.getName() << " Dead!" << endl;
				alldeadPenguin += 2;
			}
		}
		if (alldeadPenguin == 0) {

			if (DeadPenguin.size() > 0) {
				for (const string& data : DeadPenguin)
				{
					delMonkeyFile(data);
					cout << data << " Dead!" << endl;
				}
			}


		}

	}




};


//Shop class for purchasing animals, enclosures and food
class Shop {
public:

	string name_of_product = "";
	int price = 0;

	//Container for outputting a directory from a file
	vector <Shop> ProductBase;


	//Get attribute
	int getPrice() const {
		return price;
	}
	string getNameOfProduct() const {
		return name_of_product;
	}

	//Set attribute
	void setPrice(int price) {
		this->price = price;
	}
	void setNameOfProduct(string name_of_product) {
		this->name_of_product = name_of_product;
	}


	//////////////////////////////////////
   /// Output all Product from a file ///
  //////////////////////////////////////
	void getProductFile(string print) {

		ProductBase.clear();
		ProductBase.resize(0);

		ifstream getProduct("ProductBase.txt");

		if (!getProduct.is_open()) {
			cout << "Failed to open file" << endl;
		}

		Shop product;

		string Pname_of_product;
		int Pprice;



		while (getProduct >> Pname_of_product >> Pprice) {


			product.setNameOfProduct(Pname_of_product);
			product.setPrice(Pprice);

			ProductBase.push_back(product);

		}

		//if the method takes "print" then it prints the entire directory
		if (print == "print") {

			for (const auto& roduct : ProductBase) {

				cout << "Name of product - " << roduct.getNameOfProduct() << endl;
				cout << "Price of product - " << roduct.getPrice() << "$" << endl;
				cout << "____________________________" << endl;

			}

		}

		getProduct.close();

	}


	//////////////////////////////////////
   ///   Menu for in-store purchases  ///
  //////////////////////////////////////
	void ByProductShop() {

		getProductFile("print");
		Zoo byShop;
		int quantityFeed;


		cout << "\n" << endl;

		bool bolen = true;

		while (bolen == true) {

			cout << "1. Buy food for animals." << endl;
			cout << "2. Buy a Monkey." << endl;
			cout << "3. Buy a Lion." << endl;
			cout << "4. Buy a Elephant." << endl;
			cout << "5. Buy a Penguin." << endl;
			cout << "6. Buy an enclosure for a Lion." << endl;
			cout << "7. Buy an enclosure for a Elephant." << endl;
			cout << "8. Buy an enclosure for a Penguin." << endl;
			cout << "0. Back." << endl;

			cout << "Enter the number of the item you want to select: ";

			int number3 = 10;
			cin >> number3;


			//All those methods from the Zoo class are implemented here
			//Namely setZooFile(), which takes parameters and, based on them, does its task
			switch (number3)
			{
			case 1:
				cout << "Enter quantity feed: ";
				cin >> quantityFeed;

				system("cls");

				byShop.setZooFile("AddFeed", quantityFeed);

				break;

			case 2:


				system("cls");

				byShop.setZooFile("AddMonkey", 0);

				break;

			case 3:

				system("cls");

				byShop.setZooFile("AddLion", 0);

				break;

			case 4:

				system("cls");

				byShop.setZooFile("AddElephant", 0);

				break;

			case 5:

				system("cls");

				byShop.setZooFile("AddPenguin", 0);

				break;

			case 6:

				system("cls");

				byShop.setZooFile("AddEnclosureLion", 0);

				break;

			case 7:

				system("cls");

				byShop.setZooFile("AddEnclosureElephant", 0);

				break;

			case 8:

				system("cls");

				byShop.setZooFile("AddEnclosurePenguin", 0);

				break;

			case 0:

				system("cls");
				bolen = false;
				break;

			}
		}


	}

};



//the StartGame class was created for code purity.
//It calls methods to set new attributes of the zoo and animals before 
// starting the game, and also adds new values ​​to the file which stores 
// the time of the previous opening of the game
class StartGame {
public:

	void readyStartGame() {

		Zoo ready;

		ready.setZooFile("TimeAtributeCleaning", 0);
		ready.setAtributeAnimals(ready.LustTime(), "0");
		ready.setZooFile("setAtribute", 0);


		ifstream file("LastRun.txt");
		if (!file.is_open()) {
			cout << "Failed to open file" << endl;
		}

		int prev_run_time;
		file >> prev_run_time;
		file.close();

		int current_time = time(nullptr);

		int seconds_since_last_run = current_time - prev_run_time;

		int minutes_since_last_run = seconds_since_last_run / 60;
		int hours_since_last_run = minutes_since_last_run / 60;

		if (hours_since_last_run > 0) {

			ofstream outfile("LastRun.txt", ios::out);

			if (!outfile.is_open()) {
				cout << "Failed to open file" << endl;
			}

			// Записать текущее время в файл
			outfile << current_time;
			outfile.close();
		}


	}


	//Implementation of zoo cleaning and animal feeding methods
	void printZoo() {

		Zoo menu;

		bool bol = true;

		while (bol == true) {

			cout << "1. Cleaning." << endl;
			cout << "2. Feed all the animals" << endl;
			cout << "0. Back." << endl;

			cout << endl;
			cout << "Select the item you need: ";

			int number2;
			cin >> number2;

			switch (number2)
			{
			case 1:

				system("cls");
				menu.setAtributeAnimals(menu.LustTime(), menu.setZooFile("cleaning", 0));
				menu.setZooFile("cleaning", 0);
				break;

			case 2:

				system("cls");
				menu.setAtributeAnimals(menu.LustTime(), menu.setZooFile("delFeed", 0));
				break;

			case 0:

				system("cls");
				bol = false;
				break;

			}

			system("cls");

		}


	}



};

//Game start, greeting, menu
int main() {
	setlocale(LC_ALL, "Ru");

	StartGame readyGame;
	readyGame.readyStartGame();


	Zoo startGame;
	Shop by;
	StartGame MenuZoo;


	cout << "Welcome to the Zoo!" << endl;
	Sleep(3000);
	system("cls");

	bool bole = true;

	while (bole == true) {

		startGame.getZooFile("print");

		cout << "1. Print all Monkey." << endl;
		cout << "2. Print all Lions." << endl;
		cout << "3. Print all Elephant." << endl;
		cout << "4. Print all Penguin." << endl;

		cout << endl;
		cout << "5.Go to shop" << endl;
		cout << "6. Go to Zoo park" << endl;

		cout << endl;
		cout << "0. Exit." << endl;

		cout << endl;
		cout << "Select the item you need: ";

		string something;
		int number;
		cin >> number;

		switch (number)
		{
		case 1:
			system("cls");

			startGame.getMonkeyFile("print");
			cout << "Enter something: " << endl;

			cin >> something;
			break;


		case 2:
			system("cls");

			startGame.getLionFile("print");
			cout << "Enter something: " << endl;

			cin >> something;
			break;
		case 3:
			system("cls");

			startGame.getElephantFile("print");
			cout << "Enter something: " << endl;

			cin >> something;
			break;
		case 4:
			system("cls");

			startGame.getPenguinFile("print");
			cout << "Enter something: " << endl;

			cin >> something;

			break;
		case 5:
			system("cls");

			by.ByProductShop();
			break;
		case 6:
			system("cls");

			MenuZoo.printZoo();
			break;
		case 0:

			bole = false;
			break;
		}

		system("cls");

	}


	return 0;
}

