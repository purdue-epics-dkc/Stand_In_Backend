#include <node.h>


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


CATbackend {   

//void Method (oldState, count,  data)
	void Method(const FunctionCallbackInfo<V8::Value>& args) 
	{
		V8::Local<V8::Object> results = Object::New();
		V8::Local<V8::Array>  data_list = Array::New(args[2]);

		v= args[3] ->Int32Value(); 

		results->Set(V8::String::NewSymbol("count"), args[1]->Int32Value());
		results->Set(V8::String::NewSymbol("oldState"), args[0] ->Int32Value());

		while (true)
		 {
		 	//get data from server

			fingerState pointerFinger;  //initialize with glove data values for each finger
			fingerState pinkyFinger;
			fingerState thumbFinger;
			fingerState indexFinger;
			fingerState middleFinger;

			int pointerFingerData = data_list[1];
			int pinkyFingerData = data_list[4];
			int thumbFingerData = data_list[0];
			int indexFingerData = data_list[3];
			int middleFingerData = data_list[2];


			//substitute question marks with values that are applicable with the data

			//pointer finger
			if (pointerFingerData >= ? && pointerFingerData <= 4095)
			{
				pointerFinger = full_curled;
			
			}
			else if (pointerFingerData >= ? && pointerFingerData <= ?)
			{
				pointerFinger = half_curled;
			}
			else
			{
				pointerFinger = extended;
			}


			//pinky finger
			if (pinkyFingerData >= ? && pinkyFingerData <= 4095)
			{
				pinkyFinger = full_curled;
			
			}
			else if (pinkyFingerData >= ? && pinkyFingerData <= ?)
			{
				pinkyFinger = half_curled;
			}
			else
			{
				pinkyFinger = extended;
			}


			//thumb finger
			if (thumbFingerData >= ? && thumbFingerData <= 4095)
			{
				pinkyFinger = full_curled;
			
			}
			else if (thumbFingerData >= ? && thumbFingerData <= ?)
			{
				thumbFinger = half_curled;
			}
			else
			{
				thumbFinger= extended;
			}


			//middle finger
			if (middleFingerData >= ? && middleFingerData <= 4095)
			{
				middleFinger = full_curled;
			
			}
			else if (middleFingerData >= ? && middleFingerData <= ?)
			{
				middleFinger = half_curled;
			}
			else
			{
				middleFinger = extended;
			}


			//index finger
			if (indexFingerData >= ? && indexFingerData <= 4095)
			{
				indexFinger = full_curled;
			
			}
			else if (indexFingerData >= ? && indexFingerData <= ?)
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
				returnValues.handState = ZERO;
			}

			if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == full_curled && thumbFinger == full_curled && middleFinger == full_curled)
			{
				returnValues.handState = ONE;	
			}

			if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == full_curled && thumbFinger == full_curled && middleFinger == extended)
			{
				returnValues.handState = TWO;	
			}

			if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == full_curled && thumbFinger == extended && middleFinger == extended)
			{
				returnValues.handState = THREE;
			}

			if (pointerFinger == extended && pinkyFinger == extended && indexFinger == extended && thumbFinger == full_curled && middleFinger == extended)
			{
				returnValues.handState = FOUR;
			}

			if (pointerFinger == extended && pinkyFinger == extended && indexFinger == extended && thumbFinger == extended && middleFinger == extended)
			{
				returnValues.handState = FIVE;
			}

			if (pointerFinger == extended && pinkyFinger == full_curled && indexFinger == extended && thumbFinger == full_curled && middleFinger == extended)
			{
				returnValues.handState = SIX;
			}

			if (pointerFinger == extended && pinkyFinger == extended && indexFinger == full_curled && thumbFinger == full_curled && middleFinger == extended)
			{
				returnValues.handState = SEVEN;
			}

			if (pointerFinger == extended && pinkyFinger == extended && indexFinger == extended && thumbFinger == full_curled && middleFinger == full_curled)
			{
				returnValues.handState = EIGHT;
			}

			if (pointerFinger == full_curled && pinkyFinger == extended && indexFinger == extended && thumbFinger == full_curled && middleFinger == extended)
			{
				returnValues.handState = NINE;
			}


			if (returnValues.handState == result ->Get(V8::String::NewSymbol("oldState")))
			{
				//returnValues.count++;
				results->Set(V8::String::NewSymbol("count"), result->Get(V8::String::NewSymbol("count") + 1));

			}

			else
			{
				results->Set(V8::String::NewSymbol("count"), 0);

			}

			if (result->Get("count") == 10)
			{
				args.GetReturnValue().Set(result);
			}

			results->Set(V8::String::NewSymbol("oldState"), handState);

			args.GetReturnValue().Set(result);


		 }
	}

	void init(V8::Local<V8::Object> exports) 
	{
		NODE_SET_METHOD(exports, , Method);
	} 


	NODE_MODULE(NODE_GYP_MODULE_NAME, init)
}











