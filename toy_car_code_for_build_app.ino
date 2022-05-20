const int LWheelsPin1 = 10, LWheelsPin2 = 9, LWheelEN = 8, RWheelPin1 = 12, RWheelPin2 = 11, RWheelEN = 7;

char Incoming_value = 0;

void forward(){
  digitalWrite(LWheelsPin1, HIGH);
  digitalWrite(LWheelsPin2, LOW);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, HIGH);
  digitalWrite(RWheelPin2, LOW);
  digitalWrite(RWheelEN, HIGH);
}

void backward(){
  digitalWrite(LWheelsPin1, LOW);
  digitalWrite(LWheelsPin2, HIGH);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, LOW);
  digitalWrite(RWheelPin2, HIGH);
  digitalWrite(RWheelEN, HIGH);
}

void left(){
  digitalWrite(LWheelsPin1, LOW);
  digitalWrite(LWheelsPin2, LOW);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, HIGH);
  digitalWrite(RWheelPin2, LOW);
  digitalWrite(RWheelEN, HIGH);
}

void right(){
  digitalWrite(LWheelsPin1, HIGH);
  digitalWrite(LWheelsPin2, LOW);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, LOW);
  digitalWrite(RWheelPin2, LOW);
  digitalWrite(RWheelEN, HIGH);
}

void forwardLeft(){
  digitalWrite(LWheelsPin1, LOW);
  digitalWrite(LWheelsPin2, LOW);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, HIGH);
  digitalWrite(RWheelPin2, LOW);
  digitalWrite(RWheelEN, HIGH);
}

void forwardRight(){
  digitalWrite(LWheelsPin1, HIGH);
  digitalWrite(LWheelsPin2, LOW);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, LOW);
  digitalWrite(RWheelPin2, LOW);
  digitalWrite(RWheelEN, HIGH);
}

void backwardLeft(){
  digitalWrite(LWheelsPin1, LOW);
  digitalWrite(LWheelsPin2, LOW);
  digitalWrite(LWheelEN, HIGH);
  analogWrite(RWheelPin1, LOW);
  digitalWrite(RWheelPin2, HIGH);
  digitalWrite(RWheelEN, HIGH);
}

void backwardRight(){
  digitalWrite(LWheelsPin1, LOW);
  digitalWrite(LWheelsPin2, HIGH);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, LOW);
  digitalWrite(RWheelPin2, LOW);
  digitalWrite(RWheelEN, HIGH);
}

void stopCar(){
  digitalWrite(LWheelsPin1, LOW);
  digitalWrite(LWheelsPin2, LOW);
  digitalWrite(LWheelEN, HIGH);
  digitalWrite(RWheelPin1, LOW);
  digitalWrite(RWheelPin2, LOW);
  digitalWrite(RWheelEN, HIGH);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(LWheelsPin1, OUTPUT);
  pinMode(LWheelsPin2, OUTPUT);
  pinMode(LWheelEN, OUTPUT);
  pinMode(RWheelPin1, OUTPUT);
  pinMode(RWheelPin2, OUTPUT);
  pinMode(RWheelEN, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();

    if(Incoming_value == 'F'){
      forward();
    }
    else if(Incoming_value == 'B'){
      backward(); 
    }
    else if(Incoming_value == 'G'){
      forwardLeft();
    }
    else if(Incoming_value == 'I'){
      forwardRight();
    }
    else if(Incoming_value == 'H'){
      backwardLeft();
    }
    else if(Incoming_value == 'J'){
      backwardRight();
    }
    else if(Incoming_value == 'L'){
      left();
    }
    else if(Incoming_value == 'R'){
      right();
    }
    else if(Incoming_value == 'S'){
      stopCar();
    }
  }
}
