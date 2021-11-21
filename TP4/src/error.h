/*
 * error.h
 *
 *  Created on: Nov 12, 2021
 *      Author: JS
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <stdlib.h>
#include <stdio.h>

#define ERROR(X) showError(X);

void showError(int number);

#endif /* ERROR_H_ */
