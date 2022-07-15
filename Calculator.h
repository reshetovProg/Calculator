#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Field.h"
#include <Windows.h>


class Calculator 
{
private:
	friend class Button;
	sf::RenderWindow window;
	sf::Font font;
	Button* b0;
	Button* b1;
	Button* b2;
	Button* b3;
	Button* b4;
	Button* b5;
	Button* b6;
	Button* b7;
	Button* b8;
	Button* b9;
	Button* bc;
	Button* beq;
	Button* bmult;
	Button* bdif;
	Button* bsum;
	Button* bdiv;
	//int coord[16][4];
	Button** panel;
	Field* field;

public:
	Calculator();
	void run();
	std::string calculate(std::string, std::string, short);
	double strToDouble(std::string str);
private:
	void eventState();
	void update();
	void render();
	
};

