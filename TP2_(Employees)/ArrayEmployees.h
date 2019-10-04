#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee* Pointer to array of employees
* \param len int Array length
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector, int firstEmptyPosition);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);


/** \brief print the content of employees array
*
* \param list Employee* Pointer to array of employees
* \param length int Array length
* \return int
*
*/
int printEmployees(Employee* list, int length);


/** \brief Optional: Adds up to 10 prefabricated employees to the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param cant int Amount of employees to add
 * \return int Returns quantity of employees loaded
 *
 */
int hardcodeEmployees(Employee* list, int len, int cant);


/** \brief Shows custom message until a valid integer is entered
 *
 * \param errorMessage char*
 * \return int Returns the number required
 *
 */
int validInteger(char* errorMessage);


/** \brief Allows to change one employee's selected datum
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Returns (-1) if Error - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len);


/** \brief Checks if there is at least a single active employee in the array
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Returns (1) if there is at least one employee - (0) if not
 *
 */
int anyEmployee(Employee* list, int len);


/** \brief Asks for all the data necessary to register a new employee
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int
 * \return int Returns (-1) if Error - (0) if Ok
 *
 */
int registerEmployee(Employee* list, int len, int id);


/** \brief shows custom message until a valid float is entered
 *
 * \param errorMessage char*
 * \return float Returns the number required
 *
 */
float validFloat(char* errorMessage);


/** \brief Shows main menu
 *
 * \return char Returns pressed key
 *
 */
char menu();


/** \brief Shows reports menu and calculates salary-related info
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return void
 *
 */
void reportsMenu(Employee* list, int len);


/** \brief Prevents overflow by showing custom message when the entered string is too long
 *
 * \param stringRequired char*
 * \param size int String's maximum size
 * \param errorMessage char*
 * \return void
 *
 */
void validString(char* stringRequired, int size, char* errorMessage);


/** \brief Shows employee's information corresponding to the received index
 *
 * \param list Employee* Pointer to array of employees
 * \param index int
 * \return void
 *
 */
void printOneEmployee(Employee* list, int index);
