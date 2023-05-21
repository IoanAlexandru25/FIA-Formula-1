#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
#pragma warning ( disable: 4996)

//numele proiectului: Fia Formula 1

class IFile //clasa abstracta
{
public:
	virtual void writeToTextFile(ofstream& f) = 0;
	virtual void readFromTextFile(ifstream& f) = 0;
};

class Echipa : public IFile
{
private:
	char* nume;
protected:
	char* piloti;
	int nrSezoane;
	double* aniiCastigatori; //anii in care echipa a iesit castigatoare in clasamentul constructorilor
	int nrVictoriiClasamentulConstructorilor;

public:

	Echipa()
	{

	}
	//contstrcutor cu doi parametri
	Echipa(const char* nume, const char* piloti)
	{
		if (nume != NULL && piloti != NULL)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
			this->piloti = new char[strlen(piloti) + 1];
			strcpy(this->piloti, piloti);
		}
	}

	//constructor toti parametrii
	Echipa(const char* nume, const char* piloti, int nrSezoane, double* aniiCastigatori, int nrVictoriiClasamentulConstructorilor)
	{
		if (nume != NULL && piloti != NULL && nrSezoane > 0
			&& aniiCastigatori != NULL && nrVictoriiClasamentulConstructorilor >= 0)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
			this->piloti = new char[strlen(piloti) + 1];
			strcpy(this->piloti, piloti);
			this->nrSezoane = nrSezoane;
			this->nrVictoriiClasamentulConstructorilor = nrVictoriiClasamentulConstructorilor;
			this->aniiCastigatori = new double[this->nrVictoriiClasamentulConstructorilor];
			for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; i++)
			{
				this->aniiCastigatori[i] = aniiCastigatori[i];
			}

		}
	}

	//constructor copiere
	Echipa(const Echipa& o)
	{
		if (o.nume != NULL && o.piloti != NULL && o.nrSezoane > 0
			&& o.aniiCastigatori != NULL && o.nrVictoriiClasamentulConstructorilor >= 0)
		{
			this->nume = new char[strlen(o.nume) + 1];
			strcpy(this->nume, o.nume);
			this->piloti = new char[strlen(o.piloti) + 1];
			strcpy(this->piloti, o.piloti);
			this->nrSezoane = o.nrSezoane;
			this->nrVictoriiClasamentulConstructorilor = o.nrVictoriiClasamentulConstructorilor;
			this->aniiCastigatori = new double[this->nrVictoriiClasamentulConstructorilor];
			for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; i++)
			{
				this->aniiCastigatori[i] = o.aniiCastigatori[i];
			}
		}
	}

	//forma supraincarcata a operatorului =
	Echipa operator=(const Echipa& o)
	{
		if (this != &o && o.nume != NULL && o.piloti != NULL && o.nrSezoane > 0
			&& o.aniiCastigatori != NULL && o.nrVictoriiClasamentulConstructorilor >= 0)
		{
			this->nume = new char[strlen(o.nume) + 1];
			strcpy(this->nume, o.nume);
			this->piloti = new char[strlen(o.piloti) + 1];
			strcpy(this->piloti, o.piloti);
			this->nrSezoane = o.nrSezoane;
			this->nrVictoriiClasamentulConstructorilor = o.nrVictoriiClasamentulConstructorilor;
			this->aniiCastigatori = new double[this->nrVictoriiClasamentulConstructorilor];
			for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; i++)
			{
				this->aniiCastigatori[i] = o.aniiCastigatori[i];
			}
			return *this;
		}
	}

	//setteri
	void setNume(const char* nume)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	void setPiloti(const char* piloti)
	{
		this->piloti = new char[strlen(piloti) + 1];
		strcpy(this->piloti, piloti);
	}

	void setNrSezoane(int nrSezoane)
	{
		this->nrSezoane = nrSezoane;
	}

	void setAniiCastigatori(double* aniiCastigatori, int nrVictoriiClasamentulConstructorilor)
	{
		if (aniiCastigatori != NULL && nrVictoriiClasamentulConstructorilor >= 0)
		{
			if (this->aniiCastigatori != NULL)
			{
				delete[] this->aniiCastigatori;
			}
			this->aniiCastigatori = new double[nrVictoriiClasamentulConstructorilor];
			for (int i = 0; i < nrVictoriiClasamentulConstructorilor; i++)
			{
				this->aniiCastigatori[i] = aniiCastigatori[i];
			}
		}
	}

	void setNrVictoriiClasamentulConstructorilor(int nrVictoriiClasamentulConstructorilor)
	{
		this->nrVictoriiClasamentulConstructorilor = nrVictoriiClasamentulConstructorilor;
	}

	//getteri 
	char* getNume()
	{
		return this->nume;
	}

	char* getPiloti()
	{
		return this->piloti;
	}

	int getNrSezoane()
	{
		return this->nrSezoane;
	}

	int getNrVictoriiClasamentulConstructorilor()
	{
		return this->nrVictoriiClasamentulConstructorilor;
	}

	double* getAniiCastigatori()
	{

		return this->aniiCastigatori;

	}

	//operator <<
	friend ostream& operator<<(ostream& out, const Echipa& e)
	{
		out << "\n";
		out << "\nNume: " << e.nume;
		out << "\nPiloti: " << e.piloti;
		out << "\nNumar Sezoane: " << e.nrSezoane;
		out << "\nAnii in care echipa a castigat in clasamentul constructorilor: ";
		for (int i = 0; i < e.nrVictoriiClasamentulConstructorilor; i++)
		{
			out << e.aniiCastigatori[i] << ", ";
		}
		out << "\nNumarul total de victorii in clasamentul constructorilor: " << e.nrVictoriiClasamentulConstructorilor;
		return out;
	}
	//operator >> 
	friend istream& operator>>(istream& in, Echipa& e)
	{
		if (e.aniiCastigatori != NULL)
		{
			cout << "\nNume: ";
			in.getline(e.nume, 100);
			cout << "\nPiloti: ";
			in.getline(e.piloti, 100);
			cout << "\nNumar Sezoane: ";
			in >> e.nrSezoane;
			cout << "\nNumarul total de victorii in clasamentul constructorilor: ";
			in >> e.nrVictoriiClasamentulConstructorilor;
			cout << "\nAnii in care echipa a castigat in clasamentul constructorilor: ";
			for (int i = 0; i < e.nrVictoriiClasamentulConstructorilor; i++)
			{
				in >> e.aniiCastigatori[i];
			}
			cout << "\n";
		}
		return in;
	}

	//operator indexare[]
	char& operator[](int index)
	{
		return this->nume[index];
		return this->nume[0];
	}

	//operator +=
	void operator+=(int addSezon)
	{
		this->nrSezoane += addSezon;
		return;
	}

	Echipa operator+(const Echipa& o)
	{
		Echipa aux(o);
		aux.nrSezoane = this->nrSezoane + o.nrSezoane;
		return aux;
	}

	void operator++()
	{
		++this->nrSezoane;
		return;
	}

	Echipa operator++(int)
	{
		Echipa aux = *this;
		++this->nrSezoane;
		return aux;
	}

	friend bool operator==(Echipa& ec1, Echipa ec2)
	{
		if (ec1.nume != ec2.nume)
		{
			return false;
		}
		if (ec1.piloti != ec2.piloti)
		{
			return false;
		}
		bool not_equal = false;
		if (ec1.nrSezoane != ec2.nrSezoane)
		{
			return false;
		}
		for (int i = 0; i < ec1.nrVictoriiClasamentulConstructorilor && not_equal == false; i++)
		{
			if (ec1.aniiCastigatori[i] != ec2.aniiCastigatori[i])
			{
				not_equal = true;
			}
		}
		if (not_equal == true)
		{
			return false;
		}
		return true;
	}

	bool operator>(Echipa o)
	{
		return this->nrSezoane > o.nrSezoane;
	}

	bool operator>=(Echipa o)
	{
		return this->nrSezoane >= o.nrSezoane;
	}

	bool operator!()
	{
		if (this->aniiCastigatori == NULL && this->nrVictoriiClasamentulConstructorilor == 0) {
			return true;
		}
		return false;
	}

	friend bool operator<(const Echipa& e1, const Echipa& e2)
	{
		return e1.nume < e2.nume;
	}

	//destructor
	~Echipa()
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (this->piloti != NULL)
		{
			delete[] this->piloti;
		}
		if (this->aniiCastigatori != NULL)
		{
			delete[] this->aniiCastigatori;
		}
	}

	//faza 2

	friend ofstream& operator<<(ofstream& fout, Echipa& ec)
	{
		fout << ec.nume << "\n";
		fout << ec.piloti << "\n";
		fout << ec.nrSezoane << "\n";
		fout << ec.nrVictoriiClasamentulConstructorilor << "\n";
		for (int i = 0; i < ec.nrVictoriiClasamentulConstructorilor; i++)
		{
			fout << ec.aniiCastigatori[i] << " ";
		}
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Echipa& ec)
	{
		if (ec.nume != NULL)
		{
			delete[] ec.nume;
		}
		if (ec.piloti != NULL)
		{
			delete[] ec.piloti;
		}
		char aux[200];
		char aux2[200];
		fin.getline(aux, 200);
		ec.nume = new char[strlen(aux) + 1];
		strcpy(ec.nume, aux);
		fin.getline(aux2, 200);
		ec.piloti = new char[strlen(aux2) + 1];
		strcpy(ec.piloti, aux2);
		fin >> ec.nrSezoane;
		fin >> ec.nrVictoriiClasamentulConstructorilor;
		if (ec.nrVictoriiClasamentulConstructorilor > 0)
		{
			delete[] ec.aniiCastigatori;
			ec.aniiCastigatori = new double[ec.nrVictoriiClasamentulConstructorilor];
			for (int i = 0; i < ec.nrVictoriiClasamentulConstructorilor; i++)
			{
				fin >> ec.aniiCastigatori[i];
			}
		}
		return fin;
	}

	friend fstream& operator<<(fstream& fout, Echipa& ec)
	{
		int size1 = strlen(ec.nume);
		fout.write((char*)&size1, sizeof(int));
		fout.write(ec.nume, size1);
		int size2 = strlen(ec.piloti);
		fout.write((char*)&size2, sizeof(int));
		fout.write(ec.piloti, size2);
		fout.write((char*)&ec.nrSezoane, sizeof(int));
		fout.write((char*)&ec.nrVictoriiClasamentulConstructorilor, sizeof(int));
		for (int i = 0; i < ec.nrVictoriiClasamentulConstructorilor; ++i)
		{
			fout.write((char*)&ec.aniiCastigatori[i], sizeof(int));
		}
		return fout;
	}

	friend fstream& operator>>(fstream& fin, Echipa& ec)
	{
		if (ec.nume != NULL)
		{
			delete[] ec.nume;
		}
		if (ec.piloti != NULL)
		{
			delete[] ec.piloti;
		}
		if (ec.aniiCastigatori != NULL)
		{
			delete[] ec.aniiCastigatori;
		}
		char aux[200];
		char aux2[200];
		fin.read(aux, 200);
		ec.nume = new char[strlen(aux) + 1];
		strcpy(ec.nume, aux);
		fin.read(aux2, 200);
		ec.piloti = new char[strlen(aux2) + 1];
		strcpy(ec.piloti, aux2);
		fin.read((char*)&ec.nrSezoane, sizeof(int));
		fin.read((char*)&ec.nrVictoriiClasamentulConstructorilor, sizeof(int));
		if (ec.nrVictoriiClasamentulConstructorilor > 0) {
			ec.aniiCastigatori = new double[ec.nrVictoriiClasamentulConstructorilor];
			for (int i = 0; i < ec.nrVictoriiClasamentulConstructorilor; ++i)
			{
				fin.read((char*)&ec.aniiCastigatori[i], sizeof(int));
			}
		}
		return fin;
	}

	virtual void writeToTextFile(ofstream& fout)
	{
		fout << "\nNume echipa: " << this->nume;
		fout << "\nPilotii: " << this->piloti;
		fout << "\nNumar sezoane: " << this->nrSezoane;
		for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; ++i)
		{
			fout << "\nAnii in care echipa a castigat in clasamentul constructorilor: " << this->aniiCastigatori[i];
		}
		fout << "\nNumarul total de victorii in clasamentul constructorilor: " << this->nrVictoriiClasamentulConstructorilor;
	}

	virtual void readFromTextFile(ifstream& fin)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (this->piloti != NULL)
		{
			delete[] this->piloti;
		}
		if (this->aniiCastigatori != NULL)
		{
			delete[] this->aniiCastigatori;
		}
		char aux[200];
		char aux2[200];
		fin >> aux;
		nume = new char[strlen(aux) + 1];
		strcpy(this->nume, aux);
		fin >> aux2;
		piloti = new char[strlen(aux2) + 1];
		strcpy(this->piloti, aux2);
		this->nrSezoane = nrSezoane;
		int nrVictorii;
		fin >> nrVictorii;
		if (nrVictorii > 0)
		{
			this->nrVictoriiClasamentulConstructorilor = nrVictorii;
			double* aniiC = new double[nrVictorii];
			this->aniiCastigatori = new double[this->nrVictoriiClasamentulConstructorilor];
			for (int i = 0; i < nrVictorii; ++i)
			{
				fin >> aniiC[i];
			}
			for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; ++i)
			{
				this->aniiCastigatori[i] = aniiC[i];
			}
		}
	}

	void writeToFile(fstream& f) {
		int nu = strlen(this->nume) + 1;
		f.write((char*)&nu, sizeof(int));
		f.write(this->nume, nu);
		int pi = strlen(this->piloti) + 1;
		f.write((char*)&pi, sizeof(int));
		f.write(this->piloti, pi);
		f.write((char*)&this->nrSezoane, sizeof(int));
		f.write((char*)&this->nrVictoriiClasamentulConstructorilor, sizeof(int));

		for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; ++i) {

			f.write((char*)&this->aniiCastigatori[i], sizeof(double));
		}

	}

	void readFromFile(fstream& f) 
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (this->piloti != NULL)
		{
			delete[] this->piloti;
		}
		if (this->aniiCastigatori != NULL)
		{
			delete[] this->aniiCastigatori;
		}
		int nu;
		f.read((char*)&nu, sizeof(int));
		char* buffer1 = new char[nu];
		f.read(buffer1, nu);
		strcpy(this->nume, buffer1);
		delete[] buffer1;
		int pi;
		f.read((char*)&pi, sizeof(int));
		char* buffer2 = new char[pi];
		f.read(buffer2, pi);
		strcpy(this->piloti, buffer2);
		delete[] buffer2;

		f.read((char*)&this->nrSezoane, sizeof(int));
		f.read((char*)&this->nrVictoriiClasamentulConstructorilor, sizeof(int));
		this->aniiCastigatori = new double[this->nrVictoriiClasamentulConstructorilor];

		for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; i++) 
		{
			f.read((char*)&this->aniiCastigatori[i], sizeof(double));
		}
	}

	virtual void writeToCSVFile(fstream& fout)
	{
		fout << this->nume << ", ";
		fout << this->piloti << ", ";
		fout << this->nrSezoane << ", ";
		for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; ++i) {
			fout << this->aniiCastigatori[i];
			if (i < this->nrVictoriiClasamentulConstructorilor - 1) {
				fout << ", ";
			}
		}
		fout << this->nrVictoriiClasamentulConstructorilor << ", ";
	}

	virtual void readFromCSVFile(fstream& fin)
	{
		fin >> this->nume;
		fin >> this->piloti;
		fin >> this->nrSezoane;
		for (int i = 0; i < this->nrVictoriiClasamentulConstructorilor; ++i)
		{
			fin >> this->aniiCastigatori[i];
		}
		fin >> this->nrVictoriiClasamentulConstructorilor;
	}

};

