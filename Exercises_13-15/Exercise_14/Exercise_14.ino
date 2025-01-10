/*
 * 14a)
 * A member refers to a variable withing a struct
 * 
 * 14b)
 * 1. Get the data of member withing the structure.
 * 2. Assuming it's meant as (*struct).member, it assumes that the struct is a pointer. Thus it gets the struct data from the adress, and thus the member data. If *(struct).member is meant, refer to 3.
 * 3. This would be used, if the member itself is an address. This gets the data stored at the address, which member points to.
 * 4. Same as 2.
 * 
 */

//14c)
struct Animal {
  float Weight;
  int Age;
  bool isAlive;
  char Name[10];
  bool isFish;
};

void setup() {
  struct Animal shark = {486.2, 13, 1, "Sharky", 1};
  struct Animal human = {65.4, 21, 0, "Mads", 0};


}

void loop() {
  // put your main code here, to run repeatedly:

}

//14e)
void printAnimal(struct Animal A){
  Serial.println("Name \t Age \t Weight \t Is it a fish? \t Is it alive?");
  Serial.print(A.Name);
  Serial.print("\t");
  Serial.print(A.Age);
  Serial.print("\t");
  Serial.print(A.Weight);
  Serial.print("\t");
  Serial.print(A.isFish);
  Serial.print("\t");
  Serial.print(A.isAlive);
  Serial.println("\t");
}

//14f)
void swapIsFish(struct Animal *a, struct Animal *b){
  bool temp = a->isFish;
  a->isFish = b->isFish;
  b->isFish = temp;
}
