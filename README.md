# Password_Generator

A simple password generator in C, that generates password displays it and stores in a file.

## Usage

Make the file password executable or compile the file password.c.

Run the "password" file with 2 arguments.

./password {name} {filename_to_store}

Eg: ./password xyz.com password.txt

***Inside password.txt*** :

xyz.com - ***generated password***

If the file is not present a new file is created. Else the password is appended to the file.
