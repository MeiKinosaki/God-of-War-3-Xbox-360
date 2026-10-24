#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Tiny diagnostic probe; this does not call undocumented Xenon APIs. */
int main(void)
{
    const uint32_t marker = UINT32_C(0x01020304);
    const unsigned char *bytes = (const unsigned char *)&marker;
    const char *endian = bytes[0] == 0x01 ? "big" :
                         bytes[0] == 0x04 ? "little" : "unknown";
    printf("gow3-xenon-probe\n");
    printf("sizeof_pointer=%lu\n", (unsigned long)sizeof(void *));
    printf("sizeof_uint32=%lu\n", (unsigned long)sizeof(uint32_t));
    printf("endianness=%s\n", endian);
    printf("compiler=%s\n", __VERSION__);
#if defined(__powerpc__) || defined(__PPC__) || defined(_ARCH_PPC)
    printf("compiler_arch=powerpc-family\n");
#else
    printf("compiler_arch=not-identified-as-powerpc\n");
#endif
    return (sizeof(uint32_t) == 4U && strcmp(endian, "unknown") != 0) ? 0 : 1;
}
