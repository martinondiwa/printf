#ifndef CUSTOM_FLAGS_H
#define CUSTOM_FLAGS_H

#ifdef FD_ZERO
#undef FD_ZERO
#endif
#define FD_ZERO

#define F_MINUS  0x02
#define F_PLUS   0x04
#define F_SPACE  0x03
#endif /* CUSTOM_FLAGS_H */
