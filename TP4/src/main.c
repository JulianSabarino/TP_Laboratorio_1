/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	startTesting(1);  // ll_newLinkedList //LISTO
	startTesting(2);  // ll_len //LISTO
	startTesting(3);  // getNode - test_getNode //LISTO
	startTesting(4);  // addNode - test_addNode //LISTO
	startTesting(5);  // ll_add //LISTO
	startTesting(6);  // ll_get //LISTO
	startTesting(7);  // ll_set //LISTO
	startTesting(8);  // ll_remove //LISTO
	startTesting(9);  // ll_clear //LISTO
	startTesting(10); // ll_deleteLinkedList //LISTO
	startTesting(11); // ll_indexOf //LISTO
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort

    return 0;
}

































