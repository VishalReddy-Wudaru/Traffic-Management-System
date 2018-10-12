#include <SoftwareSerial.h>
 
#define DEBUG true

String server = "192.168.43.136";
String data, cmd2;
int i;
int ir[4], ir2[4], ir3[4];
int proxy[4], proxy2[4], proxy3[4];
int tr1[3], tr2[3], tr3[3];
int led[8];
int interruptPin1=18; //INT.5
int interruptPin2=19; //INT.4
int interruptPin3=20; //INT.3
int interruptPin4=21; //INT.2
int quanta = 5000;
int buff = 2000;

String uri1 = "C:/xampp/htdocs/final2.com/write_data7.php"; // Location of PHP file.
SoftwareSerial esp8266(10,11); // Make RX Arduino line is pin 10, make TX Arduino line is pin 11.

void setup()
{
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(interruptPin3, INPUT_PULLUP);
  pinMode(interruptPin4, INPUT_PULLUP);

  for(i=0;i<4;i++)
  {
    ir[i]=18+(i*1);
  }
  
  ir2[0]=A0;
  ir2[1]=A1;
  ir2[2]=A2;
  ir2[3]=A3;
  
  for(i=0;i<4;i++)
  {
    ir3[i]=2+(i);
  }

  for(i=0;i<4;i++)
  {
    pinMode(ir[i],INPUT);
    pinMode(ir2[i],INPUT);
    pinMode(ir3[i],INPUT);
  }
  

  for(i=0;i<7;i++)
  {
    led[i]=28+(i*2);
  }
  
  for(i=0;i<7;i++)
  {
    pinMode(led[i],OUTPUT);
  }
  
  
  tr1[0]=49;  tr1[1]=51;  tr1[2]=53;
  tr2[0]=47;  tr2[1]=45;  tr2[2]=43;
  tr3[0]=23;  tr3[1]=25;  tr3[2]=27;

   for(i=0;i<3;i++)
  {
    pinMode(tr1[i],OUTPUT);
    pinMode(tr2[i],OUTPUT);
    pinMode(tr3[i],OUTPUT);
  }
  
  attachInterrupt(digitalPinToInterrupt(interruptPin1), blink, LOW);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), blink, LOW);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), blink, LOW);
  attachInterrupt(digitalPinToInterrupt(interruptPin4), blink, LOW);
  
  digitalWrite(led[0],HIGH);
  digitalWrite(led[6],HIGH);
  
  Serial.begin(9600);
  esp8266.begin(9600);
  
  sendData("AT+RST\r\n",5000,DEBUG); // reset module
  //sendData("AT+CWJAP=\" +vivo 1713+",\" +onepiece+ \r\n",1000,DEBUG); //WIFI Username and Password
  //sendData("AT+CWMODE=3\r\n",1000,DEBUG); // configure as access point
  sendData("AT+CIFSR\r\n",1000,DEBUG); // get ip address
  //sendData("AT+CIPMUX=1\r\n",1000,DEBUG); // configure for multiple connections
  //sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // turn on server on port 80
}
 
