#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>
using namespace std;

class item
{
  public:
    item(string setName, string setBox)
    {
        name = setName;
        box = setBox;
    }
    string name;
    int time;
    string box;
};
typedef vector<item *> itemList;
typedef vector<itemList *> itemListTotal;
class box
{
  public:
    box(char setName, int setPosition)
    {
        name = setName;
        position = setPosition;
    }
    char name;
    int position;
    itemList all_item;
};
typedef vector<box *> boxList;
#include <random>
using namespace std;
// random_device rd;
mt19937 gen;
uniform_int_distribution<int> dis(1, 1000000);

int main()
{
    for (int a = 0; a < 10; a++)
    {

        string real{(char)(gen() % 26 + 65)};
        for (int i = 0; i < 8; ++i)
        {
            string add{(char)(dis(gen) % 26 + 65)};
            real += add;
        }
        cout << real << endl;
    }
    auto start = std::chrono::system_clock::now();
    std::time_t curr = std::chrono::system_clock::to_time_t(start);
    string curr_time = ctime(&curr);
    istringstream in(curr_time);
    string date[3];
    string t;
    int counter = 0;
    while (in >> t)
    {

        if (counter == 1)
        {
            date[0] = t;
        }
        else if (counter == 2)
        {
            date[1] = t;
        }
        else if (counter == 4)
        {
            date[2] = t;
        }
        counter++;
    }
    string Date;
    Date = date[0] + " " + date[1] + " " + date[2];
    cout << Date << endl;

    int tmp = 100;
    char cstr[20];
    snprintf(cstr, sizeof(cstr), "%d * %d = %d", tmp, tmp, tmp * tmp);
}
