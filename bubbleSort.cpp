#include <iostream>
#include <cstring> // required for string manipulation
#include <iomanip> // required for tabular output
#include <bits/stdc++.h> 

using namespace std; 

int main()
{
    // Provided arrays and constants
    const int NUM_PATIENTS = 10; // 10 patients will be included, this value cannot be modified
    const int MAX_NAME_LENGTH = 10; // no names longer than 10 characters, this value cannot be modified
    const int ID_LENGTH = 8;
    unsigned int age[NUM_PATIENTS] = {50, 22, 22, 89, 15, 16, 22, 32, 15, 66}; // 1D int array age of each patient
    char id[NUM_PATIENTS][ID_LENGTH + 1] = {"10854893", "10983922", "98333894", "57290888", "14899822", "79278282", "44293822", "62911023", "28399020", "33212322"}; // 1D int array identification #
    char firstName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"allison", "michael", "michael", "johnny", "sabrina", "helen", "ignacio", "melissa", "hassan", "melody"}; // 2D char array: first names for patients
    char lastName[NUM_PATIENTS][MAX_NAME_LENGTH] = {"pratt","xiao", "barkley", "wu", "sappal", "mcdonald", "garza", "tran", "nahas", "baker"}; // 2D char array: last names for patients
    char sex[NUM_PATIENTS] = {'f','m','m','m','f','f','m','f','m','f'}; // 1D char array sex of the patient


    // PART 1: Select a primary sorting category from user input
    char categoryUser[6]; // 1D char array of the user's input for which category they select
    int x = 0; // declares integer for the while loop 
    char category [5][6] = {"Age", "ID", "Sex", "Last", "First"}; // 2D char array with the categories and the number of letters in each 

    cout << "Please enter the sorting category (Age, ID, First, Last, Sex): "; 
    cin >> categoryUser; 

    while (x==0){ // while loop which takes in the user's input and finds the respective category selected 
        if (strcasecmp(categoryUser, category[0])==0){ // if the string of the category the user selects and the string of the age category are equal 
            cout << "Case 1, sorting by Age."; 
            x ++; // adds 1 to the integer, allowing the program to exit the loop 
            break; 
        }
        else if (strcasecmp(categoryUser, category[1])==0){ // if the string of the category the user selects and the string of the ID category are equal 
            cout << "Case 2, sorting by ID."; 
            x ++; 
            break; 
        }
        else if (strcasecmp(categoryUser, category[2])==0){ // if the string of the category the user selects and the string of the sex category are equal 
            cout << "Case 3, sorting by Sex."; 
            x++; 
            break; 
        }
        else if (strcasecmp(categoryUser, category[3])==0){ // if the string of the category the user selects and the string of the Last Name category are equal 
            cout << "Case 4, sorting by Last Name."; 
            x++; 
            break; 
        }
        else if (strcasecmp(categoryUser, category[4])==0){ // if the string of the category the user selects and the string of the First Name category are equal 
            cout << "Case 5, sorting by First Name.";
            x++; 
            break; 
        }
        else { // if the user inputs a category that is invalid 
            cout << "Unexpected Input. Please input either Age, ID, First, Last, or Sex: "; 
            cin >> categoryUser; 
        }
    } // while loop 

    // PART 3/4: Sorting patient records
    for (int f = 0; f< NUM_PATIENTS-1; f++){ // for loop to sort through the pateients records depending on the category selected 
        for (int r = 0; r< NUM_PATIENTS-1-f; r++){ // second for loop for the sorting 

    if (strcasecmp(categoryUser, category[0])==0){ // if the user selects the age category 
        for (int f=0; f<NUM_PATIENTS-1; f++){
            for (int r=0; r < NUM_PATIENTS-1-f; r++){ // for loop that goes through each age in the array 
                if (age[r] > age[r+1]){ // if statement which states that if the age is bigger than the age after it, the patients swap 
                    swap(age[r], age[r+1]); 
                    swap(id[r], id[r+1]);
                    swap(firstName[r],firstName[r+1]); 
                    swap(lastName[r], lastName[r+1]); 
                    swap (sex[r], sex[r+1]); 
            }
            }
        } // for loop for the age category 
          if (age[r] == age[r+1]){ // if statement for if the patients are the same age 
             if (strcasecmp(firstName[r], firstName[r+1])>0){ // if statement checking the patient's first name, and using this to sort same aged patients 
                swap(age[r], age[r+1]); 
                swap(id[r], id[r+1]);
                swap(firstName[r],firstName[r+1]); 
                swap(lastName[r], lastName[r+1]); 
                swap (sex[r], sex[r+1]); 
            }
        } // if statement for two same-aged patients 
    } // if statement for age category 

    else if (strcasecmp(categoryUser, category[1])==0){ // if the user selects the id category 
        for (int f =0; f<NUM_PATIENTS-1; f++){
            for (int r=0; r< NUM_PATIENTS-1-f; r++){
                if (strcasecmp(id[r], id[r+1]) > 0){ // if statement checking the values of the id, and sorting them from least to greatest 
                    swap(age[r], age[r+1]); // swaps all the patients information 
                    swap(id[r], id[r+1]);
                    swap(firstName[r],firstName[r+1]); 
                    swap(lastName[r], lastName[r+1]); 
                    swap (sex[r], sex[r+1]); 
                }
            }
        }
    } // else if for the id category 

    else if (strcasecmp(categoryUser, category[2])==0){ // if the user selects the sex category 
        for (int f =0; f<NUM_PATIENTS-1; f++){ // for loop to sort through the patients 
            for (int r=0; r< NUM_PATIENTS-1-f; r++){
                if (sex[r] > sex[r+1]){ 
                    swap(age[r], age[r+1]); 
                    swap(id[r], id[r+1]);
                    swap(firstName[r],firstName[r+1]); 
                    swap(lastName[r], lastName[r+1]); 
                    swap (sex[r], sex[r+1]); 
                }
            }
        } // regular if statement for sex category 
         if (sex[r] ==sex[r+1]){ // if statement for if the patients have the same sex 
             if (strcasecmp(firstName[r], firstName[r+1])>0){ // if the patients are the same sex, the first names are used to sort 
                swap(age[r], age[r+1]); // swaps all the patient information 
                swap(id[r], id[r+1]);
                swap(firstName[r],firstName[r+1]); 
                swap(lastName[r], lastName[r+1]); 
                swap (sex[r], sex[r+1]); 
            }
        } // if statement for if the sexes are the same 
    } // else if for sex category 

    else if (strcasecmp(categoryUser, category[3])==0){ // if the user selects the last name category 
        for (int f =0; f<NUM_PATIENTS-1; f++){
            for (int r=0; r< NUM_PATIENTS-1-f; r++){
                if (strcasecmp(lastName[r], lastName[r+1]) > 0){ // checks the last names and the letters alphabetically 
                    swap(age[r], age[r+1]); 
                    swap(id[r], id[r+1]);
                    swap(firstName[r],firstName[r+1]); 
                    swap(lastName[r], lastName[r+1]); 
                    swap (sex[r], sex[r+1]); 
                }
            }
        }
    } // else if for the last name category 
    
    else if (strcasecmp(categoryUser, category[4])==0){ // if the user selects the first name category 
        for (int f =0; f<NUM_PATIENTS-1; f++){
            for (int r=0; r< NUM_PATIENTS-1-f; r++){
                if (strcasecmp(firstName[r], firstName[r+1])>0){ // checks the patient's first name alphabetically and sorts them 
                    swap(age[r], age[r+1]); 
                    swap(id[r], id[r+1]);
                    swap(firstName[r],firstName[r+1]); 
                    swap(lastName[r], lastName[r+1]); 
                    swap (sex[r], sex[r+1]); 
                }
            }
        }
    } // else if for the first name category 
    }// second large for loop 
    } // large for loop 

    // PART 2: Outputting patient records to terminal in tabular 
    cout << " " << endl; 
    cout << setw(11) << "Age:"; // displays the "Age" header 
    for (int i =0; i <10; i++){ // for loop displaying the ages of the patients
        cout << setw(11) << age[i]; // displays the ages from the age array using the set width of 11, as there are 10 patients and a header
    }
    cout << " " << endl; // adds an extra line for spacing 

    cout << setw(11) << "ID:"; // displays the "ID" header 
    for (int i =0; i <10; i++){ // for loop displaying the patient's ids 
        cout << setw(11) << id[i]; 
    }
    cout << " " << endl; // adds an extra line for spacing

    cout << setw(11) << "First Name:"; // displays the "First Name" header 
    for (int i =0; i <10; i++){ // for loop displaying the patient's first names 
        cout << setw(11) << firstName[i]; 
    }
    cout << " " << endl; // adds an extra line for spacing

    cout << setw(11) << "Last Name:"; // displays the "Last Name" header 
    for (int i =0; i <10; i++){ // for loop displaying the patient's last names  
        cout << setw(11) << lastName[i]; 
    }
    cout << " " << endl; // adds an extra line for spacing

    cout << setw(11) << "Sex:"; // displays the "Sex" header 
    for (int i =0; i <10; i++){ // for loop displaying the patient's sex
        cout << setw(11) << sex[i]; 
    }
    cout << " " << endl; // adds an extra line for spacing

    



    return 0;
}