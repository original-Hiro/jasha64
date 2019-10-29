#include <iostream>
#include <cstdio>
#include <elf.h>
using std::cout; using std::endl;

/*
unsigned char Read_8()
{
	unsigned char c;
	scanf("%c", &c);
	return c;
}
uint16_t Read_16() //Elf64_Half
{
	union {
		unsigned char c[2];
		uint16_t r;
	};
	scanf("%c%c", &c[0], &c[1]);
	return r;
}
uint32_t Read_32() //Elf64_Word
{
	union {
		unsigned char c[4];
		uint32_t r;
	};
	scanf("%c%c%c%c", &c[0], &c[1], &c[2], &c[3]);
	return r;
}
uint64_t Read_64() //Elf64_Addr Elf64_Off
{
	
}
*/
const char* Class[] = {"Invalid", "ELF32", "ELF64"};
const char* Data[] = {"Invalid", "2's complement, little endian", "2's complement, big endian"};
const char* Type[] = {"NONE", "REL (Relocatable file)", "EXEC (Executable file)", "DYN (Shared object file)", "CORE (Core file)"};

int main()
{
	//freopen("main.o", "r", stdin);
	Elf64_Ehdr eh;
	FILE* fin = fopen("main.o", "r");
	fread(&eh, sizeof(Elf64_Ehdr), 1, fin);

	cout << "ELF Header:" << endl;
	cout << '\t' << "Magic:";
	for (int i = 0; i < EI_NIDENT; i++) printf(" %02x", eh.e_ident[i]);
	cout << endl;
	cout << '\t' << "Class: " << Class[eh.e_ident[4]] << endl;
	cout << '\t' << "Data: " << Data[eh.e_ident[5]] << endl;
	cout << "\t" << "Version: 1 (current)" << endl;
	printf("\tOS/ABI: %x\n", eh.e_ident[7]);
	printf("\tABI Version: %x\n", eh.e_ident[8]);
	cout << '\t' << "Type: " << Type[eh.e_type] << endl;
	cout << '\t' << "Machine: " << eh.e_machine << endl;
	printf("\tVersion: 0x%x\n", eh.e_version);
	printf("\tEntry point address: 0x%lx\n", eh.e_entry);
	cout << '\t' << "Start of program headers: " << eh.e_phoff << " (bytes into file)" << endl;
	cout << '\t' << "Start of section headers: " << eh.e_shoff << " (bytes into file)" << endl;
	printf("\tFlags: 0x%x\n", eh.e_flags);
	cout << '\t' << "Size of this header: " << eh.e_ehsize << " (bytes)" << endl;
	cout << '\t' << "Size of program headers: " << eh.e_phentsize << " (bytes)" << endl;
	cout << '\t' << "Number of program headers: " << eh.e_phnum << endl;
	cout << '\t' << "Size of section headers: " << eh.e_shentsize << " (bytes)" << endl;
	cout << '\t' << "Number of section headers: " << eh.e_shnum << endl;
	cout << '\t' << "Section header string table index: " << eh.e_shstrndx << endl;

	return 0;
}

