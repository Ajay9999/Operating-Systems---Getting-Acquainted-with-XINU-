.text                            #Text segment of code
.code32                          #To compile the code in 32-bit instruction set
.global zfunction

zfunction:
  pushl %ebp                     #pushing the base pointer onto stack
  movl %esp,%ebp                 #Saving the stack contents onto base pointer
  
  movl 8(%ebp),%eax              #Assigning the passed value onto accumulator 
  andl $0xfffc01ff,%eax          #Applying filter and performing bitwise AND operation
  sarl  $0x8,%eax                #Shift Right operation
  leave 
  ret  
  
  
   