class Pilot
{
private:
	char* numePilot;
protected:
	char* numeEchipa;
	int nrSezoane;
	double pozitiiObtinute[22]; //acest sezon
	int nrCurse; //acest sezon

public:

	Pilot()
	{

	}

	Pilot(const char* numePilot, const char* echipa)
	{
		if (numePilot != NULL && numeEchipa != NULL)
		{
			this->numePilot = new char[strlen(numePilot) + 1];
			strcpy(this->numePilot, numePilot);
			this->numeEchipa = new char[strlen(numeEchipa) + 1];
			strcpy(this->numeEchipa, numeEchipa);
		}
	}

	Pilot(const char* numePilot, const char* numeEchipa, int nrSezoane, double* pozitiiObtinute, int nrCurse)
	{
		if (numePilot != NULL && numeEchipa != NULL && nrSezoane > 0 && pozitiiObtinute != NULL && nrCurse > 0)
		{
			this->numePilot = new char[strlen(numePilot) + 1];
			strcpy(this->numePilot, numePilot);
			this->numeEchipa = new char[strlen(numeEchipa) + 1];
			strcpy(this->numeEchipa, numeEchipa);
			this->nrSezoane = nrSezoane;
			for (int i = 0; i < 22; i++)
			{
				this->pozitiiObtinute[i] = pozitiiObtinute[i];
			}
			this->nrCurse = nrCurse;
		}
	}

	Pilot(const Pilot& o)
	{
		if (o.numePilot != NULL && o.numeEchipa != NULL && o.nrSezoane > 0 && o.pozitiiObtinute != NULL && o.nrCurse > 0)
		{
			this->numePilot = new char[strlen(o.numePilot) + 1];
			strcpy(this->numePilot, o.numePilot);
			this->numeEchipa = new char[strlen(o.numeEchipa) + 1];
			strcpy(this->numeEchipa, o.numeEchipa);
			this->nrSezoane = o.nrSezoane;
			for (int i = 0; i < 22; i++)
			{
				this->pozitiiObtinute[i] = o.pozitiiObtinute[i];
			}
			this->nrCurse = o.nrCurse;
		}
	}

	Pilot operator=(const Pilot& o)
	{
		if (this != &o && numePilot != NULL && numeEchipa != NULL && nrSezoane > 0 && pozitiiObtinute != NULL && nrCurse > 0)
		{
			if (this->numePilot != NULL)
			{
				delete[] this->numePilot;
			}
			if (this->numeEchipa != NULL)
			{
				delete[] this->numeEchipa;
			}
			this->numePilot = new char[strlen(o.numePilot) + 1];
			strcpy(this->numePilot, o.numePilot);
			this->numeEchipa = new char[strlen(o.numeEchipa) + 1];
			strcpy(this->numeEchipa, o.numeEchipa);
			this->nrSezoane = o.nrSezoane;
			for (int i = 0; i < 22; i++)
			{
				this->pozitiiObtinute[i] = o.pozitiiObtinute[i];
			}
			this->nrCurse = o.nrCurse;
		}
		return *this;
	}

	void setNumePilot(const char* numePilot)
	{
		this->numePilot = new char[strlen(numePilot) + 1];
		strcpy(this->numePilot, numePilot);
	}

	void setNumeEchipa(const char* numeEchipa)
	{
		this->numeEchipa = new char[strlen(numeEchipa) + 1];
		strcpy(this->numeEchipa, numeEchipa);
	}

	void setNrSezoane(int nrSezoane)
	{
		this->nrSezoane = nrSezoane;
	}

	void setPozitiiObtinute(double* pozitiiObtinute)
	{
		for (int i = 0; i < 22; i++)
		{
			this->pozitiiObtinute[i] = pozitiiObtinute[i];
		}
	}

	void setNrCurse(int nrCurse)
	{
		this->nrCurse = nrCurse;
	}

	char* getNumePilot()
	{
		return this->numePilot;
	}

	char* getNumeEchipa()
	{
		return this->numeEchipa;
	}

	int getNrSezoane()
	{
		return this->nrSezoane;
	}

	double* getPozitiiObtinute()
	{

		return this->pozitiiObtinute;

	}

	int getNrCurse()
	{
		return this->nrCurse;
	}

	friend ostream& operator<<(ostream& out, const Pilot& p)
	{
		out << "\nNume: " << p.numePilot;
		out << "\nEchipa: " << p.numeEchipa;
		out << "\nNumar Sezoane: " << p.nrSezoane;
		out << "\nPozitiile obtinute acest sezon: ";
		for (int i = 0; i < 22; i++)
		{
			out << p.pozitiiObtinute[i] << ", ";
		}
		out << "\nNumar de curse in care a concurat acest sezon: " << p.nrCurse;
		return out;
	}

	friend istream& operator>>(istream& in, Pilot& p)
	{
		cout << "\nNume: ";
		in.getline(p.numePilot, 100);
		cout << "\nEchipa: ";
		in.getline(p.numeEchipa, 100);
		cout << "\nNumar Sezoane: ";
		in >> p.nrSezoane;
		cout << "\nPozitiile obtinute acest sezon: ";
		for (int i = 0; i < 22; i++)
		{
			in >> p.pozitiiObtinute[i];
		}
		cout << "\nNumar de curse in care a concurat acest sezon: ";
		in >> p.nrCurse;
		cout << "\n";
		return in;
	}

	char& operator[](int index)
	{
		return this->numePilot[index];
		return this->numePilot[0];
	}

	void operator+=(int addSezon)
	{
		this->nrSezoane += addSezon;
		return;
	}

	Pilot operator+(const Pilot& o)
	{
		Pilot aux(o);
		aux.nrSezoane = this->nrSezoane + o.nrSezoane;
		return aux;
	}

	void operator++()
	{
		++this->nrSezoane;
		return;
	}

	Pilot operator++(int)
	{
		Pilot aux = *this;
		++this->nrSezoane;
		return aux;
	}

