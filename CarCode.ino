#define B 100
#define W 250
#define S 100

int Lmtr = 11, Rmtr = 10;
void setup()
{
  pinMode(Lmtr, OUTPUT);
  pinMode(Rmtr, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{  
  int FL;
  FL = analogRead(A5);
  int ML;
  ML = analogRead(A4);
  int MR;
  MR = analogRead(A3);
  int FR;
  FR = analogRead(A2);

  Serial.println("FL");
  Serial.println(FL);
  Serial.println("ML");
  Serial.println(ML);
  Serial.println("MR");
  Serial.println(MR);
  Serial.println("FR");
  Serial.println(FR);


  int ShL = 0, ShR = 0;

  
  if (FL > W || 
      FR > W)
  {
    //Sharp left
    if (FL > W &&
        FR < B)
    {
      ShL = 1;
      analogWrite(Lmtr, S);
      analogWrite(Rmtr, 0);
    }
    //Sharp Right
    else if (FL < B && 
             FR > W)
    {
      ShR = 1;
      analogWrite(Lmtr, 0);
      analogWrite(Rmtr, S); //changed to s from s/2
    }
    //Split
    else if (FL > W && 
             FR > W)
    {
      //Left turn at split
      if (ML > W && 
          MR > W)
      {
        analogWrite(Lmtr, S);  //changed to s from s/2
        analogWrite(Rmtr, 0);
      }
      //Right turn at split
      else if ((ML < W && ML > B) &&
               (MR < W && ML > B))
      {
        analogWrite(Lmtr, 0);
        analogWrite(Rmtr, S/2);
      }
    }
    //Stop car
    else if (ML > W &&
             MR > W &&
             FL > W && 
             FR > W)
    {
      analogWrite(Lmtr, 0);
      analogWrite(Rmtr, 0);
    }
  }
  else if (ML < B &&
             MR > W)
  {
    analogWrite(Lmtr, S/2);
    analogWrite(Rmtr, 0);
  }
  else if (ML > W && 
           MR < B)
  {
    analogWrite(Lmtr, 0);
    analogWrite(Rmtr, S/2);
  }
  else
  {
    analogWrite(Lmtr, S/2);
    analogWrite(Rmtr, S/2);
  }
  
  delay(10);
}



/*Changelog:

Commit v1.0: Brandon
Commit v1.1: Achal, changed 'S/2' to 'S' in PWM function.
Commit v1.2: 
Commit v1.3:
Commit v1.4:
Commit v1.5:
