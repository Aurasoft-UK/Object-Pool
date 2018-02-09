
#include "ObjectPool.h"

function runExample()
{
  // Initialise the system with
  objectPool.createItem();

  // Create new item with
  Item *item = objectPool.createItem();

  // Destroy that item with:
  objectPool.destroyItem(item->id);

  // Destroy all the items with
  objectPool.destroyAllItems();

  // Get the number of items found with
  int numberOfItems = objectPool.getNumItems();

  // Retrieve an item by id
  Item *item = objectPool.getItem(id);
}
