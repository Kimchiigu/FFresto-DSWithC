#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int menuOption;

void mainMenu(){
	printf("   ___  ___              _            _       _           _       _     _             _\n");
	printf("  / __\\/ __\\ __ ___  ___| |_ ___     /_\\   __| |_ __ ___ (_)_ __ (_)___| |_ _ __ __ _| |_ ___  _ __\n");
	printf(" / _\\ / _\\| '__/ _ \\/ __| __/ _ \\   //_\\\\ / _` | '_ ` _ \\| | '_  | / __| __| '__/ _` | __/ _ \\| '__|\n");
	printf("/ /  / /  | | |  __/\\__ \\ || (_) | /  _  \\ (_| | | | | | | | | | | \\__ \\ |_| | | (_| | || (_) | |\n");
	printf("\\/   \\/   |_|  \\___||___/\\__\\___/  \\_/ \\_/\\__,_|_| |_| |_|_|_| |_|_|___/\\__|_|  \\__,_|\\__\\___/|_|\n");
	printf("===================================================================================================\n");
	printf("1. Insert New Dish\n");
	printf("2. Update Dish\n");
	printf("3. Delete Dish\n");
	printf("4. Add Customer\n");
	printf("5. Customer List\n");
	printf("6. Order\n");
	printf("7. Payment\n");
	printf("8. Exit\n");
	printf(">> ");
}

void menuExit(){
    printf("                            .:^:.. ..^^:..\n");
    printf("                          ...   ...:.     .......    .\n");
    printf("                            .   . ^.   :..:~~77~~~::..::.. ..\n");
    printf("                          ::::..~..:..:~7~.: :^ ~^:~..:....:^~^:^~^\n");
    printf("                        ..      .. .^!777^~~!?~^~7:^::.  .5BGB##&#7.\n");
    printf("                             .:~!!. .:~^.77?P57P7!^::~::?5B&&#GGG5.\n");
    printf("                          .:^~~^^: YJJGBGP5YY7J7!^^^?7YG##P7^7#&B~:\n");
    printf("                        .^~~:  ~J55PJ~:.       ..~JPBBBY^. .:.JG!:!!^..\n");
    printf("                     ..^7~  .::???.         .~!JG&&#J:       .7!:.^77?!^..\n");
    printf("                   .:~7!:. ^Y^.  ..      .!JPB&&#Y:          .  :7!: ~G5?!:.\n");
    printf("                 .:~7?7..~!!       .:..^?YP&&&G7         .        ~J: .BP7J!:.\n");
    printf("               .:^777~^::7^          :JB&&#BG^ .                   .J! !YYYJ?^~!^.\n");
    printf("              .:!JJJJ: :7G.         ?#&&&&B~                         ?5..^!~~!!:.\n");
    printf("             .:!YYY5~ .J&Y      . .5BBBBBG^                           YP  :?J!~!^.\n");
    printf("             .:!J?YJ^..P&!        P&&&&&#!             ..              #7 .^55?^~:.\n");
    printf("              .^7!??^..P#? .  .   ~#&&&&&J:..   ...  .   ..  ...     . 5#..:J57~!:.\n");
    printf("              .:!J~~^.?G#5      .:.^JGBBBP5Y!^75GBGP5PJYPGPP5YYJ?!^    !&:.:??~?~:.\n");
    printf("               .^?5^:.JPBP!       .:::.. .!YYY&&&###&&&&YG##&&&&#B5:   !&:.^~!5J~.\n");
    printf("                .^??:.^^?77..                 ^:.  ..P&G:^&&&&&&&&7    PG ~7:JP7:.\n");
    printf("                .:^7? .~~J?7!                 .      7#^ P&&&&&&G^    :&^ 7?5?!:.\n");
    printf("                  .^J5.:!JPBBY            .:.       ^5^ 7###&#P^      G7..7G5!:.  \n");
    printf("                   .^?5~^~:~PBP~.?!~: ^^7~^!^     .7: ~#&&#5~        ~~:.:PY~:.\n");
    printf("                    .^!5J7..~!B&PJY?J^J?YGY?7!:..^^:?#@&G7.        .~.::^Y!^.\n");
    printf("                     .:^??J!77JY57 .: :?#BYGG!7~:7G&#5~.           ... ^?Y57:.\n");
    printf("                       .:~?JY~..... :.^!J^^!7~7PGPJ~.          ... ^?Y57:.\n");
    printf("                          :~75P~:.  ^^!!^~!JYJ57:..^^....:^!:  ...5GP7^.\n");
    printf("                          ::.:~^7.JY^?77Y5Y7^..::~??5J???5J: :?Y!J5!:.  \n");
    printf("                           .  .^.7G&###B5!^:.:.::......~?J?YB#BY7^:.\n");
    printf("                              .^^YJ5###BG5J7!7JYPPGYJ??YPPPY?7~:.\n");
    printf("                              ..:^~^^........^~!~!!!!~^^::...\n\n\n");
    printf("\t\t\to---------------------------------------------o\n");
    printf("\t\t\t|      Breaking and Overcoming Challenges     |\n");
    printf("\t\t\t|    Through Courage Hardwork and Persistence |\n");
    printf("\t\t\t|           ~~ Bluejackets 23-1 ~~            |\n");
    printf("\t\t\to---------------------------------------------o\n\n\n");
}