	friend bool operator==(Pilot& pil1, Pilot pil2)
	{
		if (pil1.numePilot != pil2.numePilot)
		{
			return false;
		}
		if (pil1.numeEchipa != pil2.numeEchipa)
		{
			return false;
		}
		bool not_equal = false;
		if (pil1.nrSezoane != pil2.nrSezoane)
		{
			return false;
		}
		for (int i = 0; i < 22 && not_equal == false; i++)
		{
			if (pil1.pozitiiObtinute[i] != pil2.pozitiiObtinute[i])
			{
				not_equal = true;
			}
		}
		if (not_equal == true)
		{
			return false;
		}
		return true;
	}

	bool operator>(Pilot o)
	{
		return this->nrSezoane > o.nrSezoane;
	}

	bool operator>=(Pilot o)
	{
		return this->nrSezoane >= o.nrSezoane;
	}

	bool operator!() {
		if (this->pozitiiObtinute == NULL && this->nrCurse == 0) {
			return true;
		}
		return false;
	}

	friend bool operator<(const Pilot& p1, const Pilot& p2)
	{
		return p1.nrSezoane < p2.nrSezoane;
	}

	~Pilot()
	{
		if (this->numePilot != NULL)
		{
			delete[] this->numePilot;
		}
		if (this->numeEchipa != NULL)
		{
			delete[] this->numeEchipa;
		}
	}

	//faza 2

	friend ofstream& operator<<(ofstream& fout, Pilot& pi)
	{
		fout << pi.numePilot << "\n";
		fout << pi.numeEchipa << "\n";
		fout << pi.nrSezoane << "\n";
		fout << pi.nrCurse << "\n";
		for (int i = 0; i < 22; i++)
		{
			fout << pi.pozitiiObtinute[i] << " ";
		}
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Pilot& pi)
	{
		if (pi.numePilot != NULL)
		{
			delete[] pi.numePilot;
		}
		if (pi.numeEchipa != NULL)
		{
			delete[] pi.numeEchipa;
		}
		char aux[200];
		char aux2[200];
		fin.getline(aux, 200);
		pi.numePilot = new char[strlen(aux) + 1];
		strcpy(pi.numePilot, aux);
		fin.getline(aux2, 200);
		pi.numeEchipa = new char[strlen(aux2) + 1];
		strcpy(pi.numeEchipa, aux2);
		fin >> pi.nrSezoane;
		fin >> pi.nrCurse;
		if (pi.nrCurse = 22)
		{
			for (int i = 0; i < 22; ++i)
			{
				fin >> pi.pozitiiObtinute[i];
			}
		}
		return fin;
	}

	friend fstream& operator<<(fstream& fout, Pilot& pi)
	{
		int size1 = strlen(pi.numePilot);
		fout.write((char*)&size1, sizeof(int));
		fout.write(pi.numePilot, size1);
		int size2 = strlen(pi.numeEchipa);
		fout.write((char*)&size2, sizeof(int));
		fout.write(pi.numeEchipa, size2);
		fout.write((char*)&pi.nrSezoane, sizeof(int));
		fout.write((char*)&pi.nrCurse, sizeof(int));
		for (int i = 0; i < 22; ++i)
		{
			fout.write((char*)&pi.pozitiiObtinute[i], sizeof(int));
		}
		return fout;
	}

	friend fstream& operator>>(fstream& fin, Pilot& pi)
	{
		if (pi.numePilot != NULL)
		{
			delete[] pi.numePilot;
		}
		if (pi.numeEchipa != NULL)
		{
			delete[] pi.numeEchipa;
		}
		char aux[200];
		fin.read(aux, 200);
		pi.numePilot = new char[strlen(aux) + 1];
		strcpy(pi.numePilot, aux);
		fin.read(aux, 200);
		pi.numeEchipa = new char[strlen(aux) + 1];
		strcpy(pi.numeEchipa, aux);
		fin.read((char*)&pi.nrSezoane, sizeof(int));
		fin.read((char*)&pi.nrCurse, sizeof(int));
		if (pi.nrCurse = 22)
		{
			for (int i = 0; i < 22; ++i)
			{
				fin.read((char*)&pi.pozitiiObtinute[i], sizeof(int));
			}
		}
		return fin;
	}

	virtual void writeToTextFile(ofstream& fout)
	{
		fout << "\nNume pilot: " << this->numePilot;
		fout << "\nNume echipa: " << this->numeEchipa;
		fout << "\nNumar sezoane: " << this->nrSezoane;
		for (int i = 0; i < 22; ++i)
		{
			fout << "\nPozitiile obtinute acest sezon: " << this->pozitiiObtinute[i];
		}
		fout << "\nNumarul de curse la care a participat acest sezon: " << this->nrCurse;
	}

	virtual void readFromTextFile(ifstream& fin)
	{
		if (this->numePilot != NULL)
		{
			delete[] this->numePilot;
		}
		if (this->numeEchipa != NULL)
		{
			delete[] this->numeEchipa;
		}
		delete[] this->numePilot;
		delete[] this->numeEchipa;
		char aux[200];
		fin >> aux;
		numePilot = new char[strlen(aux) + 1];
		strcpy(this->numePilot, aux);
		numeEchipa = new char[strlen(aux) + 1];
		strcpy(this->numeEchipa, aux);
		this->nrSezoane = nrSezoane;
		if (nrCurse = 22)
		{
			for (int i = 0; i < 22; i++)
			{
				this->pozitiiObtinute[i] = pozitiiObtinute[i];
			}
		}
		this->nrCurse = nrCurse;
	}

	void writeToFile(fstream& f)
	{
		int nup = strlen(this->numePilot) + 1;
		f.write((char*)&nup, sizeof(int));
		f.write(this->numePilot, nup);
		int nue = strlen(this->numeEchipa) + 1;
		f.write((char*)&nue, sizeof(int));
		f.write(this->numeEchipa, nue);
		f.write((char*)&this->nrSezoane, sizeof(int));
		f.write((char*)&this->nrCurse, sizeof(int));
		for (int i = 0; i < 22; i++)
		{
			f.write((char*)&this->pozitiiObtinute[i], sizeof(double));
		}
	}

	void readFromFile(fstream& f)
	{
		if (this->numePilot != NULL)
		{
			delete[] this->numePilot;
		}
		if (this->numeEchipa != NULL)
		{
			delete[] this->numeEchipa;
		}
		int nup;
		f.read((char*)&nup, sizeof(int));
		char* buffer1 = new char[nup];
		f.read(buffer1, nup);
		strcpy(this->numePilot, buffer1);
		delete[] buffer1;
		int nue;
		f.read((char*)&nue, sizeof(int));
		char* buffer2 = new char[nue];
		f.read(buffer2, nue);
		strcpy(this->numeEchipa, buffer2);
		delete[] buffer2;
		f.read((char*)&this->nrSezoane, sizeof(int));
		f.read((char*)&this->nrCurse, sizeof(int));
		for (int i = 0; i < 22; ++i) {
			f.read((char*)&this->pozitiiObtinute[i], sizeof(double));
		}
	}

	virtual void writeToCSVFile2(fstream& fout)
	{
		fout << this->numePilot << ", ";
		fout << this->numeEchipa << ", ";
		fout << this->nrSezoane << ", ";
		for (int i = 0; i < 22; ++i) {
			fout << this->pozitiiObtinute[i];
			if (i < 22 - 1) {
				fout << ", ";
			}
		}
		fout << this->nrCurse << ", ";
	}

	virtual void readFromCSVFile2(fstream& fin)
	{
		fin >> this->numePilot;
		fin >> this->numeEchipa;
		fin >> this->nrSezoane;
		for (int i = 0; i < 22; ++i)
		{
			fin >> this->pozitiiObtinute[i];
		}
		fin >> this->nrCurse;
	}
};

class Cursa //clasa cu camp static si camp constant
{
	static int nrCursei;
	const int nrTotalCurse;
	char* tara;
	int nrTure;

public:


	Cursa(const char* tara) : nrTotalCurse(nrCursei)
	{
		if (tara != NULL)
		{
			this->nrCursei++;
			this->tara = new char[strlen(tara) + 1];
			strcpy(this->tara, tara);
		}
	}

	Cursa(const char* tara, int nrTure) : nrTotalCurse(nrCursei)
	{
		if (tara != NULL && nrTure > 0)
		{
			this->nrCursei++;
			this->tara = new char[strlen(tara) + 1];
			strcpy(this->tara, tara);
			this->nrTure = nrTure;
		}
	}

	Cursa(const Cursa& o) : nrTotalCurse(o.nrCursei)
	{
		if (o.tara != NULL && o.nrTure > 0)
		{
			this->tara = new char[strlen(o.tara) + 1];
			strcpy(this->tara, o.tara);
			this->nrTure = o.nrTure;
		}
	}

	Cursa operator=(const Cursa& o)
	{
		if (this != NULL && tara != NULL && nrTure > 0)
		{
			if (this->tara != NULL)
			{
				delete[] this->tara;
			}
			this->tara = new char[strlen(o.tara) + 1];
			strcpy(this->tara, o.tara);
			this->nrTure = o.nrTure;
		}
		return *this;
	}

	void setTara(const char* tara)
	{
		this->tara = new char[strlen(tara) + 1];
		strcpy(this->tara, tara);
	}

	void setNrTure(int nrTure)
	{
		this->nrTure = nrTure;
	}

	void setNrCursei(int nrCursei)
	{
		this->nrCursei = nrCursei;
	}

	char* getTara()
	{
		return this->tara;
	}

	int getNrTure()
	{
		return this->nrTure;
	}

	int getNrCursei()
	{
		return this->nrCursei;
	}

	friend ostream& operator<<(ostream& out, const Cursa& c)
	{
		out << "\nNumarul cursei: " << c.nrCursei;
		out << "\nTara: " << c.tara;
		out << "\nNumarul de ture: " << c.nrTure;
		return out;
	}

	friend istream& operator>>(istream& in, Cursa& c)
	{
		cout << "\nNumatul cursei: ";
		in >> c.nrCursei;
		cout << "\nTara: ";
		in.getline(c.tara, 100);
		cout << "\nNumar de ture: ";
		in >> c.nrTure;
		cout << "\n";
		return in;
	}

	char& operator[](int index)
	{
		return this->tara[index];
		return this->tara[0];
	}

	void operator+=(int addTura)
	{
		this->nrTure += addTura;
		return;
	}

	Cursa operator+(const Cursa& o)
	{
		Cursa aux(o);
		aux.nrTure = this->nrTure + o.nrTure;
		return aux;
	}

	void operator++()
	{
		++this->nrTure;
		return;
	}

	Cursa operator++(int)
	{
		Cursa aux = *this;
		++this->nrTure;
		return aux;
	}

	friend bool operator==(Cursa& cu1, Cursa cu2)
	{
		if (cu1.nrCursei != cu2.nrCursei)
		{
			return false;
		}
		if (cu1.tara != cu2.tara)
		{
			return false;
		}
		bool not_equal = false;
		if (cu1.nrTure != cu2.nrTure)
		{
			return false;
		}
		if (not_equal == true)
		{
			return false;
		}
		return true;
	}

