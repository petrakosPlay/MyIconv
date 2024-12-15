import requests

# Step 1: Download the EBCDIC 875 to Unicode mapping from Unicode.org
url = "http://www.unicode.org/Public/MAPPINGS/VENDORS/MICSFT/EBCDIC/CP875.TXT"
response = requests.get(url)

# Step 2: Parse the mapping
ebcdic_to_utf8 = {}

#print(response.text)

# Go through each line in the file
for line in response.text.splitlines():
    # Ignore comments and empty lines
    if line.startswith("#") or not line.strip() or line.startswith('\x1A'):
        continue
    print(line)
    #hex_values = ' '.join(f'{ord(char):02X}' for char in line)
    #print(hex_values)
    #print("-----------")
    
    # Parse the line, it should have the format: "EBCDIC HEX -> Unicode HEX"
    parts = line.split()
    ebcdic_hex = parts[0]  # The EBCDIC byte in hexadecimal
    unicode_hex = parts[1]  # The corresponding Unicode code point

    # Convert the EBCDIC byte from hexadecimal to an integer
    ebcdic_byte = int(ebcdic_hex, 16)

    # Convert the Unicode code point from hexadecimal to an actual character
    unicode_char = chr(int(unicode_hex, 16))

    # Step 3: Convert the Unicode character to its UTF-8 byte sequence
    utf8_bytes = unicode_char.encode('utf-8')

    # Store the result in the dictionary
    ebcdic_to_utf8[ebcdic_byte] = utf8_bytes

# Step 4: Generate the C lookup table
print("typedef struct {")
print("    unsigned char utf8_bytes[4];")
print("    size_t length;")
print("} Utf8Char;")
print()
print("Utf8Char ebcdic_to_utf8[256] = {")

for i in range(256):
    utf8_bytes = ebcdic_to_utf8.get(i, b'\x00')  # Default to NULL if not found
    utf8_hex = ', '.join(f'0x{byte:02X}' for byte in utf8_bytes)
    length = len(utf8_bytes)

    print(f"    {{ {{ {utf8_hex} }}, {length} }},  // EBCDIC 0x{i:02X}")

print("};")
