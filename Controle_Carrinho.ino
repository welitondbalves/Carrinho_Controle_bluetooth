/* 
O carrinho movimenta a partir 
dos comandos dados pelo aplica-
tivo android. Com os botões de
andar para frente, andar para trás,
vira para esquerda e direita e botão
freiar.
*/ 
// motor um
#define enA 11
#define in1 9
#define in2 8
// motor dois
#define enB 5
#define in3 7
#define in4 6

char Incoming_value = 0;
int velocidadeMotorUm = 150;
int velocidadeMotorDois = 150;
                
void setup() 
{
  Serial.begin(9600);         
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    if(Incoming_value == '1')
    {
      Frente();
    }
    if(Incoming_value == '2')
    {
      VireEsquerda();
      delay(1000);
      Parar();
    }
    if(Incoming_value == '3')
    {
      ViraDireita();
      delay(1000);
      Parar();
    }
    if (Incoming_value == '4')
    {
      ParaTras();
    }
    if (Incoming_value == '0')
    {
      Parar();
    }   
  }
}
void Parar()
{
  Serial.println("Robô: Parar ");
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(100);
}

void Frente()
{
  Serial.println("Robô1: Frente ");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enA,velocidadeMotorUm);
  analogWrite(enB,velocidadeMotorDois);
}

void ParaTras()
{
  Serial.println("Robô1: Ré ");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(300);
  analogWrite(enA,velocidadeMotorUm);
  analogWrite(enB,velocidadeMotorDois);
}

void ViraDireita()
{
  Serial.println("Robô1: Direita ");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(300);
  //analogWrite(enA,velocidadeMotorUm);
  analogWrite(enA,(velocidadeMotorUm*0.6));
  //analogWrite(enB,velocidadeMotorDois);
  analogWrite(enB,(velocidadeMotorDois*0.6));
}

void VireEsquerda()
{
  Serial.println("Robô1: Esquerda ");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(300);
  //analogWrite(enA,velocidadeMotorUm);
  //analogWrite(enB,velocidadeMotorDois);
  analogWrite(enA,(velocidadeMotorUm*0.6));
  analogWrite(enB,(velocidadeMotorDois*0.6));
}                     