	bool operator>(Cursa o)
	{
		return this->nrTure > o.nrTure;
	}

	bool operator>=(Cursa o)
	{
		return this->nrTure >= o.nrTure;
	}

	bool operator!() {
		if (this->tara == NULL && this->nrTure == 0) {
			return true;
		}
		return false;
	}

	friend bool operator<(const Cursa& c1, const Cursa& c2)
	{
		return c1.nrTure < c2.nrTure;
	}

	~Cursa()
	{
		if (this->tara != NULL)
		{
			delete[] this->tara;
		}
	}

	//faza 2

	friend ofstream& operator<<(ofstream& fout, Cursa& cu)
	{
		fout << cu.nrCursei << "\n";
		fout << cu.tara << "\n";
		fout << cu.nrTure << "\n";
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Cursa& cu)
	{
		fin >> cu.nrCursei;
		if (cu.tara != NULL)
		{
			delete[] cu.tara;
		}
		char aux[200];
		fin.getline(aux, 200);
		cu.tara = new char[strlen(aux) + 1];
		strcpy(cu.tara, aux);
		fin >> cu.nrTure;
		return fin;
	}

	friend fstream& operator<<(fstream& fout, Cursa& cu)
	{
		fout.write((char*)&cu.nrCursei, sizeof(int));
		fout.write((char*)&cu.nrTotalCurse, sizeof(int));
		int size = strlen(cu.tara);
		fout.write((char*)&size, sizeof(int));
		fout.write(cu.tara, size);
		fout.write((char*)&cu.nrTure, sizeof(int));
		return fout;
	}

	friend fstream& operator>>(fstream& fin, Cursa& cu)
	{
		if (cu.tara != NULL)
		{
			delete[] cu.tara;
		}
		fin.read((char*)&cu.nrCursei, sizeof(int));
		fin.read((char*)&cu.nrTotalCurse, sizeof(int));
		char aux[200];
		fin.read(aux, 200);
		cu.tara = new char[strlen(aux) + 1];
		strcpy(cu.tara, aux);
		fin.read((char*)&cu.nrTure, sizeof(int));
		return fin;
	}

	virtual void writeToTextFile(ofstream& fout)
	{
		fout << "\nNumarul cursei: " << this->nrCursei;
		fout << "\nNumarul total de curse din acest sezon: " << this->nrTotalCurse;
		fout << "\nTara: " << this->tara;
		fout << "\nNumarul de ture din cursa: " << this->nrTure;
	}

	virtual void readFromTextFile(ifstream& fin)
	{
		if (this->tara != NULL)
		{
			delete[] this->tara;
		}
		char aux[200];
		this->nrCursei = nrCursei;
		fin >> aux;
		tara = new char[strlen(aux) + 1];
		strcpy(this->tara, aux);
		this->nrTure = nrTure;
	}

	void writeToFile(fstream& f)
	{
		f.write((char*)&this->nrCursei, sizeof(int));
		f.write((char*)&this->nrTotalCurse, sizeof(int));
		int ta = strlen(this->tara) + 1;
		f.write((char*)&ta, sizeof(int));
		f.write(this->tara, ta);
		f.write((char*)&this->nrTure, sizeof(int));
	}

	void readFromFile(fstream& f)
	{
		if (this->tara != NULL)
		{
			delete[] this->tara;
		}
		f.read((char*)&this->nrCursei, sizeof(int));
		f.read((char*)&this->nrTotalCurse, sizeof(int));
		int ta;
		f.read((char*)&ta, sizeof(int));
		char* buffer = new char[ta];
		f.read(buffer, ta);
		strcpy(this->tara, buffer);
		delete[] buffer;
		f.read((char*)&this->nrTure, sizeof(int));
	}

	virtual void writeToCSVFile3(fstream& fout)
	{
		fout << this->nrCursei << ", ";
		fout << this->nrTotalCurse << ", ";
		fout << this->tara << ", ";
		fout << this->nrTure << ", ";
	}

	virtual void readFromCSVFile3(fstream& fin)
	{
		fin >> this->nrCursei;
		fin >> this->tara;
		fin >> this->nrTure;
	}

};

int Cursa::nrCursei = 0;

class Sponsor
{
	char* numeSponsor;
	char* numeEchipaColaboratoare;
	double* sezoaneColaborare;
	int totalAniColaborare;

public:

	Sponsor()
	{

	}

	Sponsor(const char* numeSponsor, const char* numeEchipaColaboratoare)
	{
		if (numeSponsor != NULL && numeEchipaColaboratoare != NULL)
		{
			this->numeSponsor = new char[strlen(numeSponsor) + 1];
			strcpy(this->numeSponsor, numeSponsor);
			this->numeEchipaColaboratoare = new char[strlen(numeEchipaColaboratoare) + 1];
			strcpy(this->numeEchipaColaboratoare, numeEchipaColaboratoare);
		}
	}

	Sponsor(const char* numeSponsor, const char* numeEchipaColaboratoare, double* sezoaneColaborare, int totalAniColaborare)
	{
		if (numeSponsor != NULL && numeEchipaColaboratoare != NULL && sezoaneColaborare != NULL && totalAniColaborare > 0)
		{
			this->numeSponsor = new char[strlen(numeSponsor) + 1];
			strcpy(this->numeSponsor, numeSponsor);
			this->numeEchipaColaboratoare = new char[strlen(numeEchipaColaboratoare) + 1];
			strcpy(this->numeEchipaColaboratoare, numeEchipaColaboratoare);
			this->totalAniColaborare = totalAniColaborare;
			this->sezoaneColaborare = new double[totalAniColaborare];
			for (int i = 0; i < this->totalAniColaborare; i++)
			{
				this->sezoaneColaborare[i] = sezoaneColaborare[i];
			}
		}
	}

	Sponsor(const Sponsor& o)
	{
		if (o.numeSponsor != NULL && o.numeEchipaColaboratoare != NULL && o.sezoaneColaborare != NULL && o.totalAniColaborare > 0)
		{
			this->numeSponsor = new char[strlen(o.numeSponsor) + 1];
			strcpy(this->numeSponsor, o.numeSponsor);
			this->numeEchipaColaboratoare = new char[strlen(o.numeEchipaColaboratoare) + 1];
			strcpy(this->numeEchipaColaboratoare, o.numeEchipaColaboratoare);
			this->totalAniColaborare = o.totalAniColaborare;
			this->sezoaneColaborare = new double[o.totalAniColaborare];
			for (int i = 0; i < this->totalAniColaborare; i++)
			{
				this->sezoaneColaborare[i] = o.sezoaneColaborare[i];
			}
		}
	}

	Sponsor operator=(const Sponsor& o)
	{
		if (this != NULL && o.numeSponsor != NULL && o.numeEchipaColaboratoare != NULL && o.sezoaneColaborare != NULL && o.totalAniColaborare > 0)
		{
			this->numeSponsor = new char[strlen(o.numeSponsor) + 1];
			strcpy(this->numeSponsor, o.numeSponsor);
			this->numeEchipaColaboratoare = new char[strlen(o.numeEchipaColaboratoare) + 1];
			strcpy(this->numeEchipaColaboratoare, o.numeEchipaColaboratoare);
			this->totalAniColaborare = o.totalAniColaborare;
			this->sezoaneColaborare = new double[o.totalAniColaborare];
			for (int i = 0; i < this->totalAniColaborare; i++)
			{
				this->sezoaneColaborare[i] = o.sezoaneColaborare[i];
			}
			return *this;
		}
	}

	void setNumeSponsor(const char* numeSponsor)
	{
		this->numeSponsor = new char[strlen(numeSponsor) + 1];
		strcpy(this->numeSponsor, numeSponsor);
	}

	void setNumeEchipaColaboratoare(const char* numeEchipaColaboratoare)
	{
		this->numeEchipaColaboratoare = new char[strlen(numeEchipaColaboratoare) + 1];
		strcpy(this->numeEchipaColaboratoare, numeEchipaColaboratoare);
	}

	void setSezoaneColaborare(double* sezoaneColaborare, int totalAniColaborare)
	{
		if (sezoaneColaborare != NULL && totalAniColaborare > 0)
		{
			if (this->sezoaneColaborare != NULL)
			{
				delete[] this->sezoaneColaborare;
			}
			this->sezoaneColaborare = new double[totalAniColaborare];
			this->totalAniColaborare = totalAniColaborare;
			for (int i = 0; i < totalAniColaborare; i++)
			{
				this->sezoaneColaborare[i] = sezoaneColaborare[i];
			}
		}
	}

	void setTotalAniColaborare(int totalAniColaborare)
	{
		this->totalAniColaborare = totalAniColaborare;
	}

	char* getNumeSponsor()
	{
		return this->numeSponsor;
	}

	char* getNumeEchipaColaboratoare()
	{
		return this->numeEchipaColaboratoare;
	}

	double* getSezoaneColaborare()
	{
		return this->sezoaneColaborare;
	}

	int getTotalAniColaborare()
	{
		return this->totalAniColaborare;
	}

	friend ostream& operator<<(ostream& out, const Sponsor& s)
	{
		out << "\nNumele sponsorului: " << s.numeSponsor;
		out << "\nNumele echipe cu care colaboreaza: " << s.numeEchipaColaboratoare;
		out << "\nSezoanele in care au colaborat: ";
		for (int i = 0; i < s.totalAniColaborare; i++)
		{
			out << s.sezoaneColaborare[i] << ", ";
		}
		out << "\nNumarul total de ani de colaborare: " << s.totalAniColaborare;
		return out;
	}

	friend istream& operator>>(istream& in, Sponsor& s)
	{
		cout << "\nNumele sponsorului: ";
		in.getline(s.numeSponsor, 100);
		cout << "\nNumele echipe cu care colaboreaza: ";
		in.getline(s.numeEchipaColaboratoare, 100);
		cout << "\nSezoanele in care au colaborat: ";
		for (int i = 0; i < s.totalAniColaborare; i++)
		{
			in >> s.sezoaneColaborare[i];
		}
		cout << "\nNumarul total de ani de colaborare: ";
		in >> s.totalAniColaborare;
		cout << "\n";
		return in;
	}

	char& operator[](int index)
	{
		return this->numeSponsor[index];
		return this->numeSponsor[0];
	}

	void operator+=(int addAn)
	{
		this->totalAniColaborare += addAn;
		return;
	}

	Sponsor operator+(const Sponsor& o)
	{
		Sponsor aux(o);
		aux.totalAniColaborare = this->totalAniColaborare + o.totalAniColaborare;
		return aux;
	}

	void operator++()
	{
		++this->totalAniColaborare;
		return;
	}

	Sponsor operator++(int)
	{
		Sponsor aux = *this;
		++this->totalAniColaborare;
		return aux;
	}

