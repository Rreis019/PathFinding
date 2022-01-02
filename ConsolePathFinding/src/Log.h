
#define DEBUG 1

#ifdef DEBUG
    #define DEBUG_PRINT(...) printf(__VA_ARGS__)
    #define DEBUG_PRINT_VAR(x) printf("%s = %d\n",#x,x)
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINT_VAR(x)
#endif


