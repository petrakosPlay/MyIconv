/*Reads from a file with EBCDIC encoding (IBM CCSID 875) from IFS
  and creates a new copy of the file converted to UTF-8 encoding.
  Some characters are not used and some are exactly the same as in
  UTF-8. They appear in the program just for reference. */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char **argv)
{
    int inputFile, outputFile, i, j, bytesRead, bytesWritten, bytesToWrite;
    char *inputFilePath, *outputFilePath;
    unsigned char inputChar, outputChar;
    unsigned char inputCharBuf[16384], outputCharBuf[32768];
    bytesRead = bytesWritten = 0;
    inputFilePath = outputFilePath = NULL;
    int n1 = strlen(*(argv+1));
    int n2 = strlen(*(argv+2));
    inputFilePath  = malloc(n1+1 * sizeof(char));
    outputFilePath = malloc(n2+1 * sizeof(char));
    memset(inputFilePath,  '\0', n1+1);
    memset(outputFilePath, '\0', n2+1);
    strncpy(inputFilePath,  *(argv+1), n1);
    strncpy(outputFilePath, *(argv+2), n2);

    if( (inputFile  = open(inputFilePath, O_RDONLY)) == -1)   return -1;
    if( (outputFile = open(outputFilePath, O_WRONLY | O_CREAT | O_TRUNC, 0666))
                                                            == -1)  return -1;

    while ( (bytesRead = read(inputFile, inputCharBuf, 16384)) > 0)
    {
        j=0;
        for (i=0; i < bytesRead; ++i)
        {
            inputChar = inputCharBuf[i];
            switch(inputChar)
            {
// 0
//              case 0x00:                      //Null (NUL)
//                  outputCharBuf[j++] =0xE2;
//                  outputCharBuf[j++] =0x90;
//                  outputCharBuf[j++] =0x80;
//                  break;
//              case 0x01:                      //Start of Heading (SOH)
//                  break;
//              case 0x02:                      //Start of Text (STX)
//                  break;
//              case 0x03:                      //End of Text (ETX)
//                  break;
//              case 0x04:                      //Not used
//                  break;
                case 0x05:                      //horizontal tab (HT)
                    outputCharBuf[j++] = 0x09;
                    break;
//              case 0x06:                      //Not used
//                  break;
                case 0x07:                      //Delete character (DEL)
                    outputCharBuf[j++] = 0x7F;
                    break;
//              case 0x08:                      //Not used
//                  break;
//              case 0x09:                      //Not used
//                  break;
//              case 0x0A:                      //Not used
//                  break;
//              case 0x0B:                      //Vertical Tabulation (VT)
//                  break;
//              case 0x0C:                      //Form Feed (FF)
//                  break;
//              case 0x0D:                      //Carriage return (CR)
//                  break;
//              case 0x0E:                      //Shift Out (SO)
//                  break;
//              case 0x0F:                      //Shift In (SI)
//                  break;
// 1
//              case 0x10:                      //Data Link Escape (DLE)
//                  break;
//              case 0x11:                      //Device Control One (DC1)
//                  break;
//              case 0x12:                      //Device Control Two (DC2)
//                  break;
//              case 0x13:                      //Device Control Three (DC3)
//                  break;
//              case 0x14:                      //Not used
//                  break;
                case 0x15:                      //Newline (NL)
                    outputCharBuf[j++] = 0xC2;
                    outputCharBuf[j++] = 0x85;
                    break;
                case 0x16:                      //Backspace (BS)
                    outputCharBuf[j++] = 0x08;
                    break;
//              case 0x17:                      //Not used
//                  break;
//              case 0x18:                      //Cancel (CAN)
//                  break;
//              case 0x19:                      //End of Medium (EM)
//                  break;
//              case 0x1A:                      //Not used
//                  break;
//              case 0x1B:                      //Not used
//                  break;
//              case 0x1C:                      //File Separator (FS)
//                  break;
//              case 0x1D:                      //Group Separator (GS)
//                  break;
//              case 0x1E:                      //Record Separator (RS)
//                  break;
//              case 0x1F:                      //Unit Separator (US)
//                  break;
//2
//              case 0x20:                      //Not used
//                  break;
//              case 0x21:                      //Not used
//                  break;
//              case 0x22:                      //File Separator (FS)
//                  outputCharBuf[j++] =0x1C;
//                  break;
//              case 0x23:                      //Not used
//                  break;
//              case 0x24:                      //Not used
//                  break;
                case 0x25:                      //Line feed or line break (LF)
                    outputCharBuf[j++] =0x0A;
                    break;
                case 0x26:         //End of transmission block character (ETB)
                    outputCharBuf[j++] =0x17;
                    break;
                case 0x27:                      //Escape (ESC)
                    outputCharBuf[j++] =0x1B;
                    break;
//              case 0x28:                      //Not used
//                  break;
//              case 0x29:                      //Not used
//                  break;
//              case 0x2A:                      //Not used
//                  break;
//              case 0x2B:                      //Not used
//                  break;
//              case 0x2C:                      //Not used
//                  break;
                case 0x2D:                      //Enquiry (ENQ)
                    outputCharBuf[j++] =0x05;
                    break;
                case 0x2E:                      //Acknowledgement (ACK)
                    outputCharBuf[j++] =0x06;
                    break;
                case 0x2F:                      //Bell code (BEL)
                    outputCharBuf[j++] =0x07;
                    break;
//3
//              case 0x30:                      //Not used
//                  break;
//              case 0x31:                      //Not used
//                  break;
                case 0x32:                      //Synchronous idle (SYN)
                    outputCharBuf[j++] =0x16;
                    break;
//              case 0x33:                      //Not used
//                  break;
//              case 0x34:                      //Not used
//                  break;
//              case 0x35:                      //Not used
//                  break;
//              case 0x36:                      //???
//                  break;
                case 0x37:                      //End of transmission (EOT)
                    outputCharBuf[j++] =0x04;
                    break;
//              case 0x38:                      //Not used
//                  break;
//              case 0x39:                      //Not used
//                  break;
//              case 0x3A:                      //Not used
//                  break;
//              case 0x3B:                      //Not used
//                  break;
                case 0x3C:                      //C0 and C1 control code (DC4)
                    outputCharBuf[j++] =0x14;
                    break;
                case 0x3D:            //negative acknowledgement (NAK or NACK)
                    outputCharBuf[j++] =0x15;
                    break;
//              case 0x3E:                      //Not used
//                  break;
                case 0x3F:                      //Substitute character (SUB)
                    outputCharBuf[j++] =0x1A;
                    break;
//4
                case 0x40:                      //Whitespace (SP)
                    outputCharBuf[j++] =0x20;
                    break;
                case 0x41:                      //Greek letter Α
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x91;
                    break;
                case 0x42:                      //Greek letter Β
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x92;
                    break;
                case 0x43:                      //Greek letter Γ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x93;
                break;
                case 0x44:                      //Greek letter Δ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x94;
                    break;
                case 0x45:                      //Greek letter Ε
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x95;
                    break;
                case 0x46:                      //Greek letter Ζ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x96;
                    break;
                case 0x47:                      //Greek letter Η
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x97;
                    break;
                case 0x48:                      //Greek letter Θ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x98;
                    break;
                case 0x49:                      //Greek letter Ι
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x99;
                    break;
                case 0x4A:                      //Left bracket [
                    outputCharBuf[j++] =0x5B;
                    break;
                case 0x4B:                      //Period .
                    outputCharBuf[j++] =0x2E;
                    break;
                case 0x4C:                      //Less than sign <
                    outputCharBuf[j++] =0x3C;
                    break;
                case 0x4D:                      //Left parenthesis (
                    outputCharBuf[j++] =0x28;
                    break;
                case 0x4E:                      //Plus sign +
                    outputCharBuf[j++] =0x2B;
                    break;
                case 0x4F:                      //Exclamation mark !
                    outputCharBuf[j++] =0x21;
                    break;
//5
                case 0x50:                      //Ampersand &
                    outputCharBuf[j++] =0x26;
                    break;
                case 0x51:                      //Greek letter Κ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x9A;
                    break;
                case 0x52:                      //Greek letter Λ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x9B;
                    break;
                case 0x53:                      //Greek letter Μ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x9C;
                    break;
                case 0x54:                      //Greek letter Ν
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x9D;
                    break;
                case 0x55:                      //Greek letter Ξ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x9E;
                    break;
                case 0x56:                      //Greek letter Ο
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x9F;
                    break;
                case 0x57:                      //Greek letter Π
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA0;
                    break;
                case 0x58:                      //Greek letter Ρ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA1;
                    break;
                case 0x59:                      //Greek letter Σ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA3;
                    break;
                case 0x5A:                      //Right bracket ]
                    outputCharBuf[j++] =0x5D;
                    break;
                case 0x5B:                      //Dollar sign $
                    outputCharBuf[j++] =0x24;
                    break;
                case 0x5C:                      //Asterisk *
                    outputCharBuf[j++] =0x2A;
                    break;
                case 0x5D:                      //Right parenthesis )
                    outputCharBuf[j++] =0x29;
                    break;
                case 0x5E:                      //Semi colon ;
                    outputCharBuf[j++] =0x3B;
                    break;
                case 0x5F:                      //Circumflex ^
                    outputCharBuf[j++] =0x5E;
                    break;
//6
                case 0x60:                      //Minus sign -
                    outputCharBuf[j++] =0x2D;
                    break;
                case 0x61:                      //Slash /
                    outputCharBuf[j++] =0x2F;
                    break;
                case 0x62:                      //Greek letter Τ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA4;
                    break;
                case 0x63:                      //Greek letter Υ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA5;
                    break;
                case 0x64:                      //Greek letter Φ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA6;
                    break;
                case 0x65:                      //Greek letter Χ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA7;
                    break;
                case 0x66:                      //Greek letter Ψ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA8;
                    break;
                case 0x67:                      //Greek letter Ω
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xA9;
                    break;
                case 0x68:                      //Greek letter Ϊ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xAA;
                    break;
                case 0x69:                      //Greek letter Ϋ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xAB;
                    break;
                case 0x6A:                      //Vertical bar |
                    outputCharBuf[j++] =0x7C;
                    break;
                case 0x6B:                      //Comma ,
                    outputCharBuf[j++] =0x2C;
                    break;
                case 0x6C:                      //Percent sign %
                    outputCharBuf[j++] =0x25;
                    break;
                case 0x6D:                      //Underscore
                    outputCharBuf[j++] =0x5F;
                    break;
                case 0x6E:                      //Greater than sign >
                    outputCharBuf[j++] =0x3E;
                    break;
                case 0x6F:                      //Question mark ?
                    outputCharBuf[j++] =0x3F;
                    break;
//7
                case 0x70:                      //Umlaut ¨
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xA8;
                    break;
                case 0x71:                      //Greek letter Ά
                    outputCharBuf[j++] =0xC3;
                    outputCharBuf[j++] =0x86;
                    break;
                case 0x72:                      //Greek letter Έ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x88;
                    break;
                case 0x73:                      //Greek letter Ή
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x89;
                    break;
                case 0x74:                      //Non break space (RSP)
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xA0;
                    break;
                case 0x75:                      //Greek letter Ί
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x8A;
                    break;
                case 0x76:                      //Greek letter Ό
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x8C;
                    break;
                case 0x77:                      //Greek letter Ύ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x8E;
                    break;
                case 0x78:                      //Greek letter Ώ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x8F;
                    break;
                case 0x79:                      //Grave accent `
                    outputCharBuf[j++] =0x60;
                    break;
                case 0x7A:                      //Colon :
                    outputCharBuf[j++] =0x3A;
                    break;
                case 0x7B:                      //Number sign #
                    outputCharBuf[j++] =0x23;
                    break;
                case 0x7C:                      //At sign @
                    outputCharBuf[j++] =0x40;
                    break;
                case 0x7D:                      //Apostrophe '
                    outputCharBuf[j++] =0x27;
                    break;
                case 0x7E:                      //Equality sign =
                    outputCharBuf[j++] =0x3D;
                    break;
                case 0x7F:                      //Quotation marks "
                    outputCharBuf[j++] =0x22;
                    break;
//8
                case 0x80:                      //Whatever this is ΅
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x85;
                    break;
                case 0x81:                      //Latin letter a
                    outputCharBuf[j++] =0x61;
                    break;
                case 0x82:                      //Latin letter b
                    outputCharBuf[j++] =0x62;
                    break;
                case 0x83:                      //Latin letter c
                    outputCharBuf[j++] =0x63;
                    break;
                case 0x84:                      //Latin letter d
                    outputCharBuf[j++] =0x64;
                    break;
                case 0x85:                      //Latin letter e
                    outputCharBuf[j++] =0x65;
                    break;
                case 0x86:                      //Latin letter f
                    outputCharBuf[j++] =0x66;
                    break;
                case 0x87:                      //Latin letter g
                    outputCharBuf[j++] =0x67;
                    break;
                case 0x88:                      //Latin letter h
                    outputCharBuf[j++] =0x68;
                    break;
                case 0x89:                      //Latin letter i
                    outputCharBuf[j++] =0x69;
                    break;
                case 0x8A:                      //Greek letter α
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB1;
                    break;
                case 0x8B:                      //Greek letter β
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB2;
                    break;
                case 0x8C:                      //Greek letter γ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB3;
                    break;
                case 0x8D:                      //Greek letter δ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB4;
                    break;
                case 0x8E:                      //Greek letter ε
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB5;
                    break;
                case 0x8F:                      //Greek letter ζ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB6;
                    break;
//9
                case 0x90:                      //Degree symbol °
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xB0;
                    break;
                case 0x91:                      //Latin letter j
                    outputCharBuf[j++] =0x6A;
                    break;
                case 0x92:                      //Latin letter k
                    outputCharBuf[j++] =0x6B;
                    break;
                case 0x93:                      //Latin letter l
                    outputCharBuf[j++] =0x6C;
                    break;
                case 0x94:                      //Latin letter m
                    outputCharBuf[j++] =0x6D;
                    break;
                case 0x95:                      //Latin letter n
                    outputCharBuf[j++] =0x6E;
                    break;
                case 0x96:                      //Latin letter o
                    outputCharBuf[j++] =0x6F;
                    break;
                case 0x97:                      //Latin letter p
                    outputCharBuf[j++] =0x70;
                    break;
                case 0x98:                      //Latin letter q
                    outputCharBuf[j++] =0x71;
                    break;
                case 0x99:                      //Latin letter r
                    outputCharBuf[j++] =0x72;
                    break;
                case 0x9A:                      //Greek letter η
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB7;
                    break;
                case 0x9B:                      //Greek letter θ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB8;
                    break;
                case 0x9C:                      //Greek letter ι
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB9;
                    break;
                case 0x9D:                      //Greek letter κ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xBA;
                    break;
                case 0x9E:                      //Greek letter λ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xBB;
                    break;
                case 0x9F:                      //Greek letter μ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xBC;
                    break;
//A
                case 0xA0:                      //Acute accent /
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xB4;
                    break;
                case 0xA1:                      //tidle ~
                    outputCharBuf[j++] =0x7E;
                    break;
                case 0xA2:                      //Latin letter s
                    outputCharBuf[j++] =0x73;
                    break;
                case 0xA3:                      //Latin letter t
                    outputCharBuf[j++] =0x74;
                    break;
                case 0xA4:                      //Latin letter u
                    outputCharBuf[j++] =0x75;
                    break;
                case 0xA5:                      //Latin letter v
                    outputCharBuf[j++] =0x76;
                    break;
                case 0xA6:                      //Latin letter w
                    outputCharBuf[j++] =0x77;
                    break;
                case 0xA7:                      //Latin letter x
                    outputCharBuf[j++] =0x78;
                    break;
                case 0xA8:                      //Latin letter y
                    outputCharBuf[j++] =0x79;
                    break;
                case 0xA9:                      //Latin letter z
                    outputCharBuf[j++] =0x7A;
                    break;
                case 0xAA:                      //Greek letter ν
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xBD;
                    break;
                case 0xAB:                      //Greek letter ξ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xBE;
                    break;
                case 0xAC:                      //Greek letter ο
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xBF;
                    break;
                case 0xAD:                      //Greek letter π
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x80;
                    break;
                case 0xAE:                      //Greek letter ρ
                    outputCharBuf[j++] =0x03;
                    outputCharBuf[j++] =0xC1;
                    break;
                case 0xAF:                      //Greek letter σ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x81;
                    break;
//B
                case 0xB0:                      //Pound sign £
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xA3;
                    break;
                case 0xB1:                      //Greek letter ά
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xAC;
                    break;
                case 0xB2:                      //Greek letter έ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xAD;
                    break;
                case 0xB3:                      //Greek letter ή
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xAE;
                    break;
                case 0xB4:                      //Greek letter ϊ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x8A;
                    break;
                case 0xB5:                      //Greek letter ί
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xAF;
                    break;
                case 0xB6:                      //Greek letter ό
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x8C;
                    break;
                case 0xB7:                      //Greek letter ύ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x8D;
                    break;
                case 0xB8:                      //Greek letter ϋ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x8B;
                    break;
                case 0xB9:                      //Greek letter ώ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x8E;
                    break;
                case 0xBA:                      //Greek letter ς
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x82;
                    break;
                case 0xBB:                      //Greek letter τ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x84;
                    break;
                case 0xBC:                      //Greek letter υ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x85;
                    break;
                case 0xBD:                      //Greek letter φ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x86;
                    break;
                case 0xBE:                      //Greek letter χ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x87;
                    break;
                case 0xBF:                      //Greek letter ψ
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x88;
                    break;
//C
                case 0xC0:                      //Left curly bracket {
                    outputCharBuf[j++] =0x7B;
                    break;
                case 0xC1:                      //Latin letter A
                    outputCharBuf[j++] =0x41;
                    break;
                case 0xC2:                      //Latin letter B
                    outputCharBuf[j++] =0x42;
                    break;
                case 0xC3:                      //Latin letter C
                    outputCharBuf[j++] =0x43;
                    break;
                case 0xC4:                      //Latin letter D
                    outputCharBuf[j++] =0x44;
                    break;
                case 0xC5:                      //Latin letter E
                    outputCharBuf[j++] =0x45;
                    break;
                case 0xC6:                      //Latin letter F
                    outputCharBuf[j++] =0x46;
                    break;
                case 0xC7:                      //Latin letter G
                    outputCharBuf[j++] =0x47;
                    break;
                case 0xC8:                      //Latin letter H
                    outputCharBuf[j++] =0x48;
                    break;
                case 0xC9:                      //Latin letter I
                    outputCharBuf[j++] =0x49;
                    break;
                case 0xCA:                      //Soft hyphen (SHY)
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xAD;
                    break;
                case 0xCB:                      //Greek letter ω
                    outputCharBuf[j++] =0xCF;
                    outputCharBuf[j++] =0x89;
                    break;
                case 0xCC:                      //Greek letter ΐ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x90;
                    break;
                case 0xCD:                      //Greek letter ΰ
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0xB0;
                    break;
                case 0xCE:                      //Quotation marks ‘
                    outputCharBuf[j++] =0xE2;
                    outputCharBuf[j++] =0x80;
                    outputCharBuf[j++] =0x98;
                    break;
                case 0xCF:                      //Dash ―
                    outputCharBuf[j++] =0xE2;
                    outputCharBuf[j++] =0x80;
                    outputCharBuf[j++] =0x95;
                    break;
//D
                case 0xD0:                      //Right curly bracket }
                    outputCharBuf[j++] =0x7D;
                    break;
                case 0xD1:                      //Latin letter J
                    outputCharBuf[j++] =0x4A;
                    break;
                case 0xD2:                      //Latin letter K
                    outputCharBuf[j++] =0x4B;
                    break;
                case 0xD3:                      //Latin letter L
                    outputCharBuf[j++] =0x4C;
                    break;
                case 0xD4:                      //Latin letter M
                    outputCharBuf[j++] =0x4D;
                    break;
                case 0xD5:                      //Latin letter N
                    outputCharBuf[j++] =0x4E;
                    break;
                case 0xD6:                      //Latin letter O
                    outputCharBuf[j++] =0x4F;
                    break;
                case 0xD7:                      //Latin letter P
                    outputCharBuf[j++] =0x50;
                    break;
                case 0xD8:                      //Latin letter Q
                    outputCharBuf[j++] =0x51;
                    break;
                case 0xD9:                      //Latin letter R
                    outputCharBuf[j++] =0x52;
                    break;
                case 0xDA:                      //Plus minus sign ±
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xB1;
                    break;
                case 0xDB:                      //One half ½
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xBD;
                    break;
    //          case 0xDC:                      //Not used
    //              break;
                case 0xDD:                      //Interpunct ·
                    outputCharBuf[j++] =0xCE;
                    outputCharBuf[j++] =0x87;
                    break;
                case 0xDE:                      //Quotation marks ’
                    outputCharBuf[j++] =0xE2;
                    outputCharBuf[j++] =0x80;
                    outputCharBuf[j++] =0x99;
                    break;
                case 0xDF:                      //Vertical bar ¦
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xA6;
                    break;
    //E
                case 0xE0:                      /*Backslash \ */
                    outputCharBuf[j++] =0x5C;
                    break;
                case 0xE1:                      //Drachma sign ?
                    outputCharBuf[j++] =0xE2;
                    outputCharBuf[j++] =0x82;
                    outputCharBuf[j++] =0xAF;
                    break;
                case 0xE2:                      //Latin letter S
                    outputCharBuf[j++] =0x53;
                    break;
                case 0xE3:                      //Latin letter T
                    outputCharBuf[j++] =0x54;
                    break;
                case 0xE4:                      //Latin letter U
                    outputCharBuf[j++] =0x55;
                    break;
                case 0xE5:                      //Latin letter V
                    outputCharBuf[j++] =0x56;
                    break;
                case 0xE6:                      //Latin letter W
                    outputCharBuf[j++] =0x57;
                    break;
                case 0xE7:                      //Latin letter X
                    outputCharBuf[j++] =0x58;
                    break;
                case 0xE8:                      //Latin letter Y
                    outputCharBuf[j++] =0x59;
                    break;
                case 0xE9:                      //Latin letter Z
                    outputCharBuf[j++] =0x5A;
                    break;
                case 0xEA:                      //Square power of two ²
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xB2;
                    break;
                case 0xEB:                      //Section sign §
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xA7;
                    break;
                case 0xEC:                      //Iota subscript υπογεγραμμένη ?
                    outputCharBuf[j++] =0xCD;
                    outputCharBuf[j++] =0xBA;
                    break;
                case 0xED:                      //Not used
                    break;
                case 0xEE:                      //Carets «
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xAB;
                    break;
                case 0xEF:                      //Negation, logical complement ¬
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xAC;
                    break;
//F
                case 0xF0:                      //Number 0
                    outputCharBuf[j++] =0x30;
                    break;
                case 0xF1:                      //Number 1
                    outputCharBuf[j++] =0x31;
                    break;
                case 0xF2:                      //Number 2
                    outputCharBuf[j++] =0x32;
                    break;
                case 0xF3:                      //Number 3
                    outputCharBuf[j++] =0x33;
                    break;
                case 0xF4:                      //Number 4
                    outputCharBuf[j++] =0x34;
                    break;
                case 0xF5:                      //Number 5
                    outputCharBuf[j++] =0x35;
                    break;
                case 0xF6:                      //Number 6
                    outputCharBuf[j++] =0x36;
                    break;
                case 0xF7:                      //Number 7
                    outputCharBuf[j++] =0x37;
                    break;
                case 0xF8:                      //Number 8
                    outputCharBuf[j++] =0x38;
                    break;
                case 0xF9:                      //Number 9
                    outputCharBuf[j++] =0x39;
                    break;
                case 0xFA:                      //Cube, power of 3 ³
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xB3;
                    break;
                case 0xFB:                      //Copyright symbol ©
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xA9;
                    break;
                case 0xFC:                      //Euro sign 
                    outputCharBuf[j++] =0xE2;
                    outputCharBuf[j++] =0x82;
                    outputCharBuf[j++] =0xAC;
                    break;
//              case 0xFD:                      //Not used
//                  break;
                case 0xFE:                      //Carets »
                    outputCharBuf[j++] =0xC2;
                    outputCharBuf[j++] =0xBB;
                    break;
//              case 0xFF:                      //Not used
//                  break;
                default:
                    outputCharBuf[j++] = inputChar;
            }
        }
        bytesToWrite = j;
        j=0;
        while(bytesToWrite > 0)
        {
            bytesWritten = write(outputFile, &outputCharBuf[j], bytesToWrite);
            bytesToWrite -= bytesWritten;
            j += bytesWritten;
        }

    }
    close(inputFile);
    close(outputFile);
    return 0;
}