	friend bool operator==(Sponsor& spo1, Sponsor spo2)
	{
		if (spo1.numeSponsor != spo2.numeSponsor)
		{
			return false;
		}
		if (spo1.numeEchipaColaboratoare != spo2.numeEchipaColaboratoare)
		{
			return false;
		}
		bool not_equal = false;
		for (int i = 0; i < spo1.totalAniColaborare && not_equal == false; i++)
		{
			if (spo1.sezoaneColaborare[i] != spo2.sezoaneColaborare[i])
			{
				not_equal = true;
			}
		}
		if (not_equal == true)
		{
			return false;
		}
		return true;
	}

	bool operator>(Sponsor o)
	{
		return this->totalAniColaborare > o.totalAniColaborare;
	}

	bool operator>=(Sponsor o)
	{
		return this->totalAniColaborare >= o.totalAniColaborare;
	}

	bool operator!() {
		if (this->sezoaneColaborare == NULL && this->totalAniColaborare == 0) {
			return true;
		}
		return false;
	}

	friend bool operator<(const Sponsor& s1, const Sponsor& s2)
	{
		return s1.totalAniColaborare < s2.totalAniColaborare;
	}

	~Sponsor()
	{
		
		if (this->numeSponsor != NULL)
		{
			delete[] this->numeSponsor;
		}
		if (this->numeEchipaColaboratoare != NULL)
		{
			delete[] this->numeEchipaColaboratoare;
		}
		if (this->sezoaneColaborare != NULL)
		{
			delete[] this->sezoaneColaborare;
		}
	}

	//faza 2

	friend ofstream& operator<<(ofstream& fout, Sponsor& sp)
	{
		fout << sp.numeSponsor << "\n";
		fout << sp.numeEchipaColaboratoare << "\n";
		fout << sp.totalAniColaborare << "\n";
		for (int i = 0; i < sp.totalAniColaborare; i++)
		{
			fout << sp.sezoaneColaborare[i] << " ";
		}
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Sponsor& sp)
	{
		if (sp.numeSponsor != NULL)
		{
			delete[] sp.numeSponsor;
		}
		if (sp.numeEchipaColaboratoare != NULL)
		{
			delete[] sp.numeEchipaColaboratoare;
		}
		char aux[200];
		char aux2[200];
		fin.getline(aux, 200);
		sp.numeSponsor = new char[strlen(aux) + 1];
		strcpy(sp.numeSponsor, aux);
		fin.getline(aux2, 200);
		sp.numeEchipaColaboratoare = new char[strlen(aux2) + 1];
		strcpy(sp.numeEchipaColaboratoare, aux2);
		fin >> sp.totalAniColaborare;
		if (sp.totalAniColaborare > 0)
		{
			delete[] sp.sezoaneColaborare;
			sp.sezoaneColaborare = new double[sp.totalAniColaborare];
			for (int i = 0; i < sp.totalAniColaborare; i++)
			{
				fin >> sp.sezoaneColaborare[i];
			}
		}
		return fin;
	}

	friend fstream& operator<<(fstream& fout, Sponsor& sp)
	{
		int size1 = strlen(sp.numeSponsor);
		fout.write((char*)&size1, sizeof(int));
		fout.write(sp.numeSponsor, size1);
		int size2 = strlen(sp.numeEchipaColaboratoare);
		fout.write((char*)&size2, sizeof(int));
		fout.write(sp.numeEchipaColaboratoare, size2);
		fout.write((char*)&sp.totalAniColaborare, sizeof(int));
		for (int i = 0; i < sp.totalAniColaborare; i++)
		{
			fout.write((char*)&sp.sezoaneColaborare[i], sizeof(int));
		}
		return fout;
	}

	friend fstream& operator>>(fstream& fin, Sponsor& sp)
	{
		if (sp.numeSponsor != NULL)
		{
			delete[] sp.numeSponsor;
		}
		if (sp.numeEchipaColaboratoare != NULL)
		{
			delete[] sp.numeEchipaColaboratoare;
		}
		if (sp.sezoaneColaborare != NULL)
		{
			delete[] sp.sezoaneColaborare;
		}
		char aux[200];
		char aux2[200];
		fin.read(aux, 200);
		sp.numeSponsor = new char[strlen(aux) + 1];
		strcpy(sp.numeSponsor, aux);
		fin.read(aux2, 200);
		sp.numeEchipaColaboratoare = new char[strlen(aux2) + 1];
		strcpy(sp.numeEchipaColaboratoare, aux2);
		fin.read((char*)&sp.totalAniColaborare, sizeof(int));
		if (sp.totalAniColaborare > 0)
		{
			sp.sezoaneColaborare = new double[sp.totalAniColaborare];
			for (int i = 0; i < sp.totalAniColaborare; i++)
			{
				fin.read((char*)&sp.sezoaneColaborare[i], sizeof(int));
			}
		}
		return fin;
	}

	virtual void writeToTextFile(ofstream& fout)
	{
		fout << "\nNume sponsor: " << this->numeSponsor;
		fout << "\nNume echipa colaboratoare: " << this->numeEchipaColaboratoare;
		for (int i = 0; i < this->totalAniColaborare; i++)
		{
			fout << "\nSezoanele in care au colaborat: " << this->sezoaneColaborare[i];
		}
		fout << "\nTotalul de ani in care au colaborat: " << this->totalAniColaborare;
	}

	virtual void readFromTextFile(ifstream& fin)
	{
		if (this->numeSponsor != NULL)
		{
			delete[] this->numeSponsor;
		}
		if (this->numeEchipaColaboratoare != NULL)
		{
			delete[] this->numeEchipaColaboratoare;
		}
		if (this->sezoaneColaborare != NULL)
		{
			delete[] this->sezoaneColaborare;
		}
		char aux[200];
		fin >> aux;
		numeSponsor = new char[strlen(aux) + 1];
		strcpy(this->numeSponsor, aux);
		char aux2[200];
		fin >> aux2;
		numeEchipaColaboratoare = new char[strlen(aux2) + 1];
		strcpy(this->numeEchipaColaboratoare, aux2);
		int nrAni;
		fin >> nrAni;
		if (nrAni > 0)
		{
			this->totalAniColaborare = nrAni;
			double* sezoaneC = new double[nrAni];
			this->sezoaneColaborare = new double[this->totalAniColaborare];
			for (int i = 0; i < nrAni; i++)
			{
				fin >> sezoaneC[i];
			}
			for (int i = 0; i < this->totalAniColaborare; ++i)
			{
				this->sezoaneColaborare[i] = sezoaneC[i];
			}
		}
	}

	void writeToFile(fstream& f)
	{
		int nus = strlen(this->numeSponsor) + 1;
		f.write((char*)&nus, sizeof(int));
		f.write(this->numeSponsor, nus);
		int nue = strlen(this->numeEchipaColaboratoare) + 1;
		f.write((char*)&nue, sizeof(int));
		f.write(this->numeEchipaColaboratoare, nue);
		f.write((char*)&this->totalAniColaborare, sizeof(int));
		for (int i = 0; i < this->totalAniColaborare; i++)
		{
			f.write((char*)&this->sezoaneColaborare[i], sizeof(double));
		}

	}

	void readFromFile(fstream& f)
	{
		if (this->numeSponsor != NULL)
		{
			delete[] this->numeSponsor;
		}
		if (this->numeEchipaColaboratoare != NULL)
		{
			delete[] this->numeEchipaColaboratoare;
		}
		if (this->sezoaneColaborare != NULL)
		{
			delete[] this->sezoaneColaborare;
		}
		int nus;
		f.read((char*)&nus, sizeof(int));
		char* buffer1 = new char[nus];
		f.read(buffer1, nus);
		strcpy(this->numeSponsor, buffer1);
		delete[] buffer1;
		int nue;
		f.read((char*)&nue, sizeof(int));
		char* buffer2 = new char[nue];
		f.read(buffer2, nue);
		strcpy(this->numeEchipaColaboratoare, buffer2);
		delete[] buffer2;
		f.read((char*)&this->totalAniColaborare, sizeof(int));
		this->sezoaneColaborare = new double[this->totalAniColaborare];
		for (int i = 0; i < this->totalAniColaborare; i++)
		{
			f.read((char*)&this->sezoaneColaborare[i], sizeof(double));
		}
	}

	virtual void writeToCSVFile4(fstream& fout)
	{
		fout << this->numeSponsor << ", ";
		fout << this->numeEchipaColaboratoare << ", ";
		for (int i = 0; i < this->totalAniColaborare; i++)
		{
			fout << this->sezoaneColaborare[i];
			if (i < this->totalAniColaborare - 1)
			{
				fout << ", ";
			}
		}
		fout << this->totalAniColaborare << ", ";
	}

	virtual void readFromCSVFile4(fstream& fin)
	{
		fin >> this->numeSponsor;
		fin >> this->numeEchipaColaboratoare;
		for (int i = 0; i < this->totalAniColaborare; ++i)
		{
			fin >> this->sezoaneColaborare[i];
		}
		fin >> this->totalAniColaborare;
	}

};

class Circuit
{
	char* numeCircuit;
	char* numeTara;
	double* sezoaneUtilizare;
	int nrCurse; //adica de cate ori a fost folosita in formula 1

public:

	Circuit()
	{

	}

	Circuit(const char* numeCircuit, const char* numeTara)
	{
		if (numeCircuit != NULL && numeTara != NULL)
		{
			this->numeCircuit = new char[strlen(numeCircuit) + 1];
			strcpy(this->numeCircuit, numeCircuit);
			this->numeTara = new char[strlen(numeTara) + 1];
			strcpy(this->numeTara, numeTara);
		}
	}

	Circuit(const char* numeCircuit, const char* numeTara, double* sezoaneUtilizare, int nrCurse)
	{
		if (numeCircuit != NULL && numeTara != NULL && sezoaneUtilizare != NULL && nrCurse > 0)
		{
			this->numeCircuit = new char[strlen(numeCircuit) + 1];
			strcpy(this->numeCircuit, numeCircuit);
			this->numeTara = new char[strlen(numeTara) + 1];
			strcpy(this->numeTara, numeTara);
			this->nrCurse = nrCurse;
			this->sezoaneUtilizare = new double[nrCurse];
			for (int i = 0; i < this->nrCurse; i++)
			{
				this->sezoaneUtilizare[i] = sezoaneUtilizare[i];
			}
		}
	}

	Circuit(const Circuit& o)
	{
		if (o.numeCircuit != NULL && o.numeTara != NULL && o.sezoaneUtilizare != NULL && o.nrCurse > 0)
		{
			this->numeCircuit = new char[strlen(o.numeCircuit) + 1];
			strcpy(this->numeCircuit, o.numeCircuit);
			this->numeTara = new char[strlen(o.numeTara) + 1];
			strcpy(this->numeTara, o.numeTara);
			this->nrCurse = o.nrCurse;
			this->sezoaneUtilizare = new double[o.nrCurse];
			for (int i = 0; i < this->nrCurse; i++)
			{
				this->sezoaneUtilizare[i] = o.sezoaneUtilizare[i];
			}
		}
	}

