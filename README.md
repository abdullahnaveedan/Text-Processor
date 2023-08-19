# Text Processor in C++

This project implements a Text Processor in C++ to perform various tasks on input paragraphs. The tasks include reading from and writing to files, displaying on the screen, checking paragraph equality, converting to uppercase/lowercase, character and word counting, encryption/decryption, spell checking, merging paragraphs, and compressing/decompressing using Huffman coding.
The project Divided into two parts just for the understanding. 
## Features

- Read a paragraph from a file using the `>>` operator.
- Write a paragraph to a file and display it on the screen using the `<<` operator.
- Check paragraph equality using the `==` and `!=` operators.
- Convert to uppercase/lowercase using unary operators `+` and `-`.
- Count English and Punctuation characters.
- Count characters in every word of each sentence.
- Count words in each paragraph and sentence.
- Encrypt/decrypt using unary operators `%` and `*`.
- Spell check against a given dictionary.
- Merge paragraphs using the `+` operator.
- Compress and decompress using Huffman coding using unary operators `!` and `^`.

## Task Breakdown

1. Define a `Paragraph` class with constructors, copy constructors, getters, and setters.
2. Implement assignment, equality, insertion, and extraction operators.
3. Divide the project into classes for better management.
4. Implement class definitions in separate `.h` files.
5. Provide class implementations in separate `.cpp` files.
6. Write a driver program to test the classes.
7. Generate a "Frequency.txt" output file containing paragraph, sentence, and word frequency.

## Requirements

- Use a 4-dimensional character array for storing paragraph text.
- Implement each task using appropriate operators and classes.
- Create separate classes for different entities.
- Implement functions for reading, writing, conversion, counting, etc.
- Provide appropriate comments and documentation for clarity.

Feel free to modify and enhance the code according to your needs.
