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

}Employee;
/** \brief menu: Menu principal del proyecto
 * \param op: almacena el digito ingresado
 * \return retorno el operador ingresado
 *
 */

int menu();
/** \brief initEmploy: Se ejecuta una sola vez al comienzo del programa para inicializar los espacios vacios
 *
 * \param lista: estructura de Employee que recorreremos e inicializaremos en 1
 * \param len: el tamaño de la estructura
 */

void initEmploy(Employee* lista, int len);
/** \brief isAdigit : verifica que el sector esté entre el sector 1,2 o 3
 *
 * \param pers: estructura de employee que verificaremos
 * \param len: el tamaño de la estructura
 * \param flag: bandera que indica si es valido
 * \return (1)si es erroneo o (0)si es un sector valido
 *
 */
int isAdigit (Employee pers,int tam);

/** \brief initEmployees:Busca el primer indice libre en el array
 *
 * \param lista: estructura de employee que recorreremos buscando un espacio libre
 * \param tam : tamaño de la estructura
 * \param lugar: almacena el primer indice libre que encontremos
 * \return devuelve un indice del array
 *
 */

int initEmployees(Employee* lista, int len);
/** \brief printEmployees :imprime el array de empleados de manera encolumnada
 *
 * \param emp: estructura de employee
 * \param len: tamaño de empleados
 * \return int
 */

int printEmployees(Employee emp[],int len);
/** \brief alta: Realiza el alta de los empleados
 *
 * \param pers:array estructura employee
 * \param len:tamaño de la estructura
 * \param legajo: numero de ID
 */

void alta(Employee pers[],int len,int legajo);
/** \brief addEmployees: Recibe los datos obtenidos por alta y los almacena en la estructura
 *
 * \param lista:array estructura employee
 * \param len: tamaño de la estructura
 * \param lugar: bandera que indica si hay espacio para guardar o no los datos
 * \param carga: informa si se cargo correctamente el dato
 * \return (0) si se cargo correctamnte o (-1) si fallo en la carga
 */

int addEmployees(Employee* lista, int len);
/** \brief removeEmployee: elimina a un empleado ingresando su id
 *
 * \param lista:array estructura Employee
 * \param len: tamaño de estructura
 * \param id: es el id recibido
 * \return devuelve un valor de (0)si se hizo la baja o (-1)si se cancelo o hubo un error
 *
 */

int removeEmployee(Employee* lista, int len, int id);
/** \brief findEmployeeById : busca un empleado por su ID
 *
 * \param lista:array estructura de Employee
 * \param len:  tamaño de estructura
 * \param id: id recibido
 * \return (-1)si no encontro el empleado o un indice de el array
 *
 */

int findEmployeeById(Employee* lista,int len,int id);
/** \brief baja: ingreso el id de un empleado y realizo la baja del mismo
 *
 * \param per:array estructura Employee
 * \param len:tamaño de estructura
 * \param int baja: actua como verificador informando si se encontro o no el empleado
 */

void baja(Employee per[],int len);
/** \brief sortEmployeesByIdSector: Ordena el array por sector de manera ascendente o descendente
 *
 * \param lista:array estructura de Employee
 * \param len:  tamaño de estructura
 * \param orden: recibe 1 o 0 para realizar el orden ascendente o descendente
 * \return (0)si no hubo error o (-1)si falla
 *
 */

int sortEmployeesbySector(Employee lista[],int len,int order);
/** \brief sortEmployeesByIdName: Ordena el array por nombre de manera ascendente o descendente
 *
 * \param lista: array estructura de Employee
 * \param len:  tamaño de estructura
 * \param orden: recibe 1 o 0 para realizar el orden ascendente o descendente
 * \return (0)si no hubo error o (-1)si falla
 */
int sortEmployeesbyName(Employee lista[],int len,int order);
/** \brief modificar: Permite modifica un empleado al ingresar su id
 *
 * \param pers:estructura de Employee
 * \param len:tamaño de estructura
 *
 */

void modificar(Employee pers[],int len);
/** \brief promSalEmp: muestra el total y promedio de salarios y la cantidad de empleados que superan el promedio
 *
 * \param emp: array estructura employee
 * \param acum: acumulador de todos los salarios
 * \param cont: aumenta a medida que se carga un empleado mas
 * \param prom: es el resultado de la division de lo acumulado y el contador
 * \param contMasPromedio: contador que aumenta cuando un empleado supera la variable prom
 */

void promSalEmp(Employee emp[],int len);
/** \brief isName: Valida que el nombre ingresado en alta esté conpuesto por letras
 *
 * \param emp: estructura employee
 * \param len:tamaño de estructura
 * \return (0)si es un nombre o (-1) si hay error
 *
 */

int isName(Employee emp,int len);
/** \brief isLastName :verifica que esté compuesto por letras
 *
 * \param emp: estructura employee
 * \param len:largo de estructura
 * \return (0)si es un nombre o (-1) si hay error
 *
 */

int isLastName(Employee emp,int len);
#endif //ARRAYEMPLOYESS_H_INCLUDED
