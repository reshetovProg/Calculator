#include "Calculator.h"

Calculator::Calculator() 
	: window(sf::VideoMode(400, 500), L"Калькулятор")
{
	if (!font.loadFromFile("resources/fonts/arial.ttf"))
	{

		//std::cout << "font not found";
	}
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
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

void Calculator::eventState()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Calculator::update()
{
	text.setString(L"Калькулятор");
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

	window.draw(text);
	window.display();
}

