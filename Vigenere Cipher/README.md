# VIGENERE CIPHER

P --> PLAIN TEXT

C --> CIPHER TEXT

K --> KEY STREAM  E.G: (PASCAL, KEY, ect..)

i, j --> index

n --> length of plain and cipher text



j = i mod n

[ENCRYPT]

C[i] = P[i] + K[j]

[DECRYPT]

P[i] = C[i] - K[j] 
