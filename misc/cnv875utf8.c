/* 
Read from a text file encoded using EBCDIC for character set IBM CCSID 875 (GREEK) and create a copy of the
file encoded using UTF-8.

*/

#include <stdio.h>
#include <fcntl.h>

/* What happens when read or write fail?? */

int main(void)
{
	int inputFile, outputFile;
	int bytesRead, bytesWritten;
	char inputChar, outputChar;
	bytesRead = bytesWritten = 0;
	if( (inputFile  = open("/home/K67563/test01.txt", O_RDONLY)) == -1)  return -1;
	if( (outputFile = open("/home/K67563/out1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)  return -1;
	while ( (bytesRead = read(inputFile, &inputChar, 1)) > 0)
	{
		switch(inputChar)
		{
			case 0x05:										//horizontal tab (HT)
				outputChar = 0x09;
				write(outputFile, &outputChar, 1);
				break;                                                                                                             
			case 0x07:										//delete character (DEL)
				outputChar = 0x7F;
				write(outputFile, &outputChar, 1);
				break;
			case 0x15:										//Newline (NL)
				outputChar = 0xC2;
				write(outputFile, &outputChar, 1);
				outputChar = 0x85;
				write(outputFile, &outputChar, 1);
				break;
			case 0x16:										//Backspace (BS)
				outputChar = 0x08;
				write(outputFile, &outputChar, 1);
				break;
			case 0x25:										//Line feed or line break (LF)
				outputChar =0x0D;
				write(outputFile, &outputChar, 1);
				outputChar =0x0A;
				write(outputFile, &outputChar, 1);
				break:
			case 0x26:										//End of transmission block character (ETB)
				outputChar =0x17;
				write(outputFile, &outputChar, 1);
				break;
			case 0x27:										//Escape (ESC)
				outputChar =0x1B;
				write(outputFile, &outputChar, 1);
				break;
			case 0x2D:										//Enquiry (ENQ)
				outputChar =0x05;
				write(outputFile, &outputChar, 1);
				break;
			case 0x2E:										//Acknowledgement (ACK)
				outputChar =0x06;
				write(outputFile, &outputChar, 1);
				break;
			case 0x2F:										//Bell code (BEL)
				outputChar =0x07;
				write(outputFile, &outputChar, 1);
				break;
			case 0x32:										//Synchronous idle (SYN)
				outputChar =0x16;
				write(outputFile, &outputChar, 1);
				break;
			case 0x37:										//End of transmission (EOT)
				outputChar =0x04;
				write(outputFile, &outputChar, 1);
				break;
			case 0x3C:										//C0 and C1 control code (DC4)
				outputChar =0x14;
				write(outputFile, &outputChar, 1);
				break;
			case 0x3D:										//negative acknowledgement (NAK or NACK)
				outputChar =0x15;
				write(outputFile, &outputChar, 1);
				break;
			case 0x3F:										//Substitute character (SUB)
				outputChar =0x1A;
				write(outputFile, &outputChar, 1);
				break;
			case 0x40:										//Whitespace (SP)
				outputChar =0x20;
				write(outputFile, &outputChar, 1);
				break;
			case 0x41:										//Greek letter Α
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x91;
				write(outputFile, &outputChar, 1);
				break;
			case 0x42:										//Greek letter Β
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x92;
				write(outputFile, &outputChar, 1);
				break;
			case 0x43:										//Greek letter Γ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x93;
				write(outputFile, &outputChar, 1);
				break;
			case 0x44:										//Greek letter Δ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x94;
				write(outputFile, &outputChar, 1);                                                                                             
				break;
			case 0x45:										//Greek letter Ε
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x95;
				write(outputFile, &outputChar, 1);
				break;
			case 0x46:										//Greek letter Ζ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x96;
				write(outputFile, &outputChar, 1);
				break;
			case 0x47:										//Greek letter Η
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x97;
				write(outputFile, &outputChar, 1):
				break;
			case 0x48:										//Greek letter Θ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x98;
				write(outputFile, &outputChar, 1);
				break;
			case 0x49:										//Greek letter Ι
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x99;
				write(outputFile, &outputChar, 1);
				break;
			case 0x4A:										//Left bracket [
				outputChar =0x5B;
				write(outputFile, &outputChar, 1);
				break;
			case 0x4B:										//Period .
				outputChar =0x2E;
				write(outputFile, &outputChar, 1);
				break;
			case 0x4C:										//Less than sign <
				outputChar =0x3C;
				write(outputFile, &outputChar, 1);
				break;
			case 0x4D:										//Left parenthesis (
				outputChar =0x28;
				write(outputFile, &outputChar, 1);
				break;
			case 0x4E:										//Plus sign +
				outputChar =0x2B;
				write(outputFile, &outputChar, 1);
				break;
			case 0x4F:										//Exclamation mark !
				outputChar =0x21;
				write(outputFile, &outputChar, 1);
				break;
			case 0x50:										//Ampersand &
				outputChar =0x26;
				write(outputFile, &outputChar, 1);
				break;
			case 0x51:										//Greek letter Κ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x9A;
				write(outputFile, &outputChar, 1);
				break;
			case 0x52:										//Greek letter Λ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x9B;
				write(outputFile, &outputChar, 1);
				break;
			case 0x53:										//Greek letter Μ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x9C;
				write(outputFile, &outputChar, 1);
				break;
			case 0x54:										//Greek letter Ν
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x9D;
				write(outputFile, &outputChar, 1);
				break;                                                                                                             
			case 0x55:										//Greek letter Ξ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x9E;
				write(outputFile, &outputChar, 1);
				break;
			case 0x56:										//Greek letter Ο
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x9F;
				write(outputFile, &outputChar, 1);
				break;
			case 0x57:										//Greek letter Π
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA0;
				write(outputFile, &outputChar, 1);
				break;
			case 0x58:										//Greek letter Ρ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA1;
				write(outputFile, &outputChar, 1);
				break;
			case 0x59:										//Greek letter Σ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA3;
				write(outputFile, &outputChar, 1);
				break;
			case 0x5A:										//Right bracket ]
				outputChar =0x5D;
				write(outputFile, &outputChar, 1);
				break;
			case 0x5B:										//Dollar sign $
				outputChar =0x24;
				write(outputFile, &outputChar, 1);
				break;
			case 0x5C:										//Asterisk *
				outputChar =0x2A;
				write(outputFile, &outputChar, 1);
				break;
			case 0x5D:										//Right parenthesis )
				outputChar =0x29;
				write(outputFile, &outputChar, 1);
				break;
			case 0x5E:										//Semi colon ;
				outputChar =0x3B;
				write(outputFile, &outputChar, 1);
				break;
			case 0x5F:										//Circumflex ^
				outputChar =0x5E;
				write(outputFile, &outputChar, 1);
				break;
			case 0x60:										//Minus sign -
				outputChar =0x2D;
				write(outputFile, &outputChar, 1);
				break;
			case 0x61:										//Slash /
				outputChar =0x2F;
				write(outputFile, &outputChar, 1);
				break;
			case 0x62:										//Greek letter Τ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA4;
				write(outputFile, &outputChar, 1;
				break;
			case 0x63:										//Greek letter Υ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA5;
				write(outputFile, &outputChar, 1);
				break;
			case 0x64:										//Greek letter Φ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA6;
				write(outputFile, &outputChar, 1);
				break;
			case 0x65:										//Greek letter Χ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA7;
				write(outputFile, &outputChar, 1);
				break;
			case 0x66:										//Greek letter Ψ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA8;
				write(outputFile, &outputChar, 1);
				break;
			case 0x67:										//Greek letter Ω
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xA9;
				write(outputFile, &outputChar, 1);
				break;
			case 0x68:										//Greek letter Ϊ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xAA;
				write(outputFile, &outputChar, 1);
				break;
			case 0x69:										//Greek letter Ϋ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xAB;
				write(outputFile, &outputChar, 1);
				break;
			case 0x6A:										//Vertical bar |
				outputChar =0x7C;
				write(outputFile, &outputChar, 1);
				break;
			case 0x6B:										//Comma ,
				outputChar =0x2C;
				write(outputFile, &outputChar, 1);
				break;
			case 0x6C:										//Percent sign %
				outputChar =0x25;
				write(outputFile, &outputChar, 1);
				break;
			case 0x6D:										//Underscore
				outputChar =0x57;
				write(outputFile, &outputChar, 1);
				break;
			case 0x6E:										//Greater than sign >
				outputChar =0x3E;
				write(outputFile, &outputChar, 1);
				break;
			case 0x6F:										//Question mark ?
				outputChar =0x3F;
				write(outputFile, &outputChar, 1);
				break;
			case 0x70:										//Umlaut ¨
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xA8;
				write(outputFile, &outputChar, 1);
				break;
			case 0x71:										//Greek letter Ά
				outputChar =0xC3;
				write(outputFile, &outputChar, 1);
				outputChar =0x86;
				write(outputFile, &outputChar, 1);
				break;
			case 0x72;										//Greek letter Έ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x88;
				write(outputFile, &outputChar, 1);
				break;
			case 0x73:										//Greek letter Ή
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x89);
				write(outputFile, &outputChar, 1);
				break;
			case 0x74:										//Non break space (RSP)
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xA0;
				write(outputFile, &outputChar, 1);
				break;
			case 0x75:										//Greek letter Ί
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x8A;
				write(outputFile, &outputChar, 1);
				break;
			case 0x76:										//Greek letter Ό
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x8C;
				write(outputFile, &outputChar, 1);
				break;
			case 0x77:										//Greek letter Ύ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x8E;
				write(outputFile, &outputChar, 1);
				break;
			case 0x78:										//Greek letter Ώ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x8F;
				write(outputFile, &outputChar, 1);
				break;
			case 0x79:										//Grave accent `
				outputChar =0x60;
				write(outputFile, &outputChar, 1);
				break;
			case 0x7A:										//Colon :
				outputChar =0x3A;
				write(outputFile, &outputChar, 1);
				break;
			case 0x7B:										//Number sign #
				outputChar =0x23;
				write(outputFile, &outputChar, 1);
				break;
			case 0x7C:										//At sign @
				outputChar =0x40;
				write(outputFile, &outputChar, 1);
				break;
			case 0x7D:										//Apostrophe '
				outputChar =0x27;
				write(outputFile, &outputChar, 1);
				break;
			case 0x7E:										//Equality sign =
				outputChar =0x3D;
				write(outputFile, &outputChar, 1);
				break;
			case 0x7F:										//Quotation marks "
				outputChar =0x22;
				write(outputFile, &outputChar, 1);
				break;                                                                                                             
			case 0x80:										//Whatever this is ΅
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x85;
				write(outputFile, &outputChar, 1);
				break;
			case 0x81:										//Latin letter a
				outputChar =0x61;
				write(outputFile, &outputChar, 1);
				break;
			case 0x82:										//Latin letter b
				outputChar =0x62;
				write(outputFile, &outputChar, 1);
				break;
			case 0x83:										//Latin letter c
				outputChar =0x63;
				write(outputFile, &outputChar, 1);
				break;
			case 0x84:										//Latin letter d
				outputChar =0x64;
				write(outputFile, &outputChar, 1);
				break;
			case 0x85:										//Latin letter e
				outputChar =0x65;
				write(outputFile, &outputChar, 1);
				break;
			case 0x86:										//Latin letter f
				outputChar =0x66;
				write(outputFile, &outputChar, 1);
				break;
			case 0x87:										//Latin letter g
				outputChar =0x67;
				write(outputFile, &outputChar, 1);
				break;
			case 0x88:										//Latin letter h
				outputChar =0x68;
				write(outputFile, &outputChar, 1);
				break;
			case 0x89:										//Latin letter i
				outputChar =0x69;
				write(outputFile, &outputChar, 1);
				break;
			case 0x8A:										//Greek letter α
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB1;
				write(outputFile, &outputChar, 1);
				break;
			case 0x8B:										//Greek letter β
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB2;
				write(outputFile, &outputChar, 1);
				break;                                                                                                             
			case 0x8C:										//Greek letter γ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB3;
				write(outputFile, &outputChar, 1);
				break;
			case 0x8D:										//Greek letter δ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB4;
				write(outputFile, &outputChar, 1);
				break;
			case 0x8E:										//Greek letter ε
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB5;
				write(outputFile, &outputChar, 1);
				break;
			case 0x8F:										//Greek letter ζ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB6;
				write(outputFile, &outputChar, 1);
				break;
			case 0x90:										//Degree symbol °
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xB0;
				write(outputFile, &outputChar, 1);
				break;
			case 0x91:										//Latin letter j
				outputChar =0x6A;
				write(outputFile, &outputChar, 1);
				break;
			case 0x92:										//Latin letter k
				outputChar =0x6B;
				write(outputFile, &outputChar, 1);
				break;
			case 0x93:										//Latin letter l
				outputChar =0x6C;
				write(outputFile, &outputChar, 1);
				break;
			case 0x94:										//Latin letter m
				outputChar =0x6D;
				write(outputFile, &outputChar, 1);
				break;
			case 0x95:										//Latin letter n
				outputChar =0x6E;
				write(outputFile, &outputChar, 1);
				break;
			case 0x96:										//Latin letter o
				outputChar =0x6F;
				write(outputFile, &outputChar, 1);
				break;
			case 0x97:										//Latin letter p
				outputChar =0x70;
				write(outputFile, &outputChar, 1);
				break;
			case 0x98:										//Latin letter q
				outputChar =0x71;
				write(outputFile, &outputChar, 1);
				break;
			case 0x99:										//Latin letter r
				outputChar =0x72;
				write(outputFile, &outputChar, 1);
				break;
			case 0x9A:										//Greek letter η
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB7;
				write(outputFile, &outputChar, 1);
				break;
			case 0x9B:										//Greek letter θ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB8;
				write(outputFile, &outputChar, 1);
				break;
			case 0x9C:										//Greek letter ι
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB9;
				write(outputFile, &outputChar, 1);
				break;
			case 0x9D:										//Greek letter κ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xBA;
				write(outputFile, &outputChar, 1);
				break;
			case 0x9E:										//Greek letter λ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xBB;
				write(outputFile, &outputChar, 1);
				break;
			case 0x9F:										//Greek letter μ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xBC;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA0:										//Acute accent ´
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xB4;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA1:										//tidle ~
				outputChar =0x7E;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA2:										//Latin letter s
				outputChar =0x73;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA3:										//Latin letter t
				outputChar =0x74;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA4:										//Latin letter u
				outputChar =0x75;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA5:										//Latin letter v
				outputChar =0x76;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA6:										//Latin letter w
				outputChar =0x77;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA7:										//Latin letter x
				outputChar =0x78;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA8:										//Latin letter y
				outputChar =0x79;
				write(outputFile, &outputChar, 1);
				break;
			case 0xA9:										//Latin letter z
				outputChar =0x7A;
				write(outputFile, &outputChar, 1);
				break;
			case 0xAA:										//Greek letter ν
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xBD;
				write(outputFile, &outputChar, 1);
				break;
			case 0xAB:										//Greek letter ξ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xBE;
				write(outputFile, &outputChar, 1);
				break;
			case 0xAC:										//Greek letter ο
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xBF;
				write(outputFile, &outputChar, 1);
				break;
			case 0xAD:										//Greek letter π
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x80;
				write(outputFile, &outputChar, 1);
				break;
			case 0xAE:										//Greek letter ρ
				outputChar =0x03;
				write(outputFile, &outputChar, 1);
				outputChar =0xC1;
				write(outputFile, &outputChar, 1);
				break;
			case 0xAF:										//Greek letter σ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x81;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB0:										//Pound sign £
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xA3;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB1:										//Greek letter ά
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xAC;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB2:										//Greek letter έ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xAD;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB3:										//Greek letter ή
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xAE;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB4:										//Greek letter ϊ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x8A;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB5:										//Greek letter ί
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xAF;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB6:										//Greek letter ό
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x8C;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB7:										//Greek letter ύ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x8D;
				write(outputFile, &outputChar, 1);
				break;                                                                                                             
			case 0xB8:										//Greek letter ϋ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x8B;
				write(outputFile, &outputChar, 1);
				break;
			case 0xB9:										//Greek letter ώ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x8E;
				write(outputFile, &outputChar, 1);
				break;
			case 0xBA:										//Greek letter ς
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x82;
				write(outputFile, &outputChar, 1);
				break;
			case 0xBB:										//Greek letter τ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x84;
				write(outputFile, &outputChar, 1);
				break;
			case 0xBC:										//Greek letter υ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x85;
				write(outputFile, &outputChar, 1);
				break;
			case 0xBD:										//Greek letter φ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x86;
				write(outputFile, &outputChar, 1);
				break;
			case 0xBE:										//Greek letter χ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x87;
				write(outputFile, &outputChar, 1);
				break;
			case 0xBF:										//Greek letter ψ
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x88;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC0:										//Left curly bracket {
				outputChar =0x7B;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC1;										//Latin letter A
				outputChar =0x41;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC2:										//Latin letter B
				outputChar =0x42;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC3:										//Latin letter C
				outputChar =0x43;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC4:										//Latin letter D
				outputChar =0x44;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC5:										//Latin letter E
				outputChar =0x45;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC6:										//Latin letter F
				outputChar =0x46;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC7:										//Latin letter G
				outputChar =0x47;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC8:										//Latin letter H
				outputChar =0x48;
				write(outputFile, &outputChar, 1);
				break;
			case 0xC9:										//Latin letter I
				outputChar =0x49;
				write(outputFile, &outputChar, 1);
				break;
			case 0xCA:										//Soft hyphen (SHY)
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xAD;
				write(outputFile, &outputChar, 1);
				break;
			case 0xCB:										//Greek letter ω
				outputChar =0xCF;
				write(outputFile, &outputChar, 1);
				outputChar =0x89;
				write(outputFile, &outputChar, 1);
				break;
			case 0xCC:										//Greek letter ΐ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x90;
				write(outputFile, &outputChar, 1);
				break;
			case 0xCD:										//Greek letter ΰ
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0xB0;
				write(outputFile, &outputChar, 1);
				break;
			case 0xCE:										//Quotation marks ‘
				outputChar =0xE2;
				write(outputFile, &outputChar, 1);
				outputChar =0x80;
				write(outputFile, &outputChar, 1);
				outputChar =0x98;
				write(outputFile, &outputChar, 1);
				break;
			case 0xCF:										//Dash ―
				outputChar =0xE2;
				write(outputFile, &outputChar, 1);
				outputChar =0x80;
				write(outputFile, &outputChar, 1);
				outputChar =0x95;
				break;
			case 0xD0;										//Right curly bracket }
				outputChar =0x7D;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD1:										//Latin letter J
				outputChar =0x4A;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD2:										//Latin letter K
				outputChar =0x4B;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD3:										//Latin letter L
				outputChar =0x4C;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD4:										//Latin letter M
				outputChar =0x4D;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD5:										//Latin letter N
				outputChar =0x4E;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD6:										//Latin letter O
				outputChar =0x4F;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD7:										//Latin letter P
				outputChar =0x50;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD8:										//Latin letter Q
				outputChar =0x51;
				write(outputFile, &outputChar, 1);
				break;
			case 0xD9:										//Latin letter R
				outputChar =0x52;
				write(outputFile, &outputChar, 1);
				break;
			case 0xDA:										//Plus minus sign ±
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xB1;
				write(outputFile, &outputChar, 1);
				break;
			case 0xDB:										//One half ½
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xBD;
				write(outputFile, &outputChar, 1);
				break;
			case 0xDD:										//Interpunct ·
				outputChar =0xCE;
				write(outputFile, &outputChar, 1);
				outputChar =0x87;
				write(outputFile, &outputChar, 1);
				break;
			case 0xDE:										//Quotation marks ’
				outputChar =0xE2;
				write(outputFile, &outputChar, 1);
				outputChar =0x80;
				write(outputFile, &outputChar, 1);
				outputChar =0x99;
				write(outputFile, &outputChar, 1);
				break;
			case 0xDF:										//Vertical bar ¦
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xA6;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE0:										/*Backslash \ */
				outputChar =0x5C;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE1:										//Drachma sign ₯
				outputChar =0xE2;
				write(outputFile, &outputChar, 1);
				outputChar =0x82;
				write(outputFile, &outputChar, 1);
				outputChar =0xAF;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE2:										//Latin letter S
				outputChar =0x53;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE3:										//Latin letter T
				outputChar =0x54;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE4:										//Latin letter U
				outputChar =0x55;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE5:										//Latin letter V
				outputChar =0x56;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE6:										//Latin letter W
				outputChar =0x57;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE7:										//Latin letter X
				outputChar =0x58;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE8:										//Latin letter Y
				outputChar =0x59;
				write(outputFile, &outputChar, 1);
				break;
			case 0xE9:										//Latin letter Z
				outputChar =0x5A;
				write(outputFile, &outputChar, 1);
				break;
			case 0xEA:										//Square power of two ²
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xB2;
				write(outputFile, &outputChar, 1);
				break;
			case 0xEB:										//Section sign §
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xA7;
				write(outputFile, &outputChar, 1);
				break;
			case 0xEC:										//Iota subscript υπογεγραμμένη ͺ
				outputChar =0xCD;
				write(outputFile, &outputChar, 1);
				outputChar =0xBA;
				write(outputFile, &outputChar, 1);
				break;
			case 0xEE:										//Carets «
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xAB;
				write(outputFile, &outputChar, 1);
				break;
			case 0xEF:										//Negation, logical complement ¬
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xAC;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF0:										//Number 0
				outputChar =0x30;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF1:										//Number 1
				outputChar =0x31;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF2:										//Number 2
				outputChar =0x32;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF3:										//Number 3
				outputChar =0x33;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF4:										//Number 4
				outputChar =0x34;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF5:										//Number 5
				outputChar =0x35;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF6:										//Number 6
				outputChar =0x36;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF7:										//Number 7
				outputChar =0x37;
				write(outputFile, &outputChar, 1;
				break;
			case 0xF8:										//Number 8
				outputChar =0x38;
				write(outputFile, &outputChar, 1);
				break;
			case 0xF9:										//Number 9
				outputChar =0x39;
				write(outputFile, &outputChar, 1);
				break;
			case 0xFA:										//Cube, power of 3 ³
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xB3;
				write(outputFile, &outputChar, 1);
				break;
			case 0xFB:										//Copyright symbol ©
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xA9;
				write(outputFile, &outputChar, 1);
				break;
			case 0xFC:										//Euro sign €
				outputChar =0xE2;
				write(outputFile, &outputChar, 1);
				outputChar =0x82;
				write(outputFile, &outputChar, 1);
				outputChar =0xAC;
				write(outputFile, &outputChar, 1);
				break;
			case 0xFE:										//Carets »
				outputChar =0xC2;
				write(outputFile, &outputChar, 1);
				outputChar =0xBB;
				write(outputFile, &outputChar, 1);
				break;
			default:
				write(outputFile, &inputChar, 1);
		}
	}
	close(fdin);
	close(outputFile);
	return 0;                                                                                                             
}                                                                                                                       
