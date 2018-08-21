
/*
    _                   ____         __ _
   / \  _   _ _ __ __ _/ ___|  ___  / _| |_
  / _ \| | | | '__/ _` \___ \ / _ \| |_| __|
 / ___ \ |_| | | | (_| |___) | (_) |  _| |_
/_/   \_\__,_|_|  \__,_|____/ \___/|_|  \__|

aRa Aurasoft 2008-2018 http://www.aurasoft-skyline.co.uk
© Copyright aRa Aurasoft & Skyline Game Engine

Hope this helps someone.
If used or adapted from, please give credit to where it came from.

Written by Jayce Young
*/

#include "stdafx.h"

class Item{
public:
	Item(){};
	~Item(){};	
	
	std::string name;
	int id;

	// Add your variables to your item class here
};

class ObjectPool{
public:
	ObjectPool(){init();};
	~ObjectPool(){};

	int maxCount;
	int numItems;
	Item * items[1000000];
	
	std::vector reusableItems;

	void init(){
		numItems = 0;
		maxCount = 1000000;
		reusableItems.clear();
	}

	Item* createItem()
	{
		int id = numItems;
			
		bool usingemptyslot = true;
			
		if (reusableItems.size() > 0){
			id = reusableItems[reusableItems.size()-1];
			reusableItems.pop_back();
			usingemptyslot = false;
		}

		items[id] = new Item();
		items[id]->id = id;
		std::stringstream ss; ss << items[id]->id;
		items[id]->name = "MyName" + ss.str();

		if (usingemptyslot)numItems++;

		return items[numItems];
	}

	void destroyItem(int id)
	{
		delete items[id];
		items[id] = NULL;

		reusableItems.push_back(id);
	}
	
	void destroyAllItems()
	{
		for (int i = 0; i < numItems; i++){
			if (items[i] != NULL){
				delete items[i];
				items[i] = NULL;
			}
		}

		numItems = 0;
	}

  Item* getItem(int id){ return items[id]; }
  void setItem(int id, Item *item){ items[id] = item; }

  int getNumItems(){ return numItems; }
};

ObjectPool objectPool;

function runExample();

