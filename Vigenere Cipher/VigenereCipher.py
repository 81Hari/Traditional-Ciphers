class VigenereCipher:
    def __init__(self):
        self.plain_text = ""
        self.cipher_text = ""
        self.key_stream = ""

    def encrypt(self):
        self.plain_text = input("\nEnter Plain Text: ")
        self.key_stream = input("\nEnter Key Stream: ")
        self.key_stream = self.key_stream.upper()
        for i in range(len(self.plain_text)):

            j = i % len(self.key_stream)

            if (ord(self.plain_text[i])>=65 and ord(self.plain_text[i])<=90):
                p = ord(self.plain_text[i])-65
                c = p + ord(self.key_stream[j]) - 65
                c = (c%26)
                c = c + 65

            elif (ord(self.plain_text[i])>=97 and ord(self.plain_text[i])<=122):
                p = ord(self.plain_text[i])-97
                c = p + ord(self.key_stream[j]) - 65
                c = (c%26)
                c = c + 97

            else:
                print("Invalid plain_text")

            self.cipher_text = self.cipher_text + chr(c)
        print("Cipher Text: " + self.cipher_text)


    def decrypt(self):
        self.cipher_text = input("\nEnter Cipher Text: ")
        self.key_stream = input("\nEnter Key Stream: ")
        self.key_stream = self.key_stream.upper()
        for i in range(len(self.cipher_text)):

            j = i % len(self.key_stream)

            if (ord(self.cipher_text[i])>=65 and ord(self.cipher_text[i])<=90):
                c = ord(self.cipher_text[i])-65
                p = c - ord(self.key_stream[j]) - 65
                p = (p%26)
                p = p + 65

            elif (ord(self.cipher_text[i])>=97 and ord(self.cipher_text[i])<=122):
                c = ord(self.cipher_text[i])-97
                p = c - ord(self.key_stream[j]) - 65
                p = (p%26)
                p = p + 97

            else:
                print("Invalid plain_text")

            self.plain_text = self.plain_text + chr(p)
        print("Plain Text: " + self.plain_text)






def main():

    print("\t\t VIGENERE CIPHER")

    print("1. Encrypt")
    print("2.Decrypt")

    ch = int(input("\nEnter the Service Number: "))

    VC = VigenereCipher()


    if ch == 1:
        VC.encrypt()
    elif ch == 2:
        VC.decrypt()
    else:
        print("Invalid input")


if __name__ == '__main__':
    main()

