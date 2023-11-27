#include <iostream>
#include <cctype>

#include "randomizer.h"
#include "tarmacStages.h"
#include "gravelStages.h"
#include "snowStages.h"
#include "cars.h"

int main() {
    std::cout << R"(
    ######                                                                         
    #     #   ##   #      #      #   #  ####  # #    # ######   ##   #    #  ####  
    #     #  #  #  #      #       # #  #      # ##  ## #       #  #  ##   # #      
    ######  #    # #      #        #    ####  # # ## # #####  #    # # #  #  ####  
    #   #   ###### #      #        #        # # #    # #      ###### #  # #      # 
    #    #  #    # #      #        #   #    # # #    # #      #    # #   ## #    # 
    #     # #    # ###### ######   #    ####  # #    # #      #    # #    #  ####  
    )" << "\n";

    std::cout << R"(
    ######  ######  ######  
    #     # #     # #     # 
    #     # #     # #     # 
    ######  ######  ######  
    #   #   #     # #   #   
    #    #  #     # #    #  
    #     # ######  #     #                       
    )" << "\n";

    std::cout << "Welcome to RSF RBR Random Car & Stages Selector\n";
    std::cout << "Tarmac = 1 || Gravel = 2 || Snow = 3\n";
    char confirmation;

    do {                                                                               // Start stage selection
        int data;
        bool isValidSelection;
        do {
            std::cout << "\nWhat surface do you want to drive on? : \n";
            std::cout << "Select: ";
            std::cin >> data;
            
            isValidSelection = true;

            if (std::cin.fail()) {                                                      // If user input character instead of number
                std::cout << "\nPlease enter a valid number!\n";
                std::cin.clear();                                                       // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // Discard invalid input
                isValidSelection = false;
            }
            else {                                                                      // User input right selection
                switch (data) {
                case 1:                                                                 // If user input 1 (tarmac stage)
                    std::cout << "\nYou will driving: ";
                    genericRandomizer(carsData);
                    std::cout << "\nOn stage: \n";
                    genericRandomizer(tarmacStages);
                    isValidSelection = true;
                    break;
                case 2:                                                                 // if user input 2 (gravel stage)
                    std::cout << "\nYou will driving: ";
                    genericRandomizer(carsData);
                    std::cout << "\nOn stage: \n";
                    genericRandomizer(gravelStages);
                    isValidSelection = true;
                    break;
                case 3:                                                                 // if user input 3 (snow stage)
                    std::cout << "\nYou will driving: ";
                    genericRandomizer(carsData);
                    std::cout << "\nOn stage: \n";
                    genericRandomizer(snowStages);
                    isValidSelection = true;
                    break;
                default:
                    std::cout << "\nPlease input the right selection!\n";               // If user input wrong selection
                    isValidSelection = false;
                    break;
                }
            }
        } while (!isValidSelection);                                                    // Repeat until selection is right

        std::cout << "\nDo you want to repeat the randomizer? (Y/N): ";                 // Prompt if user want to do randomizer again
        std::cin >> confirmation;

        while (toupper(confirmation) != 'Y' && toupper(confirmation) != 'N') {          // If user input other than Y or N
            std::cout << "\nPlease enter 'Y' or 'N'!: ";
            std::cin >> confirmation;
        }
        if (confirmation == 'N' || confirmation == 'n') {                               // If user input N = exit the program
            std::cout << "Goodbye!\n";
            break;
        }
    } while (confirmation == 'Y' || confirmation == 'y');                               // Looping if user still want to use randomizer

}