	Circuit operator=(const Circuit& o)
	{
		if (this != NULL && o.numeCircuit != NULL && o.numeTara != NULL && o.sezoaneUtilizare != NULL && o.nrCurse > 0)
		{
			if (this->numeCircuit != NULL)
			{
				delete[] this->numeCircuit;
			}
			if (this->numeTara != NULL)
			{
				delete[] this->numeTara;
			}
			if (this->sezoaneUtilizare != NULL)
			{
				delete[] this->sezoaneUtilizare;
			}
			this->numeCircuit = new char[strlen(o.numeCircuit) + 1];
			strcpy(this->numeCircuit, o.numeCircuit);
			this->numeTara = new char[strlen(o.numeTara) + 1];
			strcpy(this->numeTara, o.numeTara);
			this->nrCurse = o.nrCurse;
			this->sezoaneUtilizare = new double[o.nrCurse];
			for (int i = 0; i < this->nrCurse; i++)
			{
				this->sezoaneUtilizare[i] = o.sezoaneUtilizare[i];
			}

		}
		return *this;
	}

	void setNumeCircuit(const char* numeCircuit)
	{
		this->numeCircuit = new char[strlen(numeCircuit) + 1];
		strcpy(this->numeCircuit, numeCircuit);
	}

	void setNumeTara(const char* numeTara)
	{
		this->numeTara = new char[strlen(numeTara) + 1];
		strcpy(this->numeTara, numeTara);
	}

	void setSezoaneUtilizare(double* sezoaneUtilizare, int nrCurse)
	{
		if (sezoaneUtilizare != NULL && nrCurse > 0)
		{
			if (this->sezoaneUtilizare != NULL)
			{
				delete[] this->sezoaneUtilizare;
			}
			this->sezoaneUtilizare = new double[nrCurse];
			this->nrCurse = nrCurse;
			for (int i = 0; i < nrCurse; i++)
			{
				this->sezoaneUtilizare[i] = sezoaneUtilizare[i];
			}
		}
	}

	void setNrCurse(int nrCurse)
	{
		this->nrCurse = nrCurse;
	}

	char* getNumeCircuit()
	{
		return this->numeCircuit;
	}

	char* getNumeTara()
	{
		return this->numeTara;
	}

	double* getSezoaneUtilizare()
	{
		return this->sezoaneUtilizare;
	}

	int getNrCurse()
	{
		return this->nrCurse;
	}

	friend ostream& operator<<(ostream& out, const Circuit& c)
	{
		out << "\nNumele circuitului: " << c.numeCircuit;
		out << "\nNumele tarii: " << c.numeTara;
		out << "\nSezoanele in care a fost utilizat: ";
		for (int i = 0; i < c.nrCurse; i++)
		{
			out << c.sezoaneUtilizare[i] << ", ";
		}
		out << "\nNumarul total de curse: " << c.nrCurse;
		return out;
	}

	friend istream& operator>>(istream& in, Circuit& c)
	{
		cout << "\nNumele circuitului: ";
		in.getline(c.numeCircuit, 100);
		cout << "\nNumele tarii: ";
		in.getline(c.numeTara, 100);
		cout << "\nSezoanele in care a fost utilizat: ";
		for (int i = 0; i < c.nrCurse; i++)
		{
			in >> c.sezoaneUtilizare[i];
		}
		cout << "\nNumarul total de curse: ";
		in >> c.nrCurse;
		cout << "\n";
		return in;
	}

	char& operator[](int index)
	{
		return this->numeCircuit[index];
		return this->numeCircuit[0];
	}

	void operator+=(int addCursa)
	{
		this->nrCurse += addCursa;
		return;
	}

	Circuit operator+(const Circuit& o)
	{
		Circuit aux(o);
		aux.nrCurse = this->nrCurse + o.nrCurse;
		return aux;
	}

	void operator++()
	{
		++this->nrCurse;
		return;
	}

	Circuit operator++(int)
	{
		Circuit aux = *this;
		++this->nrCurse;
		return aux;
	}

	friend bool operator==(Circuit& cir1, Circuit cir2)
	{
		if (cir1.numeCircuit != cir2.numeCircuit)
		{
			return false;
		}
		if (cir1.numeTara != cir2.numeTara)
		{
			return false;
		}
		bool not_equal = false;
		for (int i = 0; i < cir1.nrCurse && not_equal == false; i++)
		{
			if (cir1.sezoaneUtilizare[i] != cir2.sezoaneUtilizare[i])
			{
				not_equal = true;
			}
		}
		if (not_equal == true)
		{
			return false;
		}
		return true;
	}

	bool operator>(Circuit o)
	{
		return this->nrCurse > o.nrCurse;
	}

	bool operator>=(Circuit o)
	{
		return this->nrCurse >= o.nrCurse;
	}

	bool operator!() {
		if (this->sezoaneUtilizare == NULL && this->nrCurse == 0) {
			return true;
		}
		return false;
	}

	~Circuit()
	{
		if (numeCircuit != NULL && numeTara != NULL && sezoaneUtilizare != NULL)
		{
			if (this->numeCircuit != NULL)
			{
				delete[] this->numeCircuit;
			}
			if (this->numeTara != NULL)
			{
				delete[] this->numeTara;
			}
			if (this->sezoaneUtilizare != NULL)
			{
				delete[] this->sezoaneUtilizare;
			}
		}
	}

	friend bool operator<(const Circuit& ci1, const Circuit& ci2)
	{
		return ci1.numeCircuit < ci2.numeCircuit;
	}

	//faza 2

	friend ofstream& operator<<(ofstream& fout, Circuit& ci)
	{
		fout << ci.numeCircuit << "\n";
		fout << ci.numeTara << "\n";
		for (int i = 0; i < ci.nrCurse; i++)
		{
			fout << ci.sezoaneUtilizare[i] << " ";
		}
		fout << ci.nrCurse << "\n";
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin, Circuit& ci)
	{
		if (ci.numeCircuit != NULL)
		{
			delete[] ci.numeCircuit;
		}
		if (ci.numeCircuit != NULL)
		{
			delete[] ci.numeTara;
		}
		char aux[200];
		char aux2[200];
		fin.getline(aux, 200);
		ci.numeCircuit = new char[strlen(aux) + 1];
		strcpy(ci.numeCircuit, aux);
		fin.getline(aux2, 200);
		ci.numeTara = new char[strlen(aux2) + 1];
		strcpy(ci.numeTara, aux2);
		if (ci.nrCurse > 0)
		{
			delete[] ci.sezoaneUtilizare;
			ci.sezoaneUtilizare = new double[ci.nrCurse];
			for (int i = 0; i < ci.nrCurse; i++)
			{
				fin >> ci.sezoaneUtilizare[i];
			}
		}
		fin >> ci.nrCurse;
		return fin;
	}

	friend fstream& operator<<(fstream& fout, Circuit& ci)
	{
		int size1 = strlen(ci.numeCircuit);
		fout.write((char*)&size1, sizeof(int));
		fout.write(ci.numeCircuit, size1);
		int size2 = strlen(ci.numeTara);
		fout.write((char*)&size2, sizeof(int));
		fout.write(ci.numeTara, size2);
		fout.write((char*)&ci.nrCurse, sizeof(int));
		for (int i = 0; i < ci.nrCurse; i++)
		{
			fout.write((char*)&ci.sezoaneUtilizare[i], sizeof(int));
		}
		return fout;
	}

	friend fstream& operator>>(fstream& fin, Circuit& ci)
	{
		if (ci.numeCircuit != NULL)
		{
			delete[] ci.numeCircuit;
		}
		if (ci.numeTara != NULL)
		{
			delete[] ci.numeTara;
		}
		if (ci.sezoaneUtilizare != NULL)
		{
			delete[] ci.sezoaneUtilizare;
		}
		char aux[200];
		fin.read(aux, 200);
		ci.numeCircuit = new char[strlen(aux) + 1];
		strcpy(ci.numeCircuit, aux);
		fin.read(aux, 200);
		ci.numeTara = new char[strlen(aux) + 1];
		strcpy(ci.numeTara, aux);
		fin.read((char*)&ci.nrCurse, sizeof(int));
		if (ci.nrCurse > 0)
		{
			ci.sezoaneUtilizare = new double[ci.nrCurse];
			for (int i = 0; i < ci.nrCurse; i++)
			{
				fin.read((char*)&ci.sezoaneUtilizare[i], sizeof(int));
			}
		}
		return fin;
	}

	virtual void writeToTextFile(ofstream& fout)
	{
		fout << "\nNume circuit: " << this->numeCircuit;
		fout << "\nNume tara: " << this->numeTara;
		for (int i = 0; i < this->nrCurse; i++)
		{
			fout << "\nSezoanele in care a fost utilizat: " << this->sezoaneUtilizare[i];
		}
		fout << "\nTotalul curselor care au avut loc pe acest circuit: " << this->nrCurse;
	}

	virtual void readFromTextFile(ifstream& fin)
	{
		if (this->numeCircuit != NULL)
		{
			delete[] this->numeCircuit;
		}
		if (this->numeTara != NULL)
		{
			delete[] this->numeTara;
		}
		if (this->sezoaneUtilizare != NULL)
		{
			delete[] this->sezoaneUtilizare;
		}
		char aux[200];
		fin >> aux;
		numeCircuit = new char[strlen(aux) + 1];
		strcpy(this->numeCircuit, aux);
		numeTara = new char[strlen(aux) + 1];
		strcpy(this->numeTara, aux);
		int nrC;
		fin >> nrC;
		if (nrC > 0)
		{
			this->nrCurse = nrC;
			double* sezoaneU = new double[nrC];
			this->sezoaneUtilizare = new double[this->nrCurse];
			for (int i = 0; i < nrC; i++)
			{
				fin >> sezoaneU[i];
			}
			for (int i = 0; i < this->nrCurse; i++)
			{
				this->sezoaneUtilizare[i] = sezoaneU[i];
			}
		}
	}

	void writeToFile(fstream& f)
	{
		int nuc = strlen(this->numeCircuit) + 1;
		f.write((char*)&nuc, sizeof(int));
		f.write(this->numeCircuit, nuc);
		int nut = strlen(this->numeTara) + 1;
		f.write((char*)&nut, sizeof(int));
		f.write(this->numeTara, nut);
		f.write((char*)&this->nrCurse, sizeof(int));
		for (int i = 0; i < this->nrCurse; i++)
		{
			f.write((char*)&this->sezoaneUtilizare[i], sizeof(double));
		}

	}

