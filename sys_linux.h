#include <sys/types.h>
#include <stdio.h>

#define DEVICE_NUMBER 2
#define RANDOM_DEVICE_NAME "/dev/random"
#define URANDOM_DEVICE_NAME "/dev/urandom"


#define enum_random 0
#define enum_urandom 1

#define resolve_device_name(_xenum_, _p_) \
	do { \
		if ( _xenum_ == enum_random ) \
			_p_ = RANDOM_DEVICE_NAME; \
		else \
		if ( _xenum_ == enum_urandom ) \
			_p_ = URANDOM_DEVICE_NAME; \
		else \
			_p_ = URANDOM_DEVICE_NAME; \
	} while(0) ;

int init_system_linux();
int close_system_linux();
/* return how many added */
size_t add_entropy(const void* ubuffer, size_t bytes);
/* return how many read */
size_t sample_from_device( void* pbuffer, size_t bytes, int devt);
int init_system();
size_t reseed_system(const void* ubuffer, size_t bytes);
size_t gather_random_fast(void* pbuffer, size_t bytes);
size_t gather_random_slow(void* pbuffer, size_t bytes);
int close_system();



extern __inline__
void printk(char *, ...);
#include <memory.h>
/* we used gpgs secmem.h/c code and all it does is put all process memory into the ram instead of the page allocation table so in cpdu.c we use mlockall() function call to attempt to lock all the program memory space into the ram to perform the same function as secmem attempts to do so we dont need really gpgs secmem code rather moreso locking the memory table into the ram with mlockall() being performed during program operation needs root priveleges */
#define smalloc malloc
#define sfree free
#define srealloc realloc
#if 0
extern __inline__
void *smalloc( size_t size ) {
        return secmem_malloc( size );
}

extern __inline__
void *srealloc( void *ptr, size_t newsize ) {
        return secmem_realloc( ptr, newsize );
}

extern __inline__
void sfree ( void *ptr ) {
        return secmem_free( ptr );
}
#endif
