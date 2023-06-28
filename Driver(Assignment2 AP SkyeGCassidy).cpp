// Driver(Assignment2 AP SkyeGCassidy).cpp : This file contains the 'main' function. Program execution begins and ends there.
/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include <ostream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands

	while (userCommand.compare("exit") != 0)
	{
		parameters.clear();
		cout << "Enter the command: ";
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());
		//implemented a string tokenizer to populate the parameters vector by using strtok_s
		char* token = NULL;
		char* next_Token = NULL;
		token = strtok_s(cstr, " ", &next_Token);
		//creating char pointer variables token and next token.
		//using strtok_s to get first token from string.
		while (token != NULL)
		{
			if (token != NULL)
			{
				parameters.push_back(token);
				//pushing back string token into Parameter vector.
				token = strtok_s(NULL, " ", &next_Token);
				//if token char is not NULL, get next token split from string.
			}

		}
		string command = parameters[0];
		//defining string and assigning it to the first index value of parameter.
	
		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			int x = stoi(parameters[1]); //fixed :)
			int y = stoi(parameters[2]);
			int h = stoi(parameters[3]);
			int w = stoi(parameters[4]);
			//turning Parameters to int, and to float, and assigning them to parameter elements.
			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			cout << r->toString();

			//defining pointer object r which will hold 4 arguements.
			//pushing back rectangle shape info into shape vector.
			//printing out rectangle pointing to the toString overriding method.
		}

		else if (command.compare("addS") == 0) {
			// get parameters in the correct order
			int x = stoi(parameters[1]);
			int y = stoi(parameters[2]);
			int e = stoi(parameters[3]);
			//turning Parameters to int, and to float, and assigning them to parameter elements.
			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s->toString();
			//defining pointer object s which will hold 3 arguements.
			//pushing back square shape info into shape vector.
			//printing out square pointing to the toString overriding method.
		}

		if (command.compare("addC") == 0) {
			// get parameters in the correct order
			int x = stoi(parameters[1]);
			int y = stoi(parameters[2]);
			int r = stoi(parameters[3]);
			//turning Parameters to int, and to float, and assigning them to parameter elements.
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c->toString();
			//defining pointer object c which will hold 3 arguements.
			//pushing back Circle shape info into shape vector.
			//printing out Circle pointing to the toString overriding method.
		}
		else if (command.compare("scale") == 0) {
			int shapeNo = stoi(parameters[1]);
			float x = stof(parameters[2]);
			float y = stof(parameters[3]);
			//turning Parameters to int, and to float, and assigning them to parameter elements.
			Movable* scale = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			//shapeNo must begin at index 1 so we use -1.
			//pointer object Scale, using forced downcasting to point directly to rectangle, square or circle.
			scale->scale(x, y);
			//scale points to scale method, overridden in rectangle, square and circle with 2 arguements.
			cout << shapes[shapeNo - 1]->toString();
			//print out the shape regarding the shape number, along with the updated information of the shape.

			

		}

		else if (command.compare("move") == 0) {
			int shapeNo = stoi(parameters[1]);
			int x = stoi(parameters[2]);
			int y = stoi(parameters[3]);
			//turning Parameters to int, and assigning them to parameter elements.
			Movable* move = dynamic_cast<Movable*>(shapes[shapeNo-1]);
			//shapeNo must begin at index 1 so we use -1.
			//pointer object Move, using forced downcasting to point directly to rectangle, square or circle
			move->move(x, y);
			//move points to move method, overridden in rectangle, square and circle with 2 arguements.
			
			cout << shapes[shapeNo-1]->toString();
			//print out the shape regarding the shape number, along with the updated information of the shape.
			
		}
		else if (command.compare("display") == 0) {
			// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
			
			//for (int i = 0; i < shapes.size(); i++)
			//{
			//	cout << shapes[i];
			//}


		}
		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing..
		cout << endl << endl;

	}
	cout << "Press any key to continue...";
return 0;
	
}