	void readFromFile(fstream& f)
	{
		if (this->numeCircuit != NULL)
		{
			delete[] this->numeCircuit;
		}
		if (this->numeTara != NULL)
		{
			delete[] this->numeTara;
		}
		if (this->sezoaneUtilizare != NULL)
		{
			delete[] this->sezoaneUtilizare;
		}
		int nuc;
		f.read((char*)&nuc, sizeof(int));
		char* buffer1 = new char[nuc];
		f.read(buffer1, nuc);
		strcpy(this->numeCircuit, buffer1);
		delete[] buffer1;
		int nut;
		f.read((char*)&nut, sizeof(int));
		char* buffer2 = new char[nut];
		f.read(buffer2, nut);
		strcpy(this->numeTara, buffer2);
		delete[] buffer2;
		f.read((char*)&this->nrCurse, sizeof(int));
		this->sezoaneUtilizare = new double[this->nrCurse];
		for (int i = 0; i < this->nrCurse; i++)
		{
			f.read((char*)&this->sezoaneUtilizare[i], sizeof(double));
		}
	}

	virtual void writeToCSVFile5(fstream& fout)
	{
		fout << this->numeCircuit << ", ";
		fout << this->numeTara << ", ";
		for (int i = 0; i < this->nrCurse; i++)
		{
			fout << this->sezoaneUtilizare[i];
			if (i < this->nrCurse - 1)
			{
				fout << ", ";
			}
		}
		fout << this->nrCurse << ", ";
	}

	virtual void readFromCSVFile5(fstream& fin)
	{
		fin >> this->numeCircuit;
		fin >> this->numeTara;
		for (int i = 0; i < this->nrCurse; ++i)
		{
			fin >> this->sezoaneUtilizare[i];
		}
		fin >> this->nrCurse;
	}
};

//faza 3
class SefEchipa :public Echipa
{
	string sefEchipa;

public:

	SefEchipa(const char* n, const char* p, int nrS, double* a, int nrV, string sefEchipa) : Echipa(n, p, nrS, a, nrV)
	{
		this->sefEchipa = sefEchipa;
	}

	SefEchipa(const SefEchipa& o) :Echipa(o)
	{
		this->sefEchipa = o.sefEchipa;
	}

	SefEchipa operator=(const SefEchipa& o)
	{
		Echipa::operator=(o);
		this->sefEchipa = o.sefEchipa;
		return *this;
	}

	~SefEchipa()
	{

	}

	friend ostream& operator<<(ostream& out, const SefEchipa& s)
	{
		out << (Echipa)s;
		out << "\nNumar sef de echipa: " << s.sefEchipa;
		out << "\n------------------------------------------------------------";
		return out;
	}
};

class AnulNasterii :public Pilot
{
	int anulNasterii;

public:

	AnulNasterii(const char* nP, const char* nE, int nrS, double p[22], int nrC, int anulNasterii) :Pilot(nP, nE, nrS, p, nrC)
	{
		this->anulNasterii = anulNasterii;
	}

	AnulNasterii(const AnulNasterii& o) : Pilot(o)
	{
		this->anulNasterii = o.anulNasterii;
	}

	AnulNasterii operator=(const AnulNasterii& o)
	{
		Pilot::operator=(o);
		this->anulNasterii = o.anulNasterii;
		return *this;
	}

	~AnulNasterii()
	{

	}

	friend ostream& operator<<(ostream& out, const AnulNasterii& a)
	{
		out << (Pilot)a;
		out << "\nAnul nasterii este: " << a.anulNasterii;
		out << "\n------------------------------------------------------------";
		return out;
	}
};
template<class Sponsor>
class Companie
{
	int nrEchipe = 0;
	Sponsor* s = NULL;

public:

	Companie()
	{
		
	}

	Companie(int nrEchipe, Sponsor* s)
	{
		this->nrEchipe = nrEchipe;
		this->s = new Sponsor[this->nrEchipe];
		for (int i = 0; i < this->nrEchipe; i++)
		{
			this->s[i] = s[i];
		}
	}

	Companie(const Companie& o)
	{
		this->nrEchipe = o.nrEchipe;
		this->s = new Sponsor[this->nrEchipe];
		for (int i = 0; i < this->nrEchipe; i++)
		{
			this->s[i] = o.s[i];
		}
	}

	Companie& operator=(const Companie& o)
	{
		if (this != &o)
		{
			this->nrEchipe = o.nrEchipe;
			this->s = new Sponsor[this->nrEchipe];
			for (int i = 0; i < this->nrEchipe; i++)
			{
				this->s[i] = o.s[i];
			}
		}
		return *this;
	}

	~Companie()
	{
		if (this->s != NULL)
		{
			delete[] this->s;
		}
	}

	friend ostream& operator<<(ostream& out, const Companie& c)
	{
		out << "\nNr de sponsori in F1: " << c.nrEchipe;
		out << "\nLista de sponsori: ";
		for (int i = 0; i < c.nrEchipe; i++)
		{
			out << c.s[i] << " ";
		}
		return out;
	}
};


