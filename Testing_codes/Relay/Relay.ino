  #define relay PB8
  void setup()   
  {   
  pinMode(relay,OUTPUT); // RELAY PIN   
  digitalWrite(relay,HIGH); // Normally ON Only For Chanies Relay Module   
  }   
  void loop()    
  {   
  digitalWrite(relay,LOW); // RELAY ON   
  delay(10);   
  digitalWrite(relay,HIGH); // RELAY OFF   
  delay(10);   
  }   
