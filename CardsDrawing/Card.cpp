#include "Card.h"

void Card::show()
{
	std::string mainText;
	std::string serveText;

	mainText = "The name of the card is : " + name;
	serveText = "card_name";
	Output::instance->print(mainText, serveText);

	mainText = "The lucky value of the card is : " + std::to_string(val);
	serveText = "card_val";
	Output::instance->print(mainText, serveText);

	mainText = "The num of the card is : " + std::to_string(num);
	serveText = "card_num";
	Output::instance->print(mainText, serveText);
}