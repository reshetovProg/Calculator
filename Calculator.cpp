#include "Calculator.h"

Calculator::Calculator() 
	: window(sf::VideoMode(400, 500), L"Калькулятор")
{
	
	/*for (int i = 0,k=0, yb=100; i < 4; i++, yb+=100) {
		for (int j = 0; j < 4; j++) {
			coord[k][0] = j*100;
			coord[k][1] = yb;
			coord[k][2] = coord[k][0]+99;
			coord[k++][3] = yb+99;
		}
	}*/

	/*for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << coord[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{

		//std::cout << "font not found";
	}
	field = new Field(400, 100, "0");
	field->setPosition(0,0);
	b7 = new Button(100, 100, "7");
	b7->setPosition(0, 100);
	b8 = new Button(100, 100, "8");
	b8->setPosition(100, 100);
	b9 = new Button(100, 100, "9");
	b9->setPosition(200, 100);
	bsum = new Button(100, 100, "+");
	bsum->setPosition(300, 100);

	b4 = new Button(100, 100, "4");
	b4->setPosition(0, 200);
	b5 = new Button(100, 100, "5");
	b5->setPosition(100, 200);
	b6 = new Button(100, 100, "6");
	b6->setPosition(200, 200);
	bdif = new Button(100, 100, "-");
	bdif->setPosition(300, 200);

	b1 = new Button(100, 100, "1");
	b1->setPosition(0, 300);
	b2 = new Button(100, 100, "2");
	b2->setPosition(100, 300);
	b3 = new Button(100, 100, "3");
	b3->setPosition(200, 300);
	bmult = new Button(100, 100, "X");
	bmult->setPosition(300, 300);

	bc = new Button(100, 100, "C");
	bc->setPosition(0, 400);
	b0 = new Button(100, 100, "0");
	b0->setPosition(100, 400);
	beq = new Button(100, 100, "=");
	beq->setPosition(200, 400);
	bdiv = new Button(100, 100, "/");
	bdiv->setPosition(300, 400);

	panel = new Button * [16]{ b7, b8, b9, bsum, b4, b5, b6, bdif, b1, b2, b3, bmult, bc, b0, beq, bdiv };

}

void Calculator::run()
{
	while (window.isOpen())
	{
		eventState();
		update();
		render();
	}
}

std::string Calculator::calculate(std::string number1, std::string number2, short operation)
{	
	double num1 = strToDouble(number1);
	double num2 = strToDouble(number2);

	double result;
	switch (operation) {
	case 1: //+
		result = num1 + num2;
		break;
	case 2: //-
		result = num1 - num2;
		break;
	case 3: //*
		result = num1 * num2;
		break;
	case 4: // /
		if (num2 == 0) return "division by 0";
		else {
			result = num1 / num2;
		}
		break;
	}

	std::string str = std::to_string(result);
	field->setStatus(false);
	return str;


	
}


double Calculator::strToDouble(std::string str)
{
	std::string beforePoint = "";
	std::string afterPoint = "";
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.') {
			for (int j = i + 1; str[j] != '\0'; j++) {
				afterPoint += str[j];
			}
			break;
		}
		else {
			beforePoint += str[i];
		}
	}
	double result = 0;
	for (int i = 0; beforePoint[i] != '\0'; i++) {
		result *= 10;
		result += beforePoint[i] - 48;
	}
	double result2 = 0;
	for (int i = 0; afterPoint[i] != '\0'; i++) {

		result2 *= 10;
		result2 += afterPoint[i] - 48;
	}
	result2 *= pow(0.1, size(afterPoint));
	result += double(result2);
	return result;

}



void Calculator::eventState()
{
	sf::Vector2i localPosition;
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			localPosition = sf::Mouse::getPosition(window);
			std::cout << localPosition.x << " : " << localPosition.y<<std::endl;
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			}
			for (int i = 0; i < 16; i++) {
				if (localPosition.x >= panel[i]->getPosition().x &&
					localPosition.x <= panel[i]->getPosition().x+99 &&
					localPosition.y >= panel[i]->getPosition().y &&
					localPosition.y <= panel[i]->getPosition().y + 99) {
					
					panel[i]->push(field);

				}

			}
		}
	}
}

void Calculator::update()
{
	if (field->getStatus() == true)
	{
		field->setField(
			calculate(
				field->getNum1(), field->getNum2(), field->getOperation()));
	}

}

void Calculator::render()
{
	window.clear(sf::Color::White);
	window.draw(b7->getButton());
	window.draw(b7->getText());
	window.draw(b8->getButton());
	window.draw(b8->getText());
	window.draw(b9->getButton());
	window.draw(b9->getText());
	window.draw(bsum->getButton());
	window.draw(bsum->getText());

	window.draw(b4->getButton());
	window.draw(b4->getText());
	window.draw(b5->getButton());
	window.draw(b5->getText());
	window.draw(b6->getButton());
	window.draw(b6->getText());
	window.draw(bdif->getButton());
	window.draw(bdif->getText());

	window.draw(b1->getButton());
	window.draw(b1->getText());
	window.draw(b2->getButton());
	window.draw(b2->getText());
	window.draw(b3->getButton());
	window.draw(b3->getText());
	window.draw(bmult->getButton());
	window.draw(bmult->getText());

	window.draw(bc->getButton());
	window.draw(bc->getText());
	window.draw(b0->getButton());
	window.draw(b0->getText());
	window.draw(beq->getButton());
	window.draw(beq->getText());
	window.draw(bdiv->getButton());
	window.draw(bdiv->getText());

	window.draw(field->getField());
	window.draw(field->getText());

	window.display();
}