void loop()
{
  int tq1, tq2, tq3;
  tq1 = tq2 = tq3 = quanta;
  
  for(i=0;i<4;i++)
  {
    proxy[i]=digitalRead(ir[i]);
  }
  for(i=0;i<4;i++)
  {
    proxy2[i]=digitalRead(ir2[i]);
  }
  for(i=0;i<3;i++)
  {
    proxy3[i]=digitalRead(ir3[i]);
  }



  if(proxy[0]==0)
  {
    tq1=tq1+buff;
  }
  if(proxy[1]==0)
  {
    tq1=tq1+buff;
  }
  if(proxy[2]==0)
  {
    tq1=tq1+buff;
  }
  if(proxy[3]==0)
  {
     tq1=tq1+buff;
  }
  
  if(proxy2[0]==0)
  {
    tq2=tq2+buff;
  }
  if(proxy2[1]==0)
  {
    tq2=tq2+buff;
  }
  if(proxy2[2]==0)
  {
    tq2=tq2+buff;
  }
  if(proxy2[3]==0)
  {
    tq2=tq2+buff;
  }
  
  if(proxy3[0]==0)
  {
    tq3=tq3+buff;
  }
  if(proxy3[1]==0)
  {
    tq3=tq3+buff;
  }
  if(proxy3[2]==0)
  {
    tq3=tq3+buff;
  }
      
  digitalWrite(27,1);
  digitalWrite(47,1);
  digitalWrite(49,1);
  digitalWrite(51,0);
  digitalWrite(53,0);  //enables the 1st set of signals
  digitalWrite(45,0);
  digitalWrite(43,0);
  digitalWrite(23,0);
  digitalWrite(25,0);
  
  delay(tq3);
   
  digitalWrite(45,1);     //enables the yellow
  digitalWrite(47,0);  
  delay(2000);
  
  digitalWrite(23,1);
  digitalWrite(49,1);
  digitalWrite(43,1);
  digitalWrite(47,0);    //enables the 2nd set of signals
  digitalWrite(45,0);
  digitalWrite(25,0);
  digitalWrite(27,0);
  digitalWrite(51,0);
  digitalWrite(53,0);
  delay(tq2);
  
  digitalWrite(51,1);          //enables yellow
  digitalWrite(49,0);        
  delay(2000);
  
  digitalWrite(53,1);
  digitalWrite(47,1);
  digitalWrite(23,1);
  digitalWrite(25,0);
  digitalWrite(27,0);           //enables the 3rd set of signal
  digitalWrite(45,0);
  digitalWrite(43,0);
  digitalWrite(49,0);
  digitalWrite(51,0);
  delay(tq1);
  
  digitalWrite(25,1);           //enables yellow
  digitalWrite(23,0);
  delay(2000);
 
  if(proxy[0]==1)
  {
    cmd2="GET /write_data7.php?value1=1";
  }
  if(proxy[0]==0)
  {
     cmd2="GET /write_data7.php?value1=0";
  }
  if(proxy[1]==1)
  {
    cmd2=cmd2+"&value2=1";
  }
  if(proxy[1]==0)
  {
     cmd2=cmd2+"&value2=0";
  }
  if(proxy[2]==1)
  {
    cmd2=cmd2+"&value3=1";
  }
  if(proxy[2]==0)
  {
     cmd2=cmd2+"&value3=0";
  }
  if(proxy[3]==1)
  {
    cmd2=cmd2+"&value4=1";
  }
  if(proxy[3]==0)
  {
     cmd2=cmd2+"&value4=0";
  }
  
  if(proxy2[0]==1)
  {
    cmd2=cmd2+"&value5=1";
  }
  if(proxy2[0]==0)
  {
    cmd2=cmd2+"&value5=0";
  }
  if(proxy2[1]==1)
  {
    cmd2=cmd2+"&value6=1";
  }
  if(proxy2[1]==0)
  {
    cmd2=cmd2+"&value6=0";
  }
  if(proxy2[2]==1)
  {
    cmd2=cmd2+"&value7=1";
  }
  if(proxy2[2]==0)
  {
    cmd2=cmd2+"&value7=0";
  }
  if(proxy2[3]==1)
  {
    cmd2=cmd2+"&value8=1";
  }
  if(proxy2[3]==0)
  {
    cmd2=cmd2+"&value8=0";
  }

  if(proxy3[0]==1)
  {
    cmd2=cmd2+"&value9=1";
  }
  if(proxy3[0]==0)
  {
    cmd2=cmd2+"&value9=0";
  }
  if(proxy3[1]==1)
  {
    cmd2=cmd2+"&value10=1";
  }
  if(proxy3[1]==0)
  {
    cmd2=cmd2+"&value10=0";
  }
  if(proxy3[2]==1)
  {
    cmd2=cmd2+"&value11=1";
  }
  if(proxy3[2]==0)
  {
    cmd2=cmd2+"&value11=0";
  }
  
  
  cmd2=cmd2+" HTTP/1.1\r\nHost:192.168.43.136\r\n\r\n";
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "192.168.43.136"; 
  cmd += "\",80";
  sendData(cmd+"\r\n",1000,DEBUG); 

  if( esp8266.find("OK")) 
  {
    Serial.println("TCP connection ready");
  } 
  String sendCmd = "AT+CIPSEND=";//determine the number of caracters to be sent.
  sendCmd+=cmd2.length();
  sendData(sendCmd+"\r\n",1000,DEBUG); 
  sendData(cmd2,1000,DEBUG); 
  if( esp8266.find("SEND OK")) 
  { 
    Serial.println("Packet sent");
  }
  String closeCommand = "AT+CIPCLOSE="; 
  closeCommand+="\r\n";     
  sendData(closeCommand,1000,DEBUG);
}


void blink()
{
  blink2();
}

void blink3()
{
  Serial.println("blink3 in");
  digitalWrite(led[1],HIGH);
  digitalWrite(led[3],HIGH);
  digitalWrite(led[5],HIGH);
  Serial.println("blink3 out");
}

void blink2()
{
   for(i=0;i<4;i++)
  {
    proxy[i]=digitalRead(ir[i]);
    
  }
  //LED 1
  if(proxy[0]==0)
  {
    digitalWrite(led[1],HIGH);
  }
  else
  {
    digitalWrite(led[1],LOW);
  }

  //LED 2
  if(proxy[0]==0 || proxy[1]==0)
  {
    digitalWrite(led[2],HIGH);
  }
  else
  {
    digitalWrite(led[2],LOW);
  }

  //LED 3
  if(proxy[1]==0 || proxy[2]==0)
  {
    digitalWrite(led[3],HIGH);
  }
  else
  {
    digitalWrite(led[3],LOW);
  }

  //LED 4
  if(proxy[1]==0 || proxy[2]==0)
  {
    digitalWrite(led[4],HIGH);
  }
  else
  {
    digitalWrite(led[4],LOW);
  }

  //LED 5
  if(proxy[2]==0)
  {
    digitalWrite(led[5],HIGH);
  }
  else
  {
    digitalWrite(led[5],LOW);
  }

}


String sendData(String command, const int timeout, boolean debug)
{
  String response = "";
  esp8266.print(command); // send the read character to the esp8266
  long int time = millis();
  while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
   if(debug)
   { 
      Serial.print(response);
   }
   return response;
}
