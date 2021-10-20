// WarstlerC_CSCE2004_Project4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
using namespace std;

//Public Constants
//Food
const int apple = 0;
const int steak = 1;
const int potion = 2;
const int appleHeal = 5;
const int steakHeal = 20;
const int potionHeal = 40;

//Enemy
const int slime = 0;
const int bugbear = 1;
const int mindflayer = 2;
const int slimeDmg = 5;
const int bugbearDmg = 15;
const int mindflayerDmg = 25;

//Other
const int tuition = 50;
const int ale = 10;
const int max_gold = 50;

//Function Protoypes
void PrintStatus(int gold, int health);
int FindTreasure(const int maxGold);
void EatFood(const int food, int& health);
int FightBattle(const int creature);
char GetDirection();
void Exit(int& gold, int& health);
void Room1(int& gold, int& health);
void Room2(int& gold, int& health);
void Room3(int& gold, int& health);
void Room4(int& gold, int& health);

//Add more function protoypes
void Room5(int& gold, int& health);
void Room6(int& gold, int& health);
void Room7(int& gold, int& health);
void Room8(int& gold, int& health);

void PrintStatus(int gold, int health)
{
    if (gold > 2 * health)
        cout << endl << "You are rich with " << gold
        << " gold, but your health is only " << health << endl;
    else if (health > 2 * gold)
        cout << endl << "You are strong with " << health
        << " health, but you only have " << gold << " gold" << endl;
    else
        cout << endl << "Your health is " << health
        << " and you have " << gold << " gold" << endl;
}

//------------------------------------------------------------
// Purpose: To calculate how much treasure is found
// Input:   Maximum amount of gold possible
// Output:  Actual amount of gold found
//------------------------------------------------------------
int FindTreasure(const int max_gold)
{
    int gold = 1 + rand() % max_gold;
    if (gold < max_gold / 2)
        cout << "\nYou find " << gold << " gold pieces on the floor.\n";
    else
        cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";
    return gold;
}

//------------------------------------------------------------
// Purpose: To eating food item to restore health.
// Input:   Food item number between [0..2]
// Output:  Health value after eating food.
//------------------------------------------------------------
void EatFood(const int food, int& health)
{
    switch (food)
    {
    case apple:
        health = health + appleHeal;
        cout << "\nYou find a half eaten apple on the floor "
            << "which restores your health by " << appleHeal << endl;
        break;
    case steak:
        health = health + steakHeal;
        cout << "\nYou find a warm and jucy steak on the table "
            << "which restores your health by " << steakHeal << endl;
        break;
    case potion:
        health = health + potionHeal;
        cout << "\nYou find a red glowing potion on a shelf "
            << "which restores your health by " << potionHeal << endl;
        break;
    default:
        cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
        break;
    }

    // Check maximum value for health
    if (health > 100)
        health = 100;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int FightBattle(const int creature)
{
    int damage = 0;
    switch (creature)
    {
    case slime:
        damage = 1 + rand() % slimeDmg;
        cout << "\nYou trip over a slimy slime and do "
            << damage << " damage to your health.\n";
        break;
    case bugbear:
        damage = 1 + rand() % bugbearDmg;
        cout << "\nA hairy dwarf hits you with a club and does "
            << damage << " damage to your health.\n";
        break;
    case mindflayer:
        damage = 1 + rand() % mindflayerDmg;
        cout << "\nAn angry mindflayer sucks your brain and does "
            << damage << " damage to your health.\n";
        break;
    default:
        cout << "\nIt is ghostly quiet here, you must be alone\n";
        break;
    }
    return damage;
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
    cout << "\nWhat direction would you like to go (N,S,E,W): ";
    char direction;
    cin >> direction;
    direction = toupper(direction);
    while ((direction != 'N') && (direction != 'S') &&
        (direction != 'E') && (direction != 'W'))
    {
        cout << "Sorry, You can not go that way...\n";
        cout << "What direction would you like to go (N,S,E,W): ";
        cin >> direction;
        direction = toupper(direction);
    }
    return direction;
}

//------------------------------------------------------------
// Purpose: To find the cave exit
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Exit(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou crawl out of the cave and blink your eyes to\n";
    cout << "adjust to the bright sunshine. Congratulations,\n";
    cout << "you made it out of the cave with " << health << " health!\n";

    if (gold >= tuition)
    {
        cout << "\nYou empty your pockets and discover " << gold << " gold coins.\n";
        cout << "This will pay for tuition next semester!!!\n";
    }
    else if (gold >= ale)
    {
        cout << "\nYou notice that you have " << gold << " gold coins in your pocket.\n";
        cout << "This will pay for ale at the next tavern!!!\n";
    }
    else
    {
        cout << "\nYou check your pocket and find " << gold << " gold coins.\n";
        cout << "Exploring caves sure is a hard way to make money!!!\n";
    }

    // Leave program
    exit(0);
}

void Room1(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou just stumbled into a hole in the ground. When you\n";
    cout << "shake off the dirt and leaves you realize you are in\n";
    cout << "the entrance to a cave that looks man made. As you\n";
    cout << "take a look around, you decide it might be fun to explore.\n";

    // ADD CODE HERE
    cout << "\nAs you decide to walk around and look for more supplies, a";
    cout << "\nslime hops out of the shadows and tries to headbutt you!\n";
    health = health - FightBattle(slime);
    gold += FindTreasure(max_gold);
    PrintStatus(gold, health);

    //Get direction to the next room
    char direction = GetDirection();

    while (direction == 'N')
    {
        cout << "\nYou notice there is no way to here, you decide to try another direction.\n";
        direction = GetDirection();
    }

    if (direction == 'E')
    {
        cout << "\nAfter searching around the room, you\n";
        cout << "find a crawlspace behind a couple discarded boxes.\n";
        Room3(gold, health);
    }

    if (direction == 'S')
    {
        cout << "\nAfter fumbling around in the dark, you come across a lit hallway.\n";
        cout << "You decide to follow the dimly lit hallway to the next room.\n";
        Room5(gold, health);
    }

    if (direction == 'W')
    {
        cout << "\nWhile making your way around the room, you notice a ladder going down into a pit.\n";
        cout << " You decide to take your chances and go down it.\n";
        Room2(gold, health);
    }
}

void Room2(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered the throne room. In the middle\n";
    cout << "of the room there is a giant wooden throne with\n";
    cout << "intricate carvings. As you take a closer look at the\n";
    cout << "carvings, you see that they show bugbears chasing humans.\n";
    cout << "Hmmm, maybe this is not a great place to stop for a rest.\n";

    // ADD CODE HERE
    health = health - FightBattle(bugbear);
    gold += FindTreasure(max_gold);

    cout << "\nAfter fighting to get away from the bugbear,\n";
    cout << "you decide to search the room for some food.\n";

    EatFood(steak, health);
    PrintStatus(gold, health);

    char direction = GetDirection();

    while ((direction == 'E') || (direction == 'W'))
    {
        cout << "\nYou notice that it is not possible to go that way. You decide to try another direction.\n";
        direction = GetDirection();
    }

    if (direction == 'N')
    {
        cout << "\nYou find a hallway covered in what looks like human remains.\n";
        cout << "Reluctantly, you decide to go down the hallway to see what you can find.\n";
        Room1(gold, health);
    }

    if (direction == 'S')
    {
        cout << "\nFor the fist time, you find what seems to be a normal hallway.\n";
        cout << "You take your chances and go down it anyways.\n";
        Room4(gold, health);
    }
}

void Room3(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered an abandoned tavern. There are piles\n";
    cout << "of dirty dishes and empty beer mugs all over the place.\n";
    cout << "You hear someone coming and duck behind a table to hide.\n";

    // ADD CODE HERE
    cout << "\nAs you duck behind a table, you notice a green ooze\n";
    cout << "slowly slide into view. Turns out you heard a slime.\n";
    cout << "As you sigh a breathe of relief, the slime throws\n";
    cout << "itsself at you!\n";
    health = health - FightBattle(slime);

    cout << "You decide to take a minute to find something to eat and regain your composure.\n";
    EatFood(potion, health);
    PrintStatus(gold, health);

    char direction = GetDirection();
    while (direction == 'W')
    {
        cout << "\nYou notice that it is not possible to go that way, you decide to try another direction.\n";
        direction = GetDirection();
    }

    if (direction == 'N')
    {
        cout << "\nYou walk down the nearest hallway.\n";
        Room1(gold, health);
    }

    if (direction == 'E')
    {
        cout << "\nAfter tripping over a pebble, you find a door leading to another room.\n";
        Room8(gold, health);
    }

    if (direction == 'S')
    {
        cout << "\nYou go down the hallway to the South. It is too dark to see anything.\n";
        Room5(gold, health);
    }

}

void Room4(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered a huge storage room filled with empty boxes.\n";
    cout << "Looking at the side of one box, you see 'ACME bugbear food'.\n";
    cout << "You better get out of here before you end up on the menu.\n";

    // ADD CODE HERE
    cout << "\nAs you start to run away, a bugbear grabs you by the collar of your shirt!\n";

    health = health - FightBattle(bugbear);

    cout << "After being attacked by the bugbear, you are finally able to escape.\n";
    cout << "Before you do, you were able to grab a couple gold littered throughout\n";
    cout << "the room as well as a shiny potion sitting in the corner.\n";

    gold += FindTreasure(max_gold);
    EatFood(potion, health);
    PrintStatus(gold, health);

    char direction = GetDirection();
    while (direction == 'W')
    {
        cout << "\nYou notice there is no way to go here, you decide to try another direction.\n";
        direction = GetDirection();
    }

    if (direction == 'N')
    {
        cout << "You walk down a boring hallway. You get the feeling that you are going in a circle.\n";
        Room2(gold, health);
    }

    if (direction == 'E')
    {
        Room5(gold, health);
    }

    if (direction == 'S')
    {
        Room6(gold, health);
    }

}

// ADD FUNCTIONS HERE
void Room5(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou enter what seems to be a religious alter room. You see\n";
    cout << "skulls littering the floor as you enter the room. The air is\n";
    cout << "stale, as if nobody has been in here for a very long time.\n";

    gold += FindTreasure(max_gold);

    char direction = GetDirection();
    if (direction == 'N')
    {
        Room3(gold, health);
    }

    if (direction == 'E')
    {
        Room8(gold, health);
    }

    if (direction == 'S')
    {
        Room4(gold, health);
    }

    if (direction == 'W')
    {
        Room1(gold, health);
    }

}

void Room6(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou enter what seems to be a living quarters. Dirty, makeshift\n";
    cout << "beds in each corner. You decide to take a minute and look for more treasure.\n";

    gold += FindTreasure(max_gold);

    char direction = GetDirection();
    while ((direction == 'E') || (direction == 'W'))
    {
        cout << "\nYou notice there is no way to go here, you decide to try another direction.\n";
        direction = GetDirection();
    }

    if (direction == 'N')
    {
        Room4(gold, health);
    }

    if (direction == 'S')
    {
        Room7(gold, health);
    }
}

void Room7(int& gold, int& health)
{

    cout << "\n------------------------------------------------------------\n";
    cout << "\nAfter walking around, you find a door that you hope goes outside.\n";
    cout << "As you make your way accross the room though, you trip over a Mindflayer's\n";
    cout << "tentacle. It shrieks and leaps to attack you!\n";

    health = health - FightBattle(mindflayer);

    char direction = GetDirection();
    while ((direction == 'N') || (direction == 'S'))
    {
        cout << "\nYou notice there is no way to go there, you decide to try another direction.\n";
        direction = GetDirection();
    }

    if (direction == 'E')
    {
        Exit(gold, health);
    }

    if (direction == 'W')
    {
        Room6(gold, health);
    }
}

void Room8(int& gold, int& health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nAfter being stuck in this dark and dingy cave for what seems a lifetime,\n";
    cout << "you let out a long hard sigh. As you sigh, you hear something behind you.\n";

    health = health - FightBattle(mindflayer);
    gold += FindTreasure(max_gold);

    char direction = GetDirection();
    while (direction == 'W')
    {
        cout << "\nYou notice there is no way to go that way, you decide to try another direction.\n";
        direction = GetDirection();
    }

    if (direction == 'N')
    {
        Room3(gold, health);
    }

    if (direction == 'E')
    {
        Exit(gold, health);
    }

    if (direction == 'S')
    {
        Room5(gold, health);
    }
}

int main()
{
    // Initialize game
    int gold = 0;
    int health = 100;
    srand(time(NULL));

    // ADD CODE HERE
    Room1(gold, health);

    return 0;
}