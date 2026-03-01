#include "tasks.h"



int main()
{
	// TASKS


	//4.6.4
	/* 
	Find a polynomial of degree <= 3 which interpolates the points
	(0, 1), (0.5, 0.5625), (1.5, −0.3125) and (3, 4)

	*/

	Task4_6_4();

	// Answer: 0.5x^3 - x^2 - 0.5x + 1



	//4.6.7
	/*
	Construct a polynomial of degree <= 3 which interpolates the points p0(1, 0) and
	p1(pi, 0) and where the derivatives are respectively 1 and -1 
	(we write p′(x0) = 1 and p′(x1) = −1).

	*/


	Task4_6_7();

	//Answer: -0.466942x^2 + 1.93388x - 1.46694








	//4.6.14
	/*
	Use the method of least squares to find the equation of the straight line which
	fits the points best possible: (4, 3), (0, 1), (2, 0) and (3, 4).
	
	*/


	Task4_6_14();

	// Answer: 0.518519x + 0.851852










	//4.6.15
	/*
	In a game scene the player is moving along a parabola (the graph of a second
	degree polynomial) and collect trophys along the path.The trophys have coordinates
	(0.5, 0.5), (0.5, 1.5), (2.5, −1), (3,0.5), (4, 3)
	
	The parabolic path should be constructed using the method of least squares.
		1. Write down the matrices A, AT and the vector y = ATb
		2. Find the equation for the second degree polynomial.
		
	*/

	Task4_6_15();

	// Answer:  1.414372x^2 - 5.182523x + 3.007232

	
	return 0;


}