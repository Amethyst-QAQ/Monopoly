#include "Country.h"
#include "../Player/Player.h"
#include "../IO/Menu.h"
#include "../IO/Output.h"
#include "../Map/Map.h"

using namespace std;

int Country::getBaseToll()
{
    switch (houseNum)
    {
    case 0:
        return price / 4;
    case 1:
        return price / 2;
    case 2:
        return price;
    case 3:
        return price * 2;
    case 4:
        return price * 4;
    case 5:
        return price * 10;
    }
}

void Country::show()
{
    GroundWithPrice::show();
    string mainText;
    string serverText;

    mainText = "Color: " + to_string(color);
    serverText = "show_color " + getName();
    Output::instance->print(mainText, serverText);

    mainText = "House Number: " + to_string(houseNum);
    serverText = "show_house_num " + getName();
    Output::instance->print(mainText, serverText);
}

int Country::getToll()
{
    int toll = getBaseToll();
        if (owner->getProperty("country" + to_string(color)) == Map::instance->getCountryAmount(color))
    return toll * 4;
    return toll;
}

int Country::getHousePrice()
{
    if (houseNum == 4)
        return price * 2;
    return price / 2;
}

void Country::build(Player *player)
{
    int money = player->getMoney();
    if (money < price)
    {
        Output::instance->print(
            "You don't have enough money to build.",
            "insufficient_money"
        );
        return;
    }
    money -= price;
    player->setMoney(money);
    houseNum++;
    Output::instance->print(
        "Successfully build!",
        "success"
    );
}

void Country::buy(Player *player)
{
    GroundWithPrice::buy(player);
    player->setProperty("country" + to_string(color), player->getProperty("country" + to_string(color)) + 1);
}

bool Country::onStepped(Player *player)
{
    if (GroundWithPrice::onStepped(player))
        return true;

    if (owner == player && houseNum < 5)
    {
        string mainText = "The ground is yours.";
        vector<string> operations = { "Build a ", "Exit" };
        string serverText = "build";
        if (houseNum == 4)
            operations[0] += "hotel";
        else
            operations[0] += "house";
        operations[0] += " at price " + to_string(getHousePrice());

        Menu menu(mainText, operations, serverText);
        int n = menu.exec();

        switch (n)
        {
        case 1:
            build(player);
            break;
        case 2:
            return true;
        }
    }

    return false;
}
