#include "Card.h"

void Card::show()
{
	std::string mainText;
	std::string serverText;

	mainText = "The name of the card is : " + name;
	serverText = "card_name " + name;
	Output::instance->print(mainText, serverText);

	mainText = "The lucky value of the card is : " + std::to_string(val);
	serverText = "card_val " + std::to_string(val);
	Output::instance->print(mainText, serverText);

	mainText = "The num of the card is : " + std::to_string(num);
	serverText = "card_num " + std::to_string(num);
	Output::instance->print(mainText, serverText);
}