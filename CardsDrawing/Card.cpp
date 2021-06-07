#include "Card.h"

void Card::show()
{
	std::string mainText;
	std::string serverText;

	mainText = "The name of the card is : " + name;
	serverText = "card_name";
	Output::instance->print(mainText, serverText);

	mainText = "The lucky value of the card is : " + std::to_string(val);
	serverText = "card_val";
	Output::instance->print(mainText, serverText);

	mainText = "The num of the card is : " + std::to_string(num);
	serverText = "card_num";
	Output::instance->print(mainText, serverText);
}