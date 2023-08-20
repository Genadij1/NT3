#include <iostream>
#include <fstream>
using namespace std;

class Reservoir
{
private:
	string Name;
	string Type;
	double Width;
	double Length;
	double MaxDepth;

public:
	explicit Reservoir(string Name, string Type, double Width, double Length, double MaxDepth) :Name(Name), Type(Type), Width(Width), Length(Length), MaxDepth(MaxDepth) {};
	Reservoir() : Reservoir("", "", 0.0, 0.0, 0.0) {};
	Reservoir(const Reservoir& other) : Name(other.Name), Type(other.Type), Width(other.Width), Length(other.Length), MaxDepth(other.MaxDepth) {}
	~Reservoir() {};
	void SetName()
	{
		this->Name = Name;
		cout << "Enter the name: ";
		cin >> Name;
	}
	void SetType()
	{
		this->Type = Type;
		cout << "Enter the type: ";
		cin >> Name;
	}
	void SetWidth()
	{
		this->Width = Width;
		cout << "Enter the width: ";
		cin >> Width;
	}
	void SetLength()
	{
		this->Length = Length;
		cout << "Enter the length: ";
		cin >> Length;
	}
	void SetMaxDepth()
	{
		this->MaxDepth = MaxDepth;
		cout << "Enter the max depth: ";
		cin >> MaxDepth;
	}

	double ApproximateObligation()
	{
		return Width * Length * MaxDepth;
	}
	double Area()
	{
		return Width * Length;
	}
	bool SameType(Reservoir& other) 
	{ 
		return Type == other.Type; 
	}
	bool SameArea(Reservoir& othera) 
	{ 
		return Area() == othera.Area(); 
	}
	Reservoir copy() const {
		return Reservoir(*this);
	}
	void displayInfo() {
		cout << "Name: " << Name << "\n";
		cout << "Name: " << Type << "\n";
		cout << "Width: " << Width << "\n";
		cout << "Length: " << Length << "\n";
		cout << "Max Depth: " << MaxDepth << "\n";
		cout << "ApproximateObligation = " << ApproximateObligation();
		cout << "Area = " << Area()<<endl;
		SaveToFile();
	}
	void SaveToFile()
	{
		ofstream outFile("data.txt", ios::app);
		if (outFile.is_open())
		{

			outFile << "Name: " << Name << "\t|" << "Type: " << Type << "\t|" << "Width: " << Width << "\t|" << "Length: " << Length << "\t|" << "Max depth: " << MaxDepth << "\n" << "\n";
			outFile.close();
			cout << "The data was successfully saved to a file.\n";
		}
		else
		{
			cout << "Error opening file.\n";
		}
	}
};
