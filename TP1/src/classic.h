/*
 * classic.h
 *
 *  Created on: Sep 12, 2021
 *      Author: JS
 */

#ifndef CLASSIC_H_
#define CLASSIC_H_

#include <stdio.h>
#include <stdlib.h>

#define DATOA 0		//estado tomo numero 1
#define DATOB 1		//estado tomo numero 2
#define OPERATION 2	//estado tomo operacion
#define CALCDATA 3	//estado calcular datos (otros que no sean factorial)
#define FACTORIAL 4	//estado calcular factorial


void classic();		//maquina de estado

#endif /* CLASSIC_H_ */
