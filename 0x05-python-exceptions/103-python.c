#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - a function that Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */

void print_python_bytes(PyObject *p)
{
	char *strng;
	long int size, k, lim;

	setbuf(stdout, NULL);

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		setbuf(stdout, NULL);
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	strng = ((PyBytesObject *)p)->ob_sval;

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", strng);

	if (size >= 10)
		lim = 10;
	else
		lim = size + 1;

	printf("  first %ld bytes:", lim);

	for (k = 0; k < lim; k++)
		if (strng[k] >= 0)
			printf(" %02x", strng[k]);
		else
			printf(" %02x", 256 + strng[k]);

	printf("\n");
	setbuf(stdout, NULL);
}

/**
 * print_python_float - Prints float information
 *
 * @p: Python Object
 * Return: no return
 */

void print_python_float(PyObject *p)
{
	double val;
	char *nff;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");

	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		setbuf(stdout, NULL);
		return;
	}

	val = ((PyFloatObject *)(p))->ob_fval;
	nff = PyOS_double_to_string(val, 'r', 0, Py_DTSF_ADD_DOT_0, Py_DTST_FINITE);

	printf("  value: %s\n", nff);
	setbuf(stdout, NULL);
}

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */

void print_python_list(PyObject *p)
{
	long int size, k;
	PyListObject *list;
	PyObject *objct;

	setbuf(stdout, NULL);
	printf("[*] Python list info\n");

	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		setbuf(stdout, NULL);
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	list = (PyListObject *)p;

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (k = 0; k < size; k++)
	{
		objct = list->ob_item[k];
		printf("Element %ld: %s\n", k, ((objct)->ob_type)->tp_name);

		if (PyBytes_Check(objct))
			print_python_bytes(objct);
		if (PyFloat_Check(objct))
			print_python_float(objct);
	}
	setbuf(stdout, NULL);
}
