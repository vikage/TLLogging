//
//  LoggingUtil.h
//
//  Created by Thanh Vu on 25/11/2020.
//  Copyright © 2020 Solar. All rights reserved.
//

#ifndef CUntil_h
#define CUntil_h

#import <Foundation/Foundation.h>

#if $ARCHS == arm64
#define DEBUG_BREAK_ASM() __asm("svc #0x80")
#else
#define DEBUG_BREAK_ASM() __asm("int3")
#endif

#if defined(__APPLE__) && defined(__aarch64__)
#define __debugbreak() __asm__ __volatile__(            \
    "   mov    x0, %x0;    \n" /* pid                */ \
    "   mov    x1, #0x11;  \n" /* SIGSTOP            */ \
    "   mov    x16, #0x25; \n" /* syscall 37 = kill  */ \
    "   svc    #0x80       \n" /* software interrupt */ \
    ::  "r"(getpid())                                   \
    :   "x0", "x1", "x16", "memory")
#elif defined(__APPLE__) && defined(__arm__)
#define __debugbreak() __asm__ __volatile__(            \
    "   mov    r0, %0;     \n" /* pid                */ \
    "   mov    r1, #0x11;  \n" /* SIGSTOP            */ \
    "   mov    r12, #0x25; \n" /* syscall 37 = kill  */ \
    "   svc    #0x80       \n" /* software interrupt */ \
    "   mov    r0, r0      \n" /* nop                */ \
    ::  "r"(getpid())                                   \
    :   "r0", "r1", "r12", "memory")
#elif defined(__APPLE__) && (defined(__i386__) || defined(__x86_64__))
#define __debugbreak() __asm__ __volatile__("int $3; mov %eax, %eax")
#endif

#ifdef DEBUG
#define DEBUGCHECK(conditional, File, Func, Line) if (!(conditional)) { LOG_DCHECK_FAIL(File, Func, Line); DEBUG_BREAK_ASM(); }
#else
#define DEBUGCHECK(conditional, File, Func, Line) ;
#endif

#define CHECK(conditional) \
    if (!(conditional)) {  \
        abort();           \
    }

#define LOG_DCHECK_FAIL(File, Func, Line) NSLog(@"DCHECK fail at %@ %@:%d", File, Func, Line);
#define NOTREACHED()                                                                      \
    NSLog(@"%@", [NSString stringWithFormat:@"NOTREACHED at %s:%d", __FILE__, __LINE__]); \
    DCHECK(false)
#define NOT_IMPLEMENT()                                                                      \
    NSLog(@"%@", [NSString stringWithFormat:@"Not Implement at %s:%d", __FILE__, __LINE__]); \
    DCHECK(false)
#define NOT_IMPLEMENT_CRASH()                                                                \
    NSLog(@"%@", [NSString stringWithFormat:@"Not Implement at %s:%d", __FILE__, __LINE__]); \
    exit(0);

extern void Objc_DCHECK(bool value, NSString *file, NSString *func, int line);

#endif /* CUntil_h */
