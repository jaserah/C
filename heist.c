#include <stdio.h>
#include <stdlib.h>

/*this program asks the user for the max weight their backpack can carry,
the number of items that are in the jewelery store, and the value and
weight of each of the items. it then calculates what the most profitable
heist would be and how much money it would be worth, depending on what 
can fit in the backpack*/

typedef struct heist_info_struct {
	int value;
	int weight;
	int* arr;

} heist_info;

int heist(heist_info* stuff, int max_weight, int items, int curr);


/*this is the main function and within it, the user is asked for the 
max weight that the backpack can hold, the number of items in the store
and and value and weight of each of the items, it then calls the  heist
function to solve for the most valuable heist.*/
int main() {
	int max_weight = 0;
	int items = 0;
	int i = 0;
	heist_info* stuff = NULL;
	printf("Enter the maximum amount of weight that your bag can hold: ");
	scanf("%d", &max_weight);
	printf("Enter the number of items that are in the jewelry store: ");
	scanf("%d", &items);
	printf("Enter your items, one per line (value weight):\n");
	for (i = 0; i < items; i++) {
		scanf("%d %d", &stuff[i].value, &stuff[i].weight);
	}
	stuff.arr = (heist_info*)malloc(items * sizeof(heist_info));
	int profit_heist = heist(stuff, max_weight, items, 0);
	printf("They most profitable heist will net you $%d in total.", profit_heist);

	return 0;
}

/*this function checks first that the backpack can hold something, as well as 
if the jewelery store has items in it. if it does, it returns the value when 
sent through the same function again with a new weight of an object*/
int heist(heist_info* stuff, int max_weight, int items, int curr){
	int i = 0;
	int best_profit = 0;
	best_profit = curr;
	if (max_weight == 0) {
		return curr;
	}
	else if (items == 0) {
		return curr;
	}
	else {
		for (i = 0; i < items; i++) {
			if ((stuff[i].weight) < max_weight) {
				if (best_profit < heist(stuff + i + 1, items - i - 1, max_weight - ((stuff[i]).weight), curr + (stuff[i].value))) {
					best_profit = heist(stuff + i + 1, items - i - 1, max_weight - ((stuff[i]).weight), curr + (stuff[i].value));
				}
			}
		}
		return best_profit;
	}
}