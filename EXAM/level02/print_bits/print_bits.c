# include <unistd.h>


void	print_bits(unsigned char octet)
{
    // unsigned char size = 1byte(8 bits) (0 - 255) ---> 256(overflow)
    // 2 ---->  0 0 0 0 0 0 1 0
    // i = 128 octet >= 0 i == true
    // octet / i == true? ----> write(1) octet -= i : write(0) i /= 2 [64 32 16 8 4 2 1]

    int i = 128;
    while(octet >= 0 && i) // octet = 42 // 0 0 1 0 1 0 1 0
    {
        if(octet / i)
        {
            write(1, "1", 1);
            octet -= i;
        }
        else{
            write(1, "0", 1);
        }
        i /= 2;
    }
}
int main()
{
    print_bits(256); // 0 0 1 0 1 0 1 0 // [(0 0 1 0 1 0 1 0)] == 1 byte 2 + 8 + 32 = 42
    write(1, "\n", 1);
}
