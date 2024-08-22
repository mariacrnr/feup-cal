#ifndef INCLUDE_FILES_H
#define INCLUDE_FILES_H

#include <iostream>

using namespace std;

/**Checks if user input is an int
 *
 * @return
 */
int checkIntInput();

/**Clears input from the console
 *
 * @param message
 */
void clearInput(string message);

/**Reads User Input
 *
 * @param low input value lower bound
 * @param high input value higher bound
 * @param message message to display before the input is read
 * @param invalid message to display if the input is invalid
 * @return user's input
 */
int readInput(int low, int high, string message, string invalid);

#endif //INCLUDE_FILES_H
