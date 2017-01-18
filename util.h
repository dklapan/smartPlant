#define F_CPU 48000000
#define _delay_us( US ) _delay_loops( (uint32_t)((double)US * F_CPU / 4000000.0) )
#define _delay_ms( MS ) _delay_loops( (uint32_t)((double)MS * F_CPU / 4000.0) )
#define _delay_s( S )   _delay_loops( (uint32_t)((double)S  * F_CPU / 4.0) )
