# TENENC
Tenenc is a simple encoding algorithm designed to help users understand the fundamentals of encoding and decoding text. It provides a straightforward approach to transforming characters into a different format, making it an excellent educational tool.

# Algorithm Overview
The Tenenc algorithm operates by converting each character into its ASCII value, manipulating that value, and then formatting it for storage or transmission. Below, we will walk through the encoding and decoding processes with an example.

- ## Encoding Process

    - Input String: The algorithm starts with an input string. For example, let's encrypt the string "Hello".
    Character to ASCII Conversion: Each character in the string is converted to its corresponding ASCII value.
        - H → 72
        - e → 101
        - l → 108
        - l → 108
        - o → 111
    - Manipulation: Each ASCII value is multiplied by 10.
        - 72 * 10 = 720
        - 101 * 10 = 1010
        - 108 * 10 = 1080
        - 108 * 10 = 1080
        - 111 * 10 = 1110
    - Formatting: The resulting values are formatted to ensure they are always four digits long by padding with leading zeros if necessary.
        - 720 → 0720
        - 1010 → 1010
        - 1080 → 1080
        - 1080 → 1080
        - 1110 → 1110
    - Final Encoded String: The encoded values are concatenated to form the final encoded string.
        Encoded result for "Hello": "07201010108010801110"

- ## Decoding Process
    - Input Encoded String: Start with the encoded string obtained from the encoding process, e.g., "07201010108010801110".
    - Extracting Values: The encoded string is processed in chunks of four characters.
        Extracted values: 0720, 1010, 1080, 1080, 1110
    - Reversing Manipulation: Each extracted value is divided by 10 to retrieve the original ASCII values.
        - 0720 / 10 = 72
        - 1010 / 10 = 101
        - 1080 / 10 = 108
        - 1080 / 10 = 108
        - 1110 / 10 = 111
    - Character Conversion: Convert each ASCII value back to its corresponding character.
        - 72 → H
        - 101 → e
        - 108 → l
        - 108 → l
        - 111 → o
    - Final Decoded String: Concatenate the characters to form the original string.
        Decoded result: "Hello"

# Usage
To use the Tenenc algorithm, compile the main.cpp file and execute it with commands:

```
./a.out [-encrypt/-decrypt] [text/filename] -out output_filename
```

## Command-Line Arguments

- encrypt: Specifies that you want to encode the provided text or file.
- decrypt: Specifies that you want to decode the provided text or file.
- text/filename: The text you want to encode/decode or the path to a file containing that text.
- out output_filename: Specifies a filename where the output will be saved.
