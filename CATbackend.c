#include <stdio.h>

//12 bits is 0 ≤ x ≤ 4095
// #define PINKYTHRESH 0
// #define THUMBTHRESH 0
// #define INDEXTHRESH 0
// #define MIDDLETHRESH 0
// #define RINGTHRESH 0

typedef enum state 
{
  ZERO, 	
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  PLUS //some operation ... to be confirmed
} state;

typedef enum fingerState 
{
	extended,
	half_curled, //determine other states
	full_curled,
} fingerState;

int main(void) 
{
	state handState;
	state oldState = 0;
	int count = 0;

	while (true)
	 {
	 	//get data from server

		fingerState pointerFinger;  //initialize with glove data values for each finger
		fingerState pinkyFinger;
		fingerState thumbFinger;
		fingerState indexFinger;
		fingerState middleFinger;
		

		//substitute question marks with values that are applicable with the data

		//pointer finger
		if (pointerFinger >= ? && pointerFinger <= 4095)
		{
			pointerFinger = full_curled;
		
		}
		else if (pointerFinger >= ? && pointerFinger <= ?)
		{
			pointerFinger = half_curled;
		}
		else
		{
			pointerFinger = extended;
		}


		//pinky finger
		if (pinkyFinger >= ? && pinkyFinger <= 4095)
		{
			pinkyFinger = full_curled;
		
		}
		else if (pinkyFinger >= ? && pinkyFinger <= ?)
		{
			pinkyFinger = half_curled;
		}
		else
		{
			pinkyFinger = extended;
		}


		//thumb finger
		if (thumbFinger >= ? && thumbFinger <= 4095)
		{
			pinkyFinger = full_curled;
		
		}
		else if (thumbFinger >= ? && thumbFinger <= ?)
		{
			thumbFinger = half_curled;
		}
		else
		{
			thumbFinger= extended;
		}


		//middle finger
		if (middleFinger >= ? && middleFinger <= 4095)
		{
			middleFinger = full_curled;
		
		}
		else if (middleFinger >= ? && middleFinger <= ?)
		{
			middleFinger = half_curled;
		}
		else
		{
			middleFinger = extended;
		}


		//index finger
		if (indexFinger >= ? && indexFinger <= 4095)
		{
			indexFinger = full_curled;
		
		}
		else if (indexFinger >= ? && indexFinger <= ?)
		{
			indexFinger = half_curled;
		}
		else
		{
			indexFinger = extended;
		}

		//sign indentifier

		if (pointerFinger == half_curled && pinkyFinger == half_curled && indexFinger == half_curled && thumbFinger == half_curled && middleFinger == half_curled)
		{
			handState = ZERO;
		}

		if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == full_curled && thumbFinger == full_curled && middleFinger == full_curled)
		{
			handState = ONE;	
		}

		if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == full_curled && thumbFinger == full_curled && middleFinger == extended)
		{
			handState = TWO;	
		}

		if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == full_curled && thumbFinger == extended && middleFinger == extended)
		{
			handState = THREE;
		}

		if (pointerFinger == extended && pinkyFinger == extended && indexFinger == extended && thumbFinger == full_curled && middleFinger == extended)
		{
			handState = FOUR;
		}

		if (pointerFinger == extended && pinkyFinger == extended && indexFinger == extended && thumbFinger == extended && middleFinger == extended)
		{
			handState = FIVE;
		}

		if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == extended && thumbFinger == full_curled && middleFinger == extended)
		{
			handState = SIX;
		}

		if (pointerFinger == extended && pinkyFinger == extended && indexFinger == full_curled && thumbFinger == full_curled && middleFinger == extended)
		{
			handState = SEVEN;
		}

		if (pointerFinger == extended && pinkyFinger == extended && indexFinger == extended && thumbFinger == full_curled && middleFinger == full_curled)
		{
			handState = EIGHT;
		}

		if (pointerFinger == full_curled && pinkyFinger == extended && indexFinger == extended && thumbFinger == full_curled && middleFinger == extended)
		{
			handState = NINE;
		}


		if (handState == oldState)
		{
			counter++;
		}

		else
		{
			count = 0;
		}

		if (count == 10)
		{
			return handState;
		}

		oldState = handState;


	 }
}