struct Node{
    char dishName[1000];
    int dishPrice;
    int dishStock;
    struct Node *next;
} *head = NULL, *tail = NULL;

struct Node *createNode(char name[], int price, int stock) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->dishName, name);
    newNode->dishPrice = price;
    newNode->dishStock = stock;
    newNode->next = NULL;
    return newNode;
}

struct Order {
    char dishName[1000];
    int quantity;
    int total;
    struct Order* next;
};

struct Customer {
    char name[100];
    struct Order* orderList;
    struct Customer* next;
};

struct Customer* customerList = NULL;
struct Customer* headCustomer = NULL;

void pushHead(char name[], int price, int stock) {
    struct Node *newNode = createNode(name, price, stock);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void pushSorted(char name[], int price, int stock) {
    struct Node *newNode = createNode(name, price, stock);

    // If the list is empty or the new element should be the first, update the head.
    if (head == NULL || strcmp(name, head->dishName) <= 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node *current = head;
        struct Node *prev = NULL;

        // Find the correct position to insert the new element.
        while (current != NULL && strcmp(name, current->dishName) > 0) {
            prev = current;
            current = current->next;
        }

        // Update the previous element to point to the new element.
        prev->next = newNode;
        newNode->next = current;

        // Update the tail if the new element is the last.
        if (current == NULL) {
            tail = newNode;
        }
    }
}

void readDish() {
    FILE* f = fopen("dish.txt", "r");
	char name[1000];
	int price, stock;
    if (f == NULL) {
        printf("Dish List has not been created yet...\n");
    } else {
        while (fscanf(f, "%[^#]#%d#%d\n", name, &price, &stock) != EOF) {
            pushSorted(name, price, stock);
        }
        fclose(f);
    }
}

void insertNewDish() {
    char name[1000];
    int price, stock;
    char dishID[7];

    while (1) {
        printf("Input Dish Name [Must have a minimum of 2 words and every word starts with a capital], 0 to cancel: ");
        scanf(" %[^\n]s", name); 

        // Check if the user wants to cancel
        if (strcmp(name, "0") == 0) {
            printf("Cancelled.\n");
            return;
        }

        // Validate dish name
        int wordCount = 0;
        int startOfWord = 1; // To check if the first character of the name is uppercase
        for (int i = 0; name[i] != '\0'; i++) {
            if (name[i] == ' ' && (name[i + 1] >= 'A' && name[i + 1] <= 'Z')) {
                wordCount++;
            }
            if (i == 0 && !(name[i] >= 'A' && name[i] <= 'Z')) {
                startOfWord = 0;
            }
        }
        if (wordCount < 1 || startOfWord == 0) {

        } else {
            break; // Valid input
        }
    }

    // Input and validate price
    while (1) {
        printf("Input Dish Price [Must be between 10000 - 100000] (inclusive): ");
        if (scanf("%d", &price) != 1 || price < 10000 || price > 100000) {
            while (getchar() != '\n') continue;
        } else {
            break; // Valid input
        }
    }

    // Input and validate stock
    while (1) {
        printf("Input Dish Stock [Must be between 1 - 999] (inclusive): ");
        if (scanf("%d", &stock) != 1 || stock < 1 || stock > 999) {
            while (getchar() != '\n') continue;
        } else {
            break; // Valid input
        }
    }

    // Generate Dish ID
	dishID[0] = name[0]; // First character of the first word
	dishID[1] = name[name[0] == ' ' ? 1 : (int)(strchr(name, ' ') - name + 1)]; // First character of the second word
	
	int random_number = rand() % 10; 
	dishID[2] = '0' + random_number; 
	
	random_number = rand() % 10; 
	dishID[3] = '0' + random_number; 
	
	dishID[4] = '0' + rand() % 10; 
	dishID[5] = '\0';
	
	pushSorted(name, price, stock);
    
    FILE* f = fopen("dish.txt", "a");
    if (f == NULL) {
        printf("Failed to open data file for appending.\n");
        return;
    } else {
        fprintf(f, "%s#%d#%d\n", name, price, stock);
        printf("Dish inserted successfully!\n");
        printf("Press Enter to continue...");
    }
    fclose(f);
}

void updateDish() {
    // Load the data from "dish.txt" into a linked list
    readDish();

    if (head == NULL) {
        printf("Dish is empty!\n\n");
        printf("Press Enter to go back...");

        while (getchar() != '\n') {
            // Enter
        }
        system("cls");
    } else {
        char dishID[7];
        int dishCount = 0;
        struct Node *current = head;

        printf("==================================================================\n");
        printf("| Dish ID | Dish Name              | Dish Price   | Dish Stock   |\n");
        printf("==================================================================\n");

        // Display and update dishes
        while (current != NULL) {
            snprintf(dishID, sizeof(dishID), "00%d", dishCount + 1);
            printf("| %s     | %-22s | %-12d | %-12d |\n", dishID, current->dishName, current->dishPrice, current->dishStock);
            printf("==================================================================\n");
            dishCount++;

            current = current->next;
        }

        if (dishCount == 0) {
            printf("No dishes found.\n");
        } else {
            char inputID[4];
            printf("\nEnter Dish ID to update (e.g., 001), 0 to cancel: ");
            scanf("%3s", inputID);

            if (strcmp(inputID, "0") != 0) {
                int selectedID = atoi(inputID);
                if (selectedID > 0 && selectedID <= dishCount) {
                    // Dish ID is valid
                    struct Node *current = head;
                    int currentDish = 0;

                    // Find the selected dish in the linked list
                    while (current != NULL && currentDish < selectedID - 1) {
                        current = current->next;
                        currentDish++;
                    }

                    if (current != NULL) {
                        int newStock;
                        printf("Enter new stock for %s (%s): ", current->dishName, inputID);
                        scanf("%d", &newStock);

                        // Update the stock in both the linked list and temporary data structure
                        current->dishStock = newStock;
                        system("cls");

                        printf("==================================================================\n");
                        printf("| Dish ID | Dish Name              | Dish Price   | Dish Stock   |\n");
                        printf("==================================================================\n");

                        // Display and update the dishes
                        current = head;
                        currentDish = 0;

                        while (current != NULL) {
                            snprintf(dishID, sizeof(dishID), "00%d", currentDish + 1);
                            printf("| %s     | %-22s | %-12d | %-12d |\n", dishID, current->dishName, current->dishPrice, current->dishStock);
                            printf("==================================================================\n");
                            currentDish++;
                            current = current->next;
                        }

                        // Save the updated data back to "dish.txt"
                        FILE *f = fopen("dish.txt", "w");
                        current = head;

                        while (current != NULL) {
                            fprintf(f, "%s#%d#%d\n", current->dishName, current->dishPrice, current->dishStock);
                            current = current->next;
                        }
                        fclose(f);
                        printf("Dish updated successfully!\n");
                    }
                } else {
                    printf("Invalid Dish ID.\n");
                }
            }
        }

        printf("\nPress Enter to go back...");
        while (getchar() != '\n') {
            // Enter
        }
        getchar();
        system("cls");
    }

    // Free the memory used by the linked list
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    head = tail = NULL;
}

void clearDishList() {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    head = tail = NULL;
}

void deleteDish() {
    // Load the data from "dish.txt" into a linked list
    readDish();

    if (head == NULL) {
        printf("Dish is empty!\n\n");
        printf("Press Enter to go back...");

        while (getchar() != '\n') {
            
        }
        system("cls");
    } else {
        char dishID[7];
        int dishCount = 0;
        struct Node *current = head;

        printf("==================================================================\n");
        printf("| Dish ID | Dish Name              | Dish Price   | Dish Stock   |\n");
        printf("==================================================================\n");

        // Display and delete dishes
        while (current != NULL) {
            snprintf(dishID, sizeof(dishID), "00%d", dishCount + 1);
            printf("| %s     | %-22s | %-12d | %-12d |\n", dishID, current->dishName, current->dishPrice, current->dishStock);
            printf("==================================================================\n");
            dishCount++;

            current = current->next;
        }

        if (dishCount == 0) {
            printf("No dishes found.\n");
        } else {
            char inputID[4];
            printf("\nEnter Dish ID to delete (e.g., 001), 0 to cancel: ");
            scanf("%3s", inputID);

            if (strcmp(inputID, "0") != 0) {
                int selectedID = atoi(inputID);
                if (selectedID > 0 && selectedID <= dishCount) {
                    // Dish ID is valid
                    struct Node *current = head;
                    int currentDish = 0;
                    struct Node *prev = NULL;

                    // Find the selected dish in the linked list
                    while (current != NULL && currentDish < selectedID - 1) {
                        prev = current;
                        current = current->next;
                        currentDish++;
                    }

                    if (current != NULL) {
                        if (prev == NULL) {
                            head = current->next;
                        } else {
                            prev->next = current->next;
                        }

                        free(current);
                        system("cls");

                        printf("==================================================================\n");
                        printf("| Dish ID | Dish Name              | Dish Price   | Dish Stock   |\n");
                        printf("==================================================================\n");

                        // Display remaining dishes
                        current = head;
                        currentDish = 0;

                        while (current != NULL) {
                            snprintf(dishID, sizeof(dishID), "00%d", currentDish + 1);
                            printf("| %s     | %-22s | %-12d | %-12d |\n", dishID, current->dishName, current->dishPrice, current->dishStock);
                            printf("==================================================================\n");
                            currentDish++;
                            current = current->next;
                        }

                        // Save the updated data back to "dish.txt"
                        FILE *f = fopen("dish.txt", "w");
                        current = head;

                        while (current != NULL) {
                            fprintf(f, "%s#%d#%d\n", current->dishName, current->dishPrice, current->dishStock);
                            current = current->next;
                        }
                        fclose(f);
                        printf("Dish deleted successfully!\n");

                        clearDishList();
                    }
                } else {
                    printf("Invalid Dish ID.\n");
                }
            }
        }

        printf("\nPress Enter to go back...");
        while (getchar() != '\n') {
            // Enter
        }
        getchar();
        system("cls");
    }
}

void addCustomer() {
int valid = 0;
char name[100];

	while (!valid) {
	    printf("Insert customer name [Only contains Alphabet and Space], 0 to cancel: ");
	    scanf(" %[^\n]s", name);
	
	    if (strcmp(name, "0") == 0) {
	        printf("Cancelled.\n");
	        return;
	    }
	
	    valid = 1;
	    int wordCount = 0;
	    int isWordStart = 1;
	
	    for (int i = 0; name[i] != '\0'; i++) {
	        if (isalpha(name[i])) {
	            if (isWordStart) {
	                if (islower(name[i])) {
	                    valid = 0; 
	                    break;
	                }
	                isWordStart = 0;
	            }
	        } else if (name[i] == ' ') {
	            isWordStart = 1; 
	            wordCount++;
	        } else {
	            valid = 0; 
	            break;
	        }
	    }
	
	    if (!isalpha(name[strlen(name) - 1]) && name[strlen(name) - 1] != ' ') {
	        valid = 0;
	    }
	
	    if (wordCount < 1) {
	        valid = 0; 
	    }
	
	    if (!valid) {
	        printf("Invalid customer name. Please enter a name with only alphabets and spaces.\n");
	    }
	}

    if (valid) {
        struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
        strcpy(newCustomer->name, name);
        newCustomer->next = NULL;

        if (headCustomer == NULL) {
            headCustomer = newCustomer;
        } else {
            struct Customer* current = headCustomer;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newCustomer;
        }

        printf("Customer inserted successfully!\n");
    } else {
        printf("Invalid customer name. Please enter a name with only alphabets and spaces.\n");
    }
    printf("Press Enter to continue...");
    while (getchar() != '\n') {

    }
    getchar(); 
}

void viewCustomer() {
    if (headCustomer == NULL) {
        printf("FFresto doesn't have any customer!\n");
        printf("Press Enter to continue...");
    } else {
        printf("=============================\n");
        printf("|       Customer List       |\n");
        printf("=============================\n");

        struct Customer* current = headCustomer;

        while (current != NULL) {
            printf("| %-25s |\n", current->name);
            printf("=============================\n");
            current = current->next;
        }

        printf("Press Enter to continue...");
    }

    while (getchar() != '\n') {
        // Clear the input buffer
    }
    getchar(); // Wait for Enter key press
}

void orderDish() {
    readDish();
    if (head == NULL || headCustomer == NULL) {
        // No dishes or customers available
        if (head == NULL) {
            printf("Dish is Empty!\n");
        }
        if (headCustomer == NULL) {
            printf("FFresto doesn't have any customer!\n");
        }
        printf("Press Enter to continue...\n");
        while (getchar() != '\n') {

        }
        getchar(); 
    } else {
        // Display available dishes
        printf("Available Dishes:\n");
        struct Node* currentDish = head;
        int dishCount = 0;

        while (currentDish != NULL) {
            printf("[%d] %s - Price: %d - Stock: %d\n", dishCount + 1, currentDish->dishName, currentDish->dishPrice, currentDish->dishStock);
            currentDish = currentDish->next;
            dishCount++;
        }

        // Ask the user to input a customer name
        char customerName[100];
        int foundCustomer = 0;
        while (!foundCustomer) {
            printf("Input customer name, 0 to cancel: ");
            scanf(" %[^\n]s", customerName);

            if (strcmp(customerName, "0") == 0) {
                printf("Cancelled.\n");
                break;
            }

            // Check if the customer exists
            struct Customer* currentCustomer = headCustomer;
            while (currentCustomer != NULL) {
                if (strcmp(currentCustomer->name, customerName) == 0) {
                    foundCustomer = 1;
                    break;
                }
                currentCustomer = currentCustomer->next;
            }

            if (!foundCustomer) {
                printf("Customer not found!\n");
            }
        }

        if (foundCustomer) {
            int orderCount = 0;
            int order[100][2]; // Order array to store dish ID and quantity

            while (1) {
                printf("Insert the amount of dish [more than 0]: ");
                int quantity;
                scanf("%d", &quantity);

                if (quantity <= 0) {
                    printf("Quantity must be more than 0!\n");
                } else if (quantity > dishCount) {
                    printf("FFresto only has %d types of dish!\n", dishCount);
                } else {
                    for (int i = 0; i < quantity; i++) {
                        // Ask the user to input the dish they want to order
                        int selectedDish;
                        printf("[%d] Enter your dishes [dish name] - [quantity]x: ", i + 1);
                        char inputDish[100];
                        scanf(" %[^\n]s", inputDish);

                        char dishName[100];
                        int selectedQuantity;

                        if (sscanf(inputDish, "%99[^-] - %dx", dishName, &selectedQuantity) == 2) {
                            // Validate the dish name and quantity
                            currentDish = head;
                            int dishFound = 0;

                            while (currentDish != NULL) {
                                if (strcmp(currentDish->dishName, dishName) == 0) {
                                    dishFound = 1;

                                    if (selectedQuantity <= 0) {
                                        printf("Quantity must be more than 0!\n");
                                    } else if (selectedQuantity > currentDish->dishStock) {
                                        printf("Dish stock doesn't have enough for the order!\n");
                                    } else {
                                        // Add the order to the order array
                                        order[orderCount][0] = dishCount;
                                        order[orderCount][1] = selectedQuantity;
                                        orderCount++;
                                        break;
                                    }
                                }
                                currentDish = currentDish->next;
                            }

                            if (!dishFound) {
                                printf("Dish not found!\n");
                            }
                        } else {
                            printf("Invalid input format. Please enter again.\n");
                        }
                    }

                    // Ask the user if they want to add more orders
                    char addMoreOrders;
                    printf("Do you want to add more orders (Y/N)? ");
                    scanf(" %c", &addMoreOrders);

                    if (addMoreOrders == 'N' || addMoreOrders == 'n') {
                        printf("Order success!\n");

                        for (int i = 0; i < orderCount; i++) {
                            int dishID = order[i][0];
                            int quantity = order[i][1];
                            // Update the dish stock
                            // Write the updated Dish single linked list to Dish.txt
                        }

                        printf("Press Enter to continue...");
                        while (getchar() != '\n') {
                        	
                        }
                        getchar(); 
                        break;
                    }
                }
            }
        }
        system("cls");
    }
}

void addOrder(char customerName[], char dishName[], int quantity, int price) {
    struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));
    strcpy(newOrder->dishName, dishName);
    newOrder->quantity = quantity;
    newOrder->total = quantity * price;
    newOrder->next = NULL;

    struct Customer* currentCustomer = customerList;
    while (currentCustomer != NULL) {
        if (strcmp(currentCustomer->name, customerName) == 0) {
            if (currentCustomer->orderList == NULL) {
                currentCustomer->orderList = newOrder;
            } else {
                struct Order* currentOrder = currentCustomer->orderList;
                while (currentOrder->next != NULL) {
                    currentOrder = currentOrder->next;
                }
                currentOrder->next = newOrder;
            }
            return;
        }
        currentCustomer = currentCustomer->next;
    }
}