int main()
{
	//Echipa

	double aniiCastigatoriRedBull[]{ 2010, 2011, 2012, 2013, 2022 };
	Echipa e1("Red Bull Racing", "Max Verstappen si Sergio Perez", 18, aniiCastigatoriRedBull, 5);
	cout << e1;
	cout << "\n-------------------------------------------------------------------------------------";

	double aniiCastigatoriFerrari[]{ 1961, 1964, 1975, 1976, 1977, 1979, 1982, 1983, 1999, 2000, 2001, 2002, 2003, 2004, 2007, 2008 };
	Echipa e2("Scuderia Ferrari", "Charles Leclerc si Carlos Sainz", 73, aniiCastigatoriFerrari, 16);
	cout << e2;
	cout << "\n-------------------------------------------------------------------------------------";

	Echipa e3(e2);
	cout << e3;
	cout << "\n-------------------------------------------------------------------------------------";

	Echipa e4("Scuderia Ferrari", "Charles Leclerc si Carlos Sainz", 73, aniiCastigatoriFerrari, 16);
	e4 = e3;
	cout << e4;
	cout << "\n-------------------------------------------------------------------------------------";

	double aniiCastigatoriMercedes[]{ 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021 };
	e4.setNume("Mercedes AMG Petronas");
	cout << "\nNume: " << e4.getNume();
	e4.setPiloti("Lewis Hamilton si George Russell");
	cout << "\nPiloti: " << e4.getPiloti();
	e4.setNrSezoane(15);
	cout << "\nNumar Sezoane: " << e4.getNrSezoane();
	e4.setNrVictoriiClasamentulConstructorilor(8);
	cout << "\nNumar ani victoriosi: " << e4.getNrVictoriiClasamentulConstructorilor();
	int aniiPtr = e4.getNrVictoriiClasamentulConstructorilor();
	e4.setAniiCastigatori(aniiCastigatoriMercedes, 8);
	cout << endl;
	cout << "Anii in care echipa a castigat in clasamentul constructorilor: ";
	for (int i = 0; i < aniiPtr; i++)
	{
		cout << aniiCastigatoriMercedes[i] << ", ";
	}
	cout << "\n-------------------------------------------------------------------------------------";


	char literaEchipa = e4[1];
	e4[1] = 'k';
	cout << e4;
	cout << "\n-------------------------------------------------------------------------------------";

	Echipa e5("Scuderia Ferrari", "Charles Leclerc si Carlos Sainz", 73, aniiCastigatoriFerrari, 16);
	e5 += 1;
	cout << e5;
	cout << "\n-------------------------------------------------------------------------------------";

	//Pilot

	double pozitiiMax[]{ 19, 1, 18, 1, 1, 1, 3, 1, 1, 7, 2, 1, 1, 1, 1, 1, 7, 1, 1, 1, 6, 1 };
	Pilot p1("Max Verstappen", "Red Bull Racing", 9, pozitiiMax, 22);
	cout << p1;
	cout << "\n-------------------------------------------------------------------------------------";

	double pozitiiCharles[]{ 1, 2, 1, 6, 2, 20, 4, 19, 5, 4, 1, 19, 6, 6, 3, 2, 2, 3, 3, 6, 4, 2 };
	Pilot p2("Charles Leclerc", "Scuderia Ferrari", 5, pozitiiCharles, 22);
	cout << p2;
	cout << "\n-------------------------------------------------------------------------------------";

	Pilot p3(p2);
	cout << p3;
	cout << "\n-------------------------------------------------------------------------------------";

	Pilot p4("Charles Leclerc", "Scuderia Ferrari", 5, pozitiiCharles, 22);
	p4 = p3;
	cout << p4;
	cout << "\n-------------------------------------------------------------------------------------";

	double pozitiiObtinuteLewis[]{ 3, 10, 4, 13, 5 , 6, 6, 9, 2, 19, 8, 5, 13, 5, 3, 6, 2, 7, 8, 4, 9, 20 };
	p4.setNumePilot("Lewis Hamilton");
	cout << "\nNume: " << p4.getNumePilot();
	p4.setNumeEchipa("Mercedes AMG Petronas");
	cout << "\nEchipa: " << p4.getNumeEchipa();
	p4.setNrSezoane(16);
	cout << "\nNumar Sezoane: " << p4.getNrSezoane();
	p4.setNrCurse(22);
	int pozitiiPtr = p4.getNrCurse();
	p4.setPozitiiObtinute(pozitiiObtinuteLewis);
	cout << endl;
	cout << "Pozitii obtinute acest sezon: ";
	for (int i = 0; i < pozitiiPtr; i++)
	{
		cout << pozitiiObtinuteLewis[i] << ", ";
	}
	cout << "\nNumar de curse in care a concurat acest sezon:" << p4.getNrCurse();
	cout << "\n-------------------------------------------------------------------------------------";

	char literaPilot = p4[1];
	p4[1] = 'u';
	cout << p4;
	cout << "\n-------------------------------------------------------------------------------------";

	Pilot p5("Charles Leclerc", "Scuderia Ferrari", 5, pozitiiCharles, 22);
	p5 += 1;
	cout << p5;
	cout << "\n-------------------------------------------------------------------------------------";

	//Cursa
	Cursa c1("Bahrain", 57);
	cout << c1;
	cout << "\n-------------------------------------------------------------------------------------";

	Cursa c2("Arabia Saudita", 50);
	cout << c2;
	cout << "\n-------------------------------------------------------------------------------------";

	Cursa c3(c2);
	cout << c3;
	cout << "\n-------------------------------------------------------------------------------------";

	Cursa c4("Arabia Saudita", 50);
	c4 = c3;
	cout << c4;
	cout << "\n-------------------------------------------------------------------------------------";

	c4.setNrCursei(4);
	cout << "\nNumarul cursei: " << c4.getNrCursei();
	c4.setTara("Italia");
	cout << "\nTara: " << c4.getTara();
	c4.setNrTure(63);
	cout << "\nNumarul de ture: " << c4.getNrTure();
	cout << "\n-------------------------------------------------------------------------------------";

	char literaTara = c3[1];
	c3[1] = 'h';
	cout << c3;
	cout << "\n-------------------------------------------------------------------------------------";

	Cursa c5("Arabia Saudita", 50);
	c5 += 1;
	cout << c5;
	cout << "\n-------------------------------------------------------------------------------------";

	//Sponsor

	double sezoaneColaborarePuma[]{ 2016, 2017, 2018, 2019, 2020, 2021, 2022 };
	Sponsor s1("Puma", "Red Bull Racing", sezoaneColaborarePuma, 7);
	cout << s1;
	cout << "\n-------------------------------------------------------------------------------------";

	double sezoaneColaborareRayBan[]{ 2016, 2017, 2018, 2019, 2020, 2021, 2022 };
	Sponsor s2("Ray-Ban", "Scuderia Ferrari", sezoaneColaborareRayBan, 7);
	cout << s2;
	cout << "\n-------------------------------------------------------------------------------------";

	Sponsor s3(s2);
	cout << s3;
	cout << "\n-------------------------------------------------------------------------------------";

	Sponsor s4("Ray-Ban", "Scuderia Ferrari", sezoaneColaborareRayBan, 7);
	s4 = s3;
	cout << s4;
	cout << "\n-------------------------------------------------------------------------------------";

	double sezoaneColaborareBitdefender[]{ 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022 };
	s4.setTotalAniColaborare(9);
	int sezoanePtr = s4.getTotalAniColaborare();
	s4.setNumeSponsor("Bitdefender");
	cout << "\nNumele sponsorului: " << s4.getNumeSponsor();
	s4.setNumeEchipaColaboratoare("Scuderia Ferrari");
	cout << "\nNumele echipei cu care colaboreaza: " << s4.getNumeEchipaColaboratoare();
	s4.setSezoaneColaborare(sezoaneColaborareBitdefender, 9);
	cout << "\nSezoanele in care au colaborat: ";
	for (int i = 0; i < sezoanePtr; i++)
	{
		cout << sezoaneColaborareBitdefender[i] << ", ";
	}
	cout << "\nNumarul total de ani de colaborare: " << s4.getTotalAniColaborare();
	cout << "\n-------------------------------------------------------------------------------------";


	char literaSponsor = s3[1];
	s3[1] = 'o';
	cout << s3;
	cout << "\n-------------------------------------------------------------------------------------";

	Sponsor s5("Ray-Ban", "Scuderia Ferrari", sezoaneColaborareRayBan, 7);
	s5 += 1;
	cout << s5;
	cout << "\n-------------------------------------------------------------------------------------";

	//Circuit

	double sezoaneYasMarina[]{ 2009, 2010, 2011, 2012, 2014, 2016, 2018, 2019, 2020, 2021, 2022 };
	Circuit ci1("Yas Marina Circuit", "Emiratele Arabe Unite", sezoaneYasMarina, 11);
	cout << ci1;
	cout << "\n-------------------------------------------------------------------------------------";

	double sezoaneUtilizareBahrain[]{ 2005, 2006, 2007, 2008, 2010, 2012, 2013, 2014, 2015, 2017, 2018, 2019, 2020, 2021, 2022 };
	Circuit ci2("Bahrain International Circuit", "Bahrain", sezoaneUtilizareBahrain, 15);
	cout << ci2;
	cout << "\n-------------------------------------------------------------------------------------";

	Circuit ci3(ci2);
	cout << ci3;
	cout << "\n-------------------------------------------------------------------------------------";

	Circuit ci4("Bahrain International Circuit", "Bahrain", sezoaneUtilizareBahrain, 15);
	ci4 = ci3;
	cout << ci4;
	cout << "\n-------------------------------------------------------------------------------------";

	double sezoaneUtilizareSpa[]{ 2012,2013,2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022 };
	ci4.setNrCurse(11);
	int nrCrs = ci4.getNrCurse();
	ci4.setNumeCircuit("Spa");
	cout << "\nNumele circuitului: " << ci4.getNumeCircuit();
	ci4.setNumeTara("Belgia");
	cout << "\nNumele tarii: " << ci4.getNumeTara();
	ci4.setSezoaneUtilizare(sezoaneUtilizareSpa, 11);
	cout << "\nSezoanele in care a fost utilizat: ";
	for (int i = 0; i < nrCrs; i++)
	{
		cout << sezoaneUtilizareSpa[i] << ", ";
	}
	cout << "\nNumarul total de curse: " << ci4.getNrCurse();
	cout << "\n-------------------------------------------------------------------------------------";


	char literaCircuit = ci3[1];
	ci3[1] = 'f';
	cout << ci3;
	cout << "\n-------------------------------------------------------------------------------------";

	Circuit ci5("Bahrain International Circuit", "Bahrain", sezoaneUtilizareBahrain, 15);
	ci5 += 1;
	cout << ci5;
	cout << "\n-------------------------------------------------------------------------------------";

	double sezoaneUtilizareHungaroring[]{ 2004 ,2005, 2006, 2007, 2008, 2010, 2012, 2013, 2014, 2015, 2017, 2018, 2019, 2020, 2021, 2022 };
	Circuit ci6("Hungaroring", "Ungaria", sezoaneUtilizareHungaroring, 16);
	cout << ci6;
	cout << "\n-------------------------------------------------------------------------------------";

	//faza 2
	cout << "\n-------------------------------------------------------------------------------------";
	ofstream outTxt("Detalii.txt", ios::out);
	if (!outTxt) {
		cerr << "Eroare nr 1";
		exit(2);
	}
	outTxt << e2;
	outTxt << p2;
	outTxt << c2;
	outTxt << s2;
	outTxt << ci2;
	outTxt.close();
	cout << e2;
	cout << "\n-------------------------------------------------------------------------------------";
	cout << p2;
	cout << "\n-------------------------------------------------------------------------------------";
	cout << c2;
	cout << "\n-------------------------------------------------------------------------------------";
	cout << s2;
	cout << "\n-------------------------------------------------------------------------------------";
	cout << ci2;
	cout << "\n-------------------------------------------------------------------------------------";
	ifstream inTxt("Detalii.txt", ios::in);
	if (!inTxt) 
	{
		cerr << "Eroare nr 2";
		exit(1);
	}
	inTxt >> e2;
	inTxt >> p2;
	inTxt >> c2;
	inTxt >> s1;
	inTxt >> ci1;
	inTxt.close();
	cout << e2 << "\n";
	cout << "\n-------------------------------------------------------------------------------------";
	cout << p2 << "\n";
	cout << "\n-------------------------------------------------------------------------------------";
	cout << c1 << "\n";
	cout << "\n-------------------------------------------------------------------------------------";
	cout << s2 << "\n";
	cout << "\n-------------------------------------------------------------------------------------";
	cout << ci2 << "\n";
	cout << "\n-------------------------------------------------------------------------------------";
	fstream outBinary("Alte_Informatii.txt", ios::out | ios::binary);
	if (!outBinary) {
		cerr << "Eroare nr 3";
		exit(2);
	}
	outBinary << e2;
	outBinary << p2;
	outBinary << c1;
	outBinary << s1;
	outBinary << ci1;
	outBinary.close();
	fstream inBinary("Alte_Informatii.txt", ios::in | ios::binary);
	if (!inBinary) {
		cerr << "Eroare nr 4";
		exit(1);
	}
	inBinary >> e2;
	inBinary >> p2;
	inBinary >> c1;
	inBinary >> s1;
	inBinary >> ci1;
	inBinary.close();
	fstream f("Informatii_CSV.csv", ios::out | ios::app);
	e2.writeToCSVFile(f);
	p2.writeToCSVFile2(f);
	c1.writeToCSVFile3(f);
	s1.writeToCSVFile4(f);
	ci1.writeToCSVFile5(f);
	f.close();
	string fname;
	cout << "\nIntroduceti numele fisierului: ";
	cin >> fname;

	vector<vector<string>> content;
	vector<string> row;
	string line, word;
	fstream file(fname, ios::in);
	if (file.is_open()) {
		while (getline(file, line)) {
			row.clear();
			stringstream str(line);
			while (getline(str, word, ',')) {
				row.push_back(word);
			}
			content.push_back(row);
		}
	}
	else {
		cout << "\nNu se poate deschide fisierul\n";
	}
	for (int i = 0; i < content.size(); ++i) {
		for (int j = 0; j < content[i].size(); ++j) {
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}

	//faza 3
	double aniiCastigatoriRedBull2[]{ 2010, 2011, 2012, 2013, 2022 };
	string sef = "Christian Horner";
	SefEchipa sE1("Red Bull Racing", "Max Verstappen si Sergio Perez", 18, aniiCastigatoriRedBull2, 5, sef);
	cout << sE1;

	double pozitiiMax2[]{ 19, 1, 18, 1, 1, 1, 3, 1, 1, 7, 2, 1, 1, 1, 1, 1, 7, 1, 1, 1, 6, 1 };
	AnulNasterii aN1("Max Verstappen", "Red Bull Racing", 9, pozitiiMax2, 22, 1997);
	cout << aN1;
	cout << "OPERATORUL =";
	SefEchipa sE2 = sE1;
	AnulNasterii aN2 = aN1;
	cout << sE2;
	cout << aN2;
	cout << "\n---------------------------CLASA CU TAMPLATE--------------------------";
	Sponsor vSpon[] = { s2, s3, s4 };
	Companie<Sponsor> comp1(3, vSpon);
	cout << comp1;

	cout << "\n----------------VECTOR DE POINTERI-----------------------";
	Pilot listaPilot[] = { p1, p3, p4 };
	for (int i = 0; i < 3; i++)
	{
		cout << listaPilot[i] << "\n";
	}

	cout << "\n------------------STL-----------------";
	cout << "\n";
	vector<Pilot> vecPi;
	vecPi.push_back(p1);
	vecPi.push_back(p3);
	vecPi.push_back(p4);

	for (int i = 0; i < vecPi.size(); i++)
	{
		cout << vecPi[i] << " ";
	}

	cout << "\n---------------------------------STL VECTOR---------------";
	cout << "\n";
	vector<Pilot>::iterator it1;
	for (it1 = vecPi.begin(); it1 != vecPi.end(); it1++)
	{
		cout << *it1 << " ";
	}

	cout << "\n---------------------------------STL LIST---------------";
	cout << "\n";
	list <Pilot> piList;
	piList.push_front(p1);
	piList.push_back(p3);
	piList.push_front(p4);
	list <Pilot>::iterator it2;
	for (it2 = piList.begin(); it2 != piList.end(); it2++)
	{
		cout << *it2 << " ";
	}

	cout << "\n---------------------------------STL SET---------------";
	cout << "\n";
	set<Pilot> setPilot;
	setPilot.insert(p1);
	setPilot.insert(p3);
	setPilot.insert(p4);
	set<Pilot>::iterator it3;
	for (it3 = setPilot.begin(); it3 != setPilot.end(); it3++)
	{
		cout << *it3 << "\n";
	}
	cout << "\n";

	cout << "\n--------------------------------------STL MAP---------------------------";
	cout << "\n";
	map<int, Sponsor> Map;
	Map[10] = s2;
	Map[101] = s3;

	map<int, Sponsor>::iterator itMap;
	for (itMap = Map.begin(); itMap != Map.end(); itMap++)
	{
		cout << itMap->first << " " << itMap->second << endl;
	}

	return 0;
}