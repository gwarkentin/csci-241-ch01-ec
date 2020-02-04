# csci-241-ch01-ec
Twos_Complement_with_Hexadecimal extra credit

Write a C++ program converting a 4-digit Hexadecimal integer to its Two's Complement. You can create functions declared like this
// ============================================================================
// Function:	TwosComplement
// Description: This function converts a Hexadecimal to its Two's Complement
//
// Parameter:   s [IN] - a C-string with a 4-digit Hexadecimal received
//              s2 [out] - a C-string with a 4-digit of s two's complement
// Return:      None
// ============================================================================
void TwosComplement(char* s, char* s2);


Then you can call it repeatedly in main() to verify that the 2's Complement is reversible with TwosComplement.exe:

Please Enter 4-digit Hexadecimal integer (e.g., A1B2): A0Bc
Two's Complement of Hex A0Bc is 5F44
Try again? (y/n) y

Please Enter 4-digit Hexadecimal integer (e.g., A1B2): 5f44
Two's Complement of Hex 5f44 is A0BC
Try again? (y/n) y

Please Enter 4-digit Hexadecimal integer (e.g., A1B2): AoBC
Two's Complement of Hex AoBC is Error
Try again? (y/n) y

Please Enter 4-digit Hexadecimal integer (e.g., A1B2): 0001
Two's Complement of Hex 0001 is FFFF
Try again? (y/n) n
Press any key to continue . . .


To implement TwosComplement(), only functions allowed to use are strlen(), strcpy(), and toupper() if needed. Please don't use printf() or scanf(). An implementation of TwosComplement() is suggested here:
  Receive a 4-char C-string with 4 Hex digits
  Loop through each char from right to left
  Get a Hex char digit
  Make it upper case if necessary
  Convert char digit to a number value
  Reverse every bit in Hex digit
  Plus one to the lowest digit (may cause a carry to propagate)
  Convert each number value back to char digit
A single loop should be enough without nested one
