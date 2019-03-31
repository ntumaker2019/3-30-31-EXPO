#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Utils.hpp>
#include <string>
#include <iostream>
using namespace std;
class ModelListener;
string randomString();
string currentDate();
/**
 * The Model class defines the data model in the model-view-presenter paradigm.
 * The Model is a singular object used across all presenters. The currently active
 * presenter will have a pointer to the Model through deriving from ModelListener.
 *
 * The Model will typically contain UI state information that must be kept alive
 * through screen transitions. It also usually provides the interface to the rest
 * of the system (the backend). As such, the Model can receive events and data from
 * the backend and inform the current presenter of such events through the modelListener
 * pointer, which is automatically configured to point to the current presenter.
 * Conversely, the current presenter can trigger events in the backend through the Model.
 */
class item
{
  public:
    item() {}
    item(string setName, char setBox)
    {
        name = setName;
        boxname = setBox;
    }
    void setItem(string setName, char setBox)
    {
        name = setName;
        boxname = setBox;
    }
    string name;
    string time;
    char boxname;
};

class box
{
  public:
    box() {}
    box(char setName, int setPosition)
    {
        name = setName;
        position = setPosition;
    }
    char name;
    int position;
    // itemList all_item;
};

class Model
{
  public:
    Model();

    /**
     * Sets the modelListener to point to the currently active presenter. Called automatically
     * when switching screen.
     */
    void bind(ModelListener *listener)
    {
        modelListener = listener;
    }

    /**
     * This function will be called automatically every frame. Can be used to e.g. sample hardware
     * peripherals or read events from the surrounding system and inject events to the GUI through
     * the ModelListener interface.
     */
    void tick();
    box totalBox[7];
    item totalItem[35];
    int item_size;
    void addItemList(char box);

  protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener *modelListener;

    // itemListTotal totalItem;
};

#endif /* MODEL_HPP */
