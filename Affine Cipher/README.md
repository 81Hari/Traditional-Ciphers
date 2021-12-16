# AFFINE CIPHER

y --> cipher text

x --> plain text

(a,b) --> key pair

[ENCRYPT]

y = ((x*a) + b) mod 26 

[DECRYPT]

x = [(a^(-1)) * (y-b)] mod 26

For decryption we need to use inverse modulo concept