void handlePayment() {
    if (customerList == NULL) {
        printf("FFresto doesn't have any customer!\n");
        printf("Press Enter to continue...");
        while (getchar() != '\n') {
                          
        }
        getchar(); 
    } else {
        char customerName[100];
        printf("Input customer name: ");
        scanf("%s", customerName);

        struct Customer* currentCustomer = customerList;
        struct Customer* previousCustomer = NULL;

        while (currentCustomer != NULL) {
            if (strcmp(currentCustomer->name, customerName) == 0) {
                // Customer found
                printf("Order Details:\n");
                struct Order* currentOrder = currentCustomer->orderList;
                int grandTotal = 0;

                while (currentOrder != NULL) {
                    printf("Dish Name: %s\n", currentOrder->dishName);
                    printf("Qty: %d\n", currentOrder->quantity);
                    printf("Price: %d\n", currentOrder->total);
                    grandTotal += currentOrder->total;

                    struct Order* temp = currentOrder;
                    currentOrder = currentOrder->next;
                    free(temp);
                }

                printf("Total price: %d\n", grandTotal);

				// Delete customer
                if (previousCustomer == NULL) {
                    customerList = currentCustomer->next;
                } else {
                    previousCustomer->next = currentCustomer->next;
                }

                free(currentCustomer);

                printf("Payment success for %s.\n", customerName);
                return;
            }

            previousCustomer = currentCustomer;
            currentCustomer = currentCustomer->next;
        }
		
        printf("Customer '%s' not found!\n", customerName); 
    }
}

int main() {
    srand(time(NULL));
    int run = 1; 

    while (run) {
        mainMenu();
        scanf("%d", &menuOption);
        system("cls");

        switch (menuOption) {
            case 1: {
                insertNewDish();
                system("cls");
                break;
            }
            case 2:{
            	updateDish();
				break;
			}
			case 3:{
				deleteDish();
				break;
			}
			case 4:{
				addCustomer();
				system("cls");
				break;
			}
			case 5:{
				viewCustomer();
				system("cls");
				break;
			}
			case 6:{
				orderDish();
				system("cls");
				break;
			}
			case 7:{
				handlePayment();
				system("cls");
				break;
			}
            case 8: {
                system("cls");
				menuExit();
				run = 0; 
                break;
            }
        }
    }
    return 0;
}
