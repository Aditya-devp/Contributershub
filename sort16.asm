DATA SEGMENT
MSG1 DB 0AH,0DH,"Enter the  number: $"

MSG2 DB 0AH,0DH,"SORTED STRING IS :$"

A DW 05H DUP(?)


DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: MOV AX,DATA
       MOV DS,AX
       MOV CL,05H
		LEA SI,A
		L10:INC SI

			MOV AH,09H
			LEA DX,MSG1
			INT 21H
			
			CALL P1
			
			MOV [SI],AL
			DEC SI
			
			CALL P1
			
			
			MOV [SI],AL
			INC SI
			INC SI
			DEC C1
			JNZ L10
			
		L1:		 MOV BH,CL
			MOV CH,BH


		L3:		 LEA SI,CHR1
			 MOV CL,BH
			
		L4:  		MOV AX,[SI]
					MOV BX,[SI+2]
					
					CMP AX,BX
					JC L5
					
					XCHG AX,BX
					MOV [SI],AX
					MOV [SI+2],BX
					
		L5:		INC SI
					DEC CL
					JNZ L4
					DEC CH
					
					JNZ L3
					INC BH
		
		
		
		
		
		
		
		
		
		
		



	P1 PROC
	   MOV AH,01H
	   INT 21H
	   SUB AL,30H
	   CMP AL,09H
	   JLE L1
	   SUB AL,07H
	   
	L1:MOV CL,04H
	   ROL AL,CL
	   MOV CH,AL
	   
	   MOV AH,01H
	   INT 21H  
	   SUB AL,30H
	   CMP AL,09H
	   JLE L2
	   SUB AL,07H

	L2:ADD AL,CH
	   RET
	  P1 ENDP
	
	P2 PROC
       MOV AL,[SI]
       AND AL,0F0H
       MOV CL,04H
       ROL AL,CL
       ADD AL,30H
       CMP AL,39H
       JLE L4
       ADD AL,07H
       
    L4:MOV AH,02H
       MOV DL,AL
       INT 21H
       
       MOV AL,[SI]
       AND AL,0FH
       ADD AL,30H
       CMP AL,39H
       JLE L5 
       ADD AL,07H
       
    L5:MOV AH,02H
       MOV DL,AL
       INT 21H   
       RET
       P2 ENDP
         
 
   
CODE ENDS 
END START
   